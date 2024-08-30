#include "daq_manager.h"

using namespace cq;



std::allocator<char> Module::data_allocator;
std::map<void *, int> Module::allocator_map;

void Module::init()
{
    get_status().set_name( get_id() );
    DAQmanager::theDAQmanager()->addModule(this);
}

Module::Module(const DAQid &id)
        : DAQObject(id), cmd(0), local(false)
{
    init();
}

Module::~Module()
{
    UnRegisterDAQ();
    DAQmanager::theDAQmanager()->deleteModule(this);
}


void cq::Module::update(Observable *o, Argument *arg)
{
    RunState::StatusType type = RunState::NotDefined;
    Arg<RunCommand::CommandType> *cmd =
        static_cast< Arg<RunCommand::CommandType> * > (arg);
    RunCommand *rc = static_cast<RunCommand *>(o);

    // Only if the observable is a RunCommand
    if ( !rc ) return;

    switch ( *cmd )
    {
    case RunCommand::getready:
        get_status().reset();
        GetReady();
        type = RunState::Ready;
        break;
    case RunCommand::initrun:
        PrepareForRun();
        type = RunState::Starting;
        break;
    case RunCommand::run:
        get_status().start();
        get_status().reset();
        Start();
        type = RunState::Running;
        break;
    case RunCommand::stop:
        get_status().stop();
        Stop();
        type = RunState::Ready;
        break;
    case RunCommand::pauserun:
        Pause();
        type = RunState::Paused;
        break;
    case RunCommand::resume:
        Continue();
        type = RunState::Running;
        break;
    case RunCommand::trigger:
        Trigger();
        break;
    case RunCommand::send_reset:
        get_status().stop();
        get_status().reset();
        Reset();
        type = RunState::NotReady;
        break;
    case RunCommand::gettingready:
        type = RunState::GettingReady;
        break;
    }
    get_status().set_status( type );
}
