import QtQuick 2.0
import QtQml 2.2

Rectangle {

    property var locale: Qt.locale()
    property date currentDate: new Date()
    property date currentTime
    property string dateString
    property string timeString

    anchors {
        top: parent.top
        left: parent.left
        right: parent.right
    }
    color: "transparent"
    width: parent.width
    height: dateTime.height + time.height
    Image {
        id: backButton
        height: parent.height * .7
        width: height
        anchors {
            left: parent.left
            leftMargin: 20
            verticalCenter: parent.verticalCenter
        }

        source: "qrc:/images/back.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                var d = stackView.depth
                if(d > 1)
                    stackView.pop()
            }
        }
    }

    Text {
        id: dateTime
        text: dateString
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }
        color: "white"
        font.pixelSize: 32
    }

    Text {
        id: time
        text: timeString
        anchors {
            top: dateTime.bottom
            horizontalCenter: dateTime.horizontalCenter
        }
        color: "white"
        font.pixelSize: 32
    }

    Component.onCompleted: {
        dateString = currentDate.toLocaleDateString(locale, Locale.LongFormat);
        dateTime.text = dateString;
        timeString = currentTime.toLocaleTimeString(locale, "hh:mm:ss A");
        time.text = timeString
        timer.start();
    }

    Timer {
        id: timer
        interval: 1000;
        running: true;
        repeat: true
        onTriggered: {
            currentTime = new Date();
            time.text = currentTime.toLocaleTimeString(locale, "hh:mm:ss A");
        }
    }
}
