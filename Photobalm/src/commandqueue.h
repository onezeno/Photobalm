#ifndef COMMANDQUEUE
#define COMMANDQUEUE


#include "command.h"
#include <queue>
#include <memory>


namespace photobalm {




typedef std::queue< std::shared_ptr<Command> > CommandQueue;




} // namespace photobalm


#endif // COMMANDQUEUE
