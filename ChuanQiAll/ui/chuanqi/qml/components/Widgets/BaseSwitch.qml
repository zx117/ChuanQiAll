import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.1
import Themes 1.0
import Widgets 1.0
Rectangle{
    property int switchWidth: 80
    property int switchHeight: 40
    property int switchButtonWidth: 30
    property int switchButtonHeight: 20
    property int switchRadius: 4
    property color switchColor: "#ffffff"
    property color onClickSwitchColor: "#005bb6"
    property color switchBorderColor: "#cfcfcf"
    //方块基础属性
    property int blockWidth: 20
    property int blockHeight: 20
    property int blockRadius: 4
    property color backGroundColor: "#f9f9f9"
    property color activeFocusBackGroundColor: "#0079da"
    property color borderColor: "#a0a0a0"
    property color activeFocusBorderColor: "#07467a"
    //文字属性
    property string switchText: "测试"
    property string fontFamily: "微软雅黑"
    property int fontPointSize: 12
    property color fontColor: "black"
    property bool ischecked: false
    width: switchWidth
    height: switchHeight
    color: "transparent"
    Switch {
        id: control
        anchors.verticalCenter: parent.verticalCenter
        indicator: Rectangle {
            id:switchrec
            anchors.centerIn: parent
            width: switchButtonWidth
            height: switchButtonHeight
            radius: switchRadius
            color: ischecked ? onClickSwitchColor : switchColor
            border.color: ischecked ? onClickSwitchColor : switchBorderColor
            //内部方块
            Rectangle {
                id : block
                width: blockWidth
                height: blockHeight
                radius: blockRadius
                color: activeFocus ? activeFocusBackGroundColor : backGroundColor
                border.color: activeFocus ? activeFocusBorderColor:borderColor

                //改变方块的位置
                NumberAnimation on x{
                    to: block.width/2
                    running: ischecked ? true : false
                    duration: 100
                }

                //改变方块的位置
                NumberAnimation on x{
                    to: 0
                    running: ischecked ? false : true
                    duration: 100
                }
            }
        }
        BaseTextSmall {
            id:switchtxt
            anchors.left: switchrec.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 10
            text: switchText
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                control.forceActiveFocus()
                block.forceActiveFocus()
                ischecked=!ischecked
            }
        }
    }
}








