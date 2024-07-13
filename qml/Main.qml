import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Smart Home")

    property string newLabel: "Hello, QML!"

    Column {
        width: parent.width
        height: parent.height

        ListView {
            id: labelListView
            width: parent.width * 0.8
            height: 200
            model: ListModel {
                ListElement { text: "task 1"; enabled: true }
            }
            delegate: Row {
                width: parent.width
                height: 40 // Adjust height as needed for each row
                spacing: 10 // Space between label and button

                Label {
                    text: model.enabled ? model.text : ""
                    width: parent.width * 0.6
                    horizontalAlignment: Text.AlignHCenter
                }

                Button {
                    text: model.enabled ? "ON" : "OFF"
                    onClicked: {
                        model.enabled = !model.enabled
                    }
                }
            }
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
        }

        Item {
            width: parent.width
            height: 20
        }

        Row {
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20

            TextField {
                id: inputField
                placeholderText: "---"
                width: parent.width * 0.7
                anchors.verticalCenter: parent.verticalCenter
                Keys.onReleased: {
                    if (event.key === Qt.Key_Enter || event.key === Qt.Key_Return) {
                        if (inputField.text !== "") {
                            labelListView.model.append({"text": inputField.text, "enabled": true})
                            inputField.text = ""
                        }
                    }
                }
            }

            Button {
                id: button
                text: "Submit!"
                anchors.verticalCenter: parent.verticalCenter

                onClicked: {
                    if (inputField.text !== "") {
                        labelListView.model.append({"text": inputField.text, "enabled": true})
                        inputField.text = ""
                    }
                }
            }
        }
    }
}
