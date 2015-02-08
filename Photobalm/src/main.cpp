#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "commandqueue.h"
#include "commandprocessor.h"
#include "commandstack.h"
#include "editmenuhandler.h"
#include "filemenuhandler.h"
#include "imageprovider.h"
#include "imagetoolprovider.h"
#include "mousehandler.h"
#include "pbimage.h"
#include "radiusfilltool.h"
#include "radiusselector.h"
#include "toolmenuhandler.h"


using namespace photobalm;


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  RadiusSelector radius_selector(5);

  SelectorProvider selector_provider;
  selector_provider.SetSelector(&radius_selector);

  RadiusFillTool radius_fill_tool(5, QColor(255, 0, 0));


  ImageToolProvider tool_provider;
  tool_provider.SetTool(&radius_fill_tool);

  CommandStack undo_stack;
  CommandQueue redo_queue;
  CommandQueue cmd_queue;

  CommandProcessor cmd_processor(cmd_queue);


  EditMenuHandler edit_menu_handler(&app, cmd_queue, undo_stack, redo_queue);
  ToolMenuHandler tool_menu_handler(&app);

  qmlRegisterType<PBImage>("PhotoBalm",1,0,"PBImage");

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  qDebug() << "engine loaded " << engine.rootObjects().size() << " root objects";

  QObject* root = engine.rootObjects().first();
  PBImage* image = root->findChild<PBImage*>("mainImage");

  //qDebug() << "Image pointer is " << int(image);

  ImageProvider image_provider;
  image_provider.SetImage(image);


  // the setting of the tool image needs to be moved to a tool menu handler when the user selects the tool
  radius_fill_tool.SetImage(image);
  radius_selector.SetImage(image);

  FileMenuHandler file_menu_handler(&app, image_provider);
  MouseHandler mouse_handler( &app
                            , image_provider
                            , tool_provider
                            , selector_provider
                            , cmd_processor);


  engine.rootContext()->setContextProperty("mouseHandler", &mouse_handler);
  engine.rootContext()->setContextProperty("fileMenuHandler", &file_menu_handler);
  engine.rootContext()->setContextProperty("editMenuHandler", &edit_menu_handler);
  engine.rootContext()->setContextProperty("toolMenuHandler", &tool_menu_handler);

  return app.exec();
}
