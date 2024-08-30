import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/qml/images"
Flickable {
    id: flickable
    width: parent.width
    height: root.height // 设置高度为根元素的高度，确保与内容高度一致
    boundsBehavior: Flickable.StopAtBounds // 限制拖拽的范围
    clip: true // 裁剪超出部分
    property var listmodel: null

    ListView {
        id: root
        width: flickable.width
        height: contentHeight // 使用 contentHeight 以确保适应内容的高度
        model: listmodel
        delegate: Item {
            width: root.width
            height: 50
            Rectangle {
                width: root.width
                height: 50
                color: index % 2 === 0 ? "#f0f0f0" : "#e0e0e0"
                Text {
                    anchors.centerIn: parent
                    text: name+" "+value
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Clicked:", model.name)
                    }
                }
            }
        }
    }

    ScrollBar.vertical: ScrollBar {
        policy: ScrollBar.AlwaysOn // 始终显示垂直滚动条
        size: flickable.height / root.contentHeight // 设置滚动条大小

        onPositionChanged: {
            var maxContentY = root.contentHeight - flickable.height;
            flickable.contentY = position * maxContentY; // 设置内容的垂直偏移量

            if (flickable.contentY < 0) {
                flickable.contentY = 0; // 当内容在顶部时，确保内容偏移量不小于0
            } else if (flickable.contentY > maxContentY) {
                flickable.contentY = maxContentY; // 当内容在底部时，确保内容偏移量不大于内容高度减去视图高度
            }
        }
    }
}
