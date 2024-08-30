import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import QtQml.Models 2.2
import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/qml/images"
import Widgets 1.0
import Themes 1.0
Item{
    id:flickable
    property var treeModel: null

    TreeView{
        id:myTree
        width: parent.width
        height: parent.height
        style: treeViewStyle
        headerVisible: false
        frameVisible: false//不显示边框
        backgroundVisible: false
        model:treeModel
        itemDelegate:Item{
            id:treeItem
            width: parent.width
            height:30
            Rectangle{
                height: 30
                width: parent.width
                color: treeItem.activeFocus?"#005bb6":"transparent"
                border.color: treeItem.activeFocus?"#005bb6":"transparent"
                opacity: 0.2
            }
            Row
            {
                anchors.verticalCenter: parent.verticalCenter
                Image {
                    id: image
                    width: 30
                    height: 30
                    source: model.embellish
                }
                BaseTextSmall {
                    id:itemText
                    anchors.verticalCenter: parent.verticalCenter
                    text:model.filename
                }
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    treeItem.forceActiveFocus()
                }
            }

        }
        TableViewColumn {

        }
    }

    Component {
        id:treeViewStyle
        TreeViewStyle {
            indentation: 30
            branchDelegate:Image {
                id:image
                source: styleData.isExpanded ? "qrc:/qml/images/treeIcon/treedown.png" : "qrc:/qml/images/treeIcon/treeright.png"
                width: 20
                height:20
            }
            rowDelegate: Rectangle {
                height: 30
                color: "transparent"
            }
        }
    }
}
