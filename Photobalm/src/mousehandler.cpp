#include "mousehandler.h"

#include "imagetool.h"
#include <QDebug>


using namespace photobalm;




MouseHandler::MouseHandler( QObject* parent
                          , photobalm::ImageProvider& image_provider
                          , photobalm::ImageToolProvider& tool_provider
                          , photobalm::CommandProcessor& cmd_processor)
: QObject(parent)
, imageProvider(image_provider)
, toolProvider(tool_provider)
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

    ImageTool* tool = toolProvider.GetTool();

    Selector& selector = tool->GetSelector();
    selector.AddPoint2D(Point2D(x, y));

    CommandSharedPtr new_command = tool->CreateCommand(imageProvider);

    cmdProcessor.Process(new_command);
}




void MouseHandler::onPositionChanged(int mouseX, int mouseY, int width, int height)
{
    qDebug() << "MouseHandler::OnPositionChanged " << mouseX << ", " << mouseY;
}
