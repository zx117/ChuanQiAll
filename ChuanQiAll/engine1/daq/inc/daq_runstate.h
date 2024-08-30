/* -*- mode: c++ -*- */
#ifndef __daq_runstate_h__
#define __daq_runstate_h__

#include <functional>
#include <string>
#include <set>
#include <iosfwd>
#include "daq_id.h"
#include "daq_timer.h"
#include "daq_thread.h"
#include "daq_observer_model.h"

namespace cq
{

    /**
     *  \brief class RunStateAction.
     *  \ingroup DAQ
     *  This is an abstract type that defines some actions that can be defined
     *  on a RunState.
     */
    class RunStateAction
    {
        public:
            /// destructor
            virtual ~RunStateAction()
            {}
            /// fuction that will be executed
            virtual void execute() = 0;
    };

    /**
     *  \brief class RunState.
     *  \ingroup DAQ
     *
     *  This class maintains the information about the status of a DAQ
     *  object. The status can be any of:
     *   - NotDefined,
     *   - NotReady,
     *   - GettingReady,
     *   - Ready,
     *   - Paused,
     *   - Starting,
     *   - Running,
     *   - TimeOut,
     *
     *  This class derives both from an Observer and Observable. As an
     *  Observable, it will notify any change of state to any of the
     *  subscribed Observers. As an Observer, the situation is a bit
     *  confusing and should probably need reconsideration. In the \em
     *  update method it expects as argument a pointer to an
     *  \code Arg<StatusType> \endcode
     *  On receipt of the notification it will
     *  change the state to the one given in the argument.
     *
     *  It provides methods to access some other information about the DAQ
     *  object, like the number of triggers, the number of events saved, the
     *  run duration time, the efficiency, the rate, etc.
     *
     *  It also maintains a list of RunStateAction. Those objects represent
     *  an action that could be executed at request. The list of Actions is
     *  maintained by addAction(),deleteAction(),clearActionList(),
     *  executeActionList().
     *
     *  The idea of this list of actions is to be able to make some operations,
     *  like monitoring, in an automatic way. One could think on actions like:
     *  \code
     *  class UpdateWidget : public RunStateAction 
     *  {
     *     private:
     *        RunState *_state;
     *        GtkWidget *_wdgt;
     *
     *     public:
     *        UpdateWidget(GtkWidget *w, RunState *s=0): _wdgt(w),_state(s) {}
     *        GtkWidget *wdgt() { return _wdgt; }
     *        RunState *state() { return _state; }
     *  };
     *
     *  class UpdateLabel : public UpdateWidget 
     *  {
     *     private:
     *       string str
     *     public:
     *        UpdateLabel(GtkWidget *w, RunState *s=0) : UpdateWidget(w,s),str("label") {}
     *        void execute() 
     *        {
     *           gtk_label_set_text(GTK_LABEL(wdgt),str.c_str());
     *        }
     *  };
     *
     *  \endcode
     *
     *  and similarly with classes like UpdateButton, UpdateSlider, etc.
     *
     *
     */
    class RunState : public Observable, public Observer
    {
        private:
            /// Internal copier
            void cpy(const RunState &s);
        public:
            /// Constructor
            RunState();

            /// Constructor
            RunState(const DAQid &id);

            /// Copy constructor
            RunState(const RunState &s);

            /// Asignment operator
            RunState &operator=(const RunState &s)
            {
                if (this != &s) cpy(s);
                return *this;
            }

            /// Destructor
            virtual ~RunState();

            /// Posible state values
            enum StatusType {
                NotDefined,   /*!< state undefined */
                NotReady,     /*!< not ready for run, needs a GetReady command */
                GettingReady, /*!< the object is initializing */
                Ready,        /*!< the object has been initialized and is ready to run */
                Starting,     /*!< the acquisition has just started and the object is preparing to acquire */
                Paused,       /*!< the object is acquiring but the acquisition has been paused */
                Running,      /*!< the object is acquiring */
                Stopping,     /*!< the object is closing the acquisition */
                Stopped,      /*!< the object has closed the acquisition */
                TimeOut,      /*!< the object does not respond */
                last_state
            };

            /// returns the daqid of the owner DAQObject
            const DAQid &get_daqid() const;

            /// returns the name of the RunState
            const std::string &get_name() const;

            /// sets the name of the RunState
            void set_name(const std::string &s);

            /**
             *  Resets the internal counters. It will reset the run duration
             *  time, the number of triggers, saved events, etc.
             */
            void reset();
            /// Starts the timer
            void start();
            /// Stops the timer
            void stop();
            /// returns the number of expected triggers
            unsigned int n_expected() const;
            /// returns the number of triggers
            unsigned int n_trigger() const;
            /// Returns the number of saved events
            unsigned int n_written() const;
            /// Sets the number of expected events
            void set_expected(unsigned int val);
            /// Increase the number of expected events
            void increase_expected(unsigned int val);

            /// Increases the number of triggers
            void new_trigger();
            /// Increases the number of saved events
            void new_written();
            /**
             *  Returns the efficiency.
             *  The Efficiency is defined as the ration between saved events
             *  and number of triggers.
             */
            double eff() const;
            /// Returns the acquisition rate
            /**
             *  It provides the acquisition time. It can be the average rate over
             *  the whole acquisition period, if average is true, or the 
             *  instantaneous rate if average is false.
             */
            //double rate(bool average = false) const;
            /// Returns the time elapsed since the start
            double time() const;
            ///  returns the throughput
            double  get_throughput() const;
            /// resets the throughput counter
            void reset_throughput();
            /// sets the throughput counter to a given value
            void set_throughput(unsigned int x);

            /// Returns the current status
            StatusType get_status() const;

            /// Returns true if the object is running
            bool isRunning();// const;

            /// Returns true if the object's state is Ready
            bool isReady();// const;

            /// Returns true if the object's state is Paused
            bool isPaused();// const;

            /// Returns true if the object's state is NotReady
            bool isNotReady();// const;

            /// Returns true if the object's state is TimeOut
            bool isTimeout();// const;

            /// Sets the current status
            StatusType set_status(StatusType st) ;

            /**
             *   Receives a request to change status.
             *   This is the method call by any observable for which the
             *   RunState has subscribed for notifications. It expects as
             *   agument a pointer to an 
             *   \code Arg<StatusType> \endcode
             */
            void update(Observable *o, Argument *arg);

            /// array with the names of the possible states
            static std::string str_state[last_state];
            /// Returs the state as a string
            static std::string const &status_str(StatusType st)
            {
                return str_state[st];
            }
        private:
            /// name of the RunState
            std::string name;
            /// DAQid of the owner DAQObject
            DAQid daqid;
            /// Number of expected triggers
            unsigned int nexpected;
            /// Number of triggers registered
            unsigned int ntrig;
            /// Number of events written
            unsigned int nwritten;
            /// Throughput
            unsigned int throughput;
            /// State
            StatusType status;
            /// A timer used internally to compute rate, run duration, etc
            GTimer timer;

            /// Internal buffer
            unsigned int ntrg0;
            /// Internal buffer
            double tim0;

            /// Internal structure
            Mutex _priv;

            /// generic type for the list of actions
            typedef std::set<RunStateAction *> ActionList;
            /**
             *  List of actions to be made at update time.  
             */
            ActionList action_list;
            /**
             *  This is a unary function that will be executed on every
             *  RunAction after update
             */
            struct executeAction : public std::unary_function<RunStateAction *, void>
            {
                /// Constructor
                executeAction()
                {}
                /// this will be executed by all the actions in the list
                void operator()( RunStateAction *action )
                {
                    action->execute();
                }
            };
            public:
                /// Adds an action
                void addAction(RunStateAction *);
                /// Deletes an action from the list
                void deleteAction(RunStateAction *);
                /// Clears all the action list
                void clearActionList();
                /// Execute all the actions in the action list
                void executeActionList();
    };
}
std::ostream &operator<<(std::ostream &os, const cq::RunState &st);

#endif
