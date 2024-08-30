/* -*- mode: c++ -*- */
#ifndef __daq__module_h__
#define __daq__module_h__

#include <map>
#include "daq_object.h"
#include "daq_runcommand.h"

namespace cq
{
    /**
     *   \brief class Module.
     *   \ingroup DAQ
     *   This class represents a module.
     *
     *   It is an abstract class that provides the basic DAQ commands:
     *      - PrepareForRun(),
     *      - Start(),
     *      - Stop(),
     *      - Pause(),
     *      - Continue(),
     *      - Reset(),
     *      - GetReady(),
     *      - hasData(),
     *      - getData(),
     *      - Trigger(),
     *      - flush()
     *
     *   All those operations are pure virtual methods on Module. That means
     *   the user must derive a class from Module and implement those
     *   methods.
     *
     *   It is an Observer of RunCommand. To react to DAQ commands
     *   one needs to register the Module to a RunCommand. It can also handle a
     *   RunState that will display any change in the running conditions.
     *   The RunState is set at construction. If none is give it will
     *   build a generic one.
     *
     *   It will destroy the RunState, but it wont't do anything to
     *   the RunCommand pointer.
     *
     *   A Module derives from ParameterHolder and, therefore, can mantain a
     *   list of named Parameters. The use of named parameters assumes the
     *   knowledge of the Parameter type.
     *
     *
     */
    class Module : public DAQObject, public Observer
    {
        private:
            /**
             * Pointer to RunCommand.
             * It will store the pointer until it is changed with RegisterDAQ.
             * This should allow to set in local and global on the same
             * RunManager.
             */
            RunCommand *cmd;
            /**
             *  true if module in local or standalone DAQ mode, false otherwise
             */
            bool local;

            /**
             * Module initialization.
             * If the RunState pointer in the constructor is NULL it will
             * create a new one. It will also add the module to the list of the
             * DAQmanager.
             */
            void init();
            /**
             *  Receives DAQ commands.
             *  For modules, we do not want it to be public.
             *  This will call the corresponding virtual functions
             *  for each command.
             */
            void update(Observable *o, Argument *arg);

            /** \brief The module memory allocator.
             *  In DAQ++, the module is reponsible to allocate memory for
             *  the data that it will pass to the RunManager. In order to
             *  avoid leaks, DAQ++ is designed so that memory allocation
             *  in the module is done through the methods allocate and
             *  deallocate. When the RunManager \em writes the data sent
             *  by the Module, it will deallocate the memory.
             *
             *  It may be of interest for some applications to extend the
             *  lifetime of the Module data. In that case, the Module
             *  instance can overload deallocate so that the RunManager
             *  action takes no effect and deallocate the data afterwards
             *  with deallocate_real, which is defiend to be static.
             */
            static std::allocator<char> data_allocator;

            /** \brief The allocator map.
             *  Module mantains a map in which the addresses and sizes of
             *  the memory chuncks allocated are stored. That avoids
             *  having to remember outside Module the size of the memory
             *  chuncks allocated.
             */
            static std::map<void *, int> allocator_map;
        public:
            /**
             *  Constructor.
             */
            Module(const DAQid &id);

            /// Destructor
            virtual ~Module();

            // operations
            ///
            virtual int  LoadConfiguration() = 0;
            virtual int  UpdateConfiguration() = 0;

            /// Prepares for a new run
            virtual int PrepareForRun() = 0;
            /// Start the run
            virtual int Start(int mode = 0) = 0;
            /// Stop the run
            virtual int Stop(int mode = 0) = 0;
            /// Pause the run
            virtual int Pause() = 0;
            /// Resume the run after pause
            virtual int Continue() = 0;
            /// Send a reset to the module
            virtual int Reset() = 0;
            /// Initialize the Module
            virtual int GetReady() = 0;
            /// Issues a trigger
            virtual int Trigger() = 0;
            /// Flush any remaining data on the Module
            virtual void flush() = 0;
            /// Returns true if the Module has data available
            virtual bool hasData() = 0;
            /// Retrieves the Module's data
            /**
             * This method is used by the RunManager controling this module
             * to retrieve the data.
             *
             * \warning {The memory needed to store the event
             * data should be obtained with allocate().}
             *
             * \param size returns the size of the data block
             * \return pointer to the data block.
             */
            virtual char *getData(int &size) = 0;

            /** \brief Real Data allocator.
             *  This is a static method to allocate memory for the
             *  module.
             *
             *  \param size The size in \em chars of the memory needed.
             */
            static char *allocate_real(int size)
            {
                char *ptr = data_allocator.allocate(size);
                allocator_map[(void *)ptr] = size;
                return ptr;
            }

            /** Real data deallocator.
             *  \param ptr The memory pointer. The size is obtained from
             *             datallocator_map
             */
            static void deallocate_real(char *ptr)
            {
                std::map<void *, int>::iterator ip;
                ip = allocator_map.find( (void *)ptr);
                if (ip != allocator_map.end())
                    data_allocator.deallocate((char *)ip->first, ip->second);
            }

            /** \brief Data allocator.
             *  Allocates the memory needed to store the data of a given
             *  event. This function can be overloaded in order to change
             *  the memory management inside the module. In that case one
             *  may also need to overload deallocate correspondingly.
             *
             *  \param size The size in \em chars of the memory needed.
             */
            virtual char *allocate(int size)
            {
                return allocate_real(size);
            }

            /** \brief Data deallocator
             *  Deallocates the memory holding the data of a given
             *  event.
             *  \param ptr  the pointer to the memory chunck
             *
             *  Both parameters are the same as the values given by
             *  Module::getData.
             */
            virtual void deallocate(char *ptr)
            {
                deallocate_real(ptr);
            }

            /// true if the module is in global mode
            bool is_global()
            {
                return !local;
            }

            /**
             *   Set the Module in global mode.
             */
            void in_global(RunCommand *rc = 0)
            {
                if (rc)
                    RegisterDAQ(rc);
                else
                {
                    if (cmd)
                        RegisterDAQ(cmd);
                }
                local = false;
            }

            /// true if the module is in local mode
            bool is_local()
            {
                return local;
            }
            /**
             * Sets the Module in local or standalone mode.
             * It will run with a new RunManager that will only
             * handle this Module.
             */
            void in_local()
            {
                if (cmd)
                    UnRegisterDAQ();
                local = true;
            }

            /**
             * Registers to a RunCommand. This is usually a
             * RunManager that will displach all the commands.
             */
            void RegisterDAQ(RunCommand *rc)
            {
                if (rc)
                {
                    cmd = rc;
                    rc->addObserver(*this);
                }
            }
            /**
             * Unregister from the RunCommand that controls this
             * Module.
             */
            void UnRegisterDAQ(bool reset = false)
            {
                if (cmd)
                {
                    cmd->deleteObserver(*this);
                    if (reset)
                        cmd = 0;
                }
            }
    };
}

#endif

