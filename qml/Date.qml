import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 200
    height: 50

    property string date_qml: "55/55/5555"

    Text {
        id: dateLabel
        text: date_qml
        anchors.centerIn: parent
        font.pixelSize: 24
        z : 1
    }


    Rectangle {
        id: dateFrame
        anchors.fill: dateLabel
        anchors.margins: -2 // Adjust the margins to ensure the frame surrounds the component
        border.color: "blue"
        border.width: 2
        z: 0 // Ensure the frame is behind the component
    }
    Rectangle {
        id: dateFramee
        anchors.fill: dateLabel
        anchors.margins: 0 // Adjust the margins to ensure the frame surrounds the component
        border.color: "red"
        border.width: 2
        z: 0 // Ensure the frame is behind the component
    }
}