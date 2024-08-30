import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Rectangle{
    id:remotecontrol
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    property bool remcon: false
    property bool scpi: false
    property bool xcp: false
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    Item {
        id:remote
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            spacing: 10
            BaseSwitch{
                id:remconbs
                switchText: "允许远程控制"
                onIscheckedChanged: {
                    remcon=remconbs.ischecked
                }
            }
            Row{
                spacing: 10
                Column{
                    spacing: 10
                    BaseTextSmall{
                        font.bold: true
                        text: "激活协议"
                    }
                    Rectangle{
                        width: remote.width/2
                        height: 150
                        color: "#a4a4a4"
                        enabled: remcon
                        Item {
                            width: parent.width-20
                            height: parent.height-20
                            anchors.centerIn: parent
                            Column{
                                BaseSwitch{
                                    id:scpibs
                                    switchText: "SCPI overEthernet"
                                    onIscheckedChanged: {
                                        scpi=scpibs.ischecked
                                    }
                                }
                                BaseTextSmall{
                                    text: "Simple Command Protocol Interface vai Tcp"
                                }
                                BaseTextSmall{
                                    text: "供应商:xxxxxxx"
                                }
                                BaseTextSmall{
                                    text: "版本: 1.0"
                                }
                            }
                        }
                    }
                    Rectangle{
                        width: remote.width/2
                        height: 150
                        color: "#a4a4a4"
                        enabled:remcon
                        Item {
                            width: parent.width-20
                            height: parent.height-20
                            anchors.centerIn: parent
                            Column{
                                BaseSwitch{
                                    id:xcpbs
                                    switchText: "XCP overEthernet"
                                    onIscheckedChanged: {
                                        xcp=xcpbs.ischecked
                                    }
                                }
                                BaseTextSmall{
                                    text: "XCP slave protocol interface vai TCP/UDP"
                                }
                                BaseTextSmall{
                                    text: "供应商:xxxxxxx"
                                }
                                BaseTextSmall{
                                    text: "版本: 1.0"
                                }
                            }
                        }
                    }

                }
                Column{
                    spacing: 10
                    BaseTextSmall{
                        text: "配置"
                        font.bold: true
                    }
                    Rectangle{
                        width: remote.width/2-100
                        height: 100
                        visible: scpi
                        Item {
                            width: parent.width-20
                            height: parent.height-20
                            anchors.centerIn: parent
                            Column{
                                spacing: 10
                                BaseTextSmall{
                                    text: "SCPI OVER ETHERNET"
                                    font.bold: true
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "端口"
                                    }
                                    BaseTextInput{
                                        width: reitem.width-180
                                        textContent: "10001"
                                    }
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "Override connection"
                                    }
                                    ListModel {
                                        id: override
                                        ListElement { text: "Disabled" }
                                        ListElement { text: "Enabled" }
                                    }
                                    BaseCombobox{
                                        width: reitem.width-180
                                        model: override
                                    }
                                }
                            }

                        }
                    }
                    Rectangle{
                        width: remote.width/2-100
                        height: 300
                        visible: xcp
                        Item {
                            id:reitem
                            width: parent.width-20
                            height: parent.height-20
                            anchors.centerIn: parent
                            Column{
                                spacing: 10
                                BaseTextSmall{
                                    text: "XCP OVER ETHERNET"
                                    font.bold: true
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "通讯类型"
                                    }
                                    ListModel {
                                        id: communication
                                        ListElement { text: "TCP Server" }
                                        ListElement { text: "UDP Server" }
                                    }
                                    BaseCombobox{
                                        width: reitem.width-180
                                        model: communication
                                    }
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "IP地址"
                                    }
                                    BaseTextInput{
                                        width: reitem.width-180
                                        textContent: "0.0.0.0"
                                    }
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "端口"
                                    }
                                    BaseTextInput{
                                        width: reitem.width-180
                                        textContent: "55555"
                                    }
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "输出格式"
                                    }
                                    ListModel {
                                        id: output
                                        ListElement { text: "TCP Server" }
                                        ListElement { text: "UDP Server" }
                                    }
                                    BaseCombobox{
                                        width: reitem.width-180
                                        model: output
                                    }
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "XML文件路径"
                                    }
                                    BaseTextInput{
                                        width: reitem.width-180
                                        textContent: "xxxxxxxxxxxxxxx"
                                    }
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "输出格式"
                                    }
                                    ListModel {
                                        id: send
                                        ListElement { text: "Enabled" }
                                        ListElement { text: "Disabled" }
                                    }
                                    BaseCombobox{
                                        width: reitem.width-180
                                        model: send
                                    }
                                }
                                Row{
                                    BaseTextSmall{
                                        width: 180
                                        text: "Discard telegrams"
                                    }
                                    BaseTextInput{
                                        width: reitem.width-180
                                        textContent: "0"
                                    }
                                }

                            }

                        }
                    }
                }
            }

        }
    }
}

