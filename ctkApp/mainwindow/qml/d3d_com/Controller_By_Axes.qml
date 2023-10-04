import QtQuick 2.15

import Qt3D.Core 2.10
import Qt3D.Render 2.10
import Qt3D.Input 2.0
import Qt3D.Extras 2.10

Entity {
    id: controller

    KeyboardDevice {
        id: keyboardDevice_controller
    }

    MouseDevice {
        id: mouseDevice_controller
        sensitivity: 0.001
    }

    LogicalDevice {
        id: logicalDevice

        axes: [
            Axis{
                id: keyScaleAxis
                ButtonAxisInput {
                    sourceDevice: keyboardDevice_controller
                    buttons: [Qt.Key_Up]
                    acceleration: 0.75
                    deceleration: 0.5
                }
                ButtonAxisInput {
                    sourceDevice: keyboardDevice_controller
                    buttons: [Qt.Key_Down]
                    scale: -1
                    acceleration: 0.75
                    deceleration: 0.5
                }

                onValueChanged: {
//                    console.log("0　----------- value = " +　value)
                }
            },
            Axis {
                id: mouseXAxis
                AnalogAxisInput {
                    sourceDevice: mouseDevice_controller
                    axis: MouseDevice.X
                }

                onValueChanged: {
//                    console.log("1　----------- value = " +　value)
                }
            },
            Axis {
                id: mouseYAxis
                AnalogAxisInput {
                    sourceDevice: mouseDevice_controller
                    axis: MouseDevice.Y
                }
                onValueChanged: {
//                    console.log("2　----------- value = " +　value)
                }
            }
        ]
    }

    components: [logicalDevice]
}
