import QtQuick 2.0
import QtQuick.Layouts 1.0

Rectangle {
    anchors.fill: parent
    color: "transparent"

    Text {
        id: appTitle
        text: "Weather Infomation"
        font.pixelSize: 48
        font.bold: true
        anchors {
            top: parent.bottom
            horizontalCenter: parent.horizontalCenter
            bottomMargin: 20
        }
    }

    GridView {
        id: grid
        width: parent.width
        height: parent.height - appTitle.height
        anchors {
            top: appTitle.bottom
            horizontalCenter: parent.horizontalCenter
            fill: parent
        }
        cellHeight: 100
        cellWidth: width/2

        clip: true
        model: cityModel
        delegate: cityDelegate
    }

    Component {
        id: cityDelegate
        Item {
            width: grid.cellWidth
            height: grid.cellHeight
            Rectangle {
                width: grid.cellWidth - 100
                height: grid.cellHeight - 20
                anchors.centerIn: parent
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "white" }
                    GradientStop { position: 0.33; color: "yellow" }
                    GradientStop { position: 1.0; color: "darkOrange" }
                }

                Text {
                    font.pixelSize: 28
                    anchors.centerIn: parent
                    color: "black"
                    text: countryName
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        stackView.push( "qrc:/InfoScreen.qml",
                                       {
                                           "city" : countryName,
                                           "speed" : speed,
                                           "chill" : chill,
                                           "direction" : direction,
                                           "humidity" : humidity,
                                           "pressure" : pressure,
                                           "rising" : rising,
                                           "visibility" : visibility,
                                           "sunrise" : speed,
                                           "sunset" : sunset

                                       } );
                    }
                }
            }
        }
    }
}

