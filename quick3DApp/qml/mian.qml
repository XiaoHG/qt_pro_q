import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.5

Window {
    width: 800
    height: 600
    visible: true

    D3DRender {
        id: d3DRender
        anchors.fill: parent
    }
}
