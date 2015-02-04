#ifndef COMMANDSTACK
#define COMMANDSTACK


#include "commandinterface.h"
#include <stack>
#include <memory>


namespace photobalm {




typedef std::stack< std::shared_ptr<CommandInterface> > CommandStack;




} // namespace photobalm


#endif // COMMANDSTACK

