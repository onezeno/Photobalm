#include "radiusfilltool.h"
#include "fillcommand.h"


namespace photobalm {




RadiusFillTool::RadiusFillTool(int radius, QColor color)
: ImageTool()
, selector(radius)
, color(color)
{

}




RadiusFillTool::~RadiusFillTool()
{

}




Selector& RadiusFillTool::GetSelector()
{
    return selector;
}




CommandSharedPtr RadiusFillTool::CreateCommand(ImageProvider& image_provider)
{
    return CommandSharedPtr(new FillCommand(image_provider, selector.GetSelectionList(), color));
}



} // namespace photobalm
