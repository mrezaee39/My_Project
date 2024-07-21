import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 200
    height: 50

    property string time: "00:00:00"

    Text {
        id: timeLabel
        text: time
        anchors.centerIn: parent
        font.pixelSize: 24
        z: 1 // Ensure the frame is behind the component

    }

    // Update the displayed time when the property changes
    onTimeChanged: {
        timeLabel.text = time;
    }

    Rectangle {
        id: frame
        anchors.fill: clock
        anchors.margins: 8 // Adjust the margins to ensure the frame surrounds the component
        border.color: "blue"
        border.width: 2
        z: 0 // Ensure the frame is behind the component
    }
    Rectangle {
        id: framee
        anchors.fill: clock
        anchors.margins: 12 // Adjust the margins to ensure the frame surrounds the component
        border.color: "red"
        border.width: 2
        z: 0 // Ensure the frame is behind the component
    }
}