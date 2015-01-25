#ifndef COMMANDCLEAR_H
#define COMMANDCLEAR_H


#include "command.h"


namespace photobalm {




class CommandClear : public Command
{
public:
    CommandClear(QObject *parent = 0);
    ~CommandClear();

    virtual void execute();
    virtual void undo();
};




} // namespace photobalm


#endif // COMMANDCLEAR_H
