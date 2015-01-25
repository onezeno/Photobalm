import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    title: qsTr("Photobalm")
    width: 640
    height: 480
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: fileDialog.visible = true;
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("&Edit")
            MenuItem {
                text: qsTr("&Clear");
                onTriggered: editMenuHandler.clear();
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        onAccepted: {
            mainImage.source = fileDialog.fileUrl;
            visible: false;
            splash.visible = false;
            canvas.visible = true;
        }
        onRejected: {
            visible: false
        }
        Component.onCompleted: visible = false
    }


    Image {
        id: mainImage
        fillMode: Image.PreserveAspectFit
    }


    MessageDialog {
        id: messageDialog
        title: qsTr("")

        function show(text, title) {
            messageDialog.title = title;
            messageDialog.text = text;
            messageDialog.open();
        }
    }
}
