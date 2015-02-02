#ifndef SELECTION_H
#define SELECTION_H


#include "imageiterator.h"
#include <memory>


namespace photobalm {




template <typename IteratorType>
class Selection
{
public:
    typedef IteratorType Iterator;
    friend typename Iterator;

    Selection(PBImage&);
    virtual ~Selection();

    virtual Iterator Begin() = 0;
    virtual Iterator End() = 0;

protected:
    Selection();

    PBImage& GetImage();

private:
    PBImage& image;
};




template <typename IteratorType>
Selection<IteratorType>::Selection(PBImage& image)
: image(image)
{

}




template <typename IteratorType>
Selection<IteratorType>::~Selection()
{

}




template <typename IteratorType>
PBImage& Selection<IteratorType>::GetImage()
{
    return image;
}




} // namespace photobalm


#endif // SELECTION_H
