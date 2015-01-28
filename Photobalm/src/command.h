#ifndef COMMAND_H
#define COMMAND_H


#include "imageprovider.h"
#include "selectionlist.h"


namespace photobalm {




class Command
{
public:
    Command(ImageProvider& image, const SelectionList&);
    virtual ~Command();

    virtual void execute() = 0;
    virtual void undo() = 0;

protected:
    ImageProvider& GetImageProvider();
    SelectionList& GetSelectionList();

private:
    ImageProvider& imageProvider;
    SelectionList selectionList;
};




} // namespace photobalm


#endif // COMMAND_H
