#ifndef RADIUSSELECTION_H
#define RADIUSSELECTION_H


#include "rect2diterator.h"
#include "selection.h"
#include "imagepoint2d.h"
#include "pbimage.h"


namespace photobalm {




class RadiusSelection
: public Selection<Rect2dIterator>
{
public:
    RadiusSelection(PBImage& image, int radius, ImagePoint2d center_point);
    virtual ~RadiusSelection();

    virtual Iterator Begin();
    virtual Iterator End();

protected:
    RadiusSelection();

private:
    int radius;
    ImagePoint2d centerPoint;
};





typedef std::list< std::shared_ptr<RadiusSelection> > RadiusSelectionList;




} // namespace photobalm


#endif // RADIUSSELECTION_H
