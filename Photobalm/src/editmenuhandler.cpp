#include "editmenuhandler.h"
#include <memory>

using namespace photobalm;




EditMenuHandler::EditMenuHandler( QObject* parent
                                , CommandQueue& cmd_queue
                                , CommandStack& undo_stack
                                , CommandQueue& redo_queue)
  : QObject(parent)
  , cmdQueue(cmd_queue)
  , undoStack(undo_stack)
  , redoQueue(redo_queue)
{

}




EditMenuHandler::~EditMenuHandler()
{

}




void EditMenuHandler::undo()
{
    qDebug() << "EditMenuHandler::undo";

//  std::shared_ptr<Command> cmd = undoStack.top();
//  undoStack.pop();

//  redoQueue.push(cmd);
//  cmdQueue.push(cmd);
}




void EditMenuHandler::redo()
{    
    qDebug() << "EditMenuHandler::undo";

//  std::shared_ptr<Command> cmd = redoQueue.front();
//  redoQueue.pop();

//  undoStack.push(cmd);
//  cmdQueue.push(cmd);

}






