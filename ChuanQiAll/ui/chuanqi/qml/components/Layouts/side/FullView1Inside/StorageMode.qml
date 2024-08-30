import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Widgets 1.0
import Themes 1.0
import MyTreeModel 1.0
import MyListModel 1.0
import MyTableModel 1.0

Rectangle{
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    property FontProperties fontskin: SkinManager.currentFont.fontproperty
    property FontProperties fontcol: SkinManager.currentSkin.fontproperty
    property bool dfile: false
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    Item {
        id:setif
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            Row
            {
                spacing: 5
                BaseTextSmall{
                    anchors.verticalCenter: parent.verticalCenter
                    text: "多文件保存模式"
                }
                BaseSwitch{
                    id:files
                    anchors.verticalCenter: parent.verticalCenter
                    switchText: ""
                    onIscheckedChanged: {
                        dfile=files.ischecked
                    }
                }
            }
            Column{
                spacing: 10
                Row{
                    spacing: 10
                    ExclusiveGroup { id: buttonGroup }
                    BaseRadioButton{
                        radioButtonText: "以文件大小分割文件"
                        exclusiveGroup: buttonGroup
                        enabled: dfile
                    }
                    BaseRadioButton{
                        radioButtonText: "以时间分割文件"
                        exclusiveGroup: buttonGroup
                        enabled: dfile
                    }
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        width:100
                        text: "文件大小(MB)"
                    }
                    BaseTextInput{
                        textContent: "500"
                    }
                }
                Row{
                    spacing: 10
                    BaseTextSmall{
                        width:100
                        text: "存储间隔(分钟)"
                    }
                    BaseTextInput{
                        textContent: "60"
                    }
                }
            }
        }
    }


}
