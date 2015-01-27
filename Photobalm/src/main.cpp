#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "editmenuhandler.h"
#include "commandqueue.h"
#include "pbimage.h"


using namespace photobalm;


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  CommandStack undoStack;
  CommandQueue redoQueue;
  CommandQueue cmdQueue;

  EditMenuHandler editMenuHandler(&app, cmdQueue, undoStack, redoQueue);

  qmlRegisterType<PBImage>("PhotoBalm",1,0,"PBImage");


  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  engine.rootContext()->setContextProperty("editMenuHandler", &editMenuHandler);

  return app.exec();
}
