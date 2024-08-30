import QtQuick 2.15
import QtQuick.Controls 1.4
import Themes 1.0
import Widgets 1.0

Rectangle {
    id:radio
    //外部矩形
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    property int radioWidth: 200
    property int radioHeight: 40
    property color radioBackColor: sideBarInterface.menuBackColor
    property color radioBorderColor: sideBarInterface.borderColor
    property color coreColor: "#005bb6"
    property bool checked: false
    //内部圆形
    property int cirWidth: 20
    property int cirHeight: 20
    property ExclusiveGroup exclusiveGroup: null //对外开放一个ExclusiveGroup接口，用于绑定同个组
    property string radioButtonText: ""

    width: radioWidth
    height: radioHeight
    color: radioBackColor
    border.color: radioBorderColor

    layer.enabled: true
    layer.smooth: true

    onExclusiveGroupChanged: {
        if (exclusiveGroup) {
            exclusiveGroup.bindCheckable(radio)
        }
    }

    onCheckedChanged: {
        checked ? radioBackground.color="#357abe":radioBackground.color="transparent"
    }

    Rectangle{
        id:radioBackground
        anchors.fill: parent
        color: "#357abe"
        opacity: radio.activeFocus? 0.3:0
    }
    // 内部的圆形
    Rectangle {
        id:cir
        anchors.leftMargin: 10
        width: cirWidth
        height: cirHeight
        radius: width / 2
        border.color: "black"
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        Rectangle{
            anchors.centerIn: parent
            width: parent.width/2
            height: parent.height/2
            radius: width / 2
            color: radio.checked ? coreColor : "white"
        }
    }

    // 文本标签
    BaseTextSmall {
        text: radioButtonText
        anchors.left: parent.left
        anchors.leftMargin: 40
        anchors.verticalCenter: parent.verticalCenter
    }

    // 处理鼠标点击事件
    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.checked = !parent.checked;
            radio.forceActiveFocus()
        }
    }
}
