#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H


#include "commandqueue.h"
#include "commandsharedptr.h"


namespace photobalm {




class CommandProcessor
{
public:
    explicit CommandProcessor(CommandQueue& cmd_queue);
    ~CommandProcessor();

    virtual void Process();
    virtual void Process(CommandSharedPtr& command);

private:
    CommandQueue& cmdQueue;
};




} // namespace photobalm


#endif // COMMANDPROCESSOR_H
