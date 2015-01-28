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




void RadiusSelector::AddPoint2D(Point2D p)
{
    this->centerPoint = p;
}




SelectionList RadiusSelector::GetSelectionList()
{
    SelectionList list;

    list.push_back(SelectionSharedPtr(new RadiusSelection(radius, centerPoint)));

    return list;
}




} // namespace photobalm
