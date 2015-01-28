#ifndef IMAGEITERATOR_H
#define IMAGEITERATOR_H


#include "pbimage.h"
#include "point2d.h"


namespace photobalm {



class ImageIterator
{
    friend bool operator==(const ImageIterator& lhs, const ImageIterator& rhs);
    friend bool operator!=(const ImageIterator& lhs, const ImageIterator& rhs);

public:
    ImageIterator(PBImage*);
    ImageIterator(PBImage*, const Point2D&);
    ~ImageIterator();

    ImageIterator& operator++(void);

    Point2D& operator*()
    {
        return point;
    }

    Point2D* operator->()
    {
        return &point;
    }

protected:
    ImageIterator();

    void end();

private:
    PBImage* image;
    Point2D point;
};


bool operator==(const ImageIterator& lhs, const ImageIterator& rhs);
bool operator!=(const ImageIterator& lhs, const ImageIterator& rhs);




} // namespace photobalm


#endif // IMAGEITERATOR_H
