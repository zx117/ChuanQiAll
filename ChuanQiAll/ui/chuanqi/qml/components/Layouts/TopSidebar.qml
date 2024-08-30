import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
import "qrc:/qml/images"

ToolBar{
    id:topToolBar
    property RectangelStyle skinTop :SkinManager.currentSkin.topbottomRectangel
    property string iconName: "qrc:/qml/images/RightIcon/menu.png"
    property string textValue: "运行状态栏"

    background: Rectangle {
        color: skinTop.backgroundColor
    }
    Layout.fillWidth: true
    height: 50

    RowLayout {
        anchors.centerIn: parent
        height: 50
        spacing: 10
        Item {
            height: parent.height

        }

        RowLayout
        {
            spacing: 5
            Image {
                id: img
                Layout.preferredWidth:40
                Layout.preferredHeight: 40
                source: iconName
            }
            BaseTextModerate {
                text: textValue
                color: "white"
            }
        }

        Item {
            height: parent.height

        }
    }

    function upInformation(newtextValue,newiconName){
        iconName=newiconName
        textValue=newtextValue
    }

}
