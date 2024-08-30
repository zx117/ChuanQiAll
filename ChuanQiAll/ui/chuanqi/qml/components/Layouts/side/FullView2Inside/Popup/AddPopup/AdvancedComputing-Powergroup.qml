import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import MyTreeModel 1.0
import Widgets 1.0
import Themes 1.0
Item {
    anchors.fill: parent
    Item {
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            anchors.fill: parent
            Item {
                width: parent.width
                height: 30
                BaseTextSmall{
                    text: "创建新的电力测试组:"
                }
            }
        }
    }
}
