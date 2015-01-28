#ifndef RADIUSSELECTOR_H
#define RADIUSSELECTOR_H


#include "point2d.h"
#include "selector.h"


namespace photobalm {




class RadiusSelector : public Selector
{
public:
    RadiusSelector(int radius);
    ~RadiusSelector();

    virtual void AddPoint2D(Point2D);

    virtual SelectionList GetSelectionList();

private:
    int radius;
    Point2D centerPoint;
};




} // namespace photobalm


#endif // RADIUSSELECTOR_H
