#ifndef SELECTOR_H
#define SELECTOR_H


#include "Imagepoint2d.h"
#include "selectionlist.h"
#include "selectorinterface.h"


namespace photobalm {




template<typename ImageType, typename SelectionListType>
class Selector
: public SelectorInterface
{
public:
    typedef ImageType Image;
    typedef SelectionListType SelectionList;

    Selector();
    virtual ~Selector();

    SelectionList& GetSelectionList();

    Image* GetImage();
    void SetImage(Image*);

private:
    SelectionListType selectionList;
    Image* image;
};





template<typename ImageType, typename SelectionListType>
Selector<ImageType, SelectionListType>::Selector()
: image(0)
{

}



template<typename ImageType, typename SelectionListType>
Selector<ImageType, SelectionListType>::~Selector()
{

}




template<typename ImageType, typename SelectionListType>
SelectionListType& Selector<ImageType, SelectionListType>::GetSelectionList()
{
    return selectionList;
}




template<typename ImageType, typename SelectionListType>
ImageType* Selector<ImageType, SelectionListType>::GetImage()
{
    return image;
}




template<typename ImageType, typename SelectionListType>
void Selector<ImageType, SelectionListType>::SetImage(ImageType* image)
{
    this->image = image;
}




} // namespace photobalm


#endif // SELECTOR_H
