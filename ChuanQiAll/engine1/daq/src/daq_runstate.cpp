#include <iostream>
#include <iomanip>
#include <daq_runstate.h>
#include <daq_mutexpriv.h>

std::string cq::RunState::str_state[RunState::last_state] = {
            "NotDefined",
            "NotReady",
            "GettingReady",
            "Ready",
            "Starting",
            "Paused",
            "Running",
            "Stopping",
            "Stopped",
            "TimeOut"
        };

std::ostream &operator<<(std::ostream &os, const cq::RunState &st)
{
    // double rate = st.rate();
    // std::string rate_units = " Hz";

    // if ( rate > 1.e6 )
    // {
    //     rate /= 1.e6;
    //     rate_units = "MHz";
    // }
    // else if (rate > 1000.)
    // {
    //     rate /= 1000.;
    //     rate_units = "kHz";
    // }


    double throughput = st.get_throughput()/st.time();
    std::string thr_units;
    if (throughput > 1048576.0)
    {
        throughput /= 1048576.0;
        thr_units = "Mb/s";
    }
    else if (throughput > 1024.0)
    {
        throughput /= 1024.0;
        thr_units = "kb/s";
    }
    else if (throughput > 1.0 )
    {
        thr_units = "b/s";
    }
    else
    {
        throughput *= 1024;
        thr_units = " mb/s";
    }

    os   << "Evts "
         << std::setiosflags(std::ios::fixed | std::ios::right)
         << std::setw(7) << st.n_trigger()
         << " time "
         << std::setw(6) << std::setprecision(1)
        << st.time()
        // << " rate "
        // << std::setw(8) << std::setprecision(1)
        // << rate
        // << rate_units
        << " eff "
        << std::setw(5) << std::setprecision(1)
        << st.eff()
        << " - "
        << std::setw(7) << std::setprecision(1)
        << throughput
        << " " << thr_units
        << std::flush;
    return os;
}


void cq::RunState::cpy(const RunState &s)
{
    daqid = s.daqid;
    name = s.name;
    nexpected = s.nexpected;
    ntrig = s.ntrig;
    nwritten = s.nwritten;
    throughput = s.throughput;
    status = s.status;

    timer = s.timer;
    timer.stop();
}

// double cq::RunState::rate(bool average) const
// {
//     double r, t, t0, n;

//     cq::RunState *st = const_cast<RunState *>(this);

//     t0 = timer();

//     if ( !isRunning())
//         average = true;

//     if ( average )
//     {
//         t = t0;
//         n = (double)(ntrig);
//     }
//     else
//     {
//         t = t0 - tim0;
//         n = ntrig - ntrg0;
//     }
//     r = (t != 0. ? n / t : 0.);
//     st->tim0 = t0;
//     st->ntrg0 = ntrig;
//     return r;
// }

cq::RunState::RunState()
        : name(""), daqid(""), nexpected(0), ntrig(0), nwritten(0), throughput(0), status(NotDefined),
        ntrg0(0), tim0(0.)
{
    start();
    stop();
    reset();
    //_priv = new boost::recursive_mutex();
}

cq::RunState::RunState(const DAQid &id)
        : name(""), daqid(id), nexpected(0), ntrig(0), nwritten(0), throughput(0), status(NotDefined),
        ntrg0(0), tim0(0.)
{
    start();
    stop();
    reset();
    //_priv = new boost::recursive_mutex();
}

cq::RunState::RunState(const RunState &s) : daqid("<unnamed>")
{
    cpy(s);
    //_priv = new boost::recursive_mutex();
}


cq::RunState::~RunState()
{
    deleteObservers();
    clearActionList();
    //delete _priv;
}

void cq::RunState::addAction( RunStateAction *a)
{
    action_list.insert(a);
}

void cq::RunState::deleteAction( RunStateAction *a )
{
    action_list.erase( a );
}

void cq::RunState::clearActionList()
{
    ActionList::iterator it;
    for (it = action_list.begin();it != action_list.end();++it)
        delete *it;

    action_list.clear();
}

void cq::RunState::executeActionList()
{
    std::for_each(action_list.begin(), action_list.end(), executeAction());
}

void cq::RunState::reset()
{
    nexpected = 0;
    ntrig = 0;
    nwritten = 0;
    throughput = 0;
    timer.reset();
}

void cq::RunState::start()
{
    timer.start();
}

void cq::RunState::stop()
{
    timer.stop();
}


double cq::RunState::eff() const
{
    double eff;
    double expected = nexpected;
    double registered = ntrig;
    if ( expected <= 0 )
        expected = ntrig;

    if (nwritten>=0)
        registered = nwritten;

    eff = (registered > 0.0 ? (registered / expected) : 0. );
    return 100.*eff;
}

// double DAQpp::RunState::get_throughput() const {
//    if ( time()==0. )
//       return 0.;
//    else
//       return throughput*sizeof(char)/1024./time();
// }

cq::RunState::StatusType cq::RunState::set_status(cq::RunState::StatusType st)
{
    volatile StatusType old;
    _priv.lock();
    old = status;
    status = st;
    if (status == Stopping)
    {
        timer.stop();
    }
    _priv.unlock();

    if ( st != old )
    {
        Arg<StatusType> arg(st);
        notifyObservers(&arg);
    }
    return old;
}

void cq::RunState::update(Observable *o, Argument *arg)
{
    Arg<StatusType> *st = static_cast< Arg<StatusType> * > (arg);
    set_status( *st );
}

const cq::DAQid &cq::RunState::get_daqid() const
{
    return daqid;
}

const std::string &cq::RunState::get_name() const
{
    return name;
}
/// sets the name of the RunState
void cq::RunState::set_name(const std::string &s)
{
    name = s;
}

/// returns the number of triggers
unsigned int cq::RunState::n_trigger() const
{
    return ntrig;
}
/// Increases the number of triggers
void cq::RunState::new_trigger()
{
    ntrig++;
}
/// Increases the number of saved events
void cq::RunState::new_written()
{
    nwritten++;
}
/// Returns the number of saved events
unsigned int cq::RunState::n_written() const
{
    return nwritten;
}

/// sets the number of expected events
void cq::RunState::set_expected(unsigned int val)
{
    nexpected = val;
}

void cq::RunState::increase_expected(unsigned int val)
{
    nexpected += val;
}

unsigned int cq::RunState::n_expected() const
{
    return nexpected;
}

double cq::RunState::time() const
{
    return timer();
}
///  returns the throughput
double  cq::RunState::get_throughput() const
{
    return throughput;
}
/// resets the throughput counter
void cq::RunState::reset_throughput()
{
    throughput = 0;
}
/// sets the throughput counter to a given value
void cq::RunState::set_throughput(unsigned int x)
{
    throughput += x;
}

/// Returns the current status
cq::RunState::StatusType cq::RunState::get_status() const
{
    return status;
}

/// Returns true if the object is running
bool cq::RunState::isRunning()
{
    volatile bool out;
    _priv.lock();
    out = (status == Running || status == Paused);
    _priv.unlock();
    return out;
}

/// Returns true if the object's state is Ready
bool cq::RunState::isReady()
{
    volatile bool out;
    _priv.lock();
    out = (status == Ready);
    _priv.unlock();
    return out;
}

/// Returns true if the object's state is Paused
bool cq::RunState::isPaused()
{
    volatile bool out;
    _priv.lock();
    out = (status == Paused);
    _priv.unlock();
    return out;
}

/// Returns true if the object's state is NotReady
bool cq::RunState::isNotReady()
{
    volatile bool out;
    _priv.lock();
    out = (status == NotReady);
    _priv.unlock();
    return out;
}

/// Returns true if the object's state is TimeOut
bool cq::RunState::isTimeout()
{
    volatile bool out;
    _priv.lock();
    out = (status == TimeOut);
    _priv.unlock();
    return out;
}
