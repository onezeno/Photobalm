#include "editmenuhandler.h"
#include "commandclear.h"
#include <memory>

using namespace photobalm;




EditMenuHandler::EditMenuHandler(QObject *parent, CommandQueue &cmd_queue, CommandQueue &undo_queue)
  : QObject(parent)
  , cmdQueue(cmd_queue)
  , undoQueue(undo_queue)
{

}




EditMenuHandler::~EditMenuHandler()
{

}




void EditMenuHandler::clear()
{
    std::shared_ptr<Command> cmd = std::shared_ptr<Command>(new CommandClear());

    cmdQueue.push(cmd);
    undoQueue.push(cmd);

    qDebug() << "pushed CommandClear";
}

