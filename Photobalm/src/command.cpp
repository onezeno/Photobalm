#include "command.h"
#include <QDebug>


namespace photobalm {




Command::Command(ImageProvider& image_provider, const SelectionList& selection_list)
: imageProvider(image_provider)
, selectionList(selection_list)
{
  qDebug() << "Command::Command";
}




Command::~Command()
{
  qDebug() << "Command::~Command";
}




ImageProvider& Command::GetImageProvider()
{
    return imageProvider;
}




SelectionList& Command::GetSelectionList()
{
    return selectionList;
}




} // namespace photobalm
