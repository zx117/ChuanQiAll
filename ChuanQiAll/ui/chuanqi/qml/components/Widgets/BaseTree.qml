import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/qml/images"

Item {
    id:flickable
    property var treeModel: null
    property int rowCount: 0
    width: parent.width
    height: parent.width
    // ListModel{
    //     id:listmodel
    //     ListElement{text:"text";color:"red";isCheck:false;isSave:false;value:0;range:0;ProportionalCoefficient:1;bias:0;unit:"s"}
    //     ListElement{text:"text";color:"red";isCheck:false;isSave:false;value:0;range:0;ProportionalCoefficient:1;bias:0;unit:"s"}
    //     ListElement{text:"text";color:"red";isCheck:false;isSave:false;value:0;range:0;ProportionalCoefficient:1;bias:0;unit:"s"}
    //     ListElement{text:"text";color:"red";isCheck:false;isSave:false;value:0;range:0;ProportionalCoefficient:1;bias:0;unit:"s"}
    // }


    ItemSelectionModel {
        id: sel
        model: treeModel
    }
    TreeView{
        id:myTree
        anchors.fill:parent
        style: treeViewStyle
        selection: sel
        headerVisible: false
        frameVisible: false//不显示边框
        backgroundVisible: false
        model:treeModel
        alternatingRowColors:true

        itemDelegate:Item{
            id:treeItem
            width: parent.width
            height:parent.height
            Rectangle{
                id:backrec
                width: flickable.width // 让矩形的宽度与父项相同
                height:30
                color: {
                    switch (styleData.depth) {
                    case 0: return "#b2bbc5";
                    case 1: return "#b8afd1";
                    case 2: return "#afbdcf"
                    default: return "#a6a6a6";
                    }
                }
                Drag.active: styleData.depth<1 ? false:itemMosue.drag.active;
                Drag.supportedActions: Qt.CopyAction;
                Drag.dragType: Drag.Automatic;
                Drag.mimeData: {"color": backrec.color};

                MouseArea{
                    id:itemMosue
                    hoverEnabled: true
                    anchors.fill: parent
                    drag.target: itemMosue

                    Drag.onDragStarted: {       //控制台打印开始拖动
                        console.log("start")
                    }
                    onPressed: {
                        sel.setCurrentIndex(styleData.index,0x0010) //点击了文字，选中该节点
                        if(styleData.isExpanded){                   //切换节点的展开状态
                            myTree.collapse(styleData.index)
                        }
                        else{
                            myTree.expand(styleData.index)
                        }
                    }
                }
            }

            BaseTextSmall{
                id:itemText
                anchors.verticalCenter: parent.verticalCenter
                text:styleData.value
            }

        }
        TableViewColumn {
            role: "display"
            title: "Column 1"
            width: parent.width
        }
        Component.onCompleted: {
            // 树加载完数据后展开所有节点
            expandAll(rootIndex);
        }
        function expandAll(parentIndex) {
            for (var i = 0; i < model.rowCount(parentIndex); ++i) {
                var childIndex = model.index(i, 0, parentIndex);
                expand(childIndex);
                expandAll(childIndex);
            }
        }
    }

    Component {
        id:treeViewStyle            //树的自定义样式
        TreeViewStyle {
            indentation: 30         //节点间隔
            branchDelegate:Rectangle{
                width: 30
                height:30
                color: {
                    switch (styleData.depth) {
                    case 0: return "#b2bbc5";
                    case 1: return "#b8afd1";
                    case 2: return "#afbdcf"
                    default: return "#a6a6a6";
                    }
                }
                Image { //节点的展开标记图
                    id:image
                    anchors.centerIn: parent
                    source: styleData.isExpanded ? "qrc:/qml/images/treeIcon/treedown.png" : "qrc:/qml/images/treeIcon/treeright.png"
                    width: 20
                    height:20
                }
            }
            rowDelegate: Rectangle {
                id:rect
                height: 30
                color: {
                    switch (styleData.depth) {
                    case 0: return "#b2bbc5";
                    case 1: return "#b8afd1";
                    case 2: return "#afbdcf"
                    default: return "#a6a6a6";
                    }
                }
            }

        }
    }
}
