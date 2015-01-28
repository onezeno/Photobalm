#ifndef SELECTOR_H
#define SELECTOR_H


#include "point2d.h"
#include "selectionlist.h"


namespace photobalm {



class Selector
{
public:
    Selector();
    virtual ~Selector();

    virtual void AddPoint2D(Point2D) = 0;

    virtual SelectionList GetSelectionList() = 0;

};




} // namespace photobalm


#endif // SELECTOR_H
