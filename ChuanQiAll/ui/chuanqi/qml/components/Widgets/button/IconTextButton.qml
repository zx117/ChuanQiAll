import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Button{
    id:button
    property int buttonWidth:50
    property int buttonHeight: 50
    property int iconWidth: 32
    property int iconHeight: 32
    property int buttonRadius: 5
    property int itFontPointSize:20
    property string itFontColor: "black"
    property string itFontFamily: "微软雅黑"
    property string iconSource:""
    property string toolTip: ""
    property string buttonColor: "#efefef"
    property string iconColor: "#5c5c5c"
    property string buttonLeftText:""
    property string buttonButtomText:""
    property bool isChecked: false
    property int crossmargin: 10
    property int verticalmargin: 10

    width: buttonWidth
    height: buttonHeight
    contentItem: Item {
        id:item
        anchors.fill: parent
        anchors.centerIn: parent // 将 Item 放置在按钮的中心
        Image {
            id:image
            source: iconSource
            width: iconWidth
            height: iconHeight
            anchors.horizontalCenter: parent.horizontalCenter // 图标水平居中
            anchors.verticalCenter: parent.verticalCenter // 图标垂直居中
        }

        BaseTextModerate {
            text: buttonLeftText
            anchors.left:image.right // 文本位于图标左边
            anchors.verticalCenter: parent.verticalCenter // 文本垂直居中
            anchors.leftMargin: crossmargin
        }

        BaseTextModerate {
            text: buttonButtomText
            anchors.top: image.bottom // 文本位于图标下方
            anchors.horizontalCenter: parent.horizontalCenter // 文本水平居中
            anchors.topMargin: verticalmargin

        }

    }

    states: [
        State {
            name: "normal"
            when: button.pressed
            PropertyChanges {
                target: button
                iconColor: "#5c5c5c"
                buttonColor: "#efefef"

            }
        },
        State {
            name: "PressedState"
            when: button.pressed
            PropertyChanges {
                target: button
                buttonColor: "#cfcfcf"
                iconColor: "#005bb6"

            }
        }
    ]
    // 处理按钮点击事件
    onClicked: {
        isChecked=!isChecked
        button.state = isChecked?"PressedState":"normal"
    }

}
