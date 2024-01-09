import QtQuick 2.15
import QtQuick.Scene3D 2.15
import Qt3D.Core 2.15

Rectangle {
    id: dddSceneRoot

    Scene3D {
        id: scene3D
        anchors.fill: parent
        focus: true
        aspects: ["input", "logic"]
        entity: dddScene.rootEntity
    }
}
