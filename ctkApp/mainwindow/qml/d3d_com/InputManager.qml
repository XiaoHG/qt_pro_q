import QtQuick 2.15

import Qt3D.Core 2.15
import Qt3D.Render 2.15
import Qt3D.Input 2.15
import Qt3D.Extras 2.15

Entity {
    id: imRoot

    KeyboardDevice {
        id: keyboardDevice
    }

    MouseDevice {
        id: mouseDevice
        sensitivity: 0.001
    }

    LogicalDevice {
        id: logicalDevice

        actions: [
            Action {
                id: materialAction
                inputs: ActionInput {
                    sourceDevice: keyboardDevice
                    buttons: [Qt.Key_Space, Qt.Key_Return]
                }
                onActiveChanged: {
                    console.log("Qt.Key_Space, Qt.Key_Return, active = " + active)
                }
            },

            Action {
                id: scaleAction
                InputChord {
                    timeout: 300
                    chords: [
                        ActionInput {
                            sourceDevice: keyboardDevice
                            buttons: [Qt.Key_Q]
                        },
                        ActionInput {
                            sourceDevice: keyboardDevice
                            buttons: [Qt.Key_W]
                        }
                    ]
                }
                onActiveChanged: {
                    console.log("InputChord, Q & W, active = " +　active)
                }
            },

            Action {
                id: rotateOnAction
                InputSequence {
                    timeout: 600
                    buttonInterval: 300
                    sequences: [
                        ActionInput {
                            sourceDevice: keyboardDevice
                            buttons: [Qt.Key_Z]
                        },
                        ActionInput {
                            sourceDevice: keyboardDevice
                            buttons: [Qt.Key_X]
                        }
                    ]
                }

                onActiveChanged: {
//                    console.log("InputSequence, Z & X, active = " +　active)
                }
            }
        ]

        axes: [
            Axis{
                id: keyScaleAxis
                ButtonAxisInput {
                    sourceDevice: keyboardDevice
                    buttons: [Qt.Key_Up]
                    acceleration: 0.75
                    deceleration: 0.5
                }
                ButtonAxisInput {
                    sourceDevice: keyboardDevice
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
                    sourceDevice: mouseDevice
                    axis: MouseDevice.X
                }

                onValueChanged: {
//                    console.log("1　----------- value = " +　value)
                }
            },
            Axis {
                id: mouseYAxis
                AnalogAxisInput {
                    sourceDevice: mouseDevice
                    axis: MouseDevice.Y
                }
                onValueChanged: {
                    console.log("2　----------- value = " +　value)
                }
            }
        ]
    }

    components: [logicalDevice]
}
