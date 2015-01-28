#include "imageiterator.h"
#include <QDebug>


namespace photobalm {


ImageIterator::ImageIterator(PBImage* image)
: image(image)
, point(0, 0)
{
    qDebug() << "ImageIterator::ImageIterator";
}


ImageIterator::ImageIterator(PBImage*, const Point2D& p)
: image(image)
, point(p)
{
    qDebug() << "ImageIterator::ImageIterator";
}




ImageIterator::~ImageIterator()
{
    qDebug() << "ImageIterator::~ImageIterator";
}




void ImageIterator::end()
{
    image = 0;
    point = Point2D(0, 0);
}



ImageIterator& ImageIterator::operator++(void)
{
  qDebug() << "ImageIterator::operator++ ending iteration";
  end();
  return *this;
}



bool operator==(const ImageIterator& lhs, const ImageIterator& rhs)
{
    return (lhs.image == rhs.image) && (lhs.point == rhs.point);
}


bool operator!=(const ImageIterator& lhs, const ImageIterator& rhs)
{
    qDebug() << "comparing ImageIterators";
    bool result = !(lhs == rhs);

    if (result)
    {
        qDebug() << "compared ImageIterators not equal";
    }
    else
    {
        qDebug() << "compared ImageIterators are equal";
    }

    return result;
}




} // namespace photobalm
