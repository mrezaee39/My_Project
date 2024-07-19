// ListViewDelegate.qml

import QtQuick 2.15
import QtQuick.Controls 2.15

Row {
    width: parent.width
    height: 40 // Adjust height as needed for each row
    spacing: 10 // Space between label and button 

    property bool enabledProperty: model.enabled
    property string textProperty: model.text

    Label {
        text: enabledProperty ? textProperty : ""
        width: parent.width * 0.6
        horizontalAlignment: Text.AlignHCenter
    }

    Button {
        text: enabledProperty ? "ON" : "OFF"
        onClicked: {
            enabledProperty = !enabledProperty
        }
    }
}
