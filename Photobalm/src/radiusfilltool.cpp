#include "radiusfilltool.h"
#include "fillcommand.h"


namespace photobalm {




RadiusFillTool::RadiusFillTool(int radius, QColor color)
: ImageTool()
, radius(radius)
, color(color)
{

}




RadiusFillTool::~RadiusFillTool()
{

}




CommandSharedPtr RadiusFillTool::CreateCommand()
{
    qDebug() << "RadiusFillTool::CreateCommand";

    PBImage* image = GetImage();
    if (!image)
    {
        throw std::runtime_error("need image");
    }

    SelectionList* selection_list = GetSelectionList();
    if (!selection_list)
    {
        throw std::runtime_error("need selection list");
    }


    qDebug() << "creating RadiusFillCommand";

    return CommandSharedPtr(
        new RadiusFillCommand(
            *image,
            *selection_list,
            color)
    );
}




} // namespace photobalm
