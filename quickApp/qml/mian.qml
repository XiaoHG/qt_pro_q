import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.5
import "./other"

Window {
    width: 800
    height: 600
    visible: true

    //桌面右下角弹框
    Button{
        width: 200
        height: 45
        anchors.centerIn: parent
        text: "Pop"

        onClicked: pop.showTip()

        //桌面右下角弹框
        QDesktopTip{
            id: pop
            title: qsTr("DesktopTip")

            content: Rectangle{
                width: 300
                height: 120
                color: "green"
                Text {
                    anchors.centerIn: parent
                    text: qsTr("DesktopTip")
                }
                //测试上层也有个MouseArea对对话框的MouseArea影响
                MouseArea{
                    anchors.fill: parent
                    //目前还不能设置hoverEnabled，不然parent的MouseArea没法判断
                    //hoverEnabled: true
                }
            }
        }
    }
}
