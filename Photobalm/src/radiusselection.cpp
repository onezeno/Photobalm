#include "radiusselection.h"


namespace photobalm {




RadiusSelection::RadiusSelection(int radius, Point2D center_point)
: radius(radius)
, centerPoint(center_point)
{

}




RadiusSelection::~RadiusSelection()
{

}




ImageIterator RadiusSelection::Begin(PBImage& image)
{
    return ImageIterator(&image, centerPoint);
}




} // namespace photobalm
