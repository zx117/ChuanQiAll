/* -*- mode: c++ -*- */
#ifndef __daq_runcommand_h__
#define __daq_runcommand_h__

#include "daq_observer_model.h"
#include "daq_exception.h"

namespace cq
{
/**
     *  \brief class RunCommand.   
     *  \ingroup DAQ
     *  
     *  This class distributes the commands among the modules in a RunManager
     *
     *
*/
class RunCommand : public Observable
{
public:
    /// Constructor
    RunCommand()
    {}
    /// Destructor
    virtual ~RunCommand()
    {}
    /// Possible commands
    enum CommandType {
        getready,
        initrun,
        run,
        stop,
        pauserun,
        resume,
        trigger,
        send_reset,
        gettingready
    };

    /// commands
            void send_command(CommandType cmd);
};
}
#endif
