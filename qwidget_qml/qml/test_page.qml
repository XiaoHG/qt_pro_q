import QtQuick 2.0
import QtQuick.Controls 2.0
import DataManager 1.0
import QtQuick.VirtualKeyboard 2.13
import QtQuick.VirtualKeyboard.Settings 2.1

Item{
    id: root
    anchors.fill: parent
    property var selectedList: []

    signal notifyChangedFromCPlus()
    signal selectedChangedForCPlus()

    function changedFromCPlus(){
        console.log("The changed happen from c++, dataManager.name = " + dataManager.name)
        dm.name = dataManager.name
    }

    Component.onCompleted: {
        dataManager.printer()
        root.notifyChangedFromCPlus.connect(root.changedFromCPlus)
        dm.nameChanged.connect(function(){ t.text += dm.name })
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            focus = true;
        }
    }

    Rectangle{
        id: rect
        anchors.fill: parent
        color: "green"

        Text{
            id: t
            anchors.centerIn: parent
            text: "This is a qml page, " + dm.name
            color: "white"
            font.pixelSize: 30
        }
    }

    Button{
        id: btn
        width: 200
        height: 40
        anchors.centerIn: parent
        text: dm.name

        onClicked: {
            selectedList = [0, "true", "135"]
            selectedChangedForCPlus()
        }
    }

    DataManager{
        id: dm
        objectName: "data_manager"

        onNameChanged: {
            t.text += name

            console.log("qin --- name changed")
        }
    }

    Rectangle{
        id: inputer
        x: 250
        y: 350
        width: 100
        height: 40
        color: "yellow"
        border.color:"gray"
        TextField{
            anchors.fill: parent
            anchors.margins: 4
            focus: true
            text: "please in...."

            onPressed: {
                inputX = inputer.x - (inputPanel.width - inputer.width) / 2 +30
                inputY = inputer.y - inputPanel.height
                inputPanel.visible = true
            }
        }
        function move( height ) {
            inputer.y += height;
        }
    }

//    InputPanel {
//        id: inputPanel
//        z: 99
//        x: 0
//        y: root.height
//        width: root.width

//        onActiveChanged: {
//            inputer.y = inputPanel.y - inputer.height
//        }

//        states: State {
//            name: "visible"
//            when: inputPanel.active
//            PropertyChanges {
//                target: inputPanel
//                y: root.height - inputPanel.height
//            }
//        }
//        transitions: Transition {
//            from: ""
//            to: "visible"
//            reversible: true
//            ParallelAnimation {
//                NumberAnimation {
//                    properties: "y"
//                    duration: 250
//                    easing.type: Easing.InOutQuad
//                }
//            }
//        }
//    }

    TextField {
            id: textUser
            placeholderText: "请输入用户名"
            font.family: "Microsoft YaHei"
            font.pixelSize: 28
            topPadding: 10
            anchors.top: parent.top
            anchors.topMargin: 40
            anchors.left: parent.left
            anchors.leftMargin: 40

            background: Rectangle {
                implicitWidth: 424
                implicitHeight: 50
                radius: 4
                border.color: parent.focus  ? "#498ff8" : "#C4DBFC"
            }

            // 当选择输入框的时候才显示键盘
            onPressed: {
                inputX = x
                inputY = y + height
                inputPanel.visible = true
            }
        }

        TextField {
            id: textPasswd
            placeholderText: "请输入密码"
            font.family: "Microsoft YaHei"
            font.pixelSize: 28
            topPadding: 10
            anchors.top: parent.top
            anchors.topMargin: 300
            anchors.left: parent.left
            anchors.leftMargin: 40

            background: Rectangle {
                implicitWidth: 424
                implicitHeight: 50
                radius: 4
                border.color: parent.focus  ? "#498ff8" : "#C4DBFC"
            }

            // 当选择输入框的时候才显示键盘
            onPressed: {
                inputX = x
                inputY = y - inputPanel.height
                inputPanel.visible = true
            }
        }

        property int inputX: 0 // 键盘x坐标(动态)
        property int inputY: root.height // 键盘y坐标(动态)

        // 嵌入式虚拟键盘
        InputPanel {
            id: inputPanel
            z: 99
            //更改x,y即可更改键盘位置
            x: textUser.x
            y: root.height
            //更改width即可更改键盘大小
            width: root.width - 100
            visible: false

            externalLanguageSwitchEnabled: false

            states: State {
                name: "visible"
                when: inputPanel.active
                PropertyChanges {
                    target: inputPanel
                    // 将键盘顶部放在屏幕底部会使其隐藏起来
                    x: inputX
                    y: inputY
                }
            }

            Component.onCompleted: {
                //VirtualKeyboardSettings.locale = "eesti" // 复古键盘样式
                VirtualKeyboardSettings.wordCandidateList.alwaysVisible = true
            }

            // 这种集成方式下点击隐藏键盘的按钮是没有效果的，只会改变active，因此我们自己处理一下
            onActiveChanged: {
                if(!active) { visible = false }
            }
        }
}
