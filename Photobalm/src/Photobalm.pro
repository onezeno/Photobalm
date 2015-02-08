TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    commandprocessor.cpp \
    command.cpp \
    editmenuhandler.cpp \
    selection.cpp \
    pbimage.cpp \
    imagetool.cpp \
    selector.cpp \
    radiusselector.cpp \
    radiusfilltool.cpp \
    radiusselection.cpp \
    fillcommand.cpp \
    toolmenuhandler.cpp \
    mousehandler.cpp \
    imagetoolprovider.cpp \
    filemenuhandler.cpp \
    imageprovider.cpp \
    imageiterator.cpp \
    commandinterface.cpp \
    imagesliceiterator.cpp \
    rect2d.cpp \
    imagetoolinterface.cpp \
    point2dselectionlist.cpp \
    rect2diterator.cpp \
    selectorinterface.cpp \
    point2diterator.cpp \
    selectorprovider.cpp \
    imagepoint2d.cpp \
    seamcarvecommand.cpp \
    seamcarvetool.cpp


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    command.h \
    commandqueue.h \
    commandresult.h \
    commandexception.h \
    commandprocessor.h \
    editmenuhandler.h \
    selection.h \
    selectionlist.h \
    commandstack.h \
    pbimage.h \
    imagetool.h \
    selector.h \
    radiusselector.h \
    radiusfilltool.h \
    radiusselection.h \
    fillcommand.h \
    toolmenuhandler.h \
    mousehandler.h \
    imagetoolprovider.h \
    filemenuhandler.h \
    imageprovider.h \
    commandsharedptr.h \
    imageiterator.h \
    selectionsharedptr.h \
    commandinterface.h \
    imagesliceiterator.h \
    rect2d.h \
    imagetoolinterface.h \
    point2dselectionlist.h \
    point2dselection.h \
    rect2dselection.h \
    rect2diterator.h \
    rect2dselectionlist.h \
    selectorinterface.h \
    point2diterator.h \
    selectorprovider.h \
    imagepoint2d.h \
    seamcarvecommand.h \
    seamcarvetool.h
