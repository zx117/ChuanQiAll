import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import Widgets 1.0
import Themes 1.0
Rectangle{
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    property bool loadsetfile: false
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor

    Item {
        id:save
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            spacing: 10
            BaseTextSmall{
                font.bold: true
                text: "软件启动设置"
            }
            ExclusiveGroup { id: buttonGroup }
            BaseRadioButton{
                radioButtonText: "默认"
                exclusiveGroup: buttonGroup
                checked: true
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.checked = !parent.checked;
                        parent.forceActiveFocus()
                        loadsetfile=false
                    }
                }
            }
            BaseRadioButton{
                radioButtonText: "清空设置"
                exclusiveGroup: buttonGroup
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.checked = !parent.checked;
                        parent.forceActiveFocus()
                        loadsetfile=false
                    }
                }
            }
            BaseRadioButton{
                radioButtonText: "最近一次配置"
                exclusiveGroup: buttonGroup
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.checked = !parent.checked;
                        parent.forceActiveFocus()
                        loadsetfile=false
                    }
                }
            }
            BaseRadioButton{
                radioButtonText: "加载设置文件"
                exclusiveGroup: buttonGroup
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        parent.checked = !parent.checked;
                        parent.forceActiveFocus()
                        loadsetfile=true
                    }
                }
            }
            Row{
                spacing: 10
                BaseTextInput{
                    textBoxWidth:200
                    textBoxHeight: 30
                    textContent:""
                    enabled:loadsetfile
                }
                TextButton{
                    width: 70
                    height: 30
                    text: "浏览"
                    enabled:loadsetfile
                }
            }
            BaseTextSmall{
                font.bold: true
                text: "显示工具"
            }
            BaseCheckBox{
                checkText: "使用DejaView"
            }
            Row{
                width:parent.width/2
                height: 30
                spacing: 10
                BaseTextSmall{
                    text: "Max.DejaView file to keep(0=all)"
                    anchors.verticalCenter: parent.verticalCenter
                }
                BaseTextInput{
                    anchors.verticalCenter: parent.verticalCenter
                    textBoxHeight: parent.height
                    textBoxWidth: 200
                    textContent: "100"
                }

            }
            BaseTextSmall{
                font.bold: true
                text: "冻结缓冲区"
            }
            Row{
                width:parent.width/2
                height: 30
                spacing: 10
                BaseTextSmall{
                    text: "最小时长"
                    anchors.verticalCenter: parent.verticalCenter
                }
                BaseTextInput{
                    anchors.verticalCenter: parent.verticalCenter
                    textBoxHeight: parent.height
                    textBoxWidth: 200
                    textContent: "0"
                }
                BaseTextSmall{
                    text: "最大时长"
                    anchors.verticalCenter: parent.verticalCenter
                }
                BaseTextInput{
                    anchors.verticalCenter: parent.verticalCenter
                    textBoxHeight: parent.height
                    textBoxWidth: 200
                    textContent: "20"
                }
            }
            BaseTextSmall{
                text: "系统时间同步"
                font.bold: true
            }
            BaseCheckBox{
                checkText: "将采集时间与操作系统时间同步"
            }
            Row{
                width:parent.width/2
                height: 30
                spacing: 10
                BaseTextSmall{
                    text: "Synchronize every"
                    anchors.verticalCenter: parent.verticalCenter
                }
                BaseTextInput{
                    anchors.verticalCenter: parent.verticalCenter
                    textBoxHeight: parent.height
                    textBoxWidth: 200
                    textContent: "10"
                }
                ListModel{
                    id:listmodel
                    ListElement{text:"秒"}
                    ListElement{text:"分"}
                    ListElement{text:"时"}
                }

                BaseCombobox{
                    anchors.verticalCenter: parent.verticalCenter
                    combWidth: 50
                    combHeight: parent.height
                    model: listmodel
                }

                BaseTextSmall{
                    text: "after acpuisition start"
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
            BaseTextSmall{
                text: "MISCELLANEOUS SETTINGS"
                font.bold: true
            }
            BaseCheckBox{
                checkText: "Prevent OXYGEN from shutdown during measurement"
            }
            BaseCheckBox{
                checkText: "Suppress all confirmation prompts"
            }
            BaseCheckBox{
                checkText: "Record Compressed data file"
            }

        }
    }
}
