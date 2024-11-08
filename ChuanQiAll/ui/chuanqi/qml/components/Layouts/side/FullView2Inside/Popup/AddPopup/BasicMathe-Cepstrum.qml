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
                    text: "Create a new cepstrum calcuation of the following type"
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    anchors.fill: parent
                    spacing: 10
                    ExclusiveGroup { id: buttonGroup }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "幅值"
                        exclusiveGroup: buttonGroup
                        enabled: true
                        checked: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "Power"
                        exclusiveGroup: buttonGroup
                        enabled: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "Complex"
                        exclusiveGroup: buttonGroup
                        enabled: true
                    }

                }
            }
            BaseSwitch{
                switchText: "Active liftering(filtering of the cepstrum in queferncy domain)"
            }

            Item{
                width: parent.width
                height: 30
                Row{
                    anchors.fill: parent
                    spacing: 10
                    BaseTextSmall{
                        anchors.verticalCenter: parent.verticalCenter
                        text: "名称"
                    }
                    BaseTextInput{
                        textBoxWidth:200
                        textBoxHeight: 20
                        anchors.verticalCenter: parent.verticalCenter
                        textContent: "Cepstrum Channels"
                    }
                }
            }
        }
    }
}
