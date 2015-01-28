#ifndef RADIUSFILLTOOL_H
#define RADIUSFILLTOOL_H


#include "imageprovider.h"
#include "imagetool.h"
#include "radiusselector.h"
#include <QColor>


namespace photobalm {




class RadiusFillTool : public ImageTool
{
public:
    RadiusFillTool(int radius, QColor color);
    ~RadiusFillTool();

    virtual Selector& GetSelector();

    virtual CommandSharedPtr CreateCommand(ImageProvider&);

protected:
    RadiusFillTool();

private:
    RadiusSelector selector;
    QColor color;
};




} // namespace photobalm


#endif // RADIUSFILLTOOL_H
