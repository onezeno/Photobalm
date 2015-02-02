#include "imageiterator.h"
#include <cstdlib>
#include <QDebug>


namespace photobalm {




ImageIterator::ImageIterator(PBImage* image)
: image(image)
, at(0)
, step(1)
{
    qDebug() << "ImageIterator::ImageIterator(PBImage* image)";
}




ImageIterator::ImageIterator(PBImage* image , int at, int step)
: image(image)
, at(at)
, step(step)
{
    qDebug() << "ImageIterator::ImageIterator(PBImage*, int at, int stop, int step)";
}




ImageIterator::~ImageIterator()
{
    qDebug() << "ImageIterator::~ImageIterator";
}




ImageIterator& ImageIterator::operator++(void)
{
  qDebug() << "ImageIterator::operator++ " << at;

  at += step;

  qDebug() << "ImageIterator::operator++ " << at;

  return *this;
}




int& ImageIterator::operator*()
{
    return at;
}




int* ImageIterator::operator->()
{
    return &at;
}




ImagePoint2d ImageIterator::IndexToImagePoint2d(const PBImage& image, const int index)
{
    std::div_t d = std::div(index, image.GetWidth());

    return ImagePoint2d(d.rem, d.quot);
}




ImagePoint2d ImageIterator::AtImagePoint2d()
{
    PBImage* image = GetImage();

    if (!image)
    {
        throw std::runtime_error("no image to iterate");
    }

    return IndexToImagePoint2d(*image, at);
}




PBImage* ImageIterator::GetImage()
{
    return image;
}




int ImageIterator::GetAt() const
{
    return at;
}




void ImageIterator::SetAt(int value)
{
    at = value;
}




int ImageIterator::GetStep() const
{
    return step;
}




void ImageIterator::SetStep(int value)
{
    step = value;
}




void ImageIterator::GoToEnd()
{
    qDebug() << "ImageIterator::GoToEnd " << at;

    if (!image)
    {
        at = 0;
    }
    else
    {
        int end = image->GetWidth() * image->GetHeight() + 1;

        at = end + (end % step);
    }

    qDebug() << "ImageIterator::GoToEnd " << at;
}




//bool operator==(const ImageIterator& lhs, const ImageIterator& rhs)
//{
//    return (lhs.image == rhs.image) && (lhs.point == rhs.point);
//}




//bool operator!=(const ImageIterator& lhs, const ImageIterator& rhs)
//{
//    qDebug() << "comparing ImageIterators";
//    bool result = !(lhs == rhs);

//    if (result)
//    {
//        qDebug() << "compared ImageIterators not equal";
//    }
//    else
//    {
//        qDebug() << "compared ImageIterators are equal";
//    }

//    return result;
//}




} // namespace photobalm
