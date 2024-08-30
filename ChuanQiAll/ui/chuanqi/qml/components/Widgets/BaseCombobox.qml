import QtQuick 2.15
import QtQuick.Controls 2.5
import Themes 1.0
import Widgets 1.0
ComboBox {
    id: combobox;
    signal currentDataChanged(var text);
    property int combHeight: 20;       //复选框高度
    property int combWidth: 140;       //复选框宽度
    property int combRadius: 2;
    property int popupHeight: 400;     //下拉框高度
    property int indHeight: 15;         //下拉按钮高度
    property int indWidth: 15;         //下拉按钮宽度
    property string disColor: "transparent";
    property int textLeftPadding: width * 0.4;
    property int beforeIndex: 0;
    property int itemHeight: 40

    width: combWidth;
    height: combHeight;

    delegate: ItemDelegate {
        width: combobox.width
        height: combobox.height
        BaseTextModerate{
            text: modelData
            color: combobox.currentIndex === index?"white":"black"
            leftPadding: 10
        }
        background: Rectangle {
            color: combobox.currentIndex === index ? "#c0cad4" : "transparent"
            Rectangle {
                color: combobox.currentIndex === index ? "#005bb6" : "transparent"
                height: parent.height
                width: 4
                anchors.left: parent.left
                anchors.bottom: parent.bottom
            }
        }
    }

    //指示器
    indicator: Image {
        source: combobox.activeFocus?"qrc:/qml/images/combobox/right(1)":"qrc:/qml/images/combobox/right"
        width: indWidth
        height: indHeight
        x: combobox.width - width-2 // 从右侧开始
        y: combobox.height-height
        // y: combobox.topPadding+height+1// 垂直居中
    }

    //显示的文字
    contentItem: BaseTextSmall {
        text: combobox.displayText
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        leftPadding: 10
    }

    Rectangle {
        x: 0
        y: 0
        width: 1
        height: parent.height/3
        color: combobox.activeFocus?"#005bb6":"#a4a4a4"
        anchors.bottom: down.top

    }

    // 绘制右边框
    Rectangle {
        x: parent.width - 1
        y: 0
        width: 1
        height: parent.height/3
        color: combobox.activeFocus?"#005bb6":"#a4a4a4"
        anchors.bottom: down.top

    }

    // 绘制下边框
    Rectangle {
        id:down
        x: 0
        y: parent.height - 1
        width: parent.width
        height: 1
        color: combobox.activeFocus?"#005bb6":"#a4a4a4"

    }

    background: Rectangle {
        implicitWidth: parent.width;
        implicitHeight: parent.height;
        color: combobox.activeFocus ? "#c0cad4" : disColor;
        radius: combRadius
    }


    onCurrentIndexChanged: {
        if(combobox.model && parseFloat(currentIndex) !== parseFloat(beforeIndex)) {
            beforeIndex = currentIndex;
            displayText = combobox.model[currentIndex];
            currentDataChanged(displayText);

        }
    }

}
