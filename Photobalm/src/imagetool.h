#ifndef IMAGETOOL_H
#define IMAGETOOL_H


#include "commandsharedptr.h"
#include "imageprovider.h"
#include "imagetoolinterface.h"


namespace photobalm {




template<typename CommandType>
class ImageTool
: public ImageToolInterface
{
public:
    typedef typename CommandType::Image Image;
    typedef typename CommandType::SelectionList SelectionList;

    ImageTool();
    virtual ~ImageTool();

    Image* GetImage();
    void SetImage(Image*);

    SelectionList* GetSelectionList();
    void SetSelectionList(SelectionList* selection_list);

private:
    Image* image;
    SelectionList* selectionList;
};




template<typename CommandType>
ImageTool<CommandType>::ImageTool()
: image(0)
, selectionList(0)
{

}




template<typename CommandType>
ImageTool<CommandType>::~ImageTool()
{

}




template<typename CommandType>
typename ImageTool<CommandType>::Image* ImageTool<CommandType>::GetImage()
{
    return this->image;
}




template<typename CommandType>
void ImageTool<CommandType>::SetImage(Image* image)
{
    this->image = image;
}




template<typename CommandType>
typename ImageTool<CommandType>::SelectionList* ImageTool<CommandType>::GetSelectionList()
{
    return this->selectionList;
}





template<typename CommandType>
void ImageTool<CommandType>::SetSelectionList(SelectionList* selection_list)
{
    this->selectionList = selection_list;
}




} // namespace photobalm


#endif // IMAGETOOL_H
