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
                    text: "Creates a multi-stage FIR filter"
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
                        radioButtonText: "低通滤波"
                        exclusiveGroup: buttonGroup
                        enabled: true
                        checked: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "高通滤波"
                        exclusiveGroup: buttonGroup
                        enabled: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "带通"
                        exclusiveGroup: buttonGroup
                        enabled: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "带阻"
                        exclusiveGroup: buttonGroup
                        enabled: true
                    }
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    anchors.fill: parent
                    spacing: 10
                    BaseTextSmall{
                        anchors.verticalCenter: parent.verticalCenter
                        text: "滤波频率:"
                    }

                    BaseTextInput{
                        textBoxWidth:200
                        textBoxHeight: 20
                        anchors.verticalCenter: parent.verticalCenter
                        textContent: "0"
                    }
                    BaseTextSmall{
                        anchors.verticalCenter: parent.verticalCenter
                        text: "Hz"
                    }
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    anchors.fill: parent
                    spacing: 10
                    BaseTextSmall{
                        anchors.verticalCenter: parent.verticalCenter
                        text: "Window:"
                    }
                    ListModel {
                        id: window
                        ListElement { text: "Kaiser" }
                        ListElement { text: "Rectanglue" }
                        ListElement { text: "Hann" }
                        ListElement { text: "Hamming" }
                        ListElement { text: "Blackman" }
                        ListElement { text: "Blackman/Harris" }
                        ListElement { text: "Flat Top" }
                        ListElement { text: "Bartlett" }
                        ListElement { text: "Cosine" }
                    }
                    BaseCombobox{
                        id:  windowbox
                        anchors.verticalCenter: parent.verticalCenter
                        combWidth: 150
                        combHeight: 20
                        model: window
                        currentIndex: 0
                    }
                    BaseTextSmall{
                        anchors.verticalCenter: parent.verticalCenter
                        text: "Filter length:"
                    }

                    BaseTextInput{
                        textBoxWidth:200
                        textBoxHeight: 20
                        anchors.verticalCenter: parent.verticalCenter
                        textContent: "31"
                    }
                }
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
                        textContent: "FIR Filter Channels"
                    }
                }
            }
        }
    }
}
