import QtQuick 2.15
import QtQuick.Controls 2.15
import Widgets 1.0
import Themes 1.0
Rectangle {
    id: halfview4
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    anchors.fill: parent

    function upAppInterFace(value) {
        if(value>=0)
        {
            AppHost.loadApp(value,appset,"AppSet")
        }

    }

    Column {
        id:half
        width: halfview4.width/5
        height: halfview4.height
        spacing: 0
        Rectangle {
            id:head
            height: 30
            width: half.width
            color: sideBarInterface.headBackColor
            border.color: sideBarInterface.borderColor
            BaseTextModerate {
                text: "当前App配置信息"
                font.bold: true
                width: parent.width
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }
        Flickable {
            width: half.width
            height: half.height-30
            contentHeight: half.height-30
            clip: true
            boundsBehavior: Flickable.StopAtBounds
            Column{
                width: parent.width
                height: parent.height
                Item {
                    id: appset
                    width: parent.width
                    height: parent.height

                }
            }
        }
    }
}
