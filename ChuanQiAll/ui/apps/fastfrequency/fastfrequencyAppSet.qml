import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Themes 1.0
import Widgets 1.0
Item {
    id:appset
    anchors.fill: parent
    objectName: "appset"
    signal switchGraphics(string path)
    Column{
        width: parent.width
        height: parent.height
        spacing: 0
        Item{
            width: parent.width
            height: 320
            Column{
                width: parent.width
                height: parent.height
                ListModel{
                    id:analyzemodel
                    ListElement{txt:"频率阶跃扰动实验";isChecked:false;}
                    ListElement{txt:"模拟电网扰动实验";isChecked:false;}
                    ListElement{txt:"抗扰动实验";isChecked:false;}
                    ListElement{txt:"一次调频死区测试";isChecked:false;}
                    ListElement{txt:"一次调频限幅功能测试";isChecked:false;}
                    ListElement{txt:"AGC协调控制实验";isChecked:false;}
                }
                Rectangle{
                    width: parent.width
                    height: 40
                    color: "#585858"
                    BaseTextModerate{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.leftMargin: 15
                        anchors.left: parent.left
                        text: "实验选项"
                        color: "#ffffff"
                    }
                }
                Item {
                    width: parent.width
                    height: 210
                    Column{
                        width: parent.width
                        height: parent.height
                        spacing: 0

                        ListView{
                            id:listView
                            width: parent.width
                            height: parent.height
                            model:analyzemodel
                            clip: true
                            interactive: false
                            Component.onCompleted: {
                                loadPage(analyzemodel.get(0).qmlFile1)
                                analyzemodel.get(0).isChecked=true
                            }
                            delegate: Rectangle{
                                width: parent.width
                                height: 35
                                color: index % 2 === 0? "#efefef" : "white"
                                Rectangle{
                                    height: parent.height
                                    width: parent.width
                                    anchors.left: parent.left
                                    visible: isChecked?true:false
                                    color: "#91b8e0"

                                }
                                BaseTextSmall{
                                    anchors.left: parent.left
                                    anchors.leftMargin: 10
                                    anchors.verticalCenter: parent.verticalCenter
                                    text: model.txt
                                }
                                MouseArea{
                                    anchors.fill: parent
                                    onClicked: {
                                        listView.currentIndex = index;
                                        for (var i = 0; i < analyzemodel.count; ++i) {
                                            analyzemodel.get(i).isChecked = (i === index);
                                        }
                                        loadPage(qmlFile1)
                                        switchGraphics(qmlFile)
                                    }
                                }
                            }
                        }
                    }

                }
                Rectangle{
                    width: parent.width
                    height: 40
                    color: "#585858"
                    BaseTextModerate{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.leftMargin: 15
                        anchors.left: parent.left
                        text: "界面显示"
                        color: "#ffffff"
                    }
                }
                Row{
                    width: parent.width
                    height: 40
                    TextButton{
                        width:parent.width/2
                        height: 40
                        font.bold: true
                        text: "显示波形"
                    }

                    TextButton{
                        width:parent.width/2
                        height: 40
                        font.bold: true
                        text: "显示报告"
                    }

                }
                Rectangle{
                    width: parent.width
                    height: 40
                    color: "#585858"
                    BaseTextModerate{
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.leftMargin: 15
                        anchors.left: parent.left
                        text: "功能"
                        color: "#ffffff"
                    }
                }
                Column{
                    width: parent.width
                    height: 80
                    spacing: 0
                    Row{
                        width: parent.width
                        height: parent.height/2
                        TextButton{
                            width:parent.width/2
                            height: 40
                            font.bold: true
                            text: "显示记录"
                        }
                        TextButton{
                            width:parent.width/2
                            height: 40
                            font.bold: true
                            text: "清除记录"
                        }
                    }
                    Row{
                        width: parent.width
                        height: parent.height/2
                        TextButton{
                            width:parent.width/2
                            height: 40
                            font.bold: true
                            text: "保存记录"
                        }

                        TextButton{
                            width:parent.width/2
                            height: 40
                            font.bold: true
                            text: "装载记录"
                        }

                    }

                }
            }
        }
        Item{
            width: parent.width
            height: parent.height-320
            Flickable{
                width: parent.width
                height: parent.height
                clip: true
                contentHeight: parent.height
                Column{
                    width: parent.width
                    height: parent.height
                    Loader{
                        id:graphicset
                        width: parent.width
                        height: parent.height
                    }
                }

            }
        }
    }

    function loadPage(qmlfile1){
        graphicset.source="qrc:/Layout/"+qmlfile1
    }





}
