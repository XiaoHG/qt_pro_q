import QtQuick 2.15

import Qt3D.Core 2.10
import Qt3D.Render 2.10
import Qt3D.Input 2.0
import Qt3D.Extras 2.10

Entity {
    id: root

    signal pressed(var event)
    signal clicked(var event)
    signal released(var event)
    signal entered()
    signal exited()

    property bool checked: false
    property alias position: transform.translation
    property color hoveredColor: "orange"
    property color checkedColor: "yellow"
    readonly property bool containsMouse: objectPicker.containsMouse
    readonly property bool isPressed: objectPicker.pressed

    property alias keyboardSource: keyboardInput.sourceDevice

    property GeometryRenderer mesh

    KeyboardHandler {
        id: keyboardInput
        focus: root.checked
        onPressed: {
            switch (event.key){
            case Qt.Key_W:
                console.log("sphereMesh, Key_W")
                position.z -= 1
                break;
            case Qt.Key_S:
                console.log("sphereMesh, Key_S")
                position.z += 1
                break;
            case Qt.Key_A:
                console.log("sphereMesh, Key_A")
                position.x -= 1
                break;
            case Qt.Key_D:
                console.log("sphereMesh, Key_D")
                position.x += 1
                break;
            default:
                console.log("sphereMesh, Other")
                break;
            }
        }
    }

    ObjectPicker {
        id: objectPicker
        hoverEnabled: true
        onPressed: {
            dragEnabled = true
            root.checked = true
            root.pressed(pick)
        }
        onReleased: {
            dragEnabled = false
            root.released(pick)
        }
        onEntered: root.entered()
        onExited: root.exited()
        onClicked: {
            root.clicked(pick)
        }

        onMoved: {
            position.x = pick.worldIntersection.x
            position.z = pick.worldIntersection.z
        }
    }

    PhongMaterial {
        id: material
        diffuse: root.checked ? checkedColor : ( objectPicker.containsMouse ? hoveredColor : "red" )
    }

    Transform {
        id: transform

        Behavior on scale {

            NumberAnimation {
                duration: 150
                easing.type: Easing.InQuad
            }
        }
    }

    components: [mesh, material, transform, objectPicker, keyboardInput]
}
