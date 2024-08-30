/* -*- mode: c++ -*- */
#ifndef __DAQpp_GTimer_included__
#define __DAQpp_GTimer_included__

//#include <unistd.h>
#include "boost/date_time/posix_time/posix_time.hpp"

namespace cq
{
/**
     *  \brief class GTimer
     *  \ingroup Tools
     *
     *  This class implemets a timer. It is mainly used internally by the
     *  RunState objects.
     *
     *
     */
class GTimer
{
private:
    /// start time of the timer
    boost::posix_time::ptime _start;
    /// stop time of the timer
    boost::posix_time::ptime _end;
    /// flags saying if the timer is active or not
    bool active;

public:
    /// Constructor
    GTimer();
    /// Destructor
    ~GTimer()
    {}
    /// Starts the timer
    void start();
    /// Stops the timer
    void stop();
    /// resets the timer without stopping it
    void reset();
    /// returns the time in seconds elapsed since the start
    double operator()() const;
    /// returns true if the timer is active
    bool is_active() const
    {
        return active;
    }
};
}

inline cq::GTimer::GTimer()
{
    start();
}
inline void cq::GTimer::start()
{
    active = true;
    _start = boost::posix_time::microsec_clock::universal_time();
}
inline void cq::GTimer::stop()
{
    active = false;
    _end = boost::posix_time::microsec_clock::universal_time();
}
inline void cq::GTimer::reset()
{
    _start = boost::posix_time::microsec_clock::universal_time();
    _end = _start;
}
inline double cq::GTimer::operator()() const
{
    double total;
    boost::posix_time::ptime end;

    if ( active ) end = boost::posix_time::microsec_clock::universal_time();
    else end = _end;

    boost::posix_time::time_period tp(_start, end);

    total = tp.length().total_microseconds() / 1.e6;
    return total;
}
#endif
