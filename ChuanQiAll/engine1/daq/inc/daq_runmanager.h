/* -*- mode: c++ -*- */
#ifndef __daq_runmanager_h__
#define __daq_runmanager_h__

#include "daq_object.h"
#include "daq_runcommand.h"
#include "daq_module.h"
//#include "DAQ++/Monitor.h"

#include "boost/atomic/atomic.hpp"

namespace cq
{

    /**
     * class RunManager
     *
     * \ingroup DAQ
     *
     * A RunManager controls the acquisition of a number of Module objects
     * that share a common acquisition \em style. It will also handle in
     * the same way the storage of the data from the different
     * Modules. This class is an interface between the DAQmanager and the
     * Modules. It transmits the DAQ commands to the different
     * Modules. This is done with a RunCommand that can be given in the
     * constructor. If none is given, one will be automatically generated.
     * RunManager will delete the RunCommand in the destructor, even if it
     * is given in the constructor. The operations that a RunManager can
     * make on its list of Modules are
     *
     *    - GetReady()
     *    - Start()
     *    - Pause()
     *    - Continue()
     *    - Trigger()
     *    - Reset()
     *    - Acquire()
     *    - writeData()
     *
     * All those operations can be overloaded but this is not recomended
     * unless you really know what you are doing, since that may change
     * the acquisition process. The default action is to send the command
     * to all the Modules in the list.
     *
     * RunManager also provide a number of \em hooks at some stages of the
     * acquisition and this is the place where one can savely introduce
     * his/her own code.
     *
     *    - PrepareForRun()
     *    - EndOfEvent()
     *    - EndOfRun()
     *    - CheckEndOfRun()
     *
     * Module's should be registered to a RunManager with the
     * RunManager::addModule( Module *). To unregister a Module
     * RunManager::deleteModule(Module *) should be used. The list of
     * Modules can be emptied with RunManager::deleteModules().
     *
     * The data is read from the modules in ModuleAcquire. Modules should
     * get the memory to pass the data to the RunManager with
     * Module::allocate. The run manager will take care of deallocating
     * the memory.
     *
     * A RunManager derives from ParameterHolder and, therefore, can
     * mantain a list of named Parameters. The use of named parameters
     * assumes the knowledge of the Parameter type.
     *
     *
     */

    class RunManager : public DAQObject
    {
        private:
            /// RunManager counter
            static unsigned long cntr;
            /// RunCommand
            RunCommand *cmd;
            /// Monitor
            //Monitor *monitor;
            /// Flag to now whether the RunManager is active or not.
            bool active;

            /// flag to force the RunManager to stop
            boost::atomic<bool> has_to_stop;

            /**
             * Number of events for the run.
             * In the default implementation of CheckEndOfRun()
             * a negative value, or zero, will make an infinite run, otherwise
             * this this will set the maximum number of events to be saved. 
             * If CheckEndOfRun is overloaded, then you will have to define
             * the proper behaviour.
             */
            unsigned int max_events;

            /// Common Initialization at construction
            void init();

            /// A DAQ mutex to be used internally
            boost::mutex theCondition;

        protected:
            /// Run number
            unsigned int run_number;
            /// Event number
            unsigned int event_number;

        public:
            /**
             * Constructor with a RunCommand. 
             *
             * The DAQid associated with this RunManager will be
             * generated automatically by the system.
             * \param[in] rc The RunCommand object. If not given, a default is
             *               created by the constructor
             */
            RunManager(RunCommand *rc = 0);
            /// Constructor with DAQid and RunCommand
            RunManager(const DAQid &, RunCommand *rc = 0);
            /// Destructor
            virtual ~RunManager();

            /// Set the current run number
            void set_run_number(unsigned int x)
            {
                run_number = x;
            }
            /// returns the current run number
            unsigned int get_run_number() const
            {
                return run_number;
            }
            /// returns the current event number
            unsigned int get_event_number() const
            {
                return event_number;
            }

            //---------------------------------------------------------------------
            // Module handling
            //---------------------------------------------------------------------
            /// Returns the RunCommand that communicates with the Module's
            RunCommand *operator()()
            {
                return cmd;
            }
            /// Adds a new Module
            void addModule(Module *o);

            /// Removes a Module from the list
            void deleteModule(Module *o);

            /// Delete all the modules in the list
            void deleteModules();

            /// Returns the number of Modules in the list
            int countModules()
            {
                return cmd->countObservers();
            }

            /// Moves the Modules from one RunManager to the other
            static void moveModules(RunManager *from, RunManager *to);

            /// Loops on all the modules
            template <class _Function> _Function for_each_module(_Function __f)
            {
                return cmd->for_each_observer(__f);
            }

            //---------------------------------------------------------------------
            // DAQ commands
            //---------------------------------------------------------------------
            /// Set the Stop flag
            void PrepareToStop(bool z)
            {
                has_to_stop = ( z ? 1 : 0);
            }

            /// Checks if the RUnManager needs to stop
            bool HaveToStop() const
            {
                return has_to_stop.value();
            }

            /// Returns true is the RunManager is active
            bool isActive() const
            {
                return active;
            }

            /// Deactivates the RUnManager
            void deActivate();

            /// Activates the RunManager
            void Activate();

            /**
             * Sets the maximum number of events. When this value is
             * reached the RunManager will stop the run if
             * CkeckEndOfRun() is not overloaded.
             */
            void set_max_events(unsigned int n)
            {
                max_events = n;
            }

            /// returns the maximum number of events permitted.
            unsigned int get_max_events()
            {
                return max_events;
            }

            /// Prepares to start the run.
            virtual void PrepareForRun()
            {
            }

            /// This is called right before the run is stopped
            virtual void EndOfRun()
            {
            }

            /** Checks the end of the run.
             * 
             * The default implementation will return when the maximum number
             * of events is reached. If the maximum number of events is set to 
             * 0, it will run endlessly.
             *  
             */
            virtual bool CheckEndOfRun();

            /// Sends the GetReady command to the Modules
            virtual void GetReady();

            /// Sends the Start command to the modules
            virtual void Start();

            /// Sends the Stop Command to the Modules
            virtual void Stop();

            /// Sends the Pause command to the Modules
            virtual void Pause();

            /// Sends the Continue command to the Modules
            virtual void Continue();

            /**
             * Sends the Trigger command to the Modules
             * This is call from the DAQ loop and can be used
             * to issue a software trigger if the function is defined
             */
            virtual void Trigger()
            {
                cmd->send_command(RunCommand::trigger);
            }

            /**
             *  Called at the end of an event in any data has been detected
             */
            virtual void EndOfEvent()
            {
            }

            /// Sends the Reset command to the Modules
            virtual void Reset();

            /// Acquire
            virtual void Acquire();

            /**
             * Writes the data into whatever storage medium. Should
             * return the number of bytes writen on success and 0 in 
             * case of failure
             */
            virtual int writeData(int size, const char *data)
            {
                return size;
            }
            ;

            /// returns the Monitor associated
            // Monitor *get_monitor() const
            // {
            //     return monitor;
            // }

            /**
             *  Associates a Monitor object to the RunManager
             */
            // void set_monitor(Monitor *m)
            // {
            //     if (monitor)
            //         delete monitor;

            //     monitor = m;
            // }

    };
}

#endif
