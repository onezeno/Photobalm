#ifndef COMMANDSHAREDPTR
#define COMMANDSHAREDPTR


#include "commandinterface.h"
#include <memory>


namespace photobalm {




typedef std::shared_ptr<CommandInterface> CommandSharedPtr;




} // namespace photobal


#endif // COMMANDSHAREDPTR

