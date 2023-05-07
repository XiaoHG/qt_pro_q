import QtQuick 2.0
import QtQuick.Controls 2.0

Item{
    id: root
    anchors.fill: parent
    property var selectedList: []

    signal notifyChangedFromCPlus()
    signal selectedChangedForCPlus()

    function changedFromCPlus(){
        console.log("The changed happen from c++, dataManager.name = " + dataManager.name)
    }

    Component.onCompleted: {
        dataManager.printer()
        root.notifyChangedFromCPlus.connect(root.changedFromCPlus)
    }

    Rectangle{
        id: rect
        anchors.fill: parent
        color: "green"

        Text{
            id: t
            anchors.centerIn: parent
            text: "This is a qml page"
            color: "white"
            font.pixelSize: 30
        }
    }

    Button{
        id: btn
        width: 200
        height: 40
        anchors.centerIn: parent

        onClicked: {
            selectedList = [0, "true", "135"]
            selectedChangedForCPlus()
        }
    }
}
