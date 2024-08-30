import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Button{
    id:button
    //按钮基础属性
    property int buttonWidth:50
    property int buttonHeight: 50
    property int buttonRadius: 2
    property string buttonText:""
    property bool isChecked: false
    property ButtonStyle skin: SkinManager.currentSkin.textButton
    width: buttonWidth
    height: buttonHeight

    BaseTextModerate {
        id: text
        text: buttonText
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle{
        radius: buttonRadius
        anchors.fill: parent
        color: isChecked?skin.buttonPressedColor:skin.buttonNormalColor
        border.color: skin.borderColor
    }

    onClicked: {
        isChecked=!isChecked
    }
}
