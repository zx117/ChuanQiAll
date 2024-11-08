import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4
import Themes 1.0
import Widgets 1.0
Item {

    TabView {
        anchors.fill: parent
        Tab {
            title: "电压"
            Item {
                ColumnLayout{
                    Row{
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "参数"
                                anchors.centerIn: parent
                            }
                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ua"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ub"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Uc"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "国标值"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }

        }

        Tab {
            title: "电流"

            Item {
                ColumnLayout{
                    Row{
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "参数"
                                anchors.centerIn: parent
                            }
                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ia"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ib"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ic"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "国标值"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }
        }
        Tab {
            title: "电压偏差"
            Item {
                ColumnLayout{
                    Row{
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "参数"
                                anchors.centerIn: parent
                            }
                        }
                        Rectangle{
                            width: 280
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ua"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }

                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ub"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }

                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Uc"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }

                                    Rectangle{
                                        width: parent.width/4
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "国标值"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }

        }
        Tab {
            title: "闪变"
            Item {
                ColumnLayout{
                    Row{
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "参数"
                                anchors.centerIn: parent
                            }
                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ua"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Ub"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "Uc"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "国标值"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }

        }
        Tab {
            title: "综合"
            Item {
                ColumnLayout{
                    Row{
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "参数"
                                anchors.centerIn: parent
                            }
                        }
                        Rectangle{
                            width: 350
                            height: 100
                            border.color: "black"
                            Column{
                                anchors.fill: parent
                                Rectangle{
                                    border.color: "black"
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        text: "综合"
                                        anchors.centerIn: parent
                                    }
                                }
                                Row{
                                    width: parent.width
                                    height: parent.height/2
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最大值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "平均值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "最小值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "95%值"
                                            anchors.centerIn: parent
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width/5
                                        height: parent.height
                                        border.color: "black"
                                        BaseTextSmall{
                                            text: "结果"
                                            anchors.centerIn: parent
                                        }
                                    }
                                }
                            }

                        }
                        Rectangle{
                            width: 100
                            height: 100
                            border.color: "black"
                            BaseTextSmall{
                                text: "国标值"
                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }

        }
        style: TabViewStyle {
            frameOverlap: 1
            tab: Item {
                implicitWidth: 100
                implicitHeight: 40
                ColumnLayout{
                    anchors.fill: parent
                    BaseTextSmall {
                        id: text
                        Layout.alignment: Qt.AlignCenter
                        text: styleData.title
                        color: styleData.selected ? "blue" : "black"
                    }
                    Rectangle{
                        width: 100
                        height: 4
                        color: styleData.selected ? "blue" : "transparent"
                    }
                }
            }
            frame: Rectangle {
                color: "#ffffff"
                border.color: "black"

            }
        }
    }

}
