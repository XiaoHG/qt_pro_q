import QtQuick 2.0

import Qt3D.Core 2.0      // 节点实体模型，基础变化
import Qt3D.Render 2.15    // 相机，缓冲，滤镜，图层，面片，光照，特效，材质，Shader，
import Qt3D.Input 2.15     // 输入
import Qt3D.Logic 2.0     // 每帧动画控制
import Qt3D.Extras 2.0    // 第一人称相机，轨道相机，反射贴图，基础模型等
 import Qt3D.Extras 2.15

import QtQuick.Scene3D 2.15

Rectangle {
    id: d3DRenderRoot
    color: "lightgray"

    Scene3D {
        id: scene3d
        anchors.fill: parent
        anchors.margins: 10
        focus: true
        aspects: ["input", "logic"]

        Entity {
            id: rootEntity

            components: [

                RenderSettings {
                    activeFrameGraph: ForwardRenderer {
                        clearColor: "lightgray"
                        camera: mainCamera
                    }

                    pickingSettings.pickMethod: PickingSettings.BoundingVolumePicking
                    pickingSettings.pickResultMode: PickingSettings.NearestPick
                },

//                // Event Source will be set by the Qt3DQuickWindow
                InputSettings { }
            ]


            Camera {
                id: mainCamera
                position: Qt.vector3d(0, 5, 30)
                viewCenter: Qt.vector3d(0, 0, 0)
            }

            OrbitCameraController {
                camera: mainCamera
                linearSpeed: 30
                lookSpeed: 300
            }

            Entity {

                PlaneMesh {
                    id: pMesh
                    width: 30
                    height: 30
                }

                PhongMaterial {
                    id: pmMaterial

                    diffuse: "yellow"
                }

                components: [ pMesh, pmMaterial ]

            }

            Entity {

                SphereMesh {
                    id: sMesh
                    slices: 60
                    rings: 60
                    radius: 2
                }

                PhongMaterial {
                    id: mrMaterial

                    diffuse: "red"
                }

                Transform {
                    id: sTform
                    scale: 0.5
                    translation: Qt.vector3d(0, 2, 0)
                }

                ObjectPicker {
                    id: sOPicker
                    dragEnabled: true
                    onClicked: {
                        console.log("This is picker clicked!")
                    }
                    onPressed: { console.log("This is picker pressed!") }

                    onMoved: {
                        sTform.translation.x = pick.worldIntersection.x
                        sTform.translation.y = pick.worldIntersection.y

                        console.log("sOpicker onMoved, x = " + pick.worldIntersection.x)
                        console.log("sOpicker onMoved, z = " + pick.worldIntersection.z)
                    }
                }


                components: [ sMesh, mrMaterial, sTform, sOPicker ]
            }

        }

    }

}
