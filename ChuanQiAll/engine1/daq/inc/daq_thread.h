/* -*- mode: c++ -*- */
#ifndef __daq_thread_h__
#define __daq_thread_h__

#include <string>
#include "boost/chrono.hpp"
#include "boost/thread.hpp"
#include "boost/thread/lock_guard.hpp"
#include "boost/thread/scoped_thread.hpp"
#include "boost/thread/recursive_mutex.hpp"
#include "boost/interprocess/sync/interprocess_semaphore.hpp"

namespace cq
{

    typedef  boost::recursive_mutex Mutex;
    // struct MutexPriv;
    // /** \brief class Mutex
    //  *   This class encapsulates a pthread Mutex
    //  */
    // class Mutex
    // {
    //     protected:
    //         /// debugflags
    //         bool             debug;

    //         /// the mutex
    //         boost::recursive_mutex _mtx;

    //         /// A private structure
    //         //MutexPriv *_priv;
    //         /// the thread that owns the mutex
    //         ///pthread_t       _owner;

    //         /// A counter
    //         ///int             _count;

    //         Mutex(const Mutex &);
    //         Mutex &operator=(const Mutex &);
    //     public:
    //         /// constructor
    //         Mutex();
    //         /// destructor
    //         ~Mutex();

    //         /// Sets the debug flags to the value in the input
    //         void set_debug(bool x)
    //         {
    //             debug = x;
    //         }

    //         /// Acquire or lock the mutex
    //         int  acquire();

    //         // /// Acquire or lock the mutex for time
    //         // /// The time out is in microseconds
    //         // bool  acquire_time(int time_out = -1);

    //         /** Checks whether the mutex is locked or not.
    //          *   @returns true if the mutex is locked, false otherwise.
    //          */
    //         bool busy();
    //         /** Releases the Mutex.
    //          *   Note: This class emulates a recursive mutex. One needs as
    //          *   many calls to release as calls where made to acquire.
    //          *
    //          *   @returns the number of times this function still needs to be
    //          *   called to really release the Mutex
    //          */
    //         int  release();

    // };

    /**
     * \brief call acquire_guard
     *
     * Acquire the Mutex with a constructor call, then release it with
     * the destructor call
     */
    // class acquire_guard
    // {
    //     private:
    //         Mutex &_mutex;
    //         acquire_guard(const acquire_guard &);
    //         acquire_guard &operator=(const acquire_guard &);
    //     public:
    //         acquire_guard(Mutex &m)
    //         : _mutex(m)
    //         {
    //             _mutex.lock();
    //         }
    //         ~acquire_guard()
    //         {
    //             _mutex.unlock();
    //         }
    // };
    typedef boost::lock_guard<Mutex> acquire_guard;

    /** \brief class Condition.
     *
     * This class encapsulates a condition, that is, it allows a thread
     * to suspend execution until some condition is satisfied. The way to
     * use it is calling its wait() method. When the condition is
     * satisfied the class will notify it to the waiting threads.
     *
     * This is an abstract class and the objects deriving from it should
     * implement the condition() method.
     *
     */
    class Condition
    {
        private:
            /// a pthread condition that we are Wrapping
            boost::condition_variable _cond;
            boost::mutex              _mtx;

            Condition(const Condition &);
            Condition &operator=(const Condition &);
        public:
            /// Constructor
            Condition();

            /// Destructor
            virtual ~Condition();


            /** Waits until the condition is satisfied (returns true) or
			 * 	there is a timeout (returns false). The time out is in microseconds
             */
            bool wait(int timeout = -1);

            /// Notifies a change to one of the waiting threads
            void notify();

            /// Notifies a change to all the waiting threads
            void notify_all();

            /** Condition to be checked.
             *   This function should be overloaded and return true when the
             *   thread should wake up and false otherwise
             */
            virtual bool condition() = 0;
            /**
             *  This is an optional function that is called before releasing
             *  the lock of the condition
             */
            virtual void exec()
            {}

    };

    /** \brief class Semaphore.
     */
    class Semaphore
    {
        private:
            /// The semaphore we are wrapping
            boost::interprocess::interprocess_semaphore _sem;
        public:
            /// Constructor
            Semaphore(int ifirst);
            /// Destructor
            ~Semaphore();

            /** Waits untils the sempahore value is not 0. It will decrease
             *   the semaphore count on exit.
             *   \param block if false it is a non-blocking call,
             *                otherwise it will block.
             *   \return  if in non blocking mode it will return 1
             *            value if the semaphore has a 0 count, 0 if the
             *            value could be decreased and -1 in case of
             *            error. In blocking mode it will return 0 in case
             *            of success and -1 in case of problems
             */
            bool wait(bool block = true);

            /// increases the semaphore count
            void post();

            /// returns the value of the semaphore count
            //int count();
    };

    /** \brief class Thread.
     *
     * This class represents a thread. It is an abstract class and the
     * objects deriving from it should implement the run() method, which
     * defines what the thread will execute. The thread will start
     * running when the start() method is called and can be stopped by
     * calling the stop() method.
     */
    class Thread
    {
        private:
            /// The thread we are wrapping
            boost::thread*  _thread;

            /// says if the thread has already started
            bool           _started;

            /// says if the thread has stopped
            bool           _stopped;

            /// The nice value for the thread process
            int            _nice;
        public:
            enum CancelType {
                deferred,
                asynchronous,
                disable
            };

            /// constructor
            Thread();

            /// destructor
            virtual ~Thread()
            {};

            /// Sets the nice value of the thread process
            void nice(int x)
            {
                _nice = x;
            }

            /// test if the thread has been cancelled
            void test_cancel();

            /// sets the way the thread can be cancelled. It is any of
            /// the options in CancelType
            void set_cancel(CancelType);

            /// exits the thread
            void exit(int v = 0);

            /// Starts the thread
            virtual void start();

            /// Stops the thread
            virtual void stop();

            /// The method that gets executed in the thread.
            virtual void run() = 0;

            /// Internal
            static int _run(void *);

            /// Checks if the thread is running
            bool is_running()
            {
                return _started;
            }

            /// Checks if the thread has stopped
            bool is_stopped()
            {
                return _stopped;
            }

    };

    //void wait(double sec);
}
#endif
