import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4
import Themes 1.0
import Widgets 1.0
import MyTreeModel 1.0
Item {
    // Column {
    //     width: parent.width
    //     height: parent.height
    //     spacing: 0

        // Rectangle {
        //     height: 40
        //     width: parent.width
        //     color: "#585858"
        //     BaseTextModerate {
        //         text: "通道"
        //         anchors.verticalCenter: parent.verticalCenter
        //         anchors.right: parent.right
        //         anchors.rightMargin: 20
        //         color: "#ffffff"

        //     }
        // }
        // Flickable{
        //     id:flickable
        //     width: parent.width
        //     height: 230
        //     //    contentHeight: 230
        //     //    contentWidth: parent.width

        //     clip: true

        //     Column{
        //         width: parent.width
        //         height: parent.height
        //         TreeView{
        //             id:myTree
        //             width: parent.width
        //             height: parent.height
        //             style: treeViewStyle
        //             headerVisible: false
        //             frameVisible: false//不显示边框
        //             backgroundVisible: false
        //             model:MyTreeModel
        //             alternatingRowColors:true

        //             itemDelegate:Item{
        //                 id:treeItem
        //                 width: parent.width
        //                 height:parent.height

        //                 BaseTextSmall{
        //                     id:itemText
        //                     text:styleData.value
        //                 }

        //             }
        //             TableViewColumn {
        //                 role: "display"
        //                 title: "Column 1"
        //                 width: parent.width
        //             }
        //             Component.onCompleted: {
        //                 // 树加载完数据后展开所有节点
        //                 expandAll(rootIndex);
        //             }
        //             function expandAll(parentIndex) {
        //                 for (var i = 0; i < model.rowCount(parentIndex); ++i) {
        //                     var childIndex = model.index(i, 0, parentIndex);
        //                     expand(childIndex);
        //                     expandAll(childIndex);
        //                 }
        //             }
        //         }

        //         Component {
        //             id:treeViewStyle            //树的自定义样式
        //             TreeViewStyle {
        //                 indentation: 20         //节点间隔
        //                 branchDelegate:Image { //节点的展开标记图
        //                     id:image
        //                     source: styleData.isExpanded ? "qrc:/qml/images/treeIcon/down.png" : "qrc:/qml/images/treeIcon/right.png"
        //                     width: 20
        //                     height:20
        //                     MouseArea{
        //                         anchors.fill: image
        //                         onClicked: {
        //                             if (myTree.isExpanded(styleData.index)) {
        //                                 myTree.collapse(styleData.index)
        //                             } else {
        //                                 myTree.expand(styleData.index)
        //                             }
        //                         }
        //                     }
        //                 }
        //                 rowDelegate: Rectangle {
        //                     height: 20
        //                     property bool isChecked: false
        //                     property var childItem: null
        //                     color: styleData.row % 2 === 0 ? "#efefef" : "white"
        //                     onIsCheckedChanged: {
        //                         if(isChecked===true)
        //                         {
        //                             childItem = selectchannel.createObject(layout)
        //                         }
        //                         else
        //                         {
        //                             childItem.destroy()
        //                         }
        //                     }

        //                     Rectangle{
        //                         anchors.fill: parent
        //                         color: isChecked?"#91b8e0":"transparent"
        //                         MouseArea{
        //                             anchors.fill: parent
        //                             onClicked: {
        //                                 isChecked=!isChecked
        //                             }
        //                         }
        //                     }
        //                 }

        //             }
        //         }
        //     }

        // }
        // Rectangle{
        //     id:rect
        //     width: parent.width
        //     height: 40
        //     color: "#585858"
        //     Row{
        //         width: parent.width
        //         height: parent.height
        //         BaseTextSmall{
        //             width: parent.width/4
        //             text: "名称"
        //             color: "#ffffff"
        //             height: 40
        //             horizontalAlignment: Text.AlignHCenter
        //             verticalAlignment: Text.AlignVCenter

        //         }
        //         BaseTextSmall{
        //             width: parent.width/4
        //             height: 40
        //             text: "数值"
        //             color: "#ffffff"
        //             horizontalAlignment: Text.AlignHCenter
        //             verticalAlignment: Text.AlignVCenter
        //         }
        //         BaseTextSmall{
        //             width: parent.width/4
        //             height: 40
        //             text: "单位"
        //             color: "#ffffff"
        //             horizontalAlignment: Text.AlignHCenter
        //             verticalAlignment: Text.AlignVCenter
        //         }
        //         BaseTextSmall{
        //             width: parent.width/4
        //             height: 40
        //             text: "颜色"
        //             color: "#ffffff"
        //             horizontalAlignment: Text.AlignHCenter
        //             verticalAlignment: Text.AlignVCenter
        //         }

        //     }

        // }
        // Flickable{
        //     width: parent.width
        //     height: parent.height-310
        //     contentHeight: parent.height
        //     clip: true
        //     Column{
        //         width: parent.width
        //         id: layout
        //     }
        // }
    // }
    // Component{
    //     id:selectchannel
    //     Item {
    //         width: layout.width
    //         height: 20
    //         Row{
    //             width: parent.width
    //             height: parent.height
    //             Item{
    //                 width: parent.width/4
    //                 height: parent.height
    //                 BaseTextSmall{
    //                     anchors.centerIn: parent
    //                     text: "name"
    //                 }
    //             }
    //             Item{
    //                 width: parent.width/4
    //                 height: parent.height
    //                 BaseTextSmall{
    //                     anchors.centerIn: parent
    //                     text: "value"
    //                 }
    //             }
    //             Item{
    //                 width: parent.width/4
    //                 height: parent.height
    //                 BaseTextSmall{
    //                     anchors.centerIn: parent
    //                     text: "v"
    //                 }
    //             }
    //             Item{
    //                 width: parent.width/4
    //                 height: parent.height
    //                 Rectangle{
    //                     width: 15
    //                     height: 15
    //                     anchors.centerIn: parent
    //                     color: "red"
    //                 }
    //             }
    //         }
    //     }

    // }
}
