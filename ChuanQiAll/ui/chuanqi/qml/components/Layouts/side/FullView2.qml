import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import MyTreeModel 1.0
import Widgets 1.0
import Themes 1.0
import "../side/FullView2Inside/Popup"
Rectangle{
    id:full2

    SetPopup{
        id:setpopup
    }
    ApplyPopup{
        id:applypopup
    }
    SavePopup{
        id:savepopup
    }
    AddPopup{
        id:addpopup
    }
    IdPopup{
        id:idpopup
    }

    anchors.fill: parent
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    property bool group: false
    property real widthchanged: 0.0
    property real leftwidth: 0.0
    property real rightwidth: 0.0
    property int  currentIndex: -1
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor

    Column{
        anchors.fill: parent
        Row{
            height: parent.height/4
            width: parent.width
            Rectangle{
                width: 150
                height: parent.height
                border.color: "#cfcfcf"
                color: "#ffffff"
                Flickable{
                    anchors.fill: parent
                    clip: true
                    contentHeight: parent.height
                    Column{
                        anchors.fill: parent
                        ListModel{
                            id:ippath
                            ListElement{text:"LocalNode"}
                        }
                        ListView{
                            width: parent.width
                            height: parent.height
                            model:ippath
                            delegate: Rectangle{
                                height: 50
                                width: parent.width
                                color: "#efefef"
                                border.color: "#cfcfcf"
                                BaseTextSmall{
                                    text: model.text
                                    anchors.centerIn: parent
                                }
                            }
                        }
                    }
                }
            }
            Rectangle{
                width: 150
                height: parent.height
                border.color: "#cfcfcf"
                color: "#ffffff"
                Flickable{
                    anchors.fill: parent
                    clip: true
                    contentHeight: parent.height
                    Column{
                        anchors.fill: parent
                        ListModel{
                            id:machine
                            ListElement{text:"ADMA"}
                        }
                        ListView{
                            width: parent.width
                            height: parent.height
                            model:machine
                            delegate: Rectangle{
                                height: 50
                                width: parent.width
                                color: "#efefef"
                                border.color: "#cfcfcf"
                                BaseTextSmall{
                                    text: model.text
                                    anchors.centerIn: parent
                                }
                            }
                        }
                    }
                }
            }
            Rectangle{
                width: parent.width-300
                height: parent.height
                border.color: "#cfcfcf"
                color: "#ffffff"
                Flickable{
                    anchors.fill: parent
                    clip: true
                    contentHeight: parent.height
                    Column{
                        anchors.fill: parent
                        ListModel{
                            id:machinemodel
                            ListElement{text:"text1";size:5}
                            ListElement{text:"text1";size:5}
                            ListElement{text:"text1";size:5}
                            ListElement{text:"text1";size:5}
                            ListElement{text:"text1";size:5}
                            ListElement{text:"text1";size:5}
                        }
                        ListView{
                            id:listview
                            width: parent.width
                            height: parent.height
                            orientation: Qt.Horizontal
                            model:machinemodel
                            delegate: Rectangle{
                                id:rect
                                height: parent.height
                                width: 40
                                color: "#ffffff"
                                border.color: "#cfcfcf"
                                Column{
                                    anchors.fill: parent
                                    Rectangle{
                                        width: parent.width
                                        height: 30
                                        color: "#efefef"
                                        border.color: "#cfcfcf"
                                        BaseTextSmall{
                                            text: index
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Column{
                                        id:column
                                        width: parent.width
                                        height: parent.height-60
                                        Repeater{
                                            model: size
                                            delegate: Item{
                                                height: column.height/size
                                                width:  column.width
                                                Rectangle{
                                                    height: 20
                                                    width: 20
                                                    anchors.centerIn: parent
                                                    radius: 10
                                                    color: "#efefef"
                                                    border.color: "#585858"
                                                    Rectangle{
                                                        width: parent.width/2
                                                        height: parent.height/2
                                                        anchors.centerIn: parent
                                                        radius: 10
                                                        color: "#cfcfcf"
                                                        border.color: "#585858"
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: 30
                                        color: "#005bb6"
                                        border.color: "#cfcfcf"
                                        Rectangle{
                                            width: parent.width
                                            height: parent.height/2
                                            anchors.centerIn: parent
                                            border.color: "#cfcfcf"
                                            BaseTextSmall{
                                                text: model.text
                                                font.pointSize: 7
                                                anchors.centerIn: parent
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
        Item {
            id:titlritem
            width: parent.width
            height: 60
            Row{
                anchors.fill: parent
                spacing: 0
                Item {
                    id:passagewayrect
                    width: parent.width/2
                    height: parent.height
                    Column{
                        spacing: 0
                        anchors.fill: parent
                        Item{
                            width: parent.width
                            height: parent.height/2
                            Row{
                                spacing: 5
                                anchors.fill: parent
                                Item {
                                    width: 5
                                    height: parent.height
                                }
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
                                TextButton{
                                    buttonWidth: parent.width/10
                                    buttonHeight: parent.height-5
                                    text: "Analog"
                                    anchors.verticalCenter: parent.verticalCenter
                                    buttonRadius: 2
                                }
                                TextButton{
                                    buttonWidth: parent.width/10
                                    buttonHeight: parent.height-5
                                    text: "Counter"
                                    anchors.verticalCenter: parent.verticalCenter
                                    buttonRadius: 2
                                }
                                TextButton{
                                    buttonWidth: parent.width/10
                                    buttonHeight: parent.height-5
                                    text: "Video"
                                    buttonRadius: 2
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                                BaseTextInput{
                                    textContent: "搜索"
                                    width: 150
                                    height: parent.height-5
                                    anchors.verticalCenter: parent.verticalCenter
                                }
                                IconButton{
                                    buttonWidth: 50
                                    buttonHeight: parent.height-5
                                    anchors.verticalCenter: parent.verticalCenter
                                    buttonRadius:2
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: "qrc:/qml/images/treeIcon/noscreen.png"
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
                        }
                        Rectangle{
                            width: parent.width
                            height: parent.height/2
                            color: "#585858"
                            Row{
                                anchors.fill: parent
                                spacing:1
                                IconButton{
                                    id:select
                                    buttonWidth: parent.height
                                    buttonHeight: parent.height
                                    buttonRadius:2
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: select.isChecked?"qrc:/qml/images/treeIcon/noSelectAll.png":"qrc:/qml/images/treeIcon/SelectAll.png"
                                }
                                IconButton{
                                    buttonWidth: parent.height
                                    buttonHeight: parent.height
                                    buttonRadius:2
                                    visible: group
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: "qrc:/qml/images/treeIcon/left.png"
                                }
                                IconButton{
                                    buttonWidth: parent.height
                                    buttonHeight: parent.height
                                    buttonRadius:2
                                    visible: group
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: "qrc:/qml/images/treeIcon/right.png"
                                }

                                Item {
                                    id:iditem
                                    width: group?150:212
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "ID"
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            idpopup.x=iditem.x
                                            idpopup.y=titlritem.y+titlritem.height
                                            idpopup.width=iditem.width
                                            idpopup.height=180
                                            idpopup.open()
                                        }
                                    }
                                }
                                Column{
                                    width: 1
                                    height: parent.height/3
                                    spacing: 3
                                    anchors.verticalCenter: parent.verticalCenter
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }

                                Item{
                                    id:coloritem
                                    width: 60
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "颜色"
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }
                                Item{
                                    id:setitem
                                    width: 60
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "设置"
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }
                                Item{
                                    id:useitem
                                    width: 60
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "使用"

                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            applypopup.x=setitem.x
                                            applypopup.y=titlritem.y+titlritem.height
                                            applypopup.width=setitem.width*3+15
                                            applypopup.height=100
                                            applypopup.open()
                                        }
                                    }
                                }
                                Column{
                                    width: 1
                                    height: parent.height/3
                                    spacing: 3
                                    anchors.verticalCenter: parent.verticalCenter
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }
                                Item{
                                    id:saveitem
                                    width: 60
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "存储"

                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            savepopup.x=setitem.x
                                            savepopup.y=titlritem.y+titlritem.height
                                            savepopup.width=setitem.width*3+15
                                            savepopup.height=100
                                            savepopup.open()
                                        }
                                    }
                                }
                                Column{
                                    width: 1
                                    height: parent.height/3
                                    spacing: 3
                                    anchors.verticalCenter: parent.verticalCenter
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }
                                Item {
                                    id:valueitem
                                    width: group?(parent.width-parent.height*3-iditem.width-270):(parent.width-parent.height-iditem.width-268)
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.fill: parent
                                        elide: Text.ElideRight
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "换算值"
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                    }
                                }
                                Rectangle{
                                    id:slidbarrect
                                    width: 4
                                    height: parent.height
                                    color: "#585858"
                                    border.color: "#ffffff"
                                    MouseArea {
                                        anchors.fill: parent
                                        drag.target: determine//要拖动的项目的ID
                                        drag.axis: Drag.XAxis//拖动的轴方向
                                        drag.minimumX: 0
                                        drag.maximumX:  titlritem.width
                                        onPressed: {
                                            determine.visible=true
                                            widthchanged=determine.x
                                            determine.x=slidbarrect.x
                                            leftwidth=valueitem.width

                                        }
                                        //slidbarrect     选择区域
                                        //determine       当前滑动条
                                        //passagewayrect  左侧全部
                                        //setrect         右侧全部
                                        onReleased: {
                                            determine.visible=false
                                            if(determine.x<widthchanged)
                                            {
                                                if(determine.x<(valueitem.x+30))
                                                {
                                                    passagewayrect.width=passagewayrect.width-valueitem.width+30
                                                    setrect.width=setrect.width+(leftwidth-30)
                                                    valueitem.width=30
                                                }
                                                else
                                                {
                                                    valueitem.width=valueitem.width-(widthchanged-determine.x)
                                                    passagewayrect.width=passagewayrect.width-(widthchanged-determine.x)
                                                    setrect.width=setrect.width+(widthchanged-determine.x)
                                                }

                                            }
                                            else if(determine.x>widthchanged)
                                            {
                                                if(determine.x>full2.width-50)
                                                {
                                                    valueitem.width=(full2.width-valueitem.x-50)
                                                    setrect.width=50
                                                }
                                                else{
                                                    valueitem.width=valueitem.width+(determine.x-widthchanged)
                                                    passagewayrect.width=passagewayrect.width+(determine.x-widthchanged)
                                                    setrect.width=setrect.width-(determine.x-widthchanged)
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                Rectangle{
                    id:setrect
                    width: parent.width/2
                    height: parent.height
                    color: "#585858"
                    Column{
                        anchors.fill: parent
                        Row{
                            width: parent.width
                            height: parent.height/2
                            Item{
                                width: parent.height
                                height: parent.height
                                Image {
                                    anchors.centerIn: parent
                                    width: parent.height
                                    height: parent.height
                                    source: "qrc:/qml/images/treeIcon/doubleleft.png"
                                }
                            }
                            Item{
                                width: parent.width-parent.height*2
                                height: parent.height
                                BaseSlider{
                                    sliderWidth:parent.width
                                    slideHeight:parent.height/3
                                    backWidth:parent.width
                                    backHeight: parent.height/3
                                    backRadius:3
                                    backColor:"#ffffff"
                                    slideOverColor:"#ffffff"
                                    blockWidth:parent.width/3
                                    blockHeight:parent.height/3
                                    blockColor:"#585858"
                                    blockBroderColor:"#585858"
                                    blockRadius:3
                                    anchors.centerIn: parent
                                }
                            }
                            Item{
                                width: parent.height
                                height: parent.height
                                Image {
                                    anchors.centerIn: parent
                                    width: parent.height
                                    height: parent.height
                                    source: "qrc:/qml/images/treeIcon/doubleright.png"
                                }
                            }
                        }
                        Row{
                            width: parent.width
                            height: parent.height/2
                            Item {
                                id:mileageitem
                                width: parent.width/3
                                height: parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    elide: Text.ElideRight
                                    fontcol: SkinManager.currentSkin.whitefont
                                    text: "里程"
                                }
                            }
                            Rectangle{
                                width: 1
                                height: parent.height/2
                                anchors.verticalCenter: parent.verticalCenter
                                color: "#ffffff"
                            }
                            Item {
                                id:coefficientitem
                                width: parent.width*2/3
                                height: parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    fontcol: SkinManager.currentSkin.whitefont
                                    elide: Text.ElideRight
                                    text: "比例系数"
                                }
                            }
                        }
                    }
                }

            }
            onYChanged: {
                if(idpopup.visible)
                {
                    idpopup.x=iditem.x
                    idpopup.y=y+titlritem.height
                    idpopup.width=iditem.width
                    idpopup.height=180
                }
                if(applypopup.visible)
                {
                    applypopup.x=setitem.x
                    applypopup.y=y+titlritem.height
                    applypopup.width=setitem.width*3+15
                    applypopup.height=100
                }
                if(savepopup.visible)
                {
                    savepopup.x=setitem.x
                    savepopup.y=y+titlritem.height
                    savepopup.width=setitem.width*3+15
                    savepopup.height=100
                }
                if(setpopup.visible)
                {
                    setpopup.width=listitem.width*2/3
                    setpopup.height=listitem.height
                    setpopup.x=listitem.x+listitem.width/3
                    setpopup.y=titlritem.y+titlritem.height
                }

            }
        }
        Item{
            id:listitem
            width: parent.width
            height: parent.height-parent.height/4-titlritem.height-41
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
            ListModel {
                id: treeModel
                ListElement { name: "1"; text:"LocalNode";parent:"";checked:false }
                ListElement { name: "2"; text:"ADMA Enclosure";parent:"1";checked:false}
                ListElement { name: "3"; text:"ADMA Stream1";parent:"2";checked:false }
                ListElement { name: "4"; text:"Static-Header";parent:"3";checked:false }
                ListElement { name: "5"; text:"Alias";color:"red";mileage:"0~15";coefficient:"1";bias:"0";parent:"4";checked:false }
                ListElement { name: "6"; text:"Status";parent:"3";checked:false }
                ListElement { name: "7"; text:"Status_GPS_Moder";color:"blue";mileage:"0~1";coefficient:"1";bias:"0";parent:"6";checked:false }
                ListElement { name: "8"; text:"Status_Standstill";color:"green";mileage:"0~1";coefficient:"1";bias:"0";parent:"6";checked:false }
                ListElement { name: "9"; text:"Status_Standstill2";color:"yellow";mileage:"0~1";coefficient:"1";bias:"0";parent:"6";checked:false }
            }
            // ScrollView {
            //     anchors.fill: parent
            //     Column {
            //         id: treeRoot
            //         spacing: 10

            //         Component.onCompleted: {
            //             createTree("", 0, treeRoot);
            //         }

            //         function createTree(parentName, indentLevel, parentItem) {
            //             var children = [];
            //             for (var i = 0; i < treeModel.count; i++) {
            //                 var node = treeModel.get(i);
            //                 if (node.parent === parentName) {
            //                     children.push(node);
            //                 }
            //             }

            //             children.sort(function(a, b) {
            //                 return a.text.localeCompare(b.text);
            //             });

            //             var totalHeight = 30; // 初始高度，包含ID行的高度

            //             for (var j = 0; j < children.length; j++) {
            //                 var child = children[j];
            //                 var newItem;

            //                 if (hasChildren(child.name)) {
            //                     newItem = treeNodeComponent.createObject(parentItem, {
            //                         nodeText: child.text,
            //                         indentLevel: indentLevel,
            //                         x: indentLevel === 0 ? 0 : 30,
            //                         y: totalHeight,
            //                     });
            //                     // 递归计算子节点的高度
            //                     var childHeight = createTree(child.name, indentLevel + 1, newItem);
            //                     totalHeight += childHeight; // 更新父节点的高度
            //                     console.log()
            //                 } else {
            //                     newItem = listItemComponent.createObject(parentItem, {
            //                         nodeText: child.text,
            //                         indentLevel: indentLevel,
            //                         x: 30,
            //                         y: totalHeight,
            //                         height:30
            //                     });
            //                     totalHeight += newItem.height; // 累加叶子节点的高度
            //                 }
            //             }

            //             return totalHeight;
            //         }

            //         // 判断节点是否有子节点
            //         function hasChildren(nodeName) {
            //             for (var i = 0; i < treeModel.count; i++) {
            //                 if (treeModel.get(i).parent === nodeName) {
            //                     return true;
            //                 }
            //             }
            //             return false;
            //         }
            //     }
            // }

            // Component {
            //     id: treeNodeComponent
            //     Rectangle {
            //         id: rect
            //         width: 500 // 初始宽度
            //         height: 30 // 初始高度
            //         color: "lightblue"
            //         border.color: "black"
            //         border.width: 1
            //         property string nodeText: ""
            //         property bool isExpand: true
            //         property real rectheight: 0.0

            //         Item {
            //             width: parent.width
            //             height: 30
            //             Row {
            //                 anchors.fill: parent
            //                 Item {
            //                     width: 30
            //                     height: 30
            //                     Image { // 节点展开/折叠图标
            //                         anchors.centerIn: parent
            //                         source: isExpand ? "qrc:/qml/images/treeIcon/treedown.png" : "qrc:/qml/images/treeIcon/treeright.png"
            //                         width: 20
            //                         height: 20
            //                         MouseArea {
            //                             anchors.fill: parent
            //                             onClicked: {
            //                                 isExpand = !isExpand
            //                                 if (isExpand) {
            //                                     rect.height = rectheight
            //                                 } else {
            //                                     rectheight = rect.height
            //                                     rect.height = 30
            //                                 }
            //                             }
            //                         }
            //                     }
            //                 }
            //                 BaseTextSmall {
            //                     anchors.verticalCenter: parent.verticalCenter
            //                     text: nodeText
            //                     font.bold: true
            //                     font.pointSize: 8
            //                 }
            //             }
            //         }
            //     }
            // }

            // Component {
            //     id: listItemComponent
            //     Rectangle {
            //         width: 500 // 初始宽度
            //         height: 30 // 初始高度
            //         color: "white"
            //         border.color: "black"
            //         border.width: 1
            //         property string nodeText: ""
            //         Item {
            //             width: parent.width
            //             height: 30
            //             BaseTextSmall {
            //                 anchors.verticalCenter: parent.verticalCenter
            //                 text: nodeText
            //                 font.pointSize: 8
            //             }
            //         }
            //     }
            // }

            Row{
                anchors.fill: parent
                ListView {
                    id:mytree
                    width: passagewayrect.width
                    height: parent.height
                    model: leafNodeModel // 使用单例对象
                    delegate: Rectangle{
                        width: parent.width
                        height: select.height
                        color: index%2===0?"#efefef":"#ffffff"
                        Row{
                            anchors.fill: parent
                            Item {
                                width: select.width
                                height: parent.height
                                BaseCheckBox{
                                    anchors.centerIn: parent
                                    checkBackColorVisible:false
                                    onCheckedChanged: model.checked = checked
                                }
                            }
                            Item {
                                width: select.width
                                height: parent.height
                                visible: group
                            }
                            Item {
                                width: select.width
                                height: parent.height
                                visible: group
                            }
                            Item {
                                width: iditem.width+6
                                height: parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    text: model.text
                                }
                            }
                            Item{
                                width: coloritem.width+2
                                height: parent.height
                                Rectangle{
                                    width: parent.height-10
                                    height: parent.height-10
                                    anchors.centerIn: parent
                                    radius: 5
                                    color: model.color
                                }

                            }
                            Item{
                                width: setitem.width+2
                                height: parent.height
                                Rectangle{
                                    width: parent.height
                                    height: parent.height
                                    anchors.fill: parent
                                    color: index%2===0?"#efefef":"#ffffff"
                                    Image {
                                        width: 15
                                        height: 15
                                        anchors.centerIn: parent
                                        source: "qrc:/qml/images/RightIcon/set.png"
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            setpopup.visible=true
                                            setpopup.width=listitem.width*2/3
                                            setpopup.height=listitem.height
                                            setpopup.x=listitem.x+listitem.width/3
                                            setpopup.y=titlritem.y+titlritem.height
                                            setpopup.name=model.text
                                            setpopup.popcolor=model.color
                                            currentIndex=index
                                        }
                                    }
                                }
                            }
                            Item {
                                width: useitem.width+8
                                height: parent.height
                                BaseSwitch{
                                    switchWidth: parent.width
                                    switchHeight: parent.height
                                    anchors.centerIn: parent
                                    switchText: ""
                                    ischecked: true
                                }
                            }
                            Item{
                                id:save
                                width: saveitem.width+2
                                height: parent.height
                                property bool issave: true
                                Rectangle{
                                    width: 20
                                    height: 20
                                    color: save.issave===false?"#ffffff":"red"
                                    border.color: "#cfcfcf"
                                    anchors.centerIn: parent
                                    radius: 5
                                    Rectangle{
                                        width: 10
                                        height: 10
                                        color: save.issave===false?"#efefef":"#ffffff"
                                        radius: 10
                                        anchors.centerIn: parent
                                        MouseArea{
                                            anchors.fill: parent
                                            onClicked: {
                                                save.issave=!save.issave
                                            }
                                        }
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            save.issave=!save.issave
                                        }
                                    }
                                }

                            }
                            Item{
                                width: valueitem.width
                                height: parent.height
                                Column{
                                    width: valueitem.width
                                    height: parent.height
                                    Row{
                                        width: parent.width
                                        height: parent.height/2
                                        Item {
                                            width: 30
                                            height: parent.height
                                            BaseTextSmall{
                                                font.pointSize: 6
                                                text: "NaN"
                                            }
                                        }
                                        Item {
                                            width: parent.width-60
                                            height: parent.height
                                        }
                                        Item{
                                            width: 30
                                            height: parent.height
                                            BaseTextSmall{
                                                font.pointSize: 6
                                                text: "平均值"
                                            }
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/2
                                        border.color: "#cfcfcf"
                                    }
                                }
                            }
                        }
                    }
                }
                ListView {
                    id:settree
                    width: setrect.width
                    height: parent.height
                    model: leafNodeModel
                    delegate: Rectangle{
                        width: parent.width
                        height: select.height
                        color: index%2===0?"#efefef":"#ffffff"
                        Row{
                            width: parent.width
                            height: parent.height
                            Item{
                                width: mileageitem.width
                                height:parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    text: model.mileage
                                }
                            }
                            Item{
                                width: coefficientitem.width
                                height: parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    text: model.coefficient
                                }
                            }
                        }
                    }
                }

            }
        }
        Rectangle{
            width: parent.width
            height: 1
            color: "#585858"
        }

        Item{
            width: parent.width
            height: 40
            Row{
                anchors.fill: parent
                spacing: 10
                IconButton{
                    buttonWidth: 70
                    buttonHeight: parent.height-5
                    anchors.verticalCenter: parent.verticalCenter
                    buttonRadius:2
                    iconWidth: 30
                    iconHeight: 30
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/LeftIcon/add.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            addpopup.open()
                            addpopup.width=full2.width/2
                            addpopup.height=full2.height*2/3
                        }
                    }
                }
                IconButton{
                    buttonWidth: 70
                    buttonHeight: parent.height-5
                    anchors.verticalCenter: parent.verticalCenter
                    buttonRadius:2
                    iconWidth: 30
                    iconHeight: 30
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/LeftIcon/sub.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            for (var i = leafNodeModel.count - 1; i >= 0; --i) {
                                if (leafNodeModel.get(i).checked) {
                                    leafNodeModel.remove(i);
                                }
                            }
                        }
                    }
                }
            }


        }
    }



    Rectangle{
        id:determine
        visible: false
        z:1
        width: 4
        height: settree.height
        x: slidbarrect.x
        y: titlritem.y+60
        color: "#585858"
    }



}
