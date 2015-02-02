import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

import PhotoBalm 1.0

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
                text: qsTr("Undo (Ctrl+&Z)");
                onTriggered: editMenuHandler.undo();
            }
            MenuItem {
                text: qsTr("Redo (Ctrl+&Y)");
                onTriggered: editMenuHandler.redo();
            }
        }
        Menu {
            title: qsTr("&Tools")
            MenuItem {
                text: qsTr("&Fill");
                onTriggered: toolMenuHandler.fill();
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        onAccepted: {
            fileMenuHandler.load(fileDialog.fileUrl)
            visible: false;
        }
        onRejected: {
            visible: false
        }
        Component.onCompleted: visible = false
    }

    MouseArea {
        anchors.fill: parent
        onClicked: mouseHandler.onClicked(mouseX, mouseY, width, height, main_image)
        onPositionChanged: mouseHandler.onPositionChanged(mouseX, mouseY, width, height, main_image)
        PBImage {
            id: main_image
            objectName: "mainImage"
            anchors.fill: parent
        }
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
