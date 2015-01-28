TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    commandprocessor.cpp \
    command.cpp \
    editmenuhandler.cpp \
    selection.cpp \
    pbimage.cpp \
    imagetool.cpp \
    selector.cpp \
    radiusselector.cpp \
    point2d.cpp \
    radiusfilltool.cpp \
    radiusselection.cpp \
    fillcommand.cpp \
    toolmenuhandler.cpp \
    mousehandler.cpp \
    imagetoolprovider.cpp \
    filemenuhandler.cpp \
    imageprovider.cpp \
    imageiterator.cpp


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
    point2d.h \
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
    selectionsharedptr.h
