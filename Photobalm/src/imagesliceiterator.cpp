#include "imagesliceiterator.h"
#include "pbimage.h"


namespace photobalm {




ImageSliceIterator::ImageSliceIterator( PBImage* image
                                      , int at
                                      , int step
                                      , int stride
                                      , int skip)
: ImageIterator(image, at, step)
, stride(stride)
, stride_at(0)
, skip(skip)
{

}




ImageSliceIterator::~ImageSliceIterator()
{

}




ImageSliceIterator& ImageSliceIterator::operator++(void)
{
    qDebug() << "ImageSliceIterator::operator++(void) " << GetAt();

    if (stride_at < stride)
    {
        stride_at++;
        ImageIterator::operator++();
    }
    else
    {
        int at = GetAt();
        at += skip;
        SetAt(at);
        stride_at = 0;
    }

    qDebug() << "ImageSliceIterator::operator++(void) " << GetAt();

    return *this;
}




void ImageSliceIterator::SetStride(int value)
{
    stride = value;
}




bool operator==(ImageSliceIterator& lhs, ImageSliceIterator& rhs)
{
    return (lhs.GetImage() == rhs.GetImage()) && (lhs.GetAt() == rhs.GetAt());
}




} // namespace photobalm
