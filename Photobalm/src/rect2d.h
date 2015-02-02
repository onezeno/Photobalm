#ifndef RECT2D_H
#define RECT2D_H


#include "Imagepoint2d.h"




namespace photobalm {




class Rect2d
{
public:
    Rect2d(const ImagePoint2d& p);
    Rect2d(const ImagePoint2d& p0, const ImagePoint2d& p1);
    virtual ~Rect2d();

    ImagePoint2d point0;
    ImagePoint2d point1;


    /// Return a Rect2d where point0 has the minimum x and y values,
    /// and point1 has the maximum x and y values.
    static Rect2d ToMin0Max1(const Rect2d&);

    /// Return the intersection of two Rect2d.
    static Rect2d Intersect(const Rect2d&, const Rect2d&);

    /// Return a Rect2d that contains both of the Rect2d.
    static Rect2d Envelope(const Rect2d&, const Rect2d&);

protected:
    Rect2d();
};









} // namespace photobalm


#endif // RECT2D_H
