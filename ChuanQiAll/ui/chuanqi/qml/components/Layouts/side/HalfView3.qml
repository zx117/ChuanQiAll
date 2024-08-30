import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Rectangle {
    id: halfview1
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    anchors.fill: parent
    Column {
        width: parent.width/5
        height: parent.height
        spacing: 0
        Rectangle {
            height: 30
            width: parent.width
            color: sideBarInterface.headBackColor
            border.color: sideBarInterface.borderColor
            BaseTextModerate {
                text: "当前软件信息"
                font.bold: true
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
        Item{
            width: parent.width-10
            height: parent.height-30
            anchors.horizontalCenter: parent.horizontalCenter
            Column{
                spacing: 10
                anchors.fill: parent
                Item {
                    width: parent.width
                    height: 5

                }
                BaseTextSmall{
                    text: "chuanqidemo 1.0"
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "创建日期"
                    }
                    BaseTextSmall{
                        text: "xxxxxxxxxxx"
                    }
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "修订"
                    }
                    BaseTextSmall{
                        text: "xxxxxxxxxxx"
                    }
                }
                Rectangle{
                    width: parent.width
                    height: 1
                    color: "#585858"
                }
                BaseTextSmall{
                    text: "注册信息"
                    font.bold: true
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "版本号"
                    }
                    BaseTextSmall{
                        text: "xxxxxxxxxxx"
                    }
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "许可文件"
                    }
                    BaseTextSmall{
                        text: "xxxxxxxxxxx"
                    }
                }
                Rectangle{
                    width: parent.width
                    height: 1
                    color: "#585858"
                }
                BaseTextSmall{
                    text: "远程控制"
                    font.bold: true
                }
                BaseTextSmall{
                    text: "SCPI over Ethernet"
                }
                BaseTextSmall{
                    text: "XCPI over Ethernet"
                }
                Rectangle{
                    width: parent.width
                    height: 1
                    color: "#585858"
                }
                BaseTextSmall{
                    text: "FEEDBACK"
                    font.bold: true
                }
                BaseTextSmall{
                    wrapMode: Text.Wrap
                    width: parent.width
                    text: "You are invited to scan or click the QR tag to givefeedback for 传麒"
                }
                Item {
                    width: parent.width
                    height: 200
                    Image {
                        id: company
                        width: parent.height
                        height: parent.height
                        anchors.horizontalCenter:parent.horizontalCenter
                        source: "qrc:/qml/images/RightIcon/chuanqi.png"
                    }
                }
            }

        }
    }
}

