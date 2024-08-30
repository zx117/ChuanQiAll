import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
Slider {
    id:slider
    //滑块基础属性
    property int sliderWidth:200
    property int slideHeight: 25
    //背景
    property int backWidth:slider.availableWidth//availableHeight可用高度
    property int backHeight: 10
    property int backRadius: 6
    property color backColor: "#c6c6c6"
    property color slideOverColor: "#0170e3"
    //方块
    property int blockWidth: 15
    property int blockHeight: 15
    property color blockColor: "#c6c6c6"
    property color blockBroderColor: "#0170e3"
    property int blockRadius: 20

    width: sliderWidth
    height: slideHeight
    Layout.fillWidth: true
    background: Rectangle{
        x:0
        y:slider.topPadding+(slider.availableHeight-height)/2
        width:backWidth
        height:backHeight
        radius: backRadius
        color: backColor
        Rectangle{
            //滑块相对于其父元素的宽度的百分比
            id:block
            width:slider.visualPosition*parent.width
            height:parent.height
            color: slideOverColor
            border.color: slideOverColor
            border.width: 2
            radius: backRadius
        }
    }
    handle: Rectangle{
        //slider.leftPadding代表滑块的左填充
        //slider.availableWidth - width代表滑块可用宽度与滑块宽度的差值
        //slider.visualPosition是滑块相对于其父元素的视觉位置的比例或百分比
        x:(slider.width-width)*slider.visualPosition
        y:slider.topPadding+(slider.availableHeight-height)/2
        width:blockWidth
        height:blockHeight
        color: blockColor
        border.color: blockBroderColor
        border.width: 0.5
        radius: blockRadius
    }
}

