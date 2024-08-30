/* -*- mode: c++ -*- */
#ifndef __daq_manager_h__
#define __daq_manager_h__

#include <map>
#include "daq_runmanager.h"
#include "daq_module.h"
#include "daq_observer_model.h"
#include "daq_thread.h"

namespace cq
{
    /// Type for the list of RunManager mantained by this class
    typedef std::map<std::string, RunManager *> RunManagerMap;
    /// Type for the list of Module Mantained by this class
    typedef std::map<std::string, Module *> ModulesMap;

    class Semaphore;

    /**
     *  \ingroup DAQ
     *  \brief class DAQTrigger.
     *
     *  This class defines the interface for a Trigger. For each event,
     *  DAQmanager will loop on the active RunManagers, but on each
     *  iteration it will wait for DAQTrigger to return true through its
     *  operator().
     *
     *  One can use that function to wait for interrupts, presence
     *  of data on a file or device, etc. and acquire only when the
     *  data is ready.
     *
     */
    class DAQTrigger
    {
        public:
            /// Constructor
            DAQTrigger()
            {}

            /// Destructor
            virtual ~DAQTrigger()
            {}

            /** Should return true to allow DAQmanager looping on all the
             * active RunManager objects
             */
            virtual bool operator()()
            {
                return true;
            }
    };

    /**
     *  \ingroup DAQ
     *  \brief class DAQmanager.
     *
     *  Controls the whole acquisition.
     *
     *  This object is a singleton that controls the whole acquisition. To
     *  get the pointer of its only instance one uses theDAQmanager(). It
     *  provides the \em standard operations for a DAQ controler.
     *
     *  - StartRun()
     *  - StopRun()
     *  - WaitForEndOfRun()
     *  - Acquire()
     *  - start_loop()
     *
     *  It acquires by looping on the RunManagers which are \em activated and
     *  those, in turn, delegate the acquisition commands on their Modules.
     *
     *  There are 2 ways of running the acquisition. In the first mode, one
     *  has to create first the RunManager objects and then the Module
     *  objects. Module objects are then associated to the different
     *  RunManager. Once this is done, one needs to activate the
     *  RunManager's that should take data, and the run is started with
     *  DAQmanager::StartRun(int flag). The flags determine how the
     *  acquisition will proceed (see DAQstate).
     *
     *  If 0 is given as argument, the process blocks until all the active
     *  RunManagers finish the run. If DAQmanager::Threaded is given, it
     *  runs in a different thread. One can always block the main process
     *  with DAQmanager::WaitForEndOfRun() until there is no RunManager
     *  running (or active)
     *
     *  An example of this configuration could be
     *  \code
     *  // Create the RunManager
     *  Rmanager *run_manager = new Rmanager;
     *
     *  // The run will stop after 50000 events
     *  run_manager->set_max_events(50000);
     *
     *  // Create the Modules and add them to the RunManager
     *  run_manager->addModule( (m1=new MyModule("module1)) );
     *  run_manager->addModule( (m2=new MyModule("module2)) );
     *
     *  // Activate the RunManager
     *  run_manager->Activate();
     *
     *  // Run the DAQ in another thread
     *  DAQmanager::theDAQmanager()->StartRun(DAQmanager::Threaded);
     *
     *  // Wait for end of run
     *  DAQmanager::theDAQmanager()->WaitForEndOfRun();
     *
     *
     *  \endcode
     *
     *  Another example of the previous DAQ mode could be
     *
     *  \code
     *
     *  ...
     *  Create RunManager and Modules like above
     *  ...
     *
     *  run_manager->Activate();     // activate RunManager
     *  run_manager->set_max_events(0); // Run endlessly
     *
     *  DAQmanager::theDAQmanager()->StartRun(DAQmanager::Threaded);
     *
     *  // Run only during 1 second
     *  timer.start();
     *  while ( timer()<1.);
     *
     *  // Stop the run
     *  DAQmanager::theDAQmanager()->StopRun();
     *
     *  \endcode
     *
     *
     *  In some situations one may not know a priory how many RunManager's
     *  or Module's will be active, but still wants to start the DAQ. This
     *  may be the case of a GUI controling the acquisition that will allow
     *  to create RunManager's and Modules dynamically. For these
     *  situations DAQmanager implements a DAQ loop that will only be
     *  quited if DAQmanager::StopRun() is called.
     *
     *  \code
     *  //
     *  // start the DAQ loop
     *  DAQpp::DAQmanager::StartRun(DAQmanager::Loop);
     *  \endcode
     *
     *  In this case, the acquisition will always run in a different
     *  thread.
     *
     *  In any of of the cases, the DAQmanager will loop over all the
     *  active RunManager objects provided that trigger() returns true. The
     *  function can be changed with DAQmanager::set_trigger(). This
     *  mechanism provides a way of controling the acquisition with
     *  interrupts. Imagine that you have a function that is able to detect
     *  the presence of an interrupt (a signal, a VME interrupt, etc.) and
     *  that returns true if that is the case. Only when the interrupt is
     *  detected will DAQmanager loop over the RunManager objects and,
     *  hence, readout the modules.
     *
     *  Once a run is started, the sequence of the acquisition is:
     *
     *    -# call startRunManager for all the active RunManager
     *        -# RunManager::PrepareForRun
     *    -# RunManager::GetReady
     *       - Module::GetReady for all the modules
     *    -# RunManager::Start
     *       - The RunManager sends the commands
     *          - RunCommand::initrun
     *          - RunCommand::run
     *     -# At this stage the acquisition is running. We then make the
     *        active RunMangers send a trigger command.
     *     -# We call the current DAQtrigger and wait for a real
     *        trigger. Then, for each trigger we do:
     *       - RunManager::Acquire.
     *          - RunManager::Trigger. This will send the command
     *            RunCommand::trigger to each Module  
     *          - The RunManager will loop on all the modules and for
     *                each: 
     *               -# Module::hasData
     *           -# If there is data available:
     *              - Module::getData. The module returns its
     *                data. Memory allocation should be done here
     *                with Module::allocate
     *              - If there is data:
     *                  - If the RunManger has a Monitor, send the
     *                data there
     *              - RunManager::writeData
     *              - Module::deallocate. The RunManager takes
     *                care of deallocating the data from
     *                Module::getData
     *       - RunManager::EndOfEvent
     *       - RunManager::CheckEndOfRun
     *     -# When the run is over, DAQmanager calls stopRunManager:
     *        -# RunManager::Stop
     *    -# RunManager::EndOfRun
     *    -# RunManager::deactivate
     *
     *  This is sketched in the figure below
     *  <img src="DAQLoop.png" width="450"/>
     *  Click <a href="DAQLoop.pdf">here</a> for a better view.
     *
     *  DAQmanager derives from Observable and it will notify when a new
     *  Module or RunManager is added or removed.  The argument of the
     *  notification message is
     *
     *  \code
     *  typedef pair<DAQmanager::msg, char *> newObjArg;
     *  \endcode
     *
     *  \c DAQmanager::msg is the list operation and the char pointer is a pointer
     *  to the object being inserted or erased from the list.
     *
     *  An example of an Observer \em update method would be
     *  \code
     *  void MyClass::update(Observable *o, Argument *arg) {
     *     Arg< DAQpp::DAQmanager::newObjArg> &msg =
     *        *static_cast< Arg< DAQpp::DAQmanager::newObjArg> *>(arg);
     *     DAQpp::Module *module;
     *     DAQpp::RunManager *run_manager;
     *  
     *     switch (msg().first) {
     *     case DAQpp::DAQmanager::nwModule:
     *        module = reinterpret_cast<DAQpp::Module *>(msg().second);
     *    break;
     *     case DAQpp::DAQmanager::rmModule:
     *        module = reinterpret_cast<DAQpp::Module *>(msg().second);
     *    break;
     *     case DAQpp::DAQmanager::nwRunManager:
     *        run_manager = reinterpret_cast<DAQpp::RunManager *>(msg().second);
     *    break;
     *     case DAQpp::DAQmanager::rmRunManager:
     *        run_manager = reinterpret_cast<DAQpp::RunManager *>(msg().second);
     *    break;
     *     }
     *  }
     *
     *  \endcode
     *
     *  DAQmanager mantains 3 lists of objects:
     *  - list of Module objects,
     *  - list of RunManager objects
     *  - list of active RunManager
     *
     *  The third one is somewhat internal, but the first two can be used
     *  to find existing object by name. Operations on the lists will
     *  trigger a notification to the Observers registered
     *
     */
    ///class DAQmanager
    class DAQmanager : public Observable
    {
        public:
            /** \brief Acquisition flags
             *   Set of flags that determine the status and the behaviour
             *  of the acquisition.
             */
            enum DAQstatus {
                Running  = 1,  /*!< if set the DAQ is running */
                Threaded = 2,  /*!< if set the acquisition loop wil be run in a
                             different thread */
                Loop     = 4,  /*!< if set the acquisition will loop event
                             if there are no RanManager active */
                Public   = 6   /*!< mask of public bits, ie, Loop and
                             Threaded */
            };

        private:
            /** \brief class DAQinternal.

             *
             *   This class is an abstract class from which internal
             *   classes should derive.
             */
            class DAQinternal
            {
                protected:
                    /// pointer to the DAQmanager
                    DAQmanager *mngr;
                public:
                    /// Constructor
                    DAQinternal() : mngr( DAQmanager::theDAQmanager() )
                    {}
            };
            friend class DAQinternal; // DAQinternal is declared a friend.

            /// Unique instance
            static DAQmanager theManager;

            /// List of existing RunManager
            RunManagerMap runm;

            /** \brief class RunManagerSet.
             *  This is a set where all the active RunManager are
             *  stored. It derives from DAQpp::Condition and DAQinternal.
             */
            class RunManagerSet : public std::set<RunManager *>, public Condition, public DAQinternal
            {
                public:
                    /// Constructor
                    RunManagerSet() {}
                    /// The mutex
                    boost::mutex mtx;
                    /// insert a value
                    std::pair<iterator, bool> insert(const value_type &x);
                    /// insert value at a given position
                    iterator insert(iterator pos, const value_type &x);
                    /// erase value at position
                    void erase(iterator pos);
                    /// erase value
                    size_type erase(const key_type &k);
                    /// erase from gven first to last
                    void erase(iterator first, iterator last);
                    /// clear the set
                    void clear();
                    /// The condition to check
                    bool condition();
            };
            /// \brief List of active RunManager.
            RunManagerSet active;

            /// List of existing Module
            ModulesMap mmap;

            /// Current acquisition status
            boost::atomics::atomic_int state;


            /// internal condition
            class RunCondition : public DAQinternal, public Condition
            {
                public:
                    RunCondition()
                    {}
                    bool condition();
            };
            /** This is a Condition that will wait for the RunManager
             * list to be empty. It is used by WaitForEndOfRun
             */
            RunCondition daq_cond;

            /// stores the thread id
            class DAQthread : public DAQinternal, public Thread
            {
                public:
                    /// Constructor
                    DAQthread()
                    {}

                    /// Runs the thread
                    void run();
            };
            /// This is the thread used by DAQmanager when running in Thread mode.
            DAQthread thread;


            /**
             * Data will be read out only when this function returns
             * true. The function can be changed with set_trigger()
             */
            DAQTrigger *trigger;
        protected:
            /// Hide the constructors
            DAQmanager();

            /// Copy constructor. Also hidden
            DAQmanager(const DAQmanager &);

            /// Assignment operator (hidden)
            DAQmanager &operator=(const DAQmanager &) { return *this; }

        public:
            /**
             * Destructor.
             * It will delete all the Modules and RunManagers.
             */
            ~DAQmanager();

            /// Returns a pointer to the manager
            static DAQmanager *theDAQmanager()
            {
                return &theManager;
            }

            //---------------------------------------------------------------------
            // Mantaining the list
            //---------------------------------------------------------------------
            /// Type of signals
            enum msg
            {
                startDAQ,     /*!< a new DAQ cycle is started */
                stopDAQ,      /*!< the DAQ cycle has finished */
                nwModule,     /*!< a new modules is created */
                nwRunManager, /*!< a new RunManager is created */
                rmModule,     /*!< a Module has been deleted */
                rmRunManager, /*!< a RunManager has been destroyed */
                acRunManager, /*!< a RunManager has been activated */
                dcRunManager  /*!< a RunManager has been deactivated */
            };

            /// Base for signal arguments
            typedef std::pair<msg, char *> newObjArg;

            /// adds a new Module in the list.
            void addModule(Module *m)
            {
                mmap[m->get_id()] = m;
                new_obj(nwModule, (char *)m);
            }

            /// deletes a Module from the list.
            Module * deleteModule(Module *m)
            {
                mmap.erase(m->get_id());
                new_obj(rmModule, (char *)m);
                return m;
            }

            /// Finds a Module with a given id.
            Module *find_module(const DAQid &id)
            {
                ModulesMap::iterator it = mmap.find(id);

                if ( it == mmap.end() )
                    return 0;
                else
                    return (*it).second;
            }

            /// List of existing Module objects
            const ModulesMap & ModuleMap()
            {
                return mmap;
            }

            /// Returns the number of Module objects
            int countModules()
            {
                return static_cast<int>(mmap.size());
            }

            /// Adds a RunManager in the list
            void addRunManager(RunManager *m)
            {
                runm[m->get_id()] = m;
                new_obj(nwRunManager, (char *)m);
            }

            /// Removes a RunManager from the list
            RunManager *deleteRunManager(RunManager *m)
            {
                if ( m->isActive() )
                    m->deActivate();
                runm.erase(m->get_id());
                new_obj(rmRunManager, (char *)m);
                return m;
            }

            /// Returns the number of RunManager objects
            int countRunManager()
            {
                return static_cast<int>(runm.size());
            }

            /// Finds a RunManager with a given id.
            RunManager *find_runmanager(const DAQid &id)
            {
                RunManagerMap::iterator it = runm.find(id);

                if ( it == runm.end() )
                    return 0;
                else
                    return (*it).second;
            }

            /// List of existing DAQpp::RunManager
            const RunManagerMap & RunMmap()
            {
                return runm;
            }

            /// Adds an active RunManager
            void addActiveRunManager(RunManager *rm);

            /// Removes an active RunManager
            void removeActiveRunManager(RunManager *rm);

            /// Returns the number of active RunManager objects
            int countActiveRunManager()
            {
                return static_cast<int>(active.size());
            }
            //---------------------------------------------------------------------
            // Acquisition
            //---------------------------------------------------------------------

            /** \brief Starts a run.
             * \callgraph
             *
             * This method starts a new run. It will set the running
             * flag, update the list of active RunManager, reset their
             * RunState, and call PrepareForRun for all of them. Once
             * this is done, it will call Acquire for each of the active
             * RunManager. Depending on the flags provided it can be
             * executed in a new thread and/or run endlessly, regardless
             * of the number of active RunManager, until the runnig flag
             * is erased.
             *
             * \param  flags  A bitwise-or'd word that determines how
             *                the acquisition will proceed. The
             *                different bytes can be any of the
             *                DAQstatus values.
             */
            void StartRun(int flags);
            
            /** Stops a run.
             * 
             * In the case of stopping and restarting a run, 
             * one should call this method before StartRun is 
             * called again.
             *  
             */
            void StopRun();

            /** Waits for run completion.
             * 
             * Wait completion means, in this case, that there are no
             * active RunManager left. It is not equivalent to StopRun.
             * WaitForEndOfRun may return while the run remains active.
             * This is particularly true when StartRun is called in threaded 
             * mode.
             * 
             *  \param tmout time out in microseconds
             */
            void WaitForEndOfRun(int tmout = -1);

            /** \brief Start a RunManager
             *  \callgraph
             */
            void startRunManager(RunManager *);

            /** \brief Stop a RunManager.
             *  \callgraph
             */
            void stopRunManager(RunManager *);

            /// Checks if the DAQ is still running.
            bool isRunning() const;

            /// Checks if the DAQ is looping
            bool isLooping() const;

            ///  Checks if the DAQ is threaded
            bool isThreaded() const;

            //---------------------------------------------------------------------
            // The trigger
            //---------------------------------------------------------------------
            /**
             * Changes the trigger function. If zero is given, the default
             * will be set.
             */
            void set_trigger( DAQTrigger *func );

        private:
            /** \brief Starts the acquisition.
             *  \callgraph
             */
            void Acquire();

            /** \brief process one event.
             *  \callgraph
             */
            void processTheEvent();

            /// Notifies a change in any of the lists
            void new_obj(msg tp, char *ptr)
            {
                Arg< newObjArg > arg( newObjArg(tp, ptr) );
                notifyObservers(&arg);
            }

    };


}
#endif
