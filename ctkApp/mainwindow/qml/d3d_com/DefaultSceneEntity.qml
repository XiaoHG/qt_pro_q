
import Qt3D.Core 2.10
import Qt3D.Render 2.10
import Qt3D.Input 2.0
import Qt3D.Extras 2.10

Entity {
    id: root

    property bool isCameraEnable: false

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                camera: mainCamera
                frustumCulling: false
                clearColor: "lightgray"
            }
        },
        // Event Source will be set by the Qt3DQuickWindow
        InputSettings { }
    ]

    PhongMaterial {
        id: material
        diffuse: "white"
    }

    Camera {
        id: mainCamera
        position: Qt.vector3d(0, 5, 16)
        viewCenter: Qt.vector3d(0, 0, 0)
        fieldOfView: 60
    }

    OrbitCameraController {
        camera: mainCamera
        linearSpeed: 15
        lookSpeed: 120
        enabled: isCameraEnable
    }
}
