#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <pbimage.h>

int main(int argc, char *argv[])
{
  qmlRegisterType<PBImage>("PhotoBalm",1,0,"PBImage");

  QApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



  return app.exec();
}
