#include "imagetoolprovider.h"


namespace photobalm {




ImageToolProvider::ImageToolProvider()
: tool(0)
{

}

ImageToolProvider::~ImageToolProvider()
{

}




void ImageToolProvider::SetTool(ImageTool* t)
{
    tool = t;
}




ImageTool* ImageToolProvider::GetTool()
{
    return tool;
}




} // namespace photobalm
