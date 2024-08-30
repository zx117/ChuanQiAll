import QtQuick 2.15
import QtQuick.Controls 2.0
import Themes 1.0
import Widgets 1.0
Item {
    anchors.fill: parent
    property string stationName:""
    property string lineName:""
    property string minimumShortCircuitCapacity:""
    property string equipmentInstallationCapacity:""
    property string userAgreementCapacity:""
    property string steadyStateDataLog:""
    property string startTime:""
    property string endTime:""

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
                text: "线路设置"
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "站名:"
                }
                BaseTextInput{
                    width: 100
                    textContent: stationName
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "线路名:"
                }
                BaseTextInput{
                    width: 100
                    textContent: lineName
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "最小短路容量(MW):"

                }
                BaseTextInput{
                    width: 100
                    textContent: minimumShortCircuitCapacity
                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "设备安装容量(MW):"
                }
                BaseTextInput{
                    width: 100
                    textContent: equipmentInstallationCapacity

                }
            }
            Row{
                spacing: 10
                BaseTextSmall{
                    width: 150
                    text: "用户协议容量(MW):"
                }
                BaseTextInput{
                    id:useagree
                    width: 100
                    textContent: userAgreementCapacity
                }
            }
            BaseTextSmall{
                font.bold: true
                text: "测试项目"
            }
            BaseRadioButton{
                checked: steadyStateDataLog
                radioButtonText: "稳态数据记录"

            }
            BaseTextSmall{
                font.bold: true
                text: "分析"
            }
            Row{
                spacing: 10
                width: 200
                height: 30
                BaseTextSmall{
                    width: 60
                    text: "功率组"
                }
                ListModel {
                    id: simhw
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
                    width: 60
                    text: "开始时间"
                }
                BaseTextInput{
                    width: 150
                    textContent: startTime
                }
            }
            Row{
                spacing: 10
                width: 200
                height: 30
                BaseTextSmall{
                    width: 60
                    text: "结束时间"
                }
                BaseTextInput{
                    width: 150
                    textContent: endTime
                }
            }
        }
    }
}
