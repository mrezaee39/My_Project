import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello QML")

    Text {
        text: qsTr("Hello, World!")
        anchors.centerIn: parent
    }
    /*
   Add here a button. the name of this button is generated
*/
    
}
