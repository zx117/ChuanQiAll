#include "daq_manager.h"

using namespace cq;

unsigned long RunManager::cntr = 0;

//#define cq_DEBUG 1
#if defined(cq_DEBUG)
#include <iostream>
#include <iomanip>
#include "logger.h"
#define WHOAMI(str) { \
        DAQpp::ostream os; \
        os << loglevel(DAQpp::Log::debug) << str << "::" << __FUNCTION__ \
           << " - [thread " << std::hex << pthread_self() << std::dec \
           << "]" << std::endl; \
}
#else
#define WHOAMI(str)
#endif

//---------------------------------------------------------------------
// Functors to operate on the list of modules
//---------------------------------------------------------------------
/**
 * struct ModuleAcquire.
 * It is a Functor to loop over the Module's hanging from
 * this RunManger
 */
class ModuleAcquire : public std::unary_function<Observer *, void>
{
    public:
        /// Constructor
        ModuleAcquire(RunManager *m) :
            rm(m), ndata(0)
            {
            }
        /// Called in the loop for each Module
        void operator()(Observer *o);
        /// A pointer to the calling RunManager
        RunManager *rm;
        /// Number of modules with data
        int ndata;
};

void ModuleAcquire::operator()( Observer *o)
{
    if ( rm->get_status().isRunning() )
    {
        Module *m = dynamic_cast<Module *>(o);

        if ( m->hasData() )
        {
            int sz;
            char *data = m->getData(sz);
            if ( data )
            {
                // if ( rm->get_monitor() )
                //     if ( !rm->get_monitor()->full() )
                //         rm->get_monitor()
                //         ->push_event( new Event(sz, data) );

                int nw;
                if ( (nw=rm->writeData(sz, data)) )
                    rm->get_status().set_throughput(nw);

                m->deallocate(data);
                m->get_status().new_trigger();
                ndata++;
            }
        }
    }
}


RunManager::RunManager(RunCommand *rc): 
    DAQObject(++cntr), cmd(rc), /*monitor(0),*/ active(false), has_to_stop(0), max_events(0),
    run_number(0), event_number(0)
{
    init();
}

RunManager::RunManager(const DAQid &id, RunCommand *rc): 
    DAQObject(id), cmd(rc), /*monitor(0),*/ active(false), has_to_stop(0), max_events(0),
    run_number(0), event_number(0)
{
    init();
}

void RunManager::init()
{
    if ( !cmd )
        cmd = new RunCommand;

    get_status().set_name( get_id() );
    DAQmanager::theDAQmanager()->addRunManager(this);
}

RunManager::~RunManager()
{
    // if ( monitor )
    //     delete monitor;

    if ( active )
        deActivate();

    DAQmanager::theDAQmanager()->deleteRunManager(this);


    // release the Modules
    ObserverList::iterator ip;
    std::vector<Module *> vrm;
    std::vector<Module *>::iterator iv;
    for (ip = cmd->begin();ip != cmd->end();++ip)
    {
        Module *m = dynamic_cast<Module *>(*ip);
        if (m)
            vrm.push_back(m);
    }
    for (iv = vrm.begin();iv != vrm.end();++iv)
        (*iv)->UnRegisterDAQ(true);

    delete cmd;
}

///
void RunManager::deActivate()
{
    WHOAMI("RunManager");
    if ( active )
    {
        DAQmanager::theDAQmanager()->removeActiveRunManager(this);
        active = false;
    }
}
///
void RunManager::Activate()
{
    WHOAMI("RunManager");
    if ( !active )
    {
        active = true;
        DAQmanager::theDAQmanager()->addActiveRunManager(this);
    }
}

void RunManager::addModule(Module *o)
{
    if ( cmd->find(*o) == cmd->end() )
        o->RegisterDAQ(cmd);
}

void RunManager::deleteModule(Module *o)
{
    o->UnRegisterDAQ();
}

void RunManager::deleteModules()
{
    ObserverList::iterator ip;
    std::vector<Module *> vrm;
    std::vector<Module *>::iterator iv;
    for (ip = cmd->begin();ip != cmd->end();++ip)
    {
        Module *m = dynamic_cast<Module *>(*ip);
        if (m)
            vrm.push_back(m);
    }
    for (iv = vrm.begin();iv != vrm.end();++iv)
        (*iv)->UnRegisterDAQ();
}

void RunManager::moveModules(RunManager *from, RunManager *to)
{
    ObserverList::iterator ip;

    // first delete the Modules in the destination RunManager
    to->deleteModules();

    // now transfer
    std::vector<Module *> md;
    for (ip = from->cmd->begin();ip != from->cmd->end();++ip)
    {
        Observer *o = *ip;
        Module *m = dynamic_cast<Module *>(o);
        if (m)
            md.push_back( m );
    }
    std::vector<Module *>::iterator im;
    for (im = md.begin();im != md.end();++im)
    {
        Module *m = dynamic_cast<Module *>(*im);
        from->deleteModule( m );
        to->addModule( m );
    }
}

void cq::RunManager::Acquire()
{
    WHOAMI(">>> RunManager");
    //   theCondition.acquire();
    if ( active && get_status().isRunning() )
    {
        double thrp = get_status().get_throughput();
        ModuleAcquire ma =
            for_each(cmd->Observers().begin(),
                     cmd->Observers().end(),
                     ModuleAcquire(this));
        if ( ma.ndata )
        {
            get_status().new_trigger();
            if ( get_status().get_throughput() - thrp > 0. )
                get_status().new_written();
            EndOfEvent();
        }
    }
    WHOAMI("<<< RunManager");

    //   theCondition.release();
}

bool cq::RunManager::CheckEndOfRun()
{
    WHOAMI("RunManager");
    if ( max_events <= 0 )
        return false;
    else
        return (get_status().n_trigger() > max_events);
}

void cq::RunManager::GetReady()
{
    WHOAMI("RunManager");
    PrepareToStop(false);
    cmd->send_command(RunCommand::getready);
    get_status().set_status( RunState::Ready );
}
void cq::RunManager::Reset()
{
    WHOAMI("RunManager");
    cmd->send_command(RunCommand::send_reset);
    get_status().set_status( RunState::NotReady );
}
void cq::RunManager::Start()
{
    WHOAMI("RunManager");
    get_status().reset();
    get_status().start();
    PrepareToStop(false);
    cmd->send_command(RunCommand::initrun);
    get_status().set_status( RunState::Starting );

    cmd->send_command(RunCommand::run);
    get_status().set_status( RunState::Running );
    // starts the monitor
    // if ( get_monitor())
    // {
    //     get_monitor()->start_monitor();
    // }
}
void cq::RunManager::Stop()
{
    WHOAMI("RunManager");
    //   theCondition.acquire();
    get_status().set_status( RunState::Stopping );
    get_status().stop();
    cmd->send_command(RunCommand::stop);
    EndOfRun();
    get_status().set_status( RunState::Stopped );
    // if (get_monitor() )
    // {
    //     get_monitor()->stop_monitor();
    // }
    //   theCondition.release();
}
void cq::RunManager::Pause()
{
    WHOAMI("RunManager");
    cmd->send_command(RunCommand::pauserun);
    get_status().set_status( RunState::Paused );
}
void cq::RunManager::Continue()
{
    WHOAMI("RunManager");
    cmd->send_command(RunCommand::resume);
    get_status().set_status( RunState::Running );
}

