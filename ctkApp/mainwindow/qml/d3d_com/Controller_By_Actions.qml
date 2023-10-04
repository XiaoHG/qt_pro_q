import QtQuick 2.15

import Qt3D.Core 2.10
import Qt3D.Render 2.10
import Qt3D.Input 2.0
import Qt3D.Extras 2.10

Entity {
    id: controller
    property alias ascaleUp: scaleAction.active
    property bool rotateRunning: false
    signal toggleMaterial

    KeyboardDevice {
        id: keyboardDevice_controller
    }

    LogicalDevice {
        id: logicalDevice

        actions: [
            Action {
                id: materialAction
                inputs: ActionInput {
                    sourceDevice: keyboardDevice_controller
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
                            sourceDevice: keyboardDevice_controller
                            buttons: [Qt.Key_Q]
                        },
                        ActionInput {
                            sourceDevice: keyboardDevice_controller
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
                            sourceDevice: keyboardDevice_controller
                            buttons: [Qt.Key_Z]
                        },
                        ActionInput {
                            sourceDevice: keyboardDevice_controller
                            buttons: [Qt.Key_X]
                        }
                    ]
                }

                onActiveChanged: {
                    console.log("InputSequence, Z & X, active = " +　active)
                }
            }
        ]
    }

    components: [logicalDevice]
}
