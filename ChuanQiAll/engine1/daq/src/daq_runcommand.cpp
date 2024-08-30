#include "daq_runcommand.h"

namespace cq
{

    void RunCommand::send_command(CommandType cmd)
    {
        Arg<CommandType> arg(cmd);
        notifyObservers(&arg);
    }

} // namespace cq
