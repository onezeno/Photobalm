#ifndef SLICEITERATOR_H
#define SLICEITERATOR_H


#include "imageiterator.h"
#include "pbimage.h"


namespace photobalm {




/// An interator based on "generalized slices" or the gslice
class ImageSliceIterator : public ImageIterator
{
public:
    friend bool operator==(ImageSliceIterator& lhs, ImageSliceIterator& rhs);

    ImageSliceIterator( PBImage*
                      , int at
                      , int step
                      , int stride
                      , int skip);

    virtual ~ImageSliceIterator();

    virtual ImageSliceIterator& operator++(void);

    // TODO IMPLEMENT
    //virtual void GoToEnd();

protected:
    void SetStride(int);

    int stride;
    int stride_at;
    int skip;
};




bool operator==(ImageSliceIterator& lhs, ImageSliceIterator& rhs);




} // namespace photobalm


#endif // SLICEITERATOR_H
