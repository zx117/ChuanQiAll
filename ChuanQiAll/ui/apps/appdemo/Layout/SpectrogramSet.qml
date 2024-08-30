import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.0
import Qt.labs.settings 1.0
import Themes 1.0
import Widgets 1.0
Item {
    id:spectrogram
    property string setpath: "./appdemoset/Setting.ini"
    Component.onCompleted: {
        if(setting.harmonic==="")
        {
            setting.harmonic=true
        }
        if(setting.interharmonic==="")
        {
            setting.interharmonic=false
        }
        if(setting.frequency==="")
        {
            setting.frequency=25
        }
        if(setting.yaxis==="")
        {
            setting.yaxis="Pecent"
        }
    }

    Settings {
        id:setting
        fileName:  setpath
        property bool harmonic:true
        property bool interharmonic:false
        property int  frequency: 25
        property string yaxis: "Pecent"
    }
    function setwriter(key,value)
    {
        if(key==="harmonic")
        {
            setting.harmonic=value
        }
        else if(key==="interharmonic")
        {
            setting.interharmonic=value
        }
        else if(key==="frequency")
        {
            setting.frequency=value
        }
        else if(key==="yaxis")
        {
            setting.yaxis=value
        }
    }

    Column{
        width: parent.width
        height: parent.height
        spacing: 0
        Rectangle {
            height: 40
            width: parent.width
            color: "#585858"
            BaseTextModerate {
                text: "波形"
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                anchors.rightMargin: 20
                color: "#ffffff"
            }
        }
        Row{
            spacing: 0
            width: parent.width
            height: 40

            ExclusiveGroup { id: buttonGroup }
            BaseRadioButton{
                id:radio
                width: parent.width/2
                radioButtonText:"谐波"
                exclusiveGroup: buttonGroup
                checked: setting.harmonic
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        radio.checked=!radio.checked
                        radio.forceActiveFocus()
                        if(radio.radioButtonText==="谐波")
                        {
                            setwriter("harmonic",radio.checked)
                            setwriter("interharmonic",!radio.checked)
                        }
                    }
                }
            }
            BaseRadioButton{
                id:radio1
                width: parent.width/2
                radioButtonText:"间谐波"
                exclusiveGroup: buttonGroup
                checked: setting.interharmonic
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        radio1.checked=!radio1.checked
                        radio1.forceActiveFocus()
                        if(radio1.radioButtonText==="间谐波")
                        {
                            setwriter("interharmonic",radio1.checked)
                            setwriter("harmonic",!radio1.checked)
                        }
                    }
                }
            }

        }
        Item {
            width: parent.width
            height: 40
            Row{
                width: parent.width
                height: parent.height

                BaseTextSmall{
                    anchors.verticalCenter: parent.verticalCenter
                    width: 40
                    text: "次数"
                }
                ListModel {
                    id: frequencymodel
                    ListElement { text: "25" }
                    ListElement { text: "50" }
                    ListElement { text: "100" }
                }
                BaseCombobox{
                    anchors.verticalCenter: parent.verticalCenter
                    model: frequencymodel
                    currentIndex: setting.frequency===25?0:(setting.frequency===50?1:2)
                    combHeight: 30
                    width: parent.width-40
                    onCurrentIndexChanged: {
                        // 获取选中的值
                        var selectedValue = frequencymodel.get(currentIndex).text;
                        setwriter("frequency",selectedValue)
                    }
                }
            }
        }

        Item {
            width: parent.width
            height: 40
            Row{
                width: parent.width
                height: parent.height
                BaseTextSmall{
                    anchors.verticalCenter: parent.verticalCenter
                    width: 40
                    text: "Y轴"
                }
                ListModel {
                    id: yaxismodel
                    ListElement { text: "Pecent" }
                    ListElement { text: "Value" }
                    ListElement { text: "Log(%)" }
                    ListElement { text: "Log(Val)" }
                }
                BaseCombobox{
                    anchors.verticalCenter: parent.verticalCenter
                    model: yaxismodel
                    currentIndex: setting.yaxis==="Pecent"?0:(setting.yaxis==="Value"?1:(setting.yaxis==="Log(%)"?2:3))
                    combHeight: 30
                    width: parent.width-40
                    onCurrentIndexChanged: {
                        // 获取选中的值
                        var selectedValue = yaxismodel.get(currentIndex).text;
                        setwriter("yaxis",selectedValue)
                    }
                }
            }
        }
    }
}
