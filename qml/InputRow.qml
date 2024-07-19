// qml/InputRow.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Row {
    id: root
    width: parent ? parent.width : 0

    property alias textField: inputField
    property ListView listView
    signal buttonClicked()

    TextField {
        id: inputField
        placeholderText: "---"
        width: parent ? parent.width * 0.7 : 0
        anchors.verticalCenter: parent.verticalCenter
        Keys.onReleased: {
            if ((event.key === Qt.Key_Enter || event.key === Qt.Key_Return) && inputField.text !== "") {
                listView.model.append({"text": inputField.text, "enabled": true})
                inputField.text = ""
            }
        }
    }

    Button {
        text: "Submit!"
        anchors.verticalCenter: parent.verticalCenter

        onClicked: {
            if (inputField.text !== "") {
                listView.model.append({"text": inputField.text, "enabled": true})
                inputField.text = ""
            }
            buttonClicked()
        }
    }
}
