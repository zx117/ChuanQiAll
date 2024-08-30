import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import MyTreeModel 1.0
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
                    text: "倍频程分析(CPB)"
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
                        textContent: "CPB通道"
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
                        text: "倍频类型:"
                    }
                    ListModel {
                        id: bptypemodel
                        ListElement { text: "CPB/倍频程" }
                        ListElement { text: "CPB/1/3倍频程" }
                        ListElement { text: "CPB/1/12倍频程" }
                    }
                    BaseCombobox{
                        id:  bptype
                        combWidth: 200
                        combHeight: 20
                        model: bptypemodel
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
                        text: "最小频率:"
                    }
                    ListModel {
                        id: minmodel
                        ListElement { text: "10" }
                        ListElement { text: "20" }
                        ListElement { text: "50" }
                        ListElement { text: "100" }
                    }
                    BaseCombobox{
                        id:  minbox
                        combWidth: 200
                        combHeight: 20
                        model: minmodel
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
                        text: "最大频率:"
                    }
                    ListModel {
                        id: maxmodel
                        ListElement { text: "5000" }
                        ListElement { text: "10000" }
                        ListElement { text: "20000" }
                        ListElement { text: "50000" }
                    }
                    BaseCombobox{
                        id:  maxbox
                        combWidth: 200
                        combHeight: 20
                        model: maxmodel
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
                        text: "窗函数:"
                    }
                    ListModel {
                        id: ckzmodel
                        ListElement { text: "汉宁" }
                        ListElement { text: "汉明" }
                        ListElement { text: "矩形窗" }
                        ListElement { text: "布莱克曼窗" }
                        ListElement { text: "Blackman-Harris" }
                        ListElement { text: "平顶窗" }
                        ListElement { text: "Bartlett" }
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
                        text: "重叠率:"
                    }
                    ListModel {
                        id: cdmodel
                        ListElement { text: "50" }
                        ListElement { text: "75" }
                        ListElement { text: "80" }
                        ListElement { text: "90" }
                    }
                    BaseCombobox{
                        id:  cdbox
                        combWidth: 200
                        combHeight: 20
                        model: cdmodel
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
                        text: "幅值谱:"
                    }
                    ListModel {
                        id: fzpmodel
                        ListElement { text: "Amplipude" }
                        ListElement { text: "dB" }

                    }
                    BaseCombobox{
                        id:  fzpbox
                        combWidth: 200
                        combHeight: 20
                        model: fzpmodel
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
                        text: "频率加权:"
                    }
                    ListModel {
                        id: pljqmodel
                        ListElement { text: "A" }
                        ListElement { text: "B" }
                        ListElement { text: "C" }
                        ListElement { text: "D" }
                        ListElement { text: "Z" }

                    }
                    BaseCombobox{
                        id:  pljqbox
                        combWidth: 200
                        combHeight: 20
                        model: pljqmodel
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
                    switchText: "计算单独频段能量总和"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "计算总体值"
                }
                BaseSwitch{
                    switchWidth: parent.width
                    switchHeight: 25
                    switchText: "提取制定频段"
                }

            }

         }
    }
}
