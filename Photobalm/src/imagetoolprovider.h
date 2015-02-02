#ifndef IMAGETOOLPROVIDER_H
#define IMAGETOOLPROVIDER_H


#include "imagetoolinterface.h"


namespace photobalm {




class ImageToolProvider
{
public:
    ImageToolProvider();
    virtual ~ImageToolProvider();

    virtual void SetTool(ImageToolInterface*);

    virtual ImageToolInterface* GetTool();

private:
    ImageToolInterface* tool;
};




} // namespace photobalm


#endif // IMAGETOOLPROVIDER_H
