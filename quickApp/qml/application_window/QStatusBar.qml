import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

StatusBar { //footer可以定位控件在窗口底部

    property string currentDateString: Qt.formatDateTime(new Date(), "yyyy-MM-dd hh:mm:ss")

    Timer {
        id: clockTimer
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            currentDateString = Qt.formatDateTime(new Date(), "yyyy-MM-dd hh:mm:ss")
        }
    }

    RowLayout {
        Label { text: currentDateString }
    }
}
