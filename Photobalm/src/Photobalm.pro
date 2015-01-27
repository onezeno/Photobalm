TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    commandprocessor.cpp \
    command.cpp \
    editmenuhandler.cpp \
    commandclear.cpp \
    selection.cpp \
    pbimage.cpp


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
    commandclear.h \
    selection.h \
    selectionlist.h \
    commandstack.h \
    pbimage.h
