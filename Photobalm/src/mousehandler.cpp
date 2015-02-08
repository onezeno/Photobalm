#include "mousehandler.h"

#include "imagetool.h"
#include "radiusfilltool.h"
#include "radiusselector.h"
#include "seamcarvetool.h"
#include "selectorinterface.h"
#include <QDebug>


using namespace photobalm;




MouseHandler::MouseHandler( QObject* parent
                          , photobalm::ImageProvider& image_provider
                          , photobalm::ImageToolProvider& tool_provider
                          , photobalm::SelectorProvider& selector_provider
                          , photobalm::CommandProcessor& cmd_processor)
: QObject(parent)
, imageProvider(image_provider)
, toolProvider(tool_provider)
, selectorProvider(selector_provider)
, cmdProcessor(cmd_processor)
{

}




MouseHandler::~MouseHandler()
{

}




void MouseHandler::onClicked(int mouseX, int mouseY, int width, int height)
{
    qDebug() << "MouseHandler::OnClicked " << mouseX << ", " << mouseY << ", " << width << ", " << height;

    PBImage* image = imageProvider.GetImage();

    if (!image)
    {
        return;
    }

    qDebug() << "MouseHandler::OnClicked PBImage " << image->width() << ", " << image->height();
    qDebug() << "MouseHandler::OnClicked QImage " << image->GetWidth() << ", " << image->GetHeight();

    // transform the input pixel from the container coordinates to the image coordinates
    int x = (mouseX * image->GetWidth()) / width;
    int y = (mouseY * image->GetHeight()) / height;

    qDebug() << "MouseHandler::OnClicked scaled " << x << ", " << y;


    ImageToolInterface* tool_ptr = toolProvider.GetTool();

    if (!tool_ptr)
    {
        qDebug() << "no tool";
        return;
    }

    SelectorInterface* selector_ptr = selectorProvider.GetSelector();

    if (!selector_ptr)
    {
        qDebug() << "no selector";
        return;
    }

    selector_ptr->AddPoint2D(ImagePoint2d(x, y));


    try
    {
        RadiusSelector* radius_selector_ptr = dynamic_cast<RadiusSelector*>(selector_ptr);

        if (!radius_selector_ptr)
        {
            qDebug() << "no radius selection pointer";
            return;
        }

        RadiusSelector::SelectionList& selection_list = radius_selector_ptr->GetSelectionList();


        /* TODO - NEED TO MAKE THIS WORK FOR ALL TOOLS
        qDebug() << "casting to RadiusFillTool";
        RadiusFillTool* radius_fill_tool_ptr = dynamic_cast<RadiusFillTool*>(tool_ptr);
        qDebug() << "cast to RadiusFillTool";


        if (!radius_fill_tool_ptr)
        {
            qDebug() << "could not cast to RadiusFillTool";
            return;
        }

        radius_fill_tool_ptr->SetSelectionList(&selection_list);

        CommandSharedPtr new_command = radius_fill_tool_ptr->CreateCommand();
        */

        qDebug() << "casting to SeamCarveTool";
        SeamCarveTool* seam_carve_tool_ptr = dynamic_cast<SeamCarveTool*>(tool_ptr);
        qDebug() << "cast to SeamCarveTool";


        if (!seam_carve_tool_ptr)
        {
            qDebug() << "could not cast to SeamCarveTool";
            return;
        }

        seam_carve_tool_ptr->SetSelectionList(&selection_list);

        CommandSharedPtr new_command = seam_carve_tool_ptr->CreateCommand();

        cmdProcessor.Process(new_command);
    }
    catch (std::bad_cast& error)
    {
        qDebug() << error.what();
    }
    catch (std::runtime_error& error)
    {
        qDebug() << error.what();
    }
}




void MouseHandler::onPositionChanged(int mouseX, int mouseY, int width, int height)
{
    qDebug() << "MouseHandler::OnPositionChanged " << mouseX << ", " << mouseY;
}
