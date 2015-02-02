#ifndef RECT2DITERATOR_H
#define RECT2DITERATOR_H


#include "imagesliceiterator.h"
#include "pbimage.h"
#include "rect2d.h"


namespace photobalm {




class Rect2dIterator : public ImageSliceIterator
{
    friend bool operator==(ImageSliceIterator& lhs, ImageSliceIterator& rhs);

public:
    Rect2dIterator(PBImage*, const Rect2d&);

    virtual ~Rect2dIterator();

    virtual void GoToEnd();

private:
    Rect2d rect;
};




bool operator==(Rect2dIterator& lhs, Rect2dIterator& rhs);
bool operator!=(Rect2dIterator& lhs, Rect2dIterator& rhs);




} // namespace photobalm


#endif // RECT2DITERATOR_H
