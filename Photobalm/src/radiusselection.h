#ifndef RADIUSSELECTION_H
#define RADIUSSELECTION_H


#include "selection.h"
#include "point2d.h"
#include "pbimage.h"


namespace photobalm {




class RadiusSelection : public Selection
{
public:
    RadiusSelection(int radius, Point2D center_point);
    virtual ~RadiusSelection();

    virtual ImageIterator Begin(PBImage&);

protected:
    RadiusSelection();

private:
    int radius;
    Point2D centerPoint;
};




} // namespace photobalm


#endif // RADIUSSELECTION_H
