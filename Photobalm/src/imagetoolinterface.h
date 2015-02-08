#ifndef IMAGETOOLINTERFACE_H
#define IMAGETOOLINTERFACE_H


#include "commandsharedptr.h"
#include "imageprovider.h"
#include "selectorinterface.h"


namespace photobalm {




/// Base pointer type for all image tools.
/// Allows the tools to be stored in std container.
class ImageToolInterface
{
public:
    ImageToolInterface();
    virtual ~ImageToolInterface();

    virtual CommandSharedPtr CreateCommand() = 0;
};




} // namespace photobalm


#endif // IMAGETOOLINTERFACE_H
