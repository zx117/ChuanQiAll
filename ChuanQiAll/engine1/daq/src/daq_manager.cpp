#include <iostream>
//#include <unistd.h>
#include "daq_manager.h"
#include "daq_runstate.h"
#include "daq_id.h"
#include "daq_thread.h"
//#include "daq_logger.h"

using namespace cq;
//#define DAQpp_DEBUG 1
#if defined(DAQpp_DEBUG)
#include <iomanip>
#define WHOAMI(str) {\
    DAQpp::ostream os; \
    os << loglevel(DAQpp::Log::debug) << str << "::" << __FUNCTION__ \
       << " - [thread " << std::hex << pthread_self() << std::dec << "]" \
       << std::endl; \
}
#else
#define WHOAMI(str)
#endif

DAQmanager DAQmanager::theManager;

static DAQTrigger __trigger__;


/// unary function to loop on RunManager objects
class RunAcquire : public std::unary_function<RunManager const *, void>
{
    private:
        DAQmanager *mngr;
    public:
        /// Constructor. Needs a pointer of the calling DAQmanager
        RunAcquire() :
            mngr(DAQmanager::theDAQmanager())
            {
            }
        /// Called in the loop for each RunManager
        void operator()(RunManager *rm);
};

inline void RunAcquire::operator()( RunManager *rm)
{
    if ( rm && rm->get_status().isRunning() )
    {
        rm->Acquire();
        if ( rm->CheckEndOfRun() || rm->HaveToStop() )
            mngr->stopRunManager(rm);
    }
}

void DAQmanager::DAQthread::run()
{
    mngr->new_obj( startDAQ, (char *)mngr );
    mngr->Acquire();
    mngr->new_obj( stopDAQ, (char *)mngr );
    return;
}


bool DAQmanager::RunCondition::condition()
{
    bool rc = !mngr->isRunning();
    if (!mngr->isLooping() )
        rc |= mngr->active.empty();

    return rc;
}


DAQmanager::DAQmanager() :  state(0), trigger(&__trigger__)
{
    //   active.set_debug(true);
}
DAQmanager::DAQmanager(const DAQmanager &) : state(0), trigger(&__trigger__)
{
    //   active.set_debug(true);
}


bool DAQmanager::isRunning() const
{
    volatile int _s = state.load();
    return (_s & Running) != 0;
}
/// Checks if the DAQ is looping
bool DAQmanager::isLooping() const
{
    volatile int _s = state.load();
    return (_s & Loop) != 0;
}
///  Checks if the DAQ is threaded
bool DAQmanager::isThreaded() const
{
    volatile int _s = state.load();
    return (_s & Threaded) != 0;
}



void DAQmanager::set_trigger( DAQTrigger *func )
{
    if ( !func )
        trigger = &__trigger__;
    else
        trigger = func;
}

DAQmanager::~DAQmanager()
{
    // Disconnect from subscribed obserbers
    deleteObservers();

    std::vector<Module *> modules;
    std::vector<Module *>::iterator im;
    ModulesMap::iterator m;
    for (m = mmap.begin();m != mmap.end();++m)
    {
        modules.push_back( (*m).second);
    }
    for (im=modules.begin(); im!=modules.end(); ++im)
        delete *im;

    std::vector<RunManager *> runmanagers;
    std::vector<RunManager  *>::iterator irm;
        RunManagerMap::iterator rm;
    for (rm = runm.begin();rm != runm.end();++rm)
    {
        runmanagers.push_back( (*rm).second );
    }
    for (irm=runmanagers.begin(); irm!=runmanagers.end(); ++irm)
        delete *irm;

    runm.clear();
    mmap.clear();
}

void DAQmanager::addActiveRunManager(RunManager *rm)
{
    active.insert(rm);
}

void DAQmanager::removeActiveRunManager(RunManager *rm)
{
    // We defer removal from the list until the end of the event when
    // running.
    if (!isRunning())
        active.erase(rm);
}


void DAQmanager::StartRun(int flags)
{
    WHOAMI("DAQmanager");
    if ( isRunning() )
    {
        // cq::ostream os;
        // os << DAQpp::loglevel(DAQpp::Log::error)
        //           <<  "DAQmanager::StartRun - "
        //           << "There is already an instance running"
        //           << std::endl;
        return;
    }


    RunManagerSet::iterator it;
    state = Running | ( Public & flags);
    if ( isLooping() && !isThreaded() )
        state |= Threaded;


    for ( it = active.begin();it != active.end();++it )
        startRunManager( *it );


    if ( state & Threaded )
    {
        thread.nice(0);
        thread.start();
    }
    else
    {
        new_obj( startDAQ, (char *)this );
        Acquire();
        new_obj( stopDAQ, (char *)this );
    }
}
void DAQmanager::StopRun()
{
    WHOAMI("DAQmanager");
    RunManagerMap::iterator it;
    //    if ( !(state&Running) ) {
    //       return;

    state &= ~Running;
    active.notify_all();

    for ( it = runm.begin();it != runm.end();++it )
    {
        RunManager *rm = (*it).second;
        if ( rm->isActive() && rm->get_status().isRunning() )
        {
            rm->PrepareToStop(true);
        }
    }

    WaitForEndOfRun();

    active.notify_all();
    if (isThreaded() && thread.is_running() )
        thread.stop();

}

void DAQmanager::WaitForEndOfRun(int tmout)
{
    WHOAMI(">>> DAQmanager");
    daq_cond.wait(tmout);
    WHOAMI("<<< DAQmanager");
}



void DAQmanager::startRunManager(RunManager *rm)
{
    WHOAMI(">>> DAQmanager");
    rm->PrepareToStop(false);
    rm->PrepareForRun();
    rm->GetReady();
    if (!rm->isActive())
        rm->Activate();

    rm->Start();
    WHOAMI("<<< DAQmanager");
}

void DAQmanager::stopRunManager(RunManager *rm)
{
    WHOAMI(">>> DAQmanager");
    rm->get_status().set_status( RunState::Stopping );
    rm->Stop();
    rm->deActivate();
    rm->get_status().set_status( RunState::Ready );
    rm->PrepareToStop(false);
    WHOAMI("<<< DAQmanager");
}

inline bool is_active( RunManager *r)
{
    return r->isActive();
}

void DAQmanager::processTheEvent()
{
    RunManagerSet::iterator ip;

    // First make the RunManagers send the Trigger command
    for (ip = active.begin();ip != active.end();++ip)
        (*ip)->Trigger();

    // Now wait for a trigger
    if ( (*trigger)() )
    {
        // Let active RUnManager do their job
        for_each(active.begin(), active.end(), RunAcquire());
    }

    // Check if any of them has deactivated
    //      active.erase(remove_if(active.begin(), active.end(), is_active), active.end());
    std::vector<RunManager *> vstp;
    std::vector<RunManager *>::iterator iv;
    for (ip = active.begin();ip != active.end();++ip)
    {
        if ( !(*ip)->isActive() )
            vstp.push_back(*ip);
    }
    for (iv = vstp.begin();iv != vstp.end();++iv)
        active.erase(*iv);

}

void DAQmanager::Acquire()
{
    WHOAMI("DAQmanager");
    while ( isRunning() )
    {

        // If we are looping sleep if there are no active RunManager
        if ( isLooping() )
            active.wait();

        if (!isRunning())
            break;

        // process the event
        processTheEvent();

        if ( daq_cond.condition() )
        {
            state &= ~Running;
            daq_cond.notify_all();
        }

        if ( isThreaded())
            thread.test_cancel();
    }
}



//---------------------------------------------------------------------
// The set of active RunManager
//---------------------------------------------------------------------
std::pair<DAQmanager::RunManagerSet::iterator, bool> DAQmanager::RunManagerSet::insert(const value_type &x)
{
    mtx.lock();
    std::pair<iterator, bool> rc = std::set<RunManager *>::insert(x);
    mtx.unlock();
    notify_all();
    return rc;
}
DAQmanager::RunManagerSet::iterator DAQmanager::RunManagerSet::insert(iterator pos, const value_type &x)
{
    mtx.lock();
    iterator rc = std::set<RunManager *>::insert(pos, x);
    mtx.unlock();
    notify_all();
    return rc;
}
void DAQmanager::RunManagerSet::erase(DAQmanager::RunManagerSet::iterator pos)
{
    mtx.lock();
    std::set<RunManager *>::erase(pos);
    mtx.unlock();
    notify_all();
}
DAQmanager::RunManagerSet::size_type DAQmanager::RunManagerSet::erase(const key_type &k)
{
    mtx.lock();
    size_type sz =  std::set<RunManager *>::erase(k);
    mtx.unlock();
    notify_all();
    return sz;
}
void DAQmanager::RunManagerSet::erase(DAQmanager::RunManagerSet::iterator first, DAQmanager::RunManagerSet::iterator last)
{
    mtx.lock();
    std::set<RunManager *>::erase(first, last);
    mtx.unlock();
    notify_all();
}
void DAQmanager::RunManagerSet::clear()
{
    mtx.lock();
    std::set<RunManager *>::clear();
    mtx.unlock();
    notify_all();
}

bool DAQmanager::RunManagerSet::condition()
{
    bool rc;
    mtx.lock();
    rc = !empty() && mngr->isRunning();
    mtx.unlock();
    return rc;
}

