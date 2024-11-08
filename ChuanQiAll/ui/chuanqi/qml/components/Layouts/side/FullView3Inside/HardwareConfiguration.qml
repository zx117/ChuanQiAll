import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
import Widgets 1.0
import Themes 1.0
Rectangle{
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    Component.onCompleted: {
        for(var i=0;i<getdevinf.getRootDeviceNumber();i++)
        {
            listmodel.append({"txt": getdevinf.getRootDeviceName(i),"isvisible":false})
            pugixml.setStructValue("Device_Name",getdevinf.getRootDeviceName(i))
            pugixml.addDevice("Enclosure","Name","LocalNode")
        }
    }
    Item {
        id:setif
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        ListModel{
            id:listmodel
        }
        Column{
            width: parent.width
            height: parent.height
            spacing: 10
            Row{
                spacing: 10
                width: 200
                height: 40
                BaseTextSmall{
                    text: "模拟硬件"
                }
                ListModel {
                    id: simhw
                    ListElement { text: "SyncCard" }
                }
                BaseCombobox{
                    width: 300
                    model: simhw
                }
            }
            Row{
                spacing: 10
                width: parent.width
                height: parent.height
                Column{
                    width: parent.width/2-100
                    height: parent.height
                    spacing: 10
                    ListView{
                        width: setif.width/2-100
                        height: 400
                        clip: true
                        model: listmodel
                        interactive: false
                        delegate: Rectangle{
                            id:rect
                            width: setif.width/2-100
                            height: 40
                            color: index % 2 === 0? "#efefef" : "white"
                            Component.onCompleted: {
                                hdbs.ischecked=getdevinf.getDeviceActive(index)
                            }

                            BaseSwitch{
                                id:hdbs
                                height: 20
                                anchors.verticalCenter: rect.verticalCenter
                                switchText:model.txt
                                property var createdComponent

                                onIscheckedChanged: {
                                    if(hdbs.ischecked)
                                    {
                                        let component = Qt.createComponent("HardwareConChild.qml");
                                        if (component.status === Component.Ready)
                                        {
                                            createdComponent=component.createObject(layout);
                                        }
                                        else if (component.status === Component.Error) {
                                            console.log("Error loading component:", component.errorString());
                                        }
                                        getdevinf.setDeviceActive(index,true)
                                    }
                                    else{
                                        if (createdComponent) {
                                            createdComponent.destroy();
                                        }
                                        getdevinf.setDeviceActive(index,false)
                                    }
                                }
                            }
                        }
                    }
                    BaseTextSmall{
                        font.bold: true
                        text: "调理放大器/RS232/RS485"
                    }
                    BaseCheckBox{
                        checkText: "COM3"
                    }
                    BaseCheckBox{
                        checkText: "COM4"
                    }
                    BaseTextSmall{
                        font.bold: true
                        text: "DAQP/EPAD模块"
                    }
                    Row{
                        width: parent.width
                        height: 30
                        spacing: 20
                        BaseTextSmall{
                            text: "最小地址"
                        }
                        BaseTextInput{
                            textContent: "0"
                        }
                    }
                    Row{
                        width: parent.width
                        height: 30
                        spacing: 20
                        BaseTextSmall{
                            text: "最大地址"
                        }
                        BaseTextInput{
                            textContent: "31"
                        }
                    }
                    BaseCheckBox{
                        checkText: "支持PAD-DO7"
                    }
                    TextButton{
                        width: parent.width
                        height: 30
                        text: "扫描模块"
                    }
                    TextButton{
                        width: parent.width
                        height: 30
                        text: "编辑模块地址"
                    }

                    Row{
                        width: parent.width
                        height: 30
                        Column{
                            spacing: 5
                            width: parent.width/2
                            height: parent.height
                            BaseTextSmall{
                                font.bold: true
                                text: "DAQP模块"
                            }
                            Row{
                                width: parent.width
                                height: parent.height
                                spacing: 10
                                BaseTextSmall{
                                    anchors.verticalCenter: parent.verticalCenter
                                    text: "输出里程"
                                }
                                ListModel{
                                    id:oplcmodel
                                    ListElement{text:"5V"}
                                    ListElement{text:"10V"}
                                }
                                BaseCombobox{
                                    anchors.verticalCenter: parent.verticalCenter
                                    combWidth: 100
                                    combHeight: parent.height
                                    model: oplcmodel
                                }
                            }


                        }
                        Column{
                            spacing: 5
                            width: parent.width/2
                            height: parent.height
                            BaseTextSmall{
                                font.bold: true
                                text: "EPAD同步时间设置"
                            }
                            BaseCheckBox{
                                checkText: "同步时间戳"
                            }
                        }


                    }

                }
                Column{
                    width: parent.width/2
                    height: parent.height
                    BaseTextSmall{
                        text: "硬件设置"
                    }
                    Flickable
                    {
                        height:parent.height-100
                        width: parent.width
                        contentWidth: width
                        contentHeight: layout.height
                        clip: true
                        Rectangle{
                            anchors.fill: parent
                            GridLayout {
                                id: layout
                                columns: 1
                            }
                        }
                    }
                }
            }

        }
    }
}


