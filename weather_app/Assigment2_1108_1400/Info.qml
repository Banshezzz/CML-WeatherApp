import QtQuick 2.0

Rectangle {
    property string titleText: ""

    id: title
    anchors.horizontalCenter: parent.horizontalCenter
    width: parent.width
    height: 53
    color: "#000000"
    border.color: "#ccc100"
    border.width: 3
    Text {
        width: 108
        height: 47
        color: "#ccc100"
        text: titleText
        anchors.fill: parent
        font.pixelSize: 22
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.italic: false
    }
}
