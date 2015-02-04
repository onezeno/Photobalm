#ifndef FILEMENUHANDLER_H
#define FILEMENUHANDLER_H


#include "imageprovider.h"
#include <QObject>




class FileMenuHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileMenuHandler(QObject *parent, photobalm::ImageProvider&);
    ~FileMenuHandler();

    Q_INVOKABLE void load(QString);

signals:

public slots:


private:
    photobalm::ImageProvider& imageProvider;
};




#endif // FILEMENUHANDLER_H
