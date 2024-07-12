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
                ListElement { text: "!!!" }
            }
            delegate: Label {
                text: model.text
                width: parent.width // Ensures each label takes the full width of the ListView
                horizontalAlignment: Text.AlignHCenter // Centers the text horizontally
            }
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
        }

        Item {
            width: parent.width
            height: 20 // Space between ListView and Row
        }

        Row {
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom // Anchors the Row to the bottom of the parent
            anchors.bottomMargin: 20 // Optional: adds some margin from the bottom

            TextField {
                id: inputField
                placeholderText: "---"
                width: parent.width * 0.7
                anchors.verticalCenter: parent.verticalCenter
            }

            Button {
                id: button
                text: "Submit!"
                anchors.verticalCenter: parent.verticalCenter

                onClicked: {
                    if (inputField.text !== "") {
                        labelListView.model.append({"text": inputField.text})
                        inputField.text = ""
                    }
                }
            }
        }
    }
}
