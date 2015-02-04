#include "rect2d.h"
#include "imagepoint2d.h"
#include <algorithm>
#include <stdexcept>


namespace photobalm {




Rect2d::Rect2d(const ImagePoint2d& p)
: point0(p)
, point1(p)
{

}




Rect2d::Rect2d(const ImagePoint2d& p0, const ImagePoint2d& p1)
: point0(p0)
, point1(p1)
{

}




Rect2d::~Rect2d()
{

}



Rect2d Rect2d::ToMin0Max1(const Rect2d& rect)
{
    ImagePoint2d p0( std::min(rect.point0.x, rect.point1.x)
              , std::min(rect.point0.y, rect.point1.y));

    ImagePoint2d p1( std::max(rect.point0.x, rect.point1.x)
              , std::max(rect.point0.y, rect.point1.y));


    return Rect2d(p0, p1);
}




Rect2d Rect2d::Intersect(const Rect2d& rect0, const Rect2d& rect1)
{
    Rect2d r0 = Rect2d::ToMin0Max1(rect0);
    Rect2d r1 = Rect2d::ToMin0Max1(rect1);

    // check for situation where the rectangles do not intersect
    // and throw runtime exception
    if (  (r0.point0.x > r1.point1.x)
        ||(r0.point1.x < r1.point0.x)
        ||(r0.point0.y > r1.point1.y)
        ||(r0.point1.y < r1.point0.y))
    {
        throw std::runtime_error("intersection does not exist");
    }

    ImagePoint2d p0( std::max(r0.point0.x, r1.point0.x)
              , std::max(r0.point0.y, r1.point0.y));

    ImagePoint2d p1( std::min(r0.point1.x, r1.point1.x)
              , std::min(r0.point1.y, r1.point1.y));

    return Rect2d(p0, p1);
}




Rect2d Rect2d::Envelope(const Rect2d& rect0, const Rect2d& rect1)
{
    Rect2d r0 = Rect2d::ToMin0Max1(rect0);
    Rect2d r1 = Rect2d::ToMin0Max1(rect1);

    ImagePoint2d p0( std::min(r0.point0.x, r1.point0.x)
              , std::min(r0.point0.y, r1.point0.y));

    ImagePoint2d p1( std::max(r0.point1.x, r1.point1.x)
              , std::max(r0.point1.y, r1.point1.y));

    return Rect2d(p0, p1);
}




} // namespace photobalm
