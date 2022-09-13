import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.12
Item {
    property string city: ""
    property int speed
    property int chill
    property string direction;
    property int humidity;
    property int pressure;
    property int rising;
    property int visibility ;
    property string sunrise ;
    property string sunset ;

    property ListView model : ListView { id: list }

    Component.onCompleted: {

    }
    anchors{
        fill: parent
        leftMargin: 20
        rightMargin: 20
        bottomMargin: 50
    }
    Rectangle {
        id: topBar
        width: parent.width
        height: capitalName.height
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            margins: 10
        }
        color: "transparent"
        Text {
            id: capitalName
            anchors.centerIn: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.italic: false
            font.pixelSize: 32
            color: "white"
            text: city
        }
    }

    Row {
        id: row
        anchors {
            top: topBar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

        //column 1 - wind
        Item {
            id: col1
            width: parent.width / 3
            height: parent.height

            // titleWind
            Title {
                id: titleWind
                titleText: qsTr("WIND")

                anchors {
                    horizontalCenter: parent.horizontalCenter
                }
            }
            // infoWind
            Rectangle {
                id: infoWind
                width: titleWind.width
                height: parent.height - titleWind.height
                radius: 6
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#fcfc70" }
                    GradientStop { position: 1.0; color: "#ccc100" }
                }
                color: "#ffff00"
                border.color: "black"
                border.width: 3
                anchors{
                    topMargin: 18
                    top: titleWind.bottom
                    horizontalCenter: titleWind.horizontalCenter
                }

                Text {
                    id: textChill
                    width: 43
                    height: 28
                    text: qsTr("Chill:")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    font.pixelSize: 20
                    font.bold: true
                    anchors.leftMargin: 17
                    anchors.topMargin: 31
                }

                Text {
                    id: textDirection
                    width: 99
                    height: 28
                    text: qsTr("Direction:")
                    anchors.left: parent.left
                    anchors.top: textChill.bottom
                    font.pixelSize: 20
                    font.bold: true
                    anchors.topMargin: 77
                    anchors.leftMargin: 17
                }

                Text {
                    id: textSpeed
                    width: 99
                    height: 28
                    text: qsTr("Speed:")
                    anchors.left: parent.left
                    anchors.top: textDirection.bottom
                    font.pixelSize: 20
                    font.bold: true
                    anchors.topMargin: 77
                    anchors.leftMargin: 17
                }

                TextEdit {
                    id: textEditSpeed
                    width: 243
                    height: 41
                    anchors.left: parent.left
                    anchors.top: textSpeed.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    anchors.leftMargin: 17
                    font.bold: true
                    anchors.topMargin: 10
                    text: speed + " mph"
                }

                TextEdit {
                    id: textEditDirection
                    y: 184
                    width: 243
                    height: 41
                    anchors.left: parent.left
                    anchors.top: textDirection.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    anchors.topMargin: 10
                    anchors.leftMargin: 17
                    text: direction
                }

                TextEdit {
                    id: textEditChill
                    width: 243
                    height: 41
                    anchors.left: parent.left
                    anchors.top: textChill.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    anchors.topMargin: 10
                    anchors.leftMargin: 17
                    text: chill
                }


            }

        }

        //column 2 - atmosphere
        Item {
            id: col2
            width: parent.width / 3
            height: parent.height
            anchors {
                leftMargin: 20
                rightMargin: 20
                top: parent.top
            }

            // titleAtmosphere
            Title {
                id: titleAtmosphere
                titleText: qsTr("ATMOSPHERE")

                anchors {
                    top: parent.top
                    horizontalCenter: parent.horizontalCenter
                }
            }

            // infoAtmosphere
            Rectangle {
                id: infoAtmosphere
                width: titleAtmosphere.width
                height: parent.height - titleAtmosphere.height
                color: "#ffff00"
                radius: 6
                border.width: 3
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#fcfc70" }
                    GradientStop { position: 1.0; color: "#ccc100" }
                }
                anchors{
                    topMargin: 18
                    top: titleAtmosphere.bottom
                    horizontalCenter: titleAtmosphere.horizontalCenter
                }

                Text {
                    id: textHumidity
                    width: 97
                    height: 28
                    text: qsTr("Humidity:")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    font.pixelSize: 20
                    anchors.leftMargin: 17
                    anchors.topMargin: 5
                    font.bold: true
                }

                TextEdit {
                    id: textEditHumidity
                    x: -289
                    width: 243
                    height: 41
                    anchors.left: parent.left
                    anchors.top: textHumidity.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                    text: humidity
                }

                Text {
                    id: textPressure
                    width: 97
                    height: 28
                    text: qsTr("Pressure:")
                    anchors.left: parent.left
                    anchors.top: textEditHumidity.bottom
                    font.pixelSize: 20
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                }

                TextEdit {
                    id: textEditPressure
                    x: -289
                    width: 243
                    height: 41
                    anchors.left: parent.left
                    anchors.top: textPressure.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                    text: pressure
                }

                Text {
                    id: textRising
                    width: 97
                    height: 28
                    text: qsTr("Rising:")
                    anchors.left: parent.left
                    anchors.top: textEditPressure.bottom
                    font.pixelSize: 20
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                }

                TextEdit {
                    id: textEditRising
                    x: -289
                    width: 243
                    height: 41
                    anchors.left: parent.left
                    anchors.top: textRising.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                    text: rising
                }

                Text {
                    id: textVisibility
                    width: 97
                    height: 28
                    text: qsTr("Visibility:")
                    anchors.left: parent.left
                    anchors.top: textEditRising.bottom
                    font.pixelSize: 20
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                }

                TextEdit {
                    id: textEditVisibility
                    x: -289
                    width: 243
                    height: 41
                    anchors.left: parent.left
                    anchors.top: textVisibility.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                    text: visibility
                }

            }

        }

        //column 3 - Astronomy
        Item {
            id: col3
            width: parent.width / 3
            height: parent.height
            anchors {
                top: parent.top
                leftMargin: 20
                rightMargin: 20
            }

            // titleAstronomy
            Title {
                id: titleAstronomy
                titleText: qsTr("ASTRONOMY")
                anchors {
                    top: parent.top
                    horizontalCenter: parent.horizontalCenter
                }
            }

            // infoAstronomy
            Rectangle {
                id: infoAstronomy
                width: titleAstronomy.width
                height: parent.height - titleAstronomy.height
                color: "#ffff00"
                radius: 6
                border.width: 3
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#fcfc70" }
                    GradientStop { position: 1.0; color: "#ccc100" }
                }
                anchors{
                    topMargin: 18
                    top: titleAstronomy.bottom
                    horizontalCenter: titleAstronomy.horizontalCenter
                }

                Text {
                    id: textSunrise
                    x: -287
                    y: 5
                    width: 110
                    height: 36
                    text: qsTr("Sunrise:")
                    anchors.left: parent.left
                    anchors.top: parent.top
                    font.pixelSize: 30
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                }

                TextEdit {
                    id: textEditSunrise
                    x: -287
                    width: 243
                    height: 110
                    anchors.left: parent.left
                    anchors.top: textSunrise.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    anchors.topMargin: 10
                    anchors.leftMargin: 17
                    text: sunrise
                }

                Text {
                    id: textSunset
                    x: -281
                    y: 11
                    width: 104
                    height: 36
                    text: qsTr("Sunset:")
                    anchors.left: parent.left
                    anchors.top: textEditSunrise.bottom
                    font.pixelSize: 30
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                }

                TextEdit {
                    id: textEditSunset
                    x: -287
                    width: 243
                    height: 110
                    anchors.left: parent.left
                    anchors.top: textSunset.bottom
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    anchors.topMargin: 5
                    anchors.leftMargin: 17
                    text: sunset
                }

            }

        }
    }

}

