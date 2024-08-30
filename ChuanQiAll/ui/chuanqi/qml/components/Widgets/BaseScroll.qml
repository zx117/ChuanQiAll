import QtQuick 2.15
import QtQuick.Controls 2.5
Rectangle {
    width: 20
    height: 200
    color: "#DDDDDD"

    property real contentHeight: 1000 // 假设内容的高度为 1000

    Rectangle {
        id: handle
        width: parent.width
        height: parent.width // 滑块的高度与宽度相同
        color: "steelblue"
        border.color: "black"
        radius: width / 2

        property real handlePosition: 0
        property real handleHeight: (parent.height * parent.height) / contentHeight

        MouseArea {
            id: handleMouseArea
            anchors.fill: parent
            drag.target: handle

            onPositionChanged: {
                var positionRatio = handlePosition / (parent.height - handle.height);
                contentItem.y = -positionRatio * (contentHeight - contentItem.height);
            }

            // 防止滑块超出滚动条范围
            onReleased: {
                if (handle.y < 0) {
                    handle.y = 0;
                } else if (handle.y > parent.height - handle.height) {
                    handle.y = parent.height - handle.height;
                }
            }
        }
    }

    Rectangle {
        id: contentItem
        width: parent.width
        height: contentHeight
        color: "lightgray"
        border.color: "black"

        Rectangle {
            width: parent.width
            height: 50
            color: "red"
            border.color: "black"
            Text {
                text: "Content"
                anchors.centerIn: parent
            }
        }
    }
}
