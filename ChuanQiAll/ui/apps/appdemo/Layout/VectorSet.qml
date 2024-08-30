import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.0
import Themes 1.0
import Widgets 1.0
Item {
    id:vectorset
    Column{
        width: parent.width
        height: parent.height
        spacing: 0
        Rectangle {
            height: 40
            width: parent.width
            color: "#585858"
            BaseTextModerate {
                text: "谐波设置"
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
            ListModel {
                id: waveform
                ListElement { txt: "基波"}
                ListElement { txt: "谐波"}
            }
            ExclusiveGroup { id: buttonGroup }
            ListView {
                id: listView
                width: parent.width
                height: 40
                model: waveform
                orientation: ListView.Horizontal
                interactive: false
                delegate:BaseRadioButton{
                    id:radio
                    width: vectorset.width/2
                    radioButtonText:txt
                    exclusiveGroup: buttonGroup
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
                BaseTextInput{
                    width: parent.width-40
                    height: 30
                    anchors.verticalCenter: parent.verticalCenter
                    textContent: "2"
                }
            }
        }
        // Rectangle {
        //     height: 40
        //     width: parent.width
        //     color: "#585858"
        //     BaseTextModerate {
        //         text: "通道"
        //         anchors.verticalCenter: parent.verticalCenter
        //         anchors.right: parent.right
        //         anchors.rightMargin: 20
        //         color: "#ffffff"
        //     }

        // }
        // Row{
        //     width: parent.width
        //     height: parent.height-160
        //     ListModel{
        //         id:listmodel
        //         ListElement{
        //             name:"powerGroup0"
        //             text1:"Ua"
        //             text2:"Ub"
        //             text3:"Uc"
        //             text4:"Ia"
        //             text5:"Ib"
        //             text6:"Ic"
        //         }
        //     }
        //     Item {
        //         height: parent.height
        //         width: 10
        //     }
        //     ListView{
        //         width: parent.width
        //         height: parent.height
        //         model: listmodel
        //         delegate: Item {
        //             width: parent.width
        //             height: parent.height
        //             Column{
        //                 width: parent.width
        //                 height: parent.height
        //                 Item {
        //                     id: name
        //                     width: parent.width
        //                     height: 30
        //                     BaseTextSmall{
        //                         anchors.verticalCenter: parent.verticalCenter
        //                         text: model.name
        //                     }
        //                 }
        //                 Item{
        //                     width: 60
        //                     height: 30
        //                     BaseCheckBox{
        //                         width: parent.width
        //                         height: parent.height
        //                         visible: model.text1===""?false:true
        //                         checkText: model.text1
        //                     }
        //                 }
        //                 Item{
        //                     width: 60
        //                     height: 30
        //                     BaseCheckBox{
        //                         width: parent.width
        //                         height: parent.height
        //                         visible: model.text2===""?false:true
        //                         checkText: model.text2
        //                     }
        //                 }
        //                 Item{
        //                     width: 60
        //                     height: 30
        //                     BaseCheckBox{
        //                         width: parent.width
        //                         height: parent.height
        //                         visible: model.text3===""?false:true
        //                         checkText: model.text3
        //                     }
        //                 }
        //                 Item{
        //                     width: 60
        //                     height: 30
        //                     BaseCheckBox{
        //                         width: parent.width
        //                         height: parent.height
        //                         visible: model.text4===""?false:true
        //                         checkText: model.text4
        //                     }
        //                 }
        //                 Item{
        //                     width: 60
        //                     height: 30
        //                     BaseCheckBox{
        //                         width: parent.width
        //                         height: parent.height
        //                         visible: model.text5===""?false:true
        //                         checkText: model.text5
        //                     }
        //                 }
        //                 Item{
        //                     width: 60
        //                     height: 30
        //                     BaseCheckBox{
        //                         width: parent.width
        //                         height: parent.height
        //                         visible: model.text6===""?false:true
        //                         checkText: model.text6
        //                     }
        //                 }
        //             }
        //         }
        //     }

        // }

    }
}
