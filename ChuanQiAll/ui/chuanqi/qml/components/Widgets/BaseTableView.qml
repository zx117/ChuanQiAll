import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2

TableView {
    id: tableView
    width: parent.width
    height: parent.height
    property var tablemodel: null
    model: tablemodel

    TableViewColumn {
        role: "1"
        title: "2"
        width: 100
    }

    TableViewColumn {
        role: "3"
        title: "4"
        width: 100
    }

    TableViewColumn {
        role: "5"
        title: "6"
        width: 100
    }

    style: TableViewStyle {
        // 设置表头样式
        headerDelegate: ItemDelegate {
            width: tableView.columnWidthProvider != null ? tableView.columnWidthProvider(header.role) : 100
            height: 30
            contentItem: Text {
                text: header.title // 使用 header.title 而不是 headerData
                font.bold: true
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
            background: Rectangle {
                color: "#333333"
            }
        }

        // 设置表格项样式
        itemDelegate: ItemDelegate {
            width: tableView.columnWidthProvider != null ? tableView.columnWidthProvider(model.role) : 100
            height: 30
            contentItem: Text {
                text: model.roleData
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
            background: Rectangle {
                color: styleData.selected ? "lightblue" : "transparent"
            }
        }
    }
}
