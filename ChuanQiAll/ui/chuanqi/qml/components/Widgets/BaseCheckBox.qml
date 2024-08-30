import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4
import Themes 1.0
import Widgets 1.0

Item {
    id: rec;
    // CheckBox基础属性
    property alias checked: control.checked;       // 复选框选中
    property alias checkedState: control.checkedState; // 选中状态
    property alias exclusiveGroup: control.exclusiveGroup; // 复选框互斥组
    property int checkBoxSize: 16;  // CheckBox大小 默认正方形
    property bool checkBackColorVisible: true
    //checkbox边框颜色
    property color checkBoxBroderColor: "#7b7b7b"  //未按下时边框颜色
    property color activeFocusCheckBoxBroderColor: "#4d7dbe"//按下后边框颜色
    // 复选框字体属性
    property int fontPointSize: 12; // 复选框 文字大小
    property string fontFamily: "微软雅黑";  // 文字字体
    property color fontColor: "black"; // 字体颜色
    property string checkText: "";    //文本
    //对号
    property string iconSource: "qrc:/qml/images/button/Check" //图标
    // label颜色
    property color backColor: "transparent"   //透明
    property color borderColor: "transparent"
    property color activeFocusBackColor: "#9db6d7"
    property color activeFocusBorderColor: "#98adc9"

    width: control.width + rec.checkText.length
    height: control.height
    CheckBox {
        id: control
        anchors.verticalCenter: parent.verticalCenter
        onClicked: {
            rec.forceActiveFocus()
        }
        style: CheckBoxStyle {
            spacing: 3
            indicator: Rectangle {
                implicitWidth: checkBoxSize
                implicitHeight: checkBoxSize
                color: "#efefef"
                border.color: rec.activeFocus ? activeFocusCheckBoxBroderColor : checkBoxBroderColor
                border.width: 1
                radius: 3
                Image {
                    id:checkicon
                    anchors.fill: parent
                    source: control.checked?rec.iconSource:""

                }
            }
            label: BaseTextSmall {
                text: rec.checkText;
                leftPadding: 3
                rightPadding: 3
                visible: checkBackColorVisible
                Rectangle{
                    z:-1
                    opacity:0.5
                    radius: 5
                    visible: checkBackColorVisible
                    anchors.fill: parent
                    border.color: rec.activeFocus&&rec.checkText!==""?activeFocusBorderColor:borderColor
                    color: rec.activeFocus&&rec.checkText!==""?activeFocusBackColor:backColor
                }
            }
        }
    }
}
