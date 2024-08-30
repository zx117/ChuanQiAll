import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import QtLocation 5.15
import Widgets 1.0
import Themes 1.0
Button{
    id:button
    property int buttonWidth:50
    property int buttonHeight: 50
    property int iconWidth
    property int iconHeight
    property int buttonRadius: 5
    property var dragTarget
    property int dragMinimumX: 0
    property int dragMaximumX: 0
    property bool isChecked: false
    property string iconSource:""
    property string toolTip: ""
    property string buttonText:""
    property bool toolVisible: true
    property ButtonStyle skin: SkinManager.currentSkin.iconButton
    ToolTip.visible: toolTip===""?false:hovered
    ToolTip.text: toolTip
    ToolTip.delay: 500

    width: buttonWidth
    height: buttonHeight

    Image {
        source: iconSource
        width: iconWidth
        height: iconHeight
        anchors.centerIn: parent


    }
    // icon.source:iconSource
    // icon.width: iconWidth
    // icon.height: iconHeight
    // icon.color:  isChecked?skin.iconPressedColor:skin.iconNormalColor
    smooth: true
    background: Rectangle{
        radius: buttonRadius
        width: buttonWidth
        height: buttonHeight
        color: isChecked?skin.buttonPressedColor:skin.buttonNormalColor
        border.color: skin.borderColor
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            isChecked=!isChecked
        }
    }

}
