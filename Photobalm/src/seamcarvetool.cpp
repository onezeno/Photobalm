#include "seamcarvetool.h"
#include "seamcarvecommand.h"


namespace photobalm {




SeamCarveTool::SeamCarveTool(int radius, QColor color)
: ImageTool()
, radius(radius)
, color(color)
{

}




SeamCarveTool::~SeamCarveTool()
{

}




CommandSharedPtr SeamCarveTool::CreateCommand()
{
    qDebug() << "SeamCarveTool::CreateCommand";

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


    qDebug() << "creating SeamCarveCommand";

    return CommandSharedPtr(
        new RadiusSeamCarveCommand(
            *image,
            *selection_list,
            color)
    );
}




} // namespace photobalm
