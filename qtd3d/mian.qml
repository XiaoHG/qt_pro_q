
import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Scene3D 2.0

Item {
    id: mainview
    width: 1280
    height: 768
    visible: true

    Text {
        text: qsTr("This is a test window!")
        font.pixelSize: 50
        font.bold: true
        color: "green"
        anchors.centerIn: parent
    }
}
