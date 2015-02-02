#include "rect2diterator.h"


namespace photobalm {




Rect2dIterator::Rect2dIterator(PBImage* image, const Rect2d& rect)
: ImageSliceIterator( image
                    , 0
                    , 1
                    , 1
                    , 0)
, rect(Rect2d::ToMin0Max1(rect))
{
    qDebug() << "Rect2dIterator::Rect2dIterator " << rect.point0.x << ", " << rect.point0.y << " | " << rect.point1.x << ", " << rect.point1.y;

    if (!image)
    {
        qDebug() << "Rect2dIterator::GoToBegin no image";
        return;
    }

    int at = this->rect.point0.y * image->GetWidth() + this->rect.point0.x;
    int stride = this->rect.point1.x - this->rect.point0.x;

    SetAt(at);
    SetStride(stride);
    this->skip = image->GetWidth() - this->stride;
}




Rect2dIterator::~Rect2dIterator()
{
    qDebug() << "Rect2dIterator::~Rect2dIterator";
}




void Rect2dIterator::GoToEnd()
{
    qDebug() << "Rect2dIterator::GoToEnd";

    PBImage* image = this->GetImage();

    if (!image)
    {
        SetAt(0);
    }
    else
    {
        int at = GetAt() + this->stride + (this->rect.point1.y - this->rect.point0.y) * image->GetWidth() + this->skip;
        SetAt(at);
    }
}




bool operator==(Rect2dIterator& lhs, Rect2dIterator& rhs)
{
    qDebug() << "operator==(Rect2dIterator& lhs, Rect2dIterator& rhs) " << lhs.GetAt() << " " << rhs.GetAt();
    return lhs.GetAt() == rhs.GetAt();
}



bool operator!=(Rect2dIterator& lhs, Rect2dIterator& rhs)
{
    qDebug() << "operator!=(Rect2dIterator& lhs, Rect2dIterator& rhs) " << lhs.GetAt() << " " << rhs.GetAt();
    return lhs.GetAt() != rhs.GetAt();
}




}  // namespace photobalm
