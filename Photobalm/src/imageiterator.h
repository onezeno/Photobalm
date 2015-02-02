#ifndef IMAGEITERATOR_H
#define IMAGEITERATOR_H


#include "pbimage.h"
#include "imagepoint2d.h"


namespace photobalm {




class ImageIterator
{
public:
    ImageIterator(PBImage*);
    ImageIterator(PBImage*, int at, int step);

    virtual ~ImageIterator();

    virtual ImageIterator& operator++(void);

    virtual int& operator*();
    virtual int* operator->();

    static ImagePoint2d IndexToImagePoint2d(const PBImage&, const int index);

    virtual ImagePoint2d AtImagePoint2d();

    virtual void GoToEnd();

    PBImage* GetImage();

    int GetAt() const;
    void SetAt(int);

    int GetStep() const;
    void SetStep(int);


protected:
    ImageIterator();


private:
    PBImage* image;

    int at;
    int step;
};


//bool operator==(const ImageIterator& lhs, const ImageIterator& rhs);
//bool operator!=(const ImageIterator& lhs, const ImageIterator& rhs);




} // namespace photobalm


#endif // IMAGEITERATOR_H
