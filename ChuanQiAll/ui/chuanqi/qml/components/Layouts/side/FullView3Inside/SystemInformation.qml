import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
import Widgets 1.0
import Themes 1.0

Rectangle{
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    Item {
        id:setif
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Row{
            spacing: 10
            Column{
                spacing: 10
                width: setif.width/4
                BaseTextSmall{
                    text: "软件"
                    font.bold: true
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "创建日期"
                    }
                    BaseTextSmall{
                        text: "xxxx-xx-xx"
                    }
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "修订"
                    }
                    BaseTextSmall{

                        text: "xxxxx"
                    }
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "代码"
                    }
                    BaseTextSmall{
                        text: "xxxxx"
                    }
                }
                BaseTextSmall{
                    text: "框架"
                    font.bold: true
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "Qt"
                    }
                    BaseTextSmall{
                        text: "5.15.2"
                    }
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "板卡名称"
                    }
                    BaseTextSmall{
                        text: ""
                    }
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "驱动信息"
                    }
                    BaseTextSmall{
                        text: ""
                    }
                }
                BaseTextSmall{
                    text: "注册信息"
                    font.bold: true
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "软件安装日期"
                    }
                    BaseTextSmall{
                        text: "xxxx-xx-xx"
                    }
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "许可文件"
                    }
                    BaseTextSmall{
                        text: "xxxxx"
                    }
                }
                Row{
                    spacing: 5
                    BaseTextSmall{
                        width: 100
                        text: "序列号"
                    }
                    BaseTextSmall{
                        text: "xxxxx"
                    }
                }

            }
            Column{
                spacing: 10
                BaseTextSmall{
                    text: "错误与警告"
                    font.bold: true
                }
                Rectangle{
                    width: setif.width*3/4
                    height: setif.height-30

                }
            }
        }
    }
}
