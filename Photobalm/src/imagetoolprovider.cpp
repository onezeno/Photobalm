#include "imagetoolprovider.h"


namespace photobalm {




ImageToolProvider::ImageToolProvider()
: tool(0)
{

}

ImageToolProvider::~ImageToolProvider()
{

}




void ImageToolProvider::SetTool(ImageToolInterface* t)
{
    tool = t;
}




ImageToolInterface* ImageToolProvider::GetTool()
{
    return tool;
}




} // namespace photobalm
