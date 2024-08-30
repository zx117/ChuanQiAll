import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import MyTreeModel 1.0
import Widgets 1.0
import Themes 1.0
Rectangle{
    anchors.fill: parent
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    property bool isChecked: false
    property bool group: false
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    ListModel {
        id: treeModel
        ListElement { name: "1"; text:"LocalNode";parent:"" }
        ListElement { name: "2"; text:"ADMA Enclosure";parent:"1" }
        ListElement { name: "3"; text:"ADMA Stream1";parent:"2" }
        ListElement { name: "4"; text:"Static-Header";parent:"3" }
        ListElement { name: "5"; text:"Alias";color:"red";mileage:"0~15";coefficient:"1";bias:"0";parent:"4" }
        ListElement { name: "6"; text:"Status";parent:"3" }
        ListElement { name: "7"; text:"Status_GPS_Moder";color:"blue";mileage:"0~1";coefficient:"1";bias:"0";parent:"6" }
        ListElement { name: "8"; text:"Status_Standstill";color:"green";mileage:"0~1";coefficient:"1";bias:"0";parent:"6" }
        ListElement { name: "9"; text:"Status_Standstill2";color:"yellow";mileage:"0~1";coefficient:"1";bias:"0";parent:"6" }
    }
    ListModel {
        id: leafNodeModel
    }

    Component.onCompleted: {
        for (var i = 0; i < treeModel.count; i++) {
            var node = treeModel.get(i)
            var hasChildren = false
            for (var j = 0; j < treeModel.count; j++) {
                if (treeModel.get(j).parent === node.name) {
                    hasChildren = true
                    break
                }
            }
            if (!hasChildren && node.parent !== "") {
                leafNodeModel.append(node)
            }
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
                        model: leafNodeModel // 使用单例对象
                        delegate: Rectangle{
                            width: parent.width
                            height: 30
                            color: index%2===0?"#efefef":"#ffffff"
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
                        }

                    }

                }

            }
        }
    }
}
