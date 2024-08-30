import QtQuick 2.15
import QtQuick.Controls 2.5
import Themes 1.0
FocusScope {
    //文本基础属性设置
    property int textBoxWidth:  100
    property int textBoxHeight: 20
    property string textContent: ""
    property color borderColor: "#a4a4a4"
    property color activeFocusBorderColor: "#005bb6"
    property FontProperties fontskin: SkinManager?SkinManager.currentFont.fontproperty:0
    property FontProperties fontcol: SkinManager?SkinManager.currentSkin.fontproperty:0
    id: cusinput
    width:  textBoxWidth
    height: textBoxHeight
    signal textChangel(string txt)
    Item {
        id: rec
        anchors.fill: parent
        //绘制背景色
        Rectangle{
            width: parent.width
            height: parent.height
            color: tinput.activeFocus?"#c0cad4":"transparent"
            opacity: tinput.activeFocus?0.7:1
        }
        //绘制左边框
        Rectangle {
            x: 0
            y: 0
            width: 1
            height: parent.height/3
            color: tinput.activeFocus?activeFocusBorderColor:borderColor
            anchors.bottom: down.top

        }

        // 绘制右边框
        Rectangle {
            x: parent.width - 1
            y: 0
            width: 1
            height: parent.height/3
            color: tinput.activeFocus?activeFocusBorderColor:borderColor
            anchors.bottom: down.top

        }

        // 绘制下边框
        Rectangle {
            id:down
            x: 0
            y: parent.height - 1
            width: parent.width
            height: 1
            color: tinput.activeFocus?activeFocusBorderColor:borderColor

        }
        TextInput {
            id: tinput
            clip: true
            anchors.fill: parent
            focus: true
            color: fontcol.fontColor

            font.family: fontcol.fontFamily
            font.pointSize: fontskin.level3FontSize
            verticalAlignment: Qt.AlignVCenter
            text: textContent
            leftPadding: 10
            wrapMode: Text.NoWrap

            onEditingFinished: {
                textChangel(tinput.text)
            }
        }
    }
}
