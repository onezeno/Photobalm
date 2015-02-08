#include "radiusselector.h"
#include "radiusselection.h"


namespace photobalm {




RadiusSelector::RadiusSelector(int radius)
: Selector()
, radius(radius)
, centerPoint(-1, -1)
{

}




RadiusSelector::~RadiusSelector()
{

}




void RadiusSelector::AddPoint2D(ImagePoint2d p)
{
    qDebug() << "RadiusSelector::AddPoint2D " << p.x << ", " << p.y;
    this->centerPoint = p;

    SelectionList& selection_list = GetSelectionList();
    PBImage* image = GetImage();

    if (!image)
    {
        return;
    }

    std::shared_ptr<RadiusSelection> ptr = std::shared_ptr<RadiusSelection>(new RadiusSelection(*image, radius, p));
    selection_list.push_back(ptr);
}




} // namespace photobalm
