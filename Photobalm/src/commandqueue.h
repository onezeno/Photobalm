#ifndef COMMANDQUEUE
#define COMMANDQUEUE


#include "commandinterface.h"
#include <queue>
#include <memory>


namespace photobalm {




typedef std::queue< std::shared_ptr<CommandInterface> > CommandQueue;




} // namespace photobalm


#endif // COMMANDQUEUE
