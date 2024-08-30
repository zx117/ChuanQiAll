#ifdef HAS_CONFIG_H
#include <config.h>
#endif
// #ifndef HAS_PYTHON
// #define Py_BEGIN_ALLOW_THREADS
// #define Py_END_ALLOW_THREADS
// #else
// #include <pythread.h>
// #endif
#include <cmath>
#include <cstring>
#include <iostream>
#include <cerrno>
//#include <unistd.h>
//#include <sys/types.h>
//#include <sys/time.h>
//#include <sys/resource.h>
#include <daq_thread.h>
//#include <DAQ++/logger.h>

#define NO_PYTHON
#ifdef NO_PYTHON
#define Py_BEGIN_ALLOW_THREADS
#define Py_END_ALLOW_THREADS
#endif

using namespace cq;

// struct cq::MutexPriv
// {
//         pthread_t _owner;
//         AtomicInt _count;
//         //int _count;
//         MutexPriv() : _owner(0), _count(0) {}
// };





// Mutex::Mutex() : debug(false)
// {

// }

// Mutex::~Mutex()
// {

// }
// int Mutex::acquire()
// {
// //    boost::recursive_mutex::scoped_lock lock(_mtx);
//     _mtx.lock();
//     return _mtx.recursion_count;

//     // int rc;
//  //    pthread_t me = pthread_self();
//  //    if ( pthread_equal(_priv->_owner,  me ) )
//  //    {
//  //        //_count++;
//  //        //__sync_fetch_and_add(&_count, 1);
//  //        _priv->_count++;
//  //        if ( debug )
//  //            fprintf(stdout, "Mutex::acquire (%x) count: %d\n", this, _priv->_count());
//  //        return _priv->_count();
//  //    }
//  //    Py_BEGIN_ALLOW_THREADS
//  //    rc = pthread_mutex_lock(&_mtx);
//  //    Py_END_ALLOW_THREADS
//  //    if (!rc)
//  //    {
//  //        _priv->_owner = me;
//  //        _priv->_count = 1;

//  //        if (debug)
//  //        {
//  //            //DAQpp::ostream os;
//  //            //os << loglevel(Log::debug) << "Mutex::acquire" << std::endl;
//  //            fprintf(stdout, "Mutex::acquire (%x)\n", this);
//  //        }
//  //        return 1;
//  //    }
//     //cq::ostream oss;
//     //oss << loglevel(Log::error) << "Mutex::acquire should not return 0" << std::endl;
//     //return 0;
// }

// // bool  Mutex::acquire_time(int time_out)
// // {
// //     boost::chrono::microseconds timeout(time_out);
// //     return _mtx.timed_lock( timeout );
// // }

// bool Mutex::busy()
// {
//     return _mtx.try_lock();
//     //pthread_t me = pthread_self();
//     // int rc       = pthread_mutex_trylock( &_mtx );
//     // if ( rc && errno == EBUSY )
//     // {
//     //     return true;
//     // }
//     // else
//     // {
//     //     // unlock and say it is free
//     //     //pthread_mutex_unlock(&_mtx);
//     //     release();
//     //     return false;
//     // }
// }
// int Mutex::release()
// {
//     //__sync_fetch_and_sub(&_count, 1);
// //     volatile int V = --_priv->_count;

// //     if (debug)
// //     {
// // //        DAQpp::ostream os;
// // //        os << loglevel(Log::debug) <<  "Mutex::release" << std::endl;
// //         fprintf(stdout, "Mutex::release (%x) count: %d\n", this, V);
// //     }

// //     if ( V<=0 )
// //     {
// //         _priv->_owner = 0;
// //         _priv->_count = 0;
// //         Py_BEGIN_ALLOW_THREADS
// //         pthread_mutex_unlock(&_mtx);
// //         Py_END_ALLOW_THREADS
// //     }

//     _mtx.unlock();

//     return _mtx.recursion_count;
// }

Condition::Condition()
{
    //pthread_cond_init(&_cond, 0);
}
Condition::~Condition()
{
    //pthread_cond_destroy(&_cond);
}

bool Condition::wait(int timeout)
{
    bool good = true;
    // if (debug)
    // {
    //     //DAQpp::ostream os;
    //     //os << loglevel(Log::debug) << "Condition::wait - acquiring Mutex" << std::endl;
    // }
    boost::unique_lock<boost::mutex> lock(_mtx);

    // if (debug)
    // {
    //     //DAQpp::ostream os;
    //     //os << loglevel(Log::debug) << "Condition::wait - ...done " << std::endl;
    // }
    if ( timeout <= 0 )
    {
        while ( !condition() )
        {
            // Py_BEGIN_ALLOW_THREADS
            // pthread_cond_wait(&_cond, &_mtx);
            // Py_END_ALLOW_THREADS
            _cond.wait( lock );
        }
        exec();
    }
    else
    {
        boost::chrono::microseconds duration(timeout);
        // struct timespec ts;
        // gettimeofday(&now, 0);

        // now.tv_usec += (timeout % 1000000);
        // now.tv_sec += (timeout + now.tv_usec) / 1000000;
        // now.tv_usec = now.tv_usec % 1000000;

        // ts.tv_sec = now.tv_sec;
        // ts.tv_nsec = now.tv_usec * 1000;

        boost::cv_status rc = boost::cv_status::no_timeout;
        while ( !condition() )
        {
            // Py_BEGIN_ALLOW_THREADS
            // rc = pthread_cond_timedwait(&_cond, &_mtx, &ts);
            // Py_END_ALLOW_THREADS
            rc = _cond.wait_for( lock, duration );
            if (rc == boost::cv_status::timeout)
            {
                good = false;
                break;
            }
        }
        if (good)
            exec();
    }

    // if (debug)
    // {
    //     DAQpp::ostream os;
    //     os << loglevel(Log::debug) << "Condition::wait - releasing mutex " << std::endl;
    // }
    // release();

    // if (debug)
    // {
    //     DAQpp::ostream os;
    //     os << loglevel(Log::debug) << "Condition::wait - ...done " << std::endl;
    // }
    return good;
}

void Condition::notify()
{
    //pthread_cond_signal(&_cond);
    _cond.notify_one();
}

void Condition::notify_all()
{
    //pthread_cond_broadcast(&_cond);
    _cond.notify_all();
}

Semaphore::Semaphore(int ival)
    :_sem(ival)
{
    //sem_init(&_sem, 0, ival);
}

Semaphore::~Semaphore()
{
    // do
    // {
    //     sem_destroy(&_sem);
    // }
    // while ( errno == EBUSY );
}

bool Semaphore::wait(bool block)
{
    bool rc(false);
    if ( ! block )
    {
        //rc = sem_trywait(&_sem);
        rc = _sem.try_wait();
        // if ( errno == EAGAIN )
        // {
        //     // The count is already 0
        //     rc = 1;
        // }
    }
    else
    {
        // Py_BEGIN_ALLOW_THREADS
        // rc = sem_wait(&_sem);
        // Py_END_ALLOW_THREADS
        _sem.wait();
        rc = true;
    }
    return rc;
}

void Semaphore::post()
{
    _sem.post();
}

// int Semaphore::count()
// {
//     int rc;
//     _sem.
//     return rc;
// }

Thread::Thread() : _thread(nullptr), _started(false), _stopped(false), _nice(-1)
{
}


void Thread::start()
{
    _started = true;
    _stopped = false;

    /* Initialize and set thread detached attribute */
    // pthread_attr_t attr;
    // pthread_attr_init(&attr);
    // pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // pthread_create(&_thread, &attr, _run, this);

    // pthread_attr_destroy(&attr);
    if (!_thread) {
        _thread = new boost::thread(boost::bind(_run,this));
    }
}

void Thread::stop()
{
    //void *rc;
    if (!_stopped)
    {
        _stopped = true;
        //pthread_cancel(_thread);
        //pthread_join(_thread, &rc);
        _thread->interrupt();
        _thread->join();
    }
    _started = false;
    _stopped = true;

    if (_thread) {
        delete _thread;
        _thread = nullptr;
    }
}

void Thread::exit(int val)
{
    //pthread_exit((void *)val);
}

void Thread::test_cancel()
{
   // pthread_testcancel();
}

void Thread::set_cancel(CancelType ct)
{
    switch (ct)
    {
        case deferred:
            //pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, 0);
            //pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
            break;
        case asynchronous:
            //pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, 0);
            //pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, 0);
            break;
        case disable:
            //pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, 0);
            break;
    }
}

int Thread::_run(void *data)
{
    Thread *thrd = reinterpret_cast<Thread *>(data);
    //    if (thrd->_nice>=0)
    //       setpriority(PRIO_PROCESS,getpid(),thrd->_nice);

    try {
        thrd->run();
    }
    catch (boost::thread_interrupted)
    {

    }

    thrd->_stopped = true;
    thrd->_started = false;
    //pthread_exit(0);

    return 0;
}

// void cq::wait(double secs)
// {
//     struct timeval t;
//     double frac;
//     frac = fmod(secs, 1.0);
//     secs = floor(secs);
//     t.tv_sec = (long)secs;
//     t.tv_usec = (long)(frac*1000000.0);
//     Py_BEGIN_ALLOW_THREADS
//     if (select(0, (fd_set *)0, (fd_set *)0, (fd_set *)0, &t) != 0) {
//         if (errno!=EINTR)
//         {
//             DAQpp::ostream os;
//             os << loglevel(Log::error) << "Error in DAQpp::wait: " << strerror(errno) << std::endl;
//         }
//     }
//     Py_END_ALLOW_THREADS
// }


