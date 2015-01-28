#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H



class PBImage;


namespace photobalm {




class ImageProvider
{
public:
    ImageProvider();
    virtual ~ImageProvider();

    PBImage* GetImage();

    void SetImage(PBImage*);

private:
    PBImage* image;
};




} // namespace photobalm


#endif // IMAGEPROVIDER_H
