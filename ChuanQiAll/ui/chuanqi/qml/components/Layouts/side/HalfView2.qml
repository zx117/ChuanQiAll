import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
import MyListModel 1.0
import GraphicDraw 1.0
Rectangle{
    anchors.fill: parent
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    property bool isChecked: false
    property bool group: false
    property bool isInitialized: false
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor


    Component.onCompleted: {
        for(var i=0;i<getdevinf.getActivateDeviceNumber();i++)
        {
            pugixml.setStructValue("Device_Name",getdevinf.getActivateDeviceName(i))
            pugixml.addDevice("Enclosure","Name","LocalNode")
            var num=getdevinf.getActiveDeviceChannelsNum(i)
            var devicename=getdevinf.getActivateDeviceName(i)
            for(var j=0;j<num;j++)
            {
                getdevinf.getDeviceData(i,j,0);
                pugixml.channelGroupandChannelStructAddValue(getdevinf.getChannelGroupName(i),getdevinf.getActiveDeviceChannelsName(i,j)
                                                             ,"0xDAD4FFF300000001")

            }
            pugixml.addChannelGroup("Device","Name",getdevinf.getActivateDeviceName(i))
        }
    }
    //获取通道数据，并更新数据
    Connections {
        target: getdevinf
        function onDeviceDataListChanged(threadid){
            getdevinf.upDateDeviceData(threadid);
        }
    }
    Connections {
        target: MyListModel
        function onReturnIndexValue(index,data) {
        }
    }

    Column {
        width: parent.width/5
        height: parent.height
        spacing: 0
        Rectangle {
            height: 30
            width: parent.width
            color: sideBarInterface.headBackColor
            border.color: sideBarInterface.borderColor
            BaseTextModerate {
                text: "通道查询树"
                font.bold: true
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
        Item{
            width: parent.width-5
            height: parent.height-30
            Row{
                width: parent.width
                height: parent.height
                Item {
                    width: 5
                    height: parent.height
                }
                Column{
                    width: parent.width
                    height: parent.height
                    Row{
                        height: 30
                        width: parent.width
                        BaseCheckBox{
                            height: 30
                            checkText: "隐藏未选择的通道"
                        }
                    }

                    Row{
                        width: parent.width
                        height: 30
                        spacing: 5
                        IconButton{
                            buttonWidth: 50
                            buttonHeight: parent.height-5
                            anchors.verticalCenter: parent.verticalCenter
                            buttonRadius:2
                            iconWidth: 15
                            iconHeight: 15
                            skin: SkinManager.currentSkin.screeniconButton
                            iconSource: "qrc:/qml/images/treeIcon/screen.png"
                        }
                        BaseTextInput{
                            textContent: "搜索"
                            width: parent.width-115
                            height: parent.height-5
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        IconButton{
                            id:branch
                            buttonWidth: 50
                            buttonHeight: parent.height-5
                            anchors.verticalCenter: parent.verticalCenter
                            buttonRadius:2
                            iconWidth: 15
                            iconHeight: 15
                            isChecked:false
                            skin: SkinManager.currentSkin.screeniconButton
                            iconSource: branch.isChecked?"qrc:/qml/images/treeIcon/branchwhite.png":"qrc:/qml/images/treeIcon/branch.png"
                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    branch.isChecked=!branch.isChecked
                                    group=branch.isChecked
                                }
                            }
                        }
                    }

                    Rectangle{
                        width: parent.width
                        height: 30
                        color: "#585858"
                        Row{
                            width: parent.width
                            height: 30
                            IconButton{
                                buttonWidth: parent.height
                                buttonHeight: parent.height
                                buttonRadius:2
                                iconWidth: 15
                                iconHeight: 15
                                visible: group
                                skin: SkinManager.currentSkin.screeniconButton
                                iconSource: "qrc:/qml/images/treeIcon/left.png"
                            }
                            IconButton{
                                buttonWidth: parent.height
                                buttonHeight: parent.height
                                buttonRadius:2
                                iconWidth: 15
                                visible: group
                                iconHeight: 15
                                skin: SkinManager.currentSkin.screeniconButton
                                iconSource: "qrc:/qml/images/treeIcon/right.png"
                            }

                            Item {
                                id:iditem
                                width: group===true?parent.width-110:parent.width-50
                                height: parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    fontcol: SkinManager.currentSkin.whitefont
                                    text: group===true?"名称":"长文件名"
                                }

                            }
                            Rectangle{
                                width: 1
                                height: parent.height/2
                                color: "#ffffff"
                                anchors.verticalCenter: parent.verticalCenter
                            }

                            Item {
                                id:itemcolor
                                width: 50
                                height: parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    fontcol: SkinManager.currentSkin.whitefont
                                    text: "颜色"
                                }
                            }

                        }

                    }

                    ListView {
                        id:mytree
                        width: parent.width
                        height: parent.height-90
                        model: MyListModel
                        delegate: Rectangle{
                            width: parent.width
                            height: 30
                            color: isClicked==false?index%2===0?"#efefef":"#ffffff":"#b7c9db"
                            Item{
                                anchors.fill: parent
                                Item {
                                    x:iditem.x
                                    width: iditem.width
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        text: model.text
                                    }

                                }
                                Item {
                                    anchors.right: parent.right
                                    width: 50
                                    height: parent.height
                                    Rectangle{
                                        width: 20
                                        height: 20
                                        anchors.centerIn: parent
                                        color: model.color
                                    }

                                }
                            }
                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    for(var i=0;i<MyListModel.rowCount();i++)
                                    {
                                        if(index===i)
                                        {
                                            getdevinf.setAttributeValue(i,4,true)
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
}
