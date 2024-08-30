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
            Rectangle{
                id:headrect
                width: setif.width
                height: 30
                color: "#a4a4a4"
                Row{
                    Item{
                        id:type
                        height: headrect.height
                        width: headrect.width/6
                        BaseTextSmall{
                            anchors.centerIn: parent
                            text: "类型"
                        }
                    }
                    Rectangle{
                        anchors.verticalCenter: parent.verticalCenter
                        height: 20
                        width: 2
                        color: "#ffffff"
                    }
                    Item{
                        id:name
                        height: headrect.height
                        width: headrect.width/4
                        BaseTextSmall{
                            anchors.centerIn: parent
                            text: "名称"
                        }
                    }
                    Rectangle{
                        anchors.verticalCenter: parent.verticalCenter
                        height: 20
                        width: 2
                        color: "#ffffff"
                    }
                    Item{
                        id: value
                        height: headrect.height
                        width: headrect.width/3
                        BaseTextSmall{
                            anchors.centerIn: parent
                            text: "测量值"
                        }
                    }
                    Rectangle{
                        anchors.verticalCenter: parent.verticalCenter
                        height: 20
                        width: 2
                        color: "#ffffff"
                    }
                    Item{
                        id:point
                        height: headrect.height
                        width: headrect.width/6-10
                        BaseTextSmall{
                            anchors.centerIn: parent
                            text: "提示"
                        }
                    }
                    Rectangle{
                        anchors.verticalCenter: parent.verticalCenter
                        height: 20
                        width: 2
                        color: "#ffffff"
                    }
                    Item{
                        id:force
                        height: headrect.height
                        width: headrect.width/24
                        BaseTextSmall{
                            anchors.centerIn: parent
                            text: "强制"
                        }
                    }
                    Rectangle{
                        anchors.verticalCenter: parent.verticalCenter
                        height: 20
                        width: 2
                        color: "#ffffff"
                    }
                    Item{
                        id:add
                        height: headrect.height
                        width: headrect.width/24
                        Rectangle{
                            id:addbutton
                            anchors.centerIn: parent
                            height: parent.height-10
                            width: parent.width-10
                            color: "#cfcfcf"
                            BaseTextSmall{
                                id: addname
                                anchors.centerIn: parent
                                text: qsTr("增加")
                            }
                            MouseArea{
                                anchors.fill: parent
                                onPressed: {
                                    addbutton.color="#a4a4a4"
                                    let component = Qt.createComponent("HeaderInfChild.qml");
                                    if (component.status === Component.Ready)
                                    {
                                        component.createObject(layout);
                                    }
                                    else if (component.status === Component.Error) {
                                        console.log("Error loading component:", component.errorString());
                                    }
                                }
                                onReleased: {
                                    addbutton.color="#cfcfcf"
                                }
                            }
                        }
                    }
                }
            }
            Flickable  {
                height: setif.height-headrect.height
                width: setif.width
                contentWidth: width
                contentHeight: layout.height
                clip: true
                GridLayout {
                    id: layout
                    columns: 1
                }
            }
        }
    }
}
