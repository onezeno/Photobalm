#ifndef SELECTORINTERFACE_H
#define SELECTORINTERFACE_H


#include "imagepoint2d.h"


namespace photobalm {




class SelectorInterface
{
public:
    SelectorInterface();
    ~SelectorInterface();

    virtual void AddPoint2D(ImagePoint2d) = 0;
};




} // namespace photobalm


#endif // SELECTORINTERFACE_H
