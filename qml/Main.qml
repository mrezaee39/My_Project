

import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello QML")

   Label {
        id: label 
        text: "Hello World"
        anchors.centerIn: parent
    }

    Button {
        id: button // give the button an id
        text: "Click me!"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        
        onClicked: {  
            myclass.onButtonClicked() 
            if (label.text === "Hello World") {
                label.text = "Hello User";
            } else {
                label.text = "Hello World";
        }   }
    }
}


