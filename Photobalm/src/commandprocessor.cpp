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

    CommandSharedPtr command_ptr = cmdQueue.front();
    cmdQueue.pop();

    command_ptr->execute();
}




void CommandProcessor::Process(CommandSharedPtr& command)
{
    cmdQueue.push(command);
    Process();
}




} // namespace photobalm
