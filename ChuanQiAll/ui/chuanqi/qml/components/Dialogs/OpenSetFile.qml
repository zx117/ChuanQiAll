import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import Qt.labs.folderlistmodel 2.15
import MyFileSystemModel 1.0
import MyDiskModel 1.0
import Themes 1.0
import Widgets 1.0
import "qrc:/qml/images"

Popup{
    id:odf
    width: parent.width*4/5
    height: parent.height*4/5
    modal: true
    focus: true
    background: Rectangle{
        anchors.fill: parent
        color: "#ffffff"
    }
    ColumnLayout{
        anchors.fill: parent
        spacing: 5
        Item {
            height: 40
            Layout.fillWidth: true
            BaseTextModerate{
                text: "加载测试配置"
                font.bold: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }
        RowLayout{
            spacing: 5
            Layout.fillWidth: true
            Layout.fillHeight: true
            Rectangle{
                Layout.fillHeight: true
                width: 250
                border.color: "#cfcfcf"
                Flickable {
                    id:flick
                    anchors.fill: parent
                    ColumnLayout{
                        anchors.fill: parent
                        Item {
                            Layout.fillWidth: true
                            height: 20
                            BaseTextSmall{
                                text: "文件夹"
                            }
                        }
                        Item {
                            height:30
                            Layout.fillWidth: true
                            RowLayout{
                                Layout.fillHeight: true
                                Layout.fillWidth: true
                                spacing: 5
                                Image {
                                    width: 30
                                    height:30
                                    source: "qrc:/qml/images/treeIcon/file.png"
                                }
                                BaseTextModerate{
                                    text: "D:/DATA"
                                }
                            }
                        }
                        Item {
                            Layout.fillWidth: true
                            height: 20
                            BaseTextSmall{
                                text: "系统"
                            }
                        }
                        FileSystemTree{
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            x:10
                            treeModel: MyDiskModel
                        }
                    }

                }

            }
            Rectangle{
                Layout.fillHeight: true
                width: 2
                border.color: "#cfcfcf"
            }
            Item{
                id:list
                Layout.fillHeight: true
                Layout.fillWidth: true
                ColumnLayout{
                    anchors.fill: parent
                    spacing: 5
                    Rectangle{
                        Layout.fillWidth: true
                        height: 30
                        color: "#a4a4a4"
                    }
                    Rectangle{
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        border.color: "#a4a4a4"
                        border.width: 1
                        FileSystemList{
                            anchors.fill: parent
                            anchors.margins: 1
                            listModel: MyFileSystemModel
                        }
                    }
                    Item {
                        height: 30
                        GridLayout.fillWidth: true
                        RowLayout{
                            anchors.fill: parent
                            Rectangle{
                                id:delbtn
                                width: 100
                                Layout.fillHeight: true
                                color: "#cfcfcf"
                                border.color: "#a4a4a4"
                                BaseTextModerate{
                                    anchors.centerIn: parent
                                    text: "删除"
                                }
                                MouseArea{
                                    anchors.fill: parent
                                    onPressed: {
                                        delbtn.color="#005bb6"
                                    }
                                    onReleased: {
                                        delbtn.color="#cfcfcf"
                                    }
                                }

                            }
                            Item {
                                id: name
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                            }
                            Rectangle{
                                id:newbtn
                                width: 100
                                Layout.fillHeight: true
                                color: "#cfcfcf"
                                border.color: "#a4a4a4"
                                BaseTextModerate{
                                    anchors.centerIn: parent
                                    text: "新建文件夹"
                                }
                                MouseArea{
                                    anchors.fill: parent
                                    onPressed: {
                                        newbtn.color="#005bb6"
                                    }
                                    onReleased: {
                                        newbtn.color="#cfcfcf"
                                    }
                                }
                            }
                        }
                    }
                    Rectangle{
                        Layout.fillWidth: true
                        height: 2
                        color: "#a4a4a4"
                    }

                    Item{
                        height: 170
                        GridLayout.fillWidth: true
                        TabView {
                            anchors.fill: parent

                            Tab {
                                title: "信息"
                                Item {
                                    Text {
                                        text: "不适用"
                                        anchors.centerIn: parent
                                    }
                                }

                            }

                            Tab {
                                title: "通道"
                                Item {
                                    Text {
                                        text: "不适用"
                                        anchors.centerIn: parent
                                    }
                                }
                            }
                            Tab {
                                title: "数据头"
                                Item {
                                    Text {
                                        text: "不适用"
                                        anchors.centerIn: parent
                                    }
                                }
                            }
                            style: TabViewStyle {
                                frameOverlap: 1
                                tab: Item {
                                    implicitWidth: 50
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
                                            width: 50
                                            height: 4
                                            color: styleData.selected ? "blue" : "#ffffff"
                                        }
                                    }
                                }
                                frame: Rectangle {
                                    color: "#ffffff"
                                    border.color: "#cfcfcf"
                                }
                            }
                        }
                    }
                }
            }
        }
        Rectangle{
            height: 40
            Layout.fillWidth: true
            color: "#cfcfcf"
            RowLayout{
                anchors.fill: parent
                spacing: 10
                Rectangle{
                    id:browsebtn
                    width: 100
                    Layout.fillHeight: true
                    color: "#cfcfcf"
                    BaseTextModerate{
                        anchors.centerIn: parent
                        text: "浏览"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onPressed: {
                            browsebtn.color="#005bb6"
                        }
                        onReleased: {
                            browsebtn.color="#cfcfcf"
                        }
                    }
                }
                Item {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }
                Rectangle{
                    id:closebtn
                    width: 100
                    Layout.fillHeight: true
                    color: "#cfcfcf"
                    BaseTextModerate{
                        anchors.centerIn: parent
                        text: "取消"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            odf.close()
                        }
                        onPressed: {
                            closebtn.color="#005bb6"
                        }
                        onReleased: {
                            closebtn.color="#cfcfcf"
                        }
                    }
                }
                Rectangle{
                    id:openbtn
                    width: 100
                    Layout.fillHeight: true
                    color: "#cfcfcf"
                    BaseTextModerate{
                        anchors.centerIn: parent
                        text: "打开"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onPressed: {
                            openbtn.color="#005bb6"
                        }
                        onReleased: {
                            openbtn.color="#cfcfcf"
                        }
                    }
                }
            }
        }
    }


}

