import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
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
                    text: "创建新的机械效率计算通道"
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    anchors.fill: parent
                    spacing: 10
                    BaseTextSmall{
                        anchors.verticalCenter: parent.verticalCenter
                        text: "名称"
                    }
                    BaseTextInput{
                        textBoxWidth:200
                        textBoxHeight: 20
                        anchors.verticalCenter: parent.verticalCenter
                        textContent: "机械效率图通道"
                    }
                }
            }
        }
    }
}
