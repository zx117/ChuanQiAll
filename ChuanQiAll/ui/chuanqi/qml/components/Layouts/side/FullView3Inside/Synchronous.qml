import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
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
        Column{
            spacing: 10
            Row{
                spacing: 10
                BaseTextSmall{
                    text: "主时钟"
                }
                ListModel {
                    id: simhw
                    ListElement { text: "本地时间" }
                }
                BaseCombobox{
                    width: 300
                    model: simhw
                }
            }

            BaseCheckBox{
                checkText: "自动"
            }
            BaseTextSmall{
                text: "设置"
                font.bold: true
            }
            BaseSwitch{
                switchText: "允许NET"
            }
            BaseSwitch{
                switchText: "允许锁定控制"
            }
            BaseTextSmall{
                text: "TRIONET设置"
                font.bold: true
            }
            Row{
                spacing: 10
                BaseRadioButton{
                    radioButtonText: "禁止自动锁定"
                }
                BaseTextSmall{
                    anchors.verticalCenter: parent.verticalCenter
                    text: "手动进行锁定操作"
                }
            }
            Row{
                spacing: 10
                BaseRadioButton{
                    radioButtonText: "自动通过USB锁定"
                }
                BaseTextSmall{
                    anchors.verticalCenter: parent.verticalCenter
                    text: "自动锁定通过USB链接的设备"
                }
            }
            Row{
                spacing: 10
                BaseRadioButton{
                    radioButtonText: "自动锁定所有"
                }
                BaseTextSmall{
                    anchors.verticalCenter: parent.verticalCenter
                    text: "自动锁定所有发现的设备"
                }
            }
            BaseTextSmall{
                text: "网络接口"
                font.bold: true
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 50
                    text: "接口名称"
                }
                ListModel {
                    id: ent
                    ListElement { text: "off" }
                    ListElement { text: "Auto" }
                }
                BaseCombobox{
                    combWidth: 100
                    model: ent
                    currentIndex: 0
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 50
                    text: "IP地址"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 50
                    text: "子网掩码"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
        }
    }
}
