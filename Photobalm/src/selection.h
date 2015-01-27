#ifndef SELECTION_H
#define SELECTION_H


#include <QObject>


namespace photobalm {




class Selection : public QObject
{
    Q_OBJECT
public:
    explicit Selection(QObject *parent = 0);
    ~Selection();

signals:

public slots:
};




} // namespace photobalm


#endif // SELECTION_H
