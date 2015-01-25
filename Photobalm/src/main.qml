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
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        onAccepted: {
            main_image.source = fileDialog.fileUrl;
            visible: false;
            splash.visible = false;
            canvas.visible = true;
        }
        onRejected: {
            visible: false
        }
        Component.onCompleted: visible = false
    }

    Item {
        id: splash
        anchors.fill: parent

        ColumnLayout {
            Text {
                id: title
                text: "Photobalm"
            }

            Button {
                id: selectImageButton
                text: "Select Image"

                onClicked: {
                    fileDialog.visible = true;
                }
            }
        }
    }

    Image {
        id: main_image
        fillMode: Image.PreserveAspectFit
    }



    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
