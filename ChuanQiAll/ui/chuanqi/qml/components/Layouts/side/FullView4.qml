import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0

Item{
    id:full4
    property string titleName: ""
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    property int appNum: -1

    function upAppInterFace(value) {
        appNum=value
        if (menuloader.item&&menuloader.item.upAppInterFace) {
           menuloader.item.upAppInterFace(appNum)
           console.log("appNum2",appNum)
        }
    }
    anchors.fill: parent
    Row{
        width: parent.width
        height: parent.height
        spacing: 0
        Rectangle{
            width: parent.width/5
            height: parent.height

            color: sideBarInterface.backgroundColor
            border.color: sideBarInterface.borderColor
            Column{
                width: parent.width
                height: parent.height
                spacing: 0
                Rectangle {
                    id:title
                    height: 30
                    width: parent.width
                    color: sideBarInterface.headBackColor
                    border.color: sideBarInterface.borderColor
                    BaseTextModerate {
                        text: "导航栏"
                        font.bold: true
                        anchors.centerIn: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                Rectangle{
                    height: parent.height-title.height
                    width: parent.width
                    color: sideBarInterface.backgroundColor
                    border.color: sideBarInterface.borderColor
                    Frame{
                        id:frame
                        width: parent.width*4/5
                        height: 40
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                        anchors.topMargin: 20
                        padding: 0
                        ListModel {
                            id: fullModel
                            // ListElement { txt: "存储模式";qmlFile:"StorageMode.qml";isActive:false }
                            //ListElement { txt: "文件头信息";qmlFile:"HeaderInformation.qml" ;isActive:false}
                            ListElement { txt: "App配置";qmlFile:"AppConfiguration.qml" ;isActive:false}
                        }
                        Column {
                            anchors.fill: parent
                            ListView {
                                id: listView
                                currentIndex: 0
                                width: parent.width
                                height:parent.height
                                model: fullModel
                                interactive: false
                                Component.onCompleted: {
                                    loadPage(fullModel.get(0).txt, fullModel.get(0).qmlFile)
                                    fullModel.get(0).isActive=true
                                }
                                delegate:Rectangle{
                                    id:menubutton
                                    width: frame.width
                                    height: 40
                                    border.color: sideBarInterface.borderColor
                                    color: isActive?"#91b8e0":sideBarInterface.menuBackColor
                                    Rectangle{
                                        height: parent.height
                                        width: 3
                                        color: "#005bb6"
                                        anchors.left: parent.left
                                        visible: isActive?true:false
                                    }

                                    BaseTextSmall{
                                        text: txt
                                        color:"black"
                                        anchors.left: parent.left
                                        anchors.leftMargin: 20
                                        anchors.verticalCenter: parent.verticalCenter
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            listView.currentIndex = index;
                                            for (var i = 0; i < fullModel.count; ++i) {
                                                fullModel.get(i).isActive = (i === index);
                                            }
                                            loadPage(txt,qmlFile)
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        Rectangle{
            id:interface2
            width: parent.width*4/5
            height: parent.height
            color: sideBarInterface.backgroundColor
            border.color: sideBarInterface.borderColor
            Column{
                spacing: 0
                width: parent.width
                height: parent.height
                Rectangle {
                    id:title2
                    height: 30
                    width: parent.width
                    color: sideBarInterface.headBackColor
                    border.color: sideBarInterface.borderColor
                    BaseTextModerate {
                        text: titleName
                        font.bold: true
                        anchors.centerIn: parent
                    }
                }
                Item{
                    id:menuinterface
                    width: parent.width
                    height: interface2.height-title2.height
                    Loader {
                        id: menuloader
                        width: menuinterface.width
                        height: menuinterface.height
                        // onLoaded: {
                        //      if (item&&item.upAppInterFace) {
                        //         item.upAppInterFace(appNum)
                        //         console.log("appNum2",appNum)
                        //      }
                        // }

                    }
                }
            }
        }
    }
    function loadPage(txt,qmlFile) {
        menuloader.source = "qrc:/qml/components/Layouts/side/FullView1Inside/" + qmlFile;
        titleName=txt
    }
}

