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
            spacing: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            BaseTextSmall{
                text: "OXYGEN-NET系统"
                font.bold: true
            }
            Rectangle{
                width: 200
                height: 250
                color: "#efefef"
                Column{
                    anchors.fill: parent
                    BaseTextModerate{
                        text: "DESKTOP-IUDABC2"
                        font.bold: true
                    }
                    BaseTextSmall{
                        text: "OXYGEN-NET"
                    }
                    BaseTextSmall{
                        text: "v6.51"
                    }
                    BaseTextSmall{
                        text: "ADMA Ensolure"
                        font.bold: true
                    }
                    Row{
                        BaseTextSmall{
                            text: "IP:"
                        }
                        BaseTextSmall{
                            text: "127.0.0.1"
                        }
                    }
                    Row{
                        BaseTextSmall{
                            text: "Status:"
                        }
                        BaseTextSmall{
                            text: "Not claimable"
                        }
                    }
                    BaseTextSmall{
                        text: "Local Node"
                    }
                }
            }
            BaseTextSmall{
                text: "可用节点"
                font.bold: true
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    text: "节点筛选"
                }
                ListModel {
                    id: typemodel
                    ListElement { text: "全部" }
                    ListElement { text: "可用的" }
                    ListElement { text: "允许TRIONEW"}
                    ListElement { text: "已锁定"}
                }
                BaseCombobox{
                    width: 120
                    model: typemodel
                }
            }
            TextButton{
                buttonWidth: 120
                buttonHeight: 20
                buttonRadius: 3
                buttonText: "锁定所选设备"
                onClicked: {
                    // 生成唯一的文本内容
                    var component = Qt.createComponent("NodeItem.qml");
                    if (component.status === Component.Ready) {
                        var nodeItem = component.createObject(container);
                        nodeItem.x = container.children.length * (nodeItem.width + 10); // 横向排列
                    } else {
                        console.log("Error loading component:", component.errorString());
                    }
                }
            }
            Row {
                id: container
                width: parent.width
                spacing: 10
            }
        }
    }
}
