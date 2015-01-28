#ifndef SELECTION_H
#define SELECTION_H


#include "imageiterator.h"
#include <memory>


namespace photobalm {




class Selection
{
public:
    Selection();
    virtual ~Selection();

    virtual ImageIterator Begin(PBImage&) = 0;
    virtual ImageIterator End();
};




} // namespace photobalm


#endif // SELECTION_H
