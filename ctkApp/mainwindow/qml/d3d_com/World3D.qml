import QtQuick 2.15

import QtQuick.Scene3D 2.0
import Qt3D.Render 2.15

import Qt3D.Core 2.10
import Qt3D.Input 2.0
import Qt3D.Extras 2.10

Rectangle {
    id: world3DRoot
    implicitWidth: 300
    implicitHeight: 300

    Scene3D {
        id: scene3d
        anchors.fill: parent

        focus: true
        aspects: ["input", "logic"]
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

        DefaultSceneEntity {
            id: defaultSceneEntity

            Entity {
                id: planeEntity

                PlaneMesh {
                    id: mesh
                    width: 30
                    height: 20
                }

                PhongMaterial {
                    id: material
                    diffuse: "gray"
                }

                Transform {
                    id: transform
                }

                components: [mesh, material, transform]
            }

            PickableEntity {
                id: pickableEntity_1
                position: Qt.vector3d(-2, 2, 0)


                onPressed: {
                    defaultSceneEntity.isCameraEnable = false
                    pickableEntity_2.checked = false
                }

                onReleased: {
                    defaultSceneEntity.isCameraEnable = true
                }

                mesh: CuboidMesh {}
            }

            PickableEntity {
                id: pickableEntity_2
                position: Qt.vector3d(2, 2, 0)

                onPressed: {
                    defaultSceneEntity.isCameraEnable = false
                    pickableEntity_1.checked = false
                }

                onReleased: {
                    defaultSceneEntity.isCameraEnable = true
                }

                mesh: SphereMesh {}
            }
        }
    }
}

