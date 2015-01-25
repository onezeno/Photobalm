#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H


#include <QObject>


namespace photobalm {




class CommandProcessor : public QObject
{
    Q_OBJECT

public:
    explicit CommandProcessor(QObject *parent = 0);
    ~CommandProcessor();

signals:
    void process();

public slots:
};




} // namespace photobalm


#endif // COMMANDPROCESSOR_H
