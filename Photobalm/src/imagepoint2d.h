#ifndef IMAGEPOINT2D_H
#define IMAGEPOINT2D_H


namespace photobalm {




class ImagePoint2d
{
public:
    ImagePoint2d(int x, int y);
    virtual ~ImagePoint2d();

    int x;
    int y;

protected:
    ImagePoint2d();

};




bool operator==(const ImagePoint2d& lhs, const ImagePoint2d& rhs);

ImagePoint2d operator+(const ImagePoint2d&, const ImagePoint2d&);




} // namespace photobalm


#endif // IMAGEPOINT2D_H
