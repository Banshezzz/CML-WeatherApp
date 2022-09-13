import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0

Window {
    id: root
    width: 1024
    height: 680
    visible: true
    title: qsTr("TEAM 2 - WEATHER INFOMATION")
    color: "transparent"

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightGreen" }
            GradientStop { position: 0.33; color: "green" }
            GradientStop { position: 1.0; color: "darkGreen" }
        }
    }

    StatusBar {
        id:statusBar
        anchors.top: root.top
    }

    StackView {
        id: stackView
        width: parent.width
        height: parent.height - statusBar.height
        anchors {
            top: statusBar.bottom
            bottom: root.bottom
            left: root.left
            right: root.right
        }
        initialItem: "qrc:/MainScreen.qml"
    }


}
