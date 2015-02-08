#include "commandprocessor.h"
#include <QDebug>


namespace photobalm {




CommandProcessor::CommandProcessor(CommandQueue& cmd_queue)
: cmdQueue(cmd_queue)
{

}




CommandProcessor::~CommandProcessor()
{

}




void CommandProcessor::Process()
{
    qDebug() << "CommandProcessor::process";

    CommandSharedPtr command_shared_ptr = cmdQueue.front();
    cmdQueue.pop();

    CommandInterface* command_ptr = command_shared_ptr.get();

    // may be a null pointer
    if (command_ptr)
    {
        (*command_ptr)();
    }
}




void CommandProcessor::Process(CommandSharedPtr& command)
{
    cmdQueue.push(command);
    Process();
}




} // namespace photobalm
