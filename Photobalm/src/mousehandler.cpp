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
    qDebug() << "MouseHandler::OnClicked " << mouseX << ", " << mouseY;

    PBImage* image = imageProvider.GetImage();

    if (!image)
    {
        return;
    }

    // transform the input pixel from the container coordinates to the image coordinates
    float x_f = static_cast<float>(image->width()) / static_cast<float>(width);
    float scaled_x_f = x_f * static_cast<float>(mouseX);
    int x = static_cast<int>(scaled_x_f); // NOTE: always rounds down

    float y_f = static_cast<float>(image->height()) / static_cast<float>(height);
    float scaled_y_f = y_f * static_cast<float>(mouseY);
    int y = static_cast<int>(scaled_y_f);

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
