
import Qt3D.Core 2.15
import Qt3D.Render 2.15
import Qt3D.Extras 2.15
import Qt3D.Input 2.15

import QtQuick 2.0
import QtQuick.Scene2D 2.9
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Entity {
    id: d2dEntityRoot

    property alias logoControls: logoControls

    Transform {
        id: cubeTransform
        translation: Qt.vector3d(2, 0, 10)
        scale3D: Qt.vector3d(1, 4, 1)
    }

    CuboidMesh {
        id: cubeMesh
    }

    ObjectPicker {
        id: cubePicker
        enabled: false
        hoverEnabled: true
        dragEnabled: true

        // Explicitly require a middle click to have the Scene2D grab the mouse
        // events from the picker
        onPressed: {
            if (pick.button === PickEvent.MiddleButton) {
                qmlTexture.mouseEnabled = !qmlTexture.mouseEnabled
                logoControls.enabled = !logoControls.enabled
            }
        }
    }

    TextureMaterial {
        id: cubeMaterial
        texture: offscreenTexture
    }

    Scene2D {
        id: qmlTexture
        output: RenderTargetOutput {
            attachmentPoint: RenderTargetOutput.Color0
            texture: Texture2D {
                id: offscreenTexture
                width: 256
                height: 1024
                format: Texture.RGBA8_UNorm
                generateMipMaps: true
                magnificationFilter: Texture.Linear
                minificationFilter: Texture.LinearMipMapLinear
                wrapMode {
                    x: WrapMode.ClampToEdge
                    y: WrapMode.ClampToEdge
                }
            }
        }

        entities: [ d2dEntityRoot ]

        LogoControls {
            id: logoControls
            width: offscreenTexture.width
            height: offscreenTexture.height
        }
    }


    components: [cubeTransform, cubeMaterial, cubeMesh, cubePicker]
}

