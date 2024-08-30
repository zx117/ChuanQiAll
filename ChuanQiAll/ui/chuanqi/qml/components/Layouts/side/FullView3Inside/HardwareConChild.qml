import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0

Item {
    id:hardwaresetup
    width: parent.width
    height: 690
    ColumnLayout{
        spacing: 10
        Rectangle{
            width: setif.width/2+100
            height:30
            color: "#efefef"
            BaseTextSmall{
                anchors.verticalCenter:parent.verticalCenter
                text: model.txt
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "设备1"
            }
            ListModel {
                id: sb
                ListElement { text: "True" }
                ListElement { text: "False" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: sb
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "名称"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "XXXXXXXX"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "端口"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "0"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "通道"
            }
            ListModel {
                id: td
                ListElement { text: "xxxxxx1" }
                ListElement { text: "xxxxxx2" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: td
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "设备2"
            }
            ListModel {
                id: sb1
                ListElement { text: "True" }
                ListElement { text: "False" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: sb1
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "名称"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "XXXXXXXX"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "端口"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "0"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "通道"
            }
            ListModel {
                id: td1
                ListElement { text: "xxxxxx1" }
                ListElement { text: "xxxxxx2" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: td1
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "设备3"
            }
            ListModel {
                id: sb2
                ListElement { text: "True" }
                ListElement { text: "False" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: sb2
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "名称"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "XXXXXXXX"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "端口"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "0"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "通道"
            }
            ListModel {
                id: td2
                ListElement { text: "xxxxxx1" }
                ListElement { text: "xxxxxx2" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: td2
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "设备4"
            }
            ListModel {
                id: sb3
                ListElement { text: "True" }
                ListElement { text: "False" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: sb3
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "名称"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "XXXXXXXX"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "端口"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "0"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "通道"
            }
            ListModel {
                id: td3
                ListElement { text: "xxxxxx1" }
                ListElement { text: "xxxxxx2" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: td3
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "设备5"
            }
            ListModel {
                id: sb4
                ListElement { text: "True" }
                ListElement { text: "False" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: sb4
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "名称"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "XXXXXXXX"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "端口"
            }
            BaseTextInput{
                width: setif.width/2-220
                textContent: "0"
            }
        }
        Row{
            spacing: 10
            BaseTextSmall{
                width: 200
                text: "通道"
            }
            ListModel {
                id: td4
                ListElement { text: "xxxxxx1" }
                ListElement { text: "xxxxxx2" }
            }
            BaseCombobox{
                width: setif.width/2-220
                model: td4
            }
        }
    }
}
