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
    Component.onCompleted: {
        for(var i=0;i<getdevinf.getRootDeviceNumber();i++)
        {
            rootdevice.append({"Devicename": getdevinf.getRootDeviceName(i), "Name": getdevinf.getRootDeviceTypeName(i),
                                  "IdNumber": getdevinf.getRootDeviceTypeId(i), "Description": getdevinf.getRootDeviceDescription(i),
                                  "Active": getdevinf.getDeviceActive(i),"Clicked":false,"originalIndex":i})
        }
    }

    ListModel{
        id:rootdevice
    }

    ListModel{
        id:activedevice
    }

    Item {
        id:setif
        width: parent.width-20
        height: parent.height
        anchors.centerIn: parent
        Column{
            spacing: 10
            width: parent.width
            height: parent.height
            BaseTextSmall{
                text: "OXYGEN-NET系统"
                font.bold: true
            }

            Flickable {
                width: parent.width
                height: 300
                contentWidth: parent.width
                contentHeight: height
                flickableDirection: Flickable.HorizontalFlick
                clip: true
                ListView {
                    width: parent.width
                    height: parent.height
                    model: activedevice
                    spacing: 10
                    orientation: ListView.Horizontal
                    delegate: NodeItem {
                        devicename:model.Devicename
                        name:model.Name
                        idnumber:model.IdNumber
                        description:model.Description
                        active:model.Active
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

                }
            }

            Flickable {
                id: flickable
                width: parent.width
                height: 300
                contentWidth: parent.width
                contentHeight: height
                flickableDirection: Flickable.HorizontalFlick
                clip: true
                ListView {
                    width: parent.width
                    height: parent.height
                    model: rootdevice
                    spacing: 10
                    orientation: ListView.Horizontal
                    delegate: NodeItem {
                        devicename:model.Devicename
                        name:model.Name
                        idnumber:model.IdNumber
                        description:model.Description
                        active:model.Active
                    }
                }
            }
        }
    }
}
