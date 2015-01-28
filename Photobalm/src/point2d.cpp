#include "point2d.h"


namespace photobalm {




Point2D::Point2D(int x, int y)
: x(x)
, y(y)
{

}

Point2D::~Point2D()
{

}



bool operator==(const Point2D& lhs, const Point2D& rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}




} // namespace photobalm
