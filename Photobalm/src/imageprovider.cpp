#include "imageprovider.h"


namespace photobalm {




ImageProvider::ImageProvider()
: image(0)
{

}




ImageProvider::~ImageProvider()
{

}




PBImage* ImageProvider::GetImage()
{
    return image;
}




void ImageProvider::SetImage(PBImage* i)
{
    image = i;
}




} // namespace photobalm
