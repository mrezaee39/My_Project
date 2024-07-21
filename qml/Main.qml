// qml/Main.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Smart Home")

    property string newLabel: "Hello, QML!"
    property int sig_Test: 43

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
            delegate: ListViewDelegate {
                enabledProperty: model.enabled
                textProperty: model.text
            }
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 20
        }

        Item {
            width: parent.width
            height: 20
        }

        InputRow {
            id: inputRow
            listView: labelListView
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            onButtonClicked: {
                myclass.onButtonClicked(sig_Test)
                if (inputRow.textField.text !== "") {
                    labelListView.model.append({"text": inputRow.textField.text, "enabled": true})
                    inputRow.textField.text = ""
                }
            }
        }
           
        Uhr {
            id: clock
            time: uhr.time
            anchors.top: parent.top
            anchors.left: parent.left
            z: 1
        }
    }
}
