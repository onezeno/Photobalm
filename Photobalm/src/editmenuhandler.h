#ifndef EDITMENUHANDLER_H
#define EDITMENUHANDLER_H


#include <QObject>
#include <QDebug>
#include "commandqueue.h"
#include "commandstack.h"


using namespace photobalm;




class EditMenuHandler : public QObject
{
    Q_OBJECT

public:
    explicit EditMenuHandler( QObject *parent
                            , CommandQueue& cmd_queue
                            , CommandStack& undo_queue
                            , CommandQueue& redo_queue);
    ~EditMenuHandler();

    Q_INVOKABLE void undo();
    Q_INVOKABLE void redo();

    Q_INVOKABLE void clear();

signals:

public slots:

protected:
    EditMenuHandler();

private:
    CommandQueue& cmdQueue;
    CommandStack& undoStack;
    CommandQueue& redoQueue;
};




#endif // EDITMENUHANDLER_H
