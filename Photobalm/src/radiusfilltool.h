#ifndef RADIUSFILLTOOL_H
#define RADIUSFILLTOOL_H


#include "imageprovider.h"
#include "imagetool.h"
#include "fillcommand.h"
#include "radiusselection.h"
#include <QColor>


namespace photobalm {



typedef FillCommand<PBImage, RadiusSelection> RadiusFillCommand;


class RadiusFillTool
: public ImageTool<RadiusFillCommand>
{
public:
    RadiusFillTool(int radius, QColor color);
    ~RadiusFillTool();

    virtual CommandSharedPtr CreateCommand();

protected:
    RadiusFillTool();

private:
    int radius;
    QColor color;
};




} // namespace photobalm


#endif // RADIUSFILLTOOL_H
