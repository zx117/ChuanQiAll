/* -*- mode: c++ -*- */
#ifndef __daq_object_h__
#define __daq_object_h__

#include "daq_id.h"
#include "daq_runstate.h"
#include "daq_parameter.h"

namespace cq
{
    /**
     *  \brief class DAQObject.
     *
     *  \ingroup DAQ
     *
     *  This is a DAQObject. It provides the minimum interface for a
     *  DAQ++ object. That is:
     *     - It is a named object (through a DAQid object)
     *     - Can mantain a collection of Parameter objects (derives
     *       from ParameterHolder
     *     - Stores some information about its current state in a
     *       RunState object
     *     - Can be monitored
     *
     *  Other DAQ++ objects (RunManager and Module) will derive from it.
     */
    class DAQObject : public ParameterHolder
    {
        private:
            /// DAQObject identifier.
            DAQid _id;
            /// RunState associated with the RunManager
            RunState status;

        public:
            // Default Constructor
            DAQObject() : _id("<unnamed>")
            {}

            /**\brief Constructor.
             * Makes an instance of a DAQobject with a given id.
             */
            DAQObject(const DAQid &id) : _id(id), status(id)
            {}

            /// Returns the id.
            DAQid const & get_id() const
            {
                return _id;
            }


            /// Returns the RunState associated.
            const RunState GetStatus() const
            {
                return status;
            }

            /// Returns the RunState for modification
            RunState &get_status() { return status; }

            /** \brief Adds a parameter.
             *  This method overrides the ParamHolder::add_par method. It
             *  just gives the name of the DAQObject to the parameter
             */
            void add_par(const char *pnam, Parameter *par, const DAQid *id = 0)
            {
                ParameterHolder::add_par(pnam, par, &_id);
            }

            /// Gets data for monitoring
            /**
             *  It can be used to retrieve any kind of data needed to monitor
             *  the acquisition.
             *  \param size returns the size of the data block
             *  \param data a pointer to a char pointer to the data. The memory should be
             *         allocated with the new operator so that the end user deallocates
             *         calling the delete [] operator.
             *  \return true is data is available, false otherwise
             */
            virtual bool get_monitor_data(int &size, char **data)
            {
                size = 0;
                *data = 0;
                return false;
            }
            /// Resets monitoring data
            virtual void reset_monitor_data()
            {}
    };
}

#endif
