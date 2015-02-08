#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include "commandprocessor.h"
#include "imageprovider.h"
#include "imagetoolprovider.h"
#include "pbimage.h"
#include "selectorprovider.h"




class MouseHandler : public QObject
{
    Q_OBJECT
public:
    explicit MouseHandler( QObject* parent
                         , photobalm::ImageProvider&
                         , photobalm::ImageToolProvider&
                         , photobalm::SelectorProvider&
                         , photobalm::CommandProcessor&);
    ~MouseHandler();

    Q_INVOKABLE void onClicked(int mouseX, int mouseY, int width, int height);
    Q_INVOKABLE void onPositionChanged(int mouseX, int mouseY, int width, int height);

signals:

public slots:

private:
    photobalm::ImageProvider& imageProvider;
    photobalm::ImageToolProvider& toolProvider;
    photobalm::SelectorProvider& selectorProvider;
    photobalm::CommandProcessor& cmdProcessor;
};




#endif // MOUSEHANDLER_H
