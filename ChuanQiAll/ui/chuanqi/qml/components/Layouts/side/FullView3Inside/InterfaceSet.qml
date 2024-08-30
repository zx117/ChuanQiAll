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
    MyInterface{
        id:mif
    }
    Item {
        id:setif
        width: parent.width-20
        height: parent.height
        anchors.centerIn: parent
        Row{
            anchors.fill: parent
            spacing: 20
            Column{
                width: parent.width/2
                height: parent.height
                spacing: 10
                BaseTextSmall{
                    text: "语言"
                }
                ListModel {
                    id: translate
                    ListElement { text: "zn-(chinese)" }
                }
                BaseCombobox{
                    width: parent.width*2/3
                    model: translate
                }
                BaseTextSmall{
                    text: "时钟设置"
                }
                BaseCheckBox{
                    checkText: "使用UTC时间"
                }
                ListModel {
                    id: timestyle
                    ListElement { text: "小时:分:秒" }
                    ListElement { text: "日期_小时:分:秒" }
                }
                BaseCombobox{
                    width: parent.width*2/3
                    model: timestyle
                }
                BaseTextSmall{
                    text: "UI选项"
                }
                BaseCheckBox{
                    checkText: "全屏"
                }
                BaseTextSmall{
                    text: "界面风格"
                }
                ListModel {
                    id: style
                    ListElement { text: "whitestyle" }
                    ListElement { text: "blackstyle" }
                }
                BaseCombobox{
                    model: style
                    currentIndex: 0
                    width: parent.width*2/3
                    onCurrentIndexChanged: {
                        var selectedTheme = model.get(currentIndex).text
                        if (selectedTheme === "whitestyle") {
                            // 设置白色主题
                            SkinManager.currentSkin=SkinWhite
                        } else if (selectedTheme === "blackstyle") {
                            // 设置黑色主题
                            SkinManager.currentSkin=SkinBlack

                        }
                    }
                }
                ListModel {
                    id: fontsize
                    ListElement { text: "大" }
                    ListElement { text: "适中" }
                    ListElement { text: "小" }
                }
                BaseTextSmall{
                    text: "字体大小"
                }
                BaseCombobox{
                    model: fontsize
                    currentIndex: 1
                    width: parent.width*2/3
                    onCurrentIndexChanged: {
                        var selectedTheme = model.get(currentIndex).text
                        if (selectedTheme === "大") {
                            SkinManager.currentFont=SkinLargeFont
                        } else if (selectedTheme === "适中") {
                            SkinManager.currentFont=SkinModerateFont
                        }
                        else if (selectedTheme === "小") {
                            SkinManager.currentFont=SkinSmallFont
                        }
                    }

                }
                BaseTextSmall{
                    text: "工具栏位置"
                }
                BaseCheckBox{
                    checkText: "居左"
                }
                BaseTextSmall{
                    text: "通道设置"
                }
                BaseCheckBox{
                    checkText: "灰色区域/字体不可操作"
                }
                BaseTextSmall{
                    text: "重置自定义项"
                }
                Row{
                    width: parent.width/3
                    height: 25
                    spacing: 10
                    TextButton{
                        buttonWidth: parent.width/2-5
                        buttonHeight: parent.height
                        buttonText: "侧工具栏顺序"
                    }
                    TextButton{
                        buttonHeight: parent.height
                        buttonWidth: parent.width/2-5
                        buttonText: "表格列宽"
                    }
                }

            }

            Column{
                spacing: 20
                width: parent.width/2
                height: parent.height
                BaseTextSmall{
                    text: "图形选项API"
                }
                Item {
                    width: parent.width
                    height: 400
                    ListModel {
                        id: interfaceModel
                        ListElement { txt: "Automatic"}
                        ListElement { txt: "OpenGL"}
                        ListElement { txt: "OpenGL RHI"}
                        ListElement { txt: "Direct3D11 RHI"}
                        ListElement { txt: "Vulkan RHI"}
                        ListElement { txt: "OpenVG"}
                        ListElement { txt: "Direct3D 9 ANGLE"}
                        ListElement { txt: "Direct3D 11 ANGLE"}
                    }
                    ExclusiveGroup { id: buttonGroup }
                    ListView {
                        id: listView
                        currentIndex: 0
                        anchors.fill: parent
                        model: interfaceModel
                        interactive: false
                        spacing:10
                        delegate:BaseRadioButton{
                            id:radio
                            radioWidth: parent.width*2/3
                            radioHeight: 40
                            radioButtonText:txt
                            exclusiveGroup: buttonGroup
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    radio.checked = !radio.checked;
                                    radio.forceActiveFocus()
                                    mif.renderInterface(model.txt)
                                }
                            }
                        }
                    }
                }
                BaseCheckBox{
                    checkText:"显示FPS覆盖"
                }
            }
        }

    }
}
