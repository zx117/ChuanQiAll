import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Item {
    anchors.fill: parent
    Item {
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            anchors.fill: parent
            Item {
                width: parent.width
                height: 30
                BaseTextSmall{
                    text: "基于加权模式的声级计"
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    anchors.fill: parent
                    spacing: 10
                    BaseTextSmall{
                        width: 100
                        anchors.verticalCenter: parent.verticalCenter
                        text: "名称:"
                    }

                    BaseTextInput{
                        textBoxWidth:200
                        textBoxHeight: 20
                        anchors.verticalCenter: parent.verticalCenter
                        textContent: "声级计通道"
                    }
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    width: parent.width
                    height: parent.height
                    spacing: 10
                    BaseTextSmall{
                        width: 100
                        anchors.verticalCenter: parent.verticalCenter
                        text: "频率加权:"
                    }
                    ListModel {
                        id: jqmodel
                        ListElement { text: "A" }
                        ListElement { text: "B" }
                        ListElement { text: "C" }
                        ListElement { text: "D" }
                        ListElement { text: "Z" }
                    }
                    BaseCombobox{
                        id:  jqbox
                        combWidth: 200
                        combHeight: 20
                        model: jqmodel
                        currentIndex: 0
                    }
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    width: parent.width
                    height: parent.height
                    spacing: 10
                    BaseTextSmall{
                        width: 100
                        anchors.verticalCenter: parent.verticalCenter
                        text: "时间加权:"
                    }
                    ListModel {
                        id: timejqmodel
                        ListElement { text: "Fast(125ms)" }
                        ListElement { text: "Slow(1s)" }
                        ListElement { text: "Impulse(35ms/1.5s)" }
                    }
                    BaseCombobox{
                        id:  timejqbox
                        combWidth: 200
                        combHeight: 20
                        model: timejqmodel
                        currentIndex: 0
                    }
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    width: parent.width
                    height: parent.height
                    spacing: 10
                    BaseTextSmall{
                        width: 100
                        anchors.verticalCenter: parent.verticalCenter
                        text: "间隔时间:"
                    }
                    ListModel {
                        id: jgtimemodel
                        ListElement { text: "0.1" }
                        ListElement { text: "0.5" }
                        ListElement { text: "1" }
                        ListElement { text: "5" }
                        ListElement { text: "10" }
                    }
                    BaseCombobox{
                        id:  jgtimebox
                        combWidth: 200
                        combHeight: 20
                        model: jgtimemodel
                        currentIndex: 0
                    }
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    width: parent.width
                    height: parent.height
                    spacing: 10
                    BaseTextSmall{
                        width: 100
                        anchors.verticalCenter: parent.verticalCenter
                        text: "参考值:"
                    }
                    ListModel {
                        id: ckzmodel
                        ListElement { text: "1" }
                        ListElement { text: "20" }
                    }
                    BaseCombobox{
                        id:  ckzbox
                        combWidth: 200
                        combHeight: 20
                        model: ckzmodel
                        currentIndex: 0
                    }
                }
            }
            Item {
                width: parent.width
                height: 30
                BaseTextSmall{
                    text: "输出通道"
                }
            }
            Column{
                width: 100
                height: parent.height
                spacing: 5
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "L(x)_eq(等效声压计)"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "声压级时域数值[dB(x)]"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "频率加权升压[Pa]"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "L(x)_Ex_8h(8小时等效声级[dB(x)]和D噪声计量[%])"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25

                    switchText: "声级统计最大/最小值[dB(x)]"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "平均等效声压级计算"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "声压级最大/最小/平均统计"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "声级百分比占值统计"
                }
            }

         }
    }
}
