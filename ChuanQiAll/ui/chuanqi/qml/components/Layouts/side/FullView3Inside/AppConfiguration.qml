import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Rectangle{
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    property int rectCount: 0
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor

    Item {
        id:appcon
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            spacing: 10
            width: parent.width
            height: parent.height
            Rectangle{
                id:apprect
                width:appcon.width
                height: 300
                color: "#efefef"
                Row{
                    spacing: 10
                    Column{
                        spacing: 10
                        Rectangle{
                            width: apprect.width/3
                            height: 30
                            color: "#a4a4a4"
                            Row{
                                spacing: 10
                                BaseTextSmall {
                                    width: 100
                                    text: qsTr("功率组")
                                }
                                BaseTextSmall {
                                    text: qsTr("PowerGroup0")
                                }
                            }
                        }
                        Row{
                            spacing: 10
                            BaseTextSmall {
                                width: 100
                                text: qsTr("接线方式")
                            }
                            ListModel {
                                id: wiring
                                ListElement { text: "Single Phase" }
                                ListElement { text: "3-Phase star" }
                                ListElement { text: "3-Phase delta" }
                                ListElement { text: "3-Phase Two wattmeter" }
                                ListElement { text: "2-Phase" }
                            }
                            BaseCombobox{
                                model: wiring
                                currentIndex: 1
                            }
                        }
                        Rectangle{

                            width: apprect.width/3
                            height: 30
                            color: "#a4a4a4"
                            BaseTextSmall{
                                anchors.verticalCenter: parent.verticalCenter
                                text: "接线方式"
                            }
                        }
                        Row{
                            spacing: 10
                            BaseTextSmall {
                                id:txt
                                text: qsTr("LV1")
                            }
                            ListModel {
                                id: vl1
                                ListElement { text: "" }

                            }
                            BaseCombobox{
                                combWidth:apprect.width/6-txt.width-20
                                model: vl1
                                currentIndex: 1
                            }
                            BaseTextSmall {
                                text: qsTr("LV1")
                            }
                            ListModel {
                                id: il1
                                ListElement { text: "" }

                            }
                            BaseCombobox{
                                combWidth:apprect.width/6-txt.width-20
                                model: il1
                                currentIndex: 1
                            }
                        }
                        Row{
                            spacing: 10
                            BaseTextSmall {
                                text: qsTr("LV2")
                            }
                            ListModel {
                                id: vl2
                                ListElement { text: "" }

                            }
                            BaseCombobox{
                                combWidth:apprect.width/6-txt.width-20
                                model: vl2
                                currentIndex: 1
                            }
                            BaseTextSmall {
                                text: qsTr("LV2")
                            }
                            ListModel {
                                id: il2
                                ListElement { text: "" }

                            }
                            BaseCombobox{
                                combWidth:apprect.width/6-txt.width-20
                                model: il2
                                currentIndex: 1
                            }
                        }
                        Row{
                            spacing: 10
                            BaseTextSmall {
                                text: qsTr("LV3")
                            }
                            ListModel {
                                id: vl3
                                ListElement { text: "" }

                            }
                            BaseCombobox{
                                combWidth:apprect.width/6-txt.width-20
                                model: vl3
                                currentIndex: 1
                            }
                            BaseTextSmall {
                                text: qsTr("LV3")
                            }
                            ListModel {
                                id: il3
                                ListElement { text: "" }

                            }
                            BaseCombobox{
                                combWidth:apprect.width/6-txt.width-20
                                model: il3
                                currentIndex: 1
                            }
                        }
                        Row{
                            spacing: 10
                            BaseTextSmall {
                                text: qsTr("LV4")
                            }
                            ListModel {
                                id: vl4
                                ListElement { text: "" }

                            }
                            BaseCombobox{
                                combWidth:apprect.width/6-txt.width-20
                                model: vl4
                                currentIndex: 1
                            }
                            BaseTextSmall {
                                text: qsTr("LV4")
                            }
                            ListModel {
                                id: il4
                                ListElement { text: "" }

                            }
                            BaseCombobox{
                                combWidth:apprect.width/6-txt.width-20
                                model: il4
                                currentIndex: 1
                            }
                        }

                    }
                    Item{
                        width:apprect.width*2/3-10
                        height: apprect.height
                        TabView {
                            anchors.fill: parent
                            Tab {
                                title: "通用"
                                Item {
                                    Column{
                                        spacing: 10
                                        Row{
                                            spacing: 10
                                            Row{
                                                spacing: 10
                                                BaseTextSmall {
                                                    width: 110
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: qsTr("频率(Hz)")
                                                }
                                                ListModel {
                                                    id: frequency
                                                    ListElement { text: "50" }
                                                    ListElement { text: "60" }
                                                }
                                                BaseCombobox{
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    combWidth: 100
                                                    model: frequency
                                                    currentIndex: 0
                                                }
                                            }
                                            Row{
                                                spacing: 10
                                                BaseTextSmall {
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    width: 110
                                                    text: qsTr("频率源")
                                                }
                                                ListModel {
                                                    id: frequencysource
                                                    ListElement { text: "电压源" }
                                                    ListElement { text: "电流源" }
                                                }
                                                BaseCombobox{
                                                    combWidth: 100
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    model: frequencysource
                                                    currentIndex: 0
                                                }
                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            Row{
                                                spacing: 10
                                                BaseTextSmall {
                                                    width: 110
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: qsTr("额定相电压(V)")
                                                }
                                                BaseTextInput{
                                                    textBoxWidth:100
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    textContent: "230"

                                                }
                                            }
                                            Row{
                                                spacing: 10
                                                BaseTextSmall {
                                                    width: 110
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: qsTr("输出单位")
                                                }
                                                ListModel {
                                                    id: output
                                                    ListElement { text: "V.A.W" }
                                                    ListElement { text: "V.A.KW" }
                                                    ListElement { text: "V.A.W" }
                                                    ListElement { text: "KV.A.KW" }
                                                    ListElement { text: "KV.A.MW" }
                                                    ListElement { text: "KV.KA.MW" }
                                                    ListElement { text: "KV.A.GW" }
                                                }
                                                BaseCombobox{
                                                    combWidth: 100
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    model: output
                                                    currentIndex: 0
                                                }
                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            Row{
                                                spacing: 10
                                                BaseTextSmall {
                                                    width: 110
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: qsTr("额定线电压(V)")
                                                }
                                                BaseTextInput{
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    textBoxWidth:100
                                                    textContent: ""
                                                }
                                            }
                                            Row{
                                                spacing: 10
                                                BaseTextSmall {
                                                    width: 110
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: qsTr("存储间隔(秒)")
                                                }
                                                ListModel {
                                                    id: savetime
                                                    ListElement { text: "0.2" }
                                                    ListElement { text: "3" }
                                                    ListElement { text: "60" }
                                                }
                                                BaseCombobox{
                                                    combWidth: 100
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    model: savetime
                                                    currentIndex: 0
                                                }
                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            BaseTextSmall {
                                                width: 110
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: qsTr("CT一次电流(A)")
                                            }
                                            BaseTextInput{
                                                textBoxWidth:100
                                                anchors.verticalCenter: parent.verticalCenter
                                                textContent: ""
                                            }
                                        }
                                    }
                                }
                            }

                            Tab {
                                title: "谐波"
                                Item {
                                    Column{
                                        spacing: 10
                                        Row{
                                            spacing:50
                                            Row{
                                                spacing: 10
                                                BaseTextSmall{
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: "计算谐波"
                                                }
                                                BaseSwitch{
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    switchText: ""
                                                }
                                            }
                                            Row{
                                                spacing: 10
                                                BaseTextSmall{
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    text: "计算高次谐波"
                                                }
                                                BaseSwitch{
                                                    anchors.verticalCenter: parent.verticalCenter
                                                    switchText: ""
                                                }
                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            BaseTextSmall{
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: "最大谐波阶次"
                                            }
                                            BaseTextInput{
                                                anchors.verticalCenter: parent.verticalCenter
                                                textContent: "50"
                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            BaseTextSmall{
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: "谐波总畸变率"
                                            }
                                            BaseTextInput{
                                                anchors.verticalCenter: parent.verticalCenter
                                                textContent: "40"
                                            }
                                        }
                                    }
                                }
                            }
                            Tab {
                                title: "闪变"
                                Item {
                                    Column{
                                        spacing: 10
                                        Row{
                                            spacing: 10
                                            BaseTextSmall{
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: "计算谐波"
                                            }
                                            BaseSwitch{
                                                anchors.verticalCenter: parent.verticalCenter
                                                switchText: ""
                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            BaseTextSmall{
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: "输入形式"
                                            }
                                            ListModel {
                                                id: input
                                                ListElement { text: "230" }
                                                ListElement { text: "110" }
                                            }
                                            BaseCombobox{
                                                combWidth: 100
                                                anchors.verticalCenter: parent.verticalCenter
                                                model: input
                                                currentIndex: 0
                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            BaseTextSmall{
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: "短时闪变(分)"
                                            }
                                            BaseSwitch{
                                                anchors.verticalCenter: parent.verticalCenter
                                                switchText: ""

                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            BaseTextSmall{
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: "长时闪变(分)"
                                            }
                                            BaseSwitch{
                                                anchors.verticalCenter: parent.verticalCenter
                                                switchText: ""
                                            }
                                        }
                                    }
                                }
                            }
                            Tab {
                                title: "周期值"
                                Item {
                                    Column{
                                        spacing: 10
                                        Row{
                                            spacing: 10
                                            BaseTextSmall{
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: "周期计算"
                                            }
                                            BaseSwitch{
                                                anchors.verticalCenter: parent.verticalCenter
                                                switchText: ""
                                            }
                                        }
                                        Row{
                                            spacing: 10
                                            BaseTextSmall{
                                                anchors.verticalCenter: parent.verticalCenter
                                                text: "频率阈值(%)"
                                            }
                                            BaseTextInput{
                                                anchors.verticalCenter: parent.verticalCenter
                                                textContent: ""
                                            }
                                        }
                                        Column{
                                            spacing: 10
                                            BaseTextSmall{
                                                text: "计算周期"
                                            }
                                            ExclusiveGroup { id: buttonGroup }
                                            Row{
                                                spacing: 10
                                                RadioButton{
                                                    exclusiveGroup:buttonGroup
                                                }
                                                BaseTextSmall{
                                                    text: "周期"
                                                }
                                            }
                                            Row{
                                                spacing: 10
                                                RadioButton{
                                                    exclusiveGroup:buttonGroup
                                                }
                                                BaseTextSmall{
                                                    text: "自动"
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            style: TabViewStyle {
                                frameOverlap: 1
                                tab: Item {
                                    id:item
                                    implicitWidth: 70
                                    implicitHeight: 40

                                    Column{
                                        width: parent.width
                                        height: parent.height
                                        anchors.topMargin: 10
                                        Rectangle {
                                            width: parent.width
                                            height: parent.height-10
                                            color: styleData.selected ?"lightblue":"#efefef"
                                            BaseTextSmall {
                                                anchors.horizontalCenter: parent.horizontalCenter
                                                text: styleData.title
                                                color: styleData.selected ? "blue" : "black"
                                            }

                                        }
                                        Rectangle{
                                            width: item.width
                                            height: 4
                                            color: styleData.selected ? "blue" : "#efefef"
                                        }
                                        Item{
                                            width: item.width
                                            height: 6
                                        }
                                    }
                                }
                                frame: Item {

                                }
                            }

                        }

                    }
                }
            }
        }
    }
    function addRectangle() {
        var newRect = Qt.createQmlObject(
                    'import QtQuick 2.15;
                  Rectangle {
                  width:setif.width;
                  height: 200;
                  color: "#efefef"
                  }', parent)
        newRect.x = 10
        newRect.y = rectCount * 60 // 控制矩形的间距
        rectCount++
    }
}
