import QtQuick 2.15
import QtQuick.Controls 2.14

MenuBar {
    Menu {
        id: menuFile
        title: qsTr("文件")
        MenuItem {
            text: "New"
            onTriggered: document.reset()
        }
        MenuItem {
            text: "Open"
            onTriggered: openDialog.open()
        }
        MenuItem {
            text: "Save"
            onTriggered: saveDialog.open()
        }
    }
    Menu {
        id: menuEdit
        title: qsTr("编辑")
        MenuItem {
            text: "放大"
            //onTriggered: document.reset()
        }
        MenuItem {
            text: "缩小"
            //onTriggered: openDialog.open()
        }
        MenuItem {
            text: "还原"
            //onTriggered: saveDialog.open()
        }
    }
}
