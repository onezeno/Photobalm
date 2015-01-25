#include "commandclear.h"
#include <QDebug>


namespace photobalm {




CommandClear::CommandClear(QObject* parent)
  : Command(parent)
{

}

CommandClear::~CommandClear()
{

}



void CommandClear::execute()
{
    qDebug() << "excuting CommandClear";
}




void CommandClear::undo()
{
    qDebug() << "undoing CommandClear";
}




} // photobalm

