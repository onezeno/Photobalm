#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "editmenuhandler.h"
#include "commandqueue.h"


using namespace photobalm;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    CommandQueue undoQueue;
    CommandQueue cmdQueue;

    EditMenuHandler editMenuHandler(&app, cmdQueue, undoQueue);


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    engine.rootContext()->setContextProperty("editMenuHandler", &editMenuHandler);

    return app.exec();
}
