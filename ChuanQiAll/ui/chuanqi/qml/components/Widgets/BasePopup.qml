import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.2
Popup{
    parent: Overlay.overlay
    width:200
    height:20
    background: Rectangle{
        color:"#585858"
        radius: 6
        border.color: "#585858"
        opacity: 0.5
    }

    Text {
        text: qsTr("错误")
        color: "black"
        font.bold: true
        font.pointSize: 10
        anchors.left: parent.Left
        anchors.verticalCenter:parent.verticalCenter
    }


}
