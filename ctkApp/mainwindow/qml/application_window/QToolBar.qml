import QtQuick 2.15
import QtQuick.Controls 2.14

ToolBar{ //header可以定位控件在窗口顶部

    Row {
        spacing: 1
        ToolButton
        {
            text: 'ToolButton1'
            onClicked: console.log('Button1 Clicked.')
        }
        ToolButton
        {
            text: 'ToolButton2'
            onClicked: console.log('Button2 Clicked.')
        }
        ToolButton
        {
            text: 'ToolButton3'
            onClicked: console.log('Button3 Clicked.')
        }
    }

    background: Rectangle {
        anchors.fill:parent
        color:'#666666'
    }
}
