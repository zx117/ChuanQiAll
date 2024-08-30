import QtQuick 2.15
import Themes 1.0
import Widgets 1.0
Item {

    Column{
        width: parent.width
        height: parent.height
        spacing: 0
        Rectangle {
            height: 40
            width: parent.width
            color: "#585858"
            BaseTextModerate {
                text: "时间设置"
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
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                BaseTextSmall{
                    anchors.centerIn: parent
                    text: "时间"
                }
            }
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                color: "#cfcfcf"
                BaseTextSmall{

                    anchors.centerIn: parent
                    text: "+"
                }
            }
            Rectangle{
                height: 40
                width: parent.width-120
                border.color: "black"
                BaseTextSmall{
                    anchors.centerIn: parent
                    text: "500ms"
                }
            }
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                color: "#cfcfcf"
                BaseTextSmall{

                    anchors.centerIn: parent
                    text: "-"
                }
            }

        }
        Rectangle {
            height: 40
            width: parent.width
            color: "#585858"
            BaseTextModerate {
                text: "Y轴设置"
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
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                BaseTextSmall{
                    anchors.centerIn: parent
                    text: "间隔"
                }
            }
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                color: "#cfcfcf"
                BaseTextSmall{

                    anchors.centerIn: parent
                    text: "+"
                }
            }
            Rectangle{
                height: 40
                width: parent.width-120
                border.color: "black"
                BaseTextSmall{
                    anchors.centerIn: parent
                    text: "5mv"
                }
            }
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                color: "#cfcfcf"
                BaseTextSmall{

                    anchors.centerIn: parent
                    text: "-"
                }
            }

        }
        Row{
            spacing: 0
            width: parent.width
            height: 40
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                BaseTextSmall{
                    anchors.centerIn: parent
                    text: "偏移"
                }
            }
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                color: "#cfcfcf"
                BaseTextSmall{

                    anchors.centerIn: parent
                    text: "+"
                }
            }
            Rectangle{
                height: 40
                width: parent.width-120
                border.color: "black"
                BaseTextSmall{
                    anchors.centerIn: parent
                    text: "0.00"
                }
            }
            Rectangle{
                height: 40
                width: 40
                border.color: "black"
                color: "#cfcfcf"
                BaseTextSmall{

                    anchors.centerIn: parent
                    text: "-"
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
        //     height: 40
        //     width: parent.width
        //     Rectangle{
        //         height: parent.height
        //         width: parent.width/4
        //         BaseTextSmall{
        //             anchors.centerIn: parent
        //             text: "通道名"
        //         }
        //     }
        //     Rectangle{
        //         height: parent.height
        //         width: parent.width/4
        //         BaseTextSmall{
        //             anchors.centerIn: parent
        //             text: "间隔"
        //         }
        //     }
        //     Rectangle{
        //         height: parent.height
        //         width: parent.width/4
        //         BaseTextSmall{
        //             anchors.centerIn: parent
        //             text: "偏移"
        //         }
        //     }
        //     Rectangle{
        //         height: parent.height
        //         width: parent.width/4
        //         BaseTextSmall{
        //             anchors.centerIn: parent
        //             text: "颜色"
        //         }
        //     }
        // }
        // ListModel{
        //     id:listmodel
        //     ListElement{name:"133/Ua";interval:"0";deviation:"0";color:"red"}
        //     ListElement{name:"133/Ub";interval:"0";deviation:"0";color:"green"}
        //     ListElement{name:"133/Uc";interval:"0";deviation:"0";color:"blue"}
        //     ListElement{name:"133/Ia";interval:"0";deviation:"0";color:"red"}
        //     ListElement{name:"133/Ib";interval:"0";deviation:"0";color:"green"}
        //     ListElement{name:"133/Ic";interval:"0";deviation:"0";color:"blue"}
        // }
        // ListView{
        //     width: parent.width
        //     height: parent.height-280
        //     clip: true
        //     model: listmodel
        //     delegate: Rectangle{
        //         width: parent.width
        //         height: 30
        //         color: index % 2 === 0? "#efefef" : "white"
        //         Row{
        //             anchors.fill: parent
        //             Item{
        //                 height: parent.height
        //                 width: parent.width/4
        //                 BaseTextSmall{
        //                     anchors.centerIn: parent
        //                     text: model.name
        //                 }
        //             }
        //             Item{
        //                 height: parent.height
        //                 width: parent.width/4
        //                 BaseTextSmall{
        //                     anchors.centerIn: parent
        //                     text: model.interval
        //                 }
        //             }
        //             Item{
        //                 height: parent.height
        //                 width: parent.width/4
        //                 BaseTextSmall{
        //                     anchors.centerIn: parent
        //                     text: model.deviation
        //                 }
        //             }
        //             Item{
        //                 height: parent.height
        //                 width: parent.width/4
        //                 Rectangle{
        //                     width: 20
        //                     height: 20
        //                     color: model.color
        //                     anchors.centerIn: parent

        //                 }
        //             }
        //         }
        //     }

        // }
    }
}
