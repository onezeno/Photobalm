#ifndef POINT2D_H
#define POINT2D_H


namespace photobalm {




class Point2D
{
public:
    Point2D(int x, int y);
    virtual ~Point2D();

    int x;
    int y;

protected:
    Point2D();

};




bool operator==(const Point2D& lhs, const Point2D& rhs);




} // namespace photobalm


#endif // POINT2D_H
