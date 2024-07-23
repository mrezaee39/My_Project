import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 200
    height: 50

    property string time_qml: "00:00:00"

    Text {
        id: timeLabel
        text: time_qml
        anchors.centerIn: parent
        font.pixelSize: 24
        z: 1 // Ensure the frame is behind the component

    }

}