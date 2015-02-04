#include "radiusselection.h"
#include "rect2d.h"

namespace photobalm {




RadiusSelection::RadiusSelection( PBImage& image
                                , int radius
                                , ImagePoint2d center_point)
: Selection(image)
, radius(radius)
, centerPoint(center_point)
{

}




RadiusSelection::~RadiusSelection()
{

}




RadiusSelection::Iterator RadiusSelection::Begin()
{
    PBImage& image = GetImage();

    Rect2d rect( centerPoint + ImagePoint2d(-radius/2, -radius/2)
               , centerPoint + ImagePoint2d(radius/2, radius/2));

    return Rect2dIterator(&image, rect);
}




RadiusSelection::Iterator RadiusSelection::End()
{
    PBImage& image = GetImage();

    Rect2d rect( centerPoint + ImagePoint2d(-radius/2, -radius/2)
               , centerPoint + ImagePoint2d(radius/2, radius/2));

    Rect2dIterator it(&image, rect);
    it.GoToEnd();
    return it;
}




} // namespace photobalm
