#ifndef IMAGETOOL_H
#define IMAGETOOL_H


#include "commandsharedptr.h"
#include "imageprovider.h"
#include "selector.h"


namespace photobalm {




class ImageTool
{
public:
    explicit ImageTool();
    virtual ~ImageTool();

    virtual Selector& GetSelector() = 0;

    virtual CommandSharedPtr CreateCommand(ImageProvider&) = 0;
};




} // namespace photobalm


#endif // IMAGETOOL_H
