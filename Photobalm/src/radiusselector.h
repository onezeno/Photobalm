#ifndef RADIUSSELECTOR_H
#define RADIUSSELECTOR_H


#include "imagepoint2d.h"
#include "pbimage.h"
#include "radiusselection.h"
#include "selector.h"


namespace photobalm {




class RadiusSelector
: public Selector<PBImage, RadiusSelectionList>
{
public:
    RadiusSelector(int radius);
    ~RadiusSelector();

    virtual void AddPoint2D(ImagePoint2d);

private:
    int radius;
    ImagePoint2d centerPoint;
};




} // namespace photobalm


#endif // RADIUSSELECTOR_H
