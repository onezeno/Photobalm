#ifndef COMMANDSTACK
#define COMMANDSTACK


#include "command.h"
#include <stack>
#include <memory>


namespace photobalm {




typedef std::stack< std::shared_ptr<Command> > CommandStack;




} // namespace photobalm


#endif // COMMANDSTACK

