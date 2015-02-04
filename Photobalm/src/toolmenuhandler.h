#ifndef TOOLMENUHANDLER_H
#define TOOLMENUHANDLER_H

#include <QObject>

class ToolMenuHandler : public QObject
{
    Q_OBJECT
public:
    explicit ToolMenuHandler(QObject *parent = 0);
    ~ToolMenuHandler();

    Q_INVOKABLE void fill();

signals:

public slots:
};

#endif // TOOLMENUHANDLER_H
