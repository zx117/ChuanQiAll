import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Rectangle {
    id: halfview1
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    signal jumptoheaderfilewindow()
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    anchors.fill: parent

    Column {
        id:half
        width: halfview1.width/5
        height: halfview1.height
        spacing: 0
        Rectangle {
            id:head
            height: 30
            width: half.width
            color: sideBarInterface.headBackColor
            border.color: sideBarInterface.borderColor
            BaseTextModerate {
                text: "当前文件存储信息"
                font.bold: true
                width: parent.width
                height: parent.height
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }
        Item{
            width: half.width-10
            height: half.height-30
            anchors.horizontalCenter: parent.horizontalCenter
            Column{
                spacing: 10
                anchors.fill: parent
                Item {
                    height: 5
                    width: parent.width
                }
                BaseTextSmall{
                    font.bold: true
                    text: "数据存储"
                }
                BaseTextSmall{
                    text: "文件名预览:"
                }
                BaseTextSmall{
                    text: "xxxxxxxxxxxx"
                }
                Rectangle{
                    width: parent.width
                    height: 1
                    color: "#a4a4a4"
                }
                BaseTextSmall{
                    font.bold: true
                    text: "存储记录"
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "文件名:"
                    }
                    BaseTextSmall{
                        text: "xxxxxxx"
                    }
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "文件大小"
                    }
                    BaseTextSmall{
                        text: "xxxxxxx"
                    }
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "存储开始时间"
                    }
                    BaseTextSmall{
                        text: "xxxxxxx"
                    }
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "时区"
                    }
                    BaseTextSmall{
                        text: "xxxxxxx"
                    }
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        text: "持续时间"
                    }
                    BaseTextSmall{
                        text: "xxxxxxx"
                    }
                }
                Rectangle{
                    width: parent.width
                    height: 1
                    color: "#a4a4a4"
                }
                Item{
                    width: parent.width
                    height: 30
                    BaseTextSmall{
                        font.bold: true
                        text: "数据头"
                    }
                    IconButton{
                        buttonWidth: 30
                        buttonHeight:20
                        buttonRadius:2
                        iconWidth: 15
                        iconHeight: 15
                        anchors.right: parent.right
                        skin: SkinManager.currentSkin.screeniconButton
                        iconSource:"qrc:/qml/images/RightIcon/set.png"
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                halfview1.jumptoheaderfilewindow()
                            }
                        }
                    }

                }
            }
        }
    }
}

