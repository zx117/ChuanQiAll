import QtQuick 2.15
import QtQuick.Controls 2.5

Rectangle{
    property string tooltxt: ""

    width: 40
    height: 30
    x:parent.x
    y:parent.y-30
    BaseTextSmall{
        text: tooltxt
    }
}

// ToolTip{
//     property string tipText: ""
//     property bool toolVisible
//     visible: toolVisible
//     delay: 500 // 显示前的延迟时间
//     text: tipText

// }
