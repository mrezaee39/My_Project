import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 200
    height: 50

    property string time: "00/00/0000"

    Text {
        id: dateLabel
        text: time
        anchors.centerIn: parent
        font.pixelSize: 24
    }

    // Update the displayed time when the property changes
    onTimeChanged: {
        timeLabel.text = time;
    }
}