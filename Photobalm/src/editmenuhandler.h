#ifndef EDITMENUHANDLER_H
#define EDITMENUHANDLER_H


#include <QObject>
#include <QDebug>
#include "commandqueue.h"


using namespace photobalm;




class EditMenuHandler : public QObject
{
    Q_OBJECT

public:
    explicit EditMenuHandler( QObject *parent
                            , CommandQueue& cmd_queue
                            , CommandQueue& undo_queue);
    ~EditMenuHandler();

    Q_INVOKABLE void clear();

signals:

public slots:

protected:
    EditMenuHandler();

private:
    CommandQueue& cmdQueue;
    CommandQueue& undoQueue;
};




#endif // EDITMENUHANDLER_H
