import QtQuick 2.15
import QtQuick.Controls 2.0
import Themes 1.0
import Widgets 1.0
Item {
    anchors.fill: parent

    Item {
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            id:set
            height: parent.height
            width: parent.width
            spacing: 15
            BaseTextSmall{
                font.bold: true
                text: "场站信息"
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "场站名:"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "安装容量:"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "频率死区(上)(Hz):"

                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "频率死区(下)(Hz):"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""

                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "调差率(上)(%):"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "调差率(下)(%):"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "功率稳定阈值(%Pn):"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "功率限幅(上)(%):"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "功率限幅(下)(%):"
                }
                BaseTextInput{
                    width: 100
                    textContent: ""
                }
            }
            BaseTextSmall{
                font.bold: true
                text: "测量配置"
            }
            Row{
                spacing: 10
                width: 200
                height: 30
                BaseTextSmall{
                    width: 150
                    text: "功率通道"
                }
                ListModel {
                    id: power
                    ListElement { text: "powerGroup0" }
                }
                BaseCombobox{
                    width: 150
                    model: simhw
                }
            }
            Row{
                spacing: 10
                width: 200
                height: 30
                BaseTextSmall{
                    width: 150
                    text: "频率通道"
                }
                ListModel {
                    id: freq
                    ListElement { text: "powerGroup0" }
                }
                BaseCombobox{
                    width: 150
                    model: freq
                }
            }
            Row{
                spacing: 10
                width: 400
                height: 30
                BaseTextSmall{
                    width: 150
                    text: "A相电压扰动通道"
                }
                ListModel {
                    id: au
                    ListElement { text: "powerGroup0" }
                }
                BaseCombobox{
                    width: 150
                    model: au
                }
            }
            Row{
                spacing: 10
                width: 400
                height: 30
                BaseTextSmall{
                    width: 150
                    text: "B相电压扰动通道"
                }
                ListModel {
                    id: bu
                    ListElement { text: "powerGroup0" }
                }
                BaseCombobox{
                    width: 150
                    model: bu
                }
            }
            Row{
                spacing: 10
                width: 400
                height: 30
                BaseTextSmall{
                    width: 150
                    text: "C相电压扰动通道"
                }
                ListModel {
                    id: cu
                    ListElement { text: "powerGroup0" }
                }
                BaseCombobox{
                    width: 150
                    model: cu
                }
            }
        }
    }
}
