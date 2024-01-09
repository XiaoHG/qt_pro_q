import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.5

import QtQuick.Scene3D 2.15
import Qt3D.Core 2.15

Window {
    width: 900
    height: 600
    visible: true

    Rectangle {
        id: dddBackB
        anchors.fill: parent
        color: "green"

        Scene3D {
            id: scene3d
            anchors.fill: parent
            anchors.margins: 20
            focus: true
            aspects: ["input", "logic"]
            entity: dddScene.rootEntity
        }
    }
}
