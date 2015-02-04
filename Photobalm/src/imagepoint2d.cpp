#include "imagepoint2d.h"


namespace photobalm {




ImagePoint2d::ImagePoint2d(int x, int y)
: x(x)
, y(y)
{

}




ImagePoint2d::~ImagePoint2d()
{

}




bool operator==(const ImagePoint2d& lhs, const ImagePoint2d& rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}




ImagePoint2d operator+(const ImagePoint2d& p0, const ImagePoint2d& p1)
{
    return ImagePoint2d(p0.x + p1.x, p0.y + p1.y);
}




} // namespace photobalm
