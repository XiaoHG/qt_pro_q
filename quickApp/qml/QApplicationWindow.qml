import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.0
import "./application_window"

ApplicationWindow {
    id: window
    visible: true   //ApplicationWindow默认是不可见的
    width: 900;
    height: 600;

    menuBar: QMenuBar { }
    header: QToolBar{ }
    footer: QStatusBar { }

    TabView {
        id: myContent
        anchors.fill: parent

        Tab {
            title: "Red"
            Rectangle { color: "red" }
        }
        Tab {
            title: "Blue"
            Rectangle { color: "blue" }
        }
        Tab {
            title: "Green"
            Rectangle { color: "green" }
        }
    }
}
