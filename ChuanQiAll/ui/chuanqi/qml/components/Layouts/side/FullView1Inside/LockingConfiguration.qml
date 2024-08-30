import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
import MyInterface 1.0
Rectangle{
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    anchors.fill: parent
    Item {
        id:setif
        width: parent.width-20
        height: parent.height
        anchors.centerIn: parent
        Column{
            spacing: 15
            Layout.fillHeight: true
            Layout.fillWidth: true
            BaseTextSmall{
                text: "锁定配置"
                font.bold: true
            }
            BaseCheckBox{
                checkText: "通道列表"
            }
            BaseCheckBox{
                checkText: "停止测试"
            }
            BaseCheckBox{
                checkText: "测试界面编辑"
            }
            BaseCheckBox{
                checkText: "保存设置"
            }
            BaseCheckBox{
                checkText: "存储设置"
            }
            TextButton{
                buttonWidth: 150
                buttonHeight: 30
                buttonRadius: 3
                buttonText: "设置/修改密码"
            }
            TextButton{
                buttonWidth: 150
                buttonHeight: 30
                buttonRadius: 3
                buttonText: "解除锁定"
            }
            TextButton{
                buttonWidth: 150
                buttonHeight: 30
                buttonRadius: 3
                buttonText: "锁定"
            }
            Row{
                BaseTextSmall{
                    text: "当前状态:"
                }
                BaseTextSmall{
                    text: "不允许"
                }
            }
        }
    }
}
