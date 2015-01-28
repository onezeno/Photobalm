#ifndef IMAGETOOLPROVIDER_H
#define IMAGETOOLPROVIDER_H




namespace photobalm {



class ImageTool;


class ImageToolProvider
{
public:
    ImageToolProvider();
    virtual ~ImageToolProvider();

    virtual void SetTool(ImageTool*);

    virtual ImageTool* GetTool();

private:

    ImageTool* tool;
};




} // namespace photobalm


#endif // IMAGETOOLPROVIDER_H
