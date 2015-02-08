#ifndef SEAMCARVETOOL_H
#define SEAMCARVETOOL_H


#include "imageprovider.h"
#include "imagetool.h"
#include "seamcarvecommand.h"
#include "radiusselection.h"
#include <QColor>


namespace photobalm {



typedef SeamCarveCommand<PBImage, RadiusSelection> RadiusSeamCarveCommand;


class SeamCarveTool
: public ImageTool<RadiusSeamCarveCommand>
{
public:
    SeamCarveTool(int radius, QColor color);
    ~SeamCarveTool();

    virtual CommandSharedPtr CreateCommand();

protected:
    SeamCarveTool();

private:
    int radius;
    QColor color;
};




} // namespace photobalm


#endif // SEAMCARVETOOL_H
