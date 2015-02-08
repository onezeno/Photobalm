#include "filemenuhandler.h"
#include "pbimage.h"
#include <QDebug>




FileMenuHandler::FileMenuHandler(QObject *parent, photobalm::ImageProvider& image_provider)
: QObject(parent)
, imageProvider(image_provider)
{

}




FileMenuHandler::~FileMenuHandler()
{

}




void FileMenuHandler::load(QString str)
{
    qDebug() << "FileMenuHandler::load " << str;

    PBImage* image = imageProvider.GetImage();

    if (image)
    {
        qDebug() << "FileMenuHandler::load setting image";

        image->setImage(str);

        qDebug() << "FileMenuHandler::load updating image";

        image->update();
    }
    else
    {
        qDebug() << "FileMenuHandler::load image is null";
    }
}

