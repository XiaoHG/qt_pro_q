import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import "./dddScene"
import "./topTool"
import "./leftTool"
import "./rightTool"

Window {
    width: 900
    height: 600
    visible: true
    title: qsTr("XiaoHG's Qt3d Eidtor")

    TopToolBar {
        id: topToolBar
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
    }

    Item {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: topToolBar.bottom
        anchors.bottom: parent.bottom

        RowLayout {
            anchors.fill: parent

            LeftToolBar {
                id: leftToolBar
                Layout.fillHeight: true
            }

            DDDScene {
                id: dddSceneqml
                Layout.fillWidth: true
                Layout.fillHeight: true
            }

            RightToolBar {
                id: rightToolBar
                Layout.fillHeight: true
            }
        }
    }



}
