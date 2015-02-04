#ifndef COMMAND_H
#define COMMAND_H


#include <memory>
#include <list>
#include <QDebug>


namespace photobalm {




template <typename ImageType, typename SelectionType>
class Command : public CommandInterface
{
public:
    typedef std::shared_ptr<SelectionType> SelectionSharedPtr;
    typedef std::list<SelectionSharedPtr> SelectionList;
    typedef ImageType Image;

    Command(Image& image, const SelectionList&);
    virtual ~Command();


protected:
    Command();

    Image& GetImage();
    SelectionList& GetSelectionList();


private:
    Image& image;
    SelectionList selectionList;
};




template <typename ImageType, typename SelectionType>
Command<ImageType, SelectionType>::Command(Image& image, const SelectionList& selection_list)
: image(image)
, selectionList(selection_list)
{
  qDebug() << "Command::Command";
}




template <typename ImageType, typename SelectionType>
Command<ImageType, SelectionType>::~Command()
{
  qDebug() << "Command::~Command";
}




template <typename ImageType, typename SelectionType>
ImageType& Command<ImageType, SelectionType>::GetImage()
{
    return image;
}




template <typename ImageType, typename SelectionType>
std::list< std::shared_ptr<SelectionType> >& Command<ImageType, SelectionType>::GetSelectionList()
{
    return selectionList;
}




} // namespace photobalm


#endif // COMMAND_H
