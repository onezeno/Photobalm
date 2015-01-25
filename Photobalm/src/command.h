#ifndef COMMAND_H
#define COMMAND_H


#include <QObject>


namespace photobalm {




class Command : public QObject
{
    Q_OBJECT

public:
    explicit Command(QObject *parent = 0);
    ~Command();

    virtual void execute() = 0;
    virtual void undo() = 0;

signals:

public slots:
};




} // namespace photobalm


#endif // COMMAND_H
