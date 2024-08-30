import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
import MyInterface 1.0
Item {
    width: parent.width-1
    height: parent.height-1
    anchors.centerIn: parent
    Item {
        id:setif
        width: parent.width-20
        height: parent.height
        anchors.centerIn: parent
        Column{
            spacing: 10
            height: parent.height
            width: parent.width
            Row{
                spacing: 10
                width: parent.width
                height: 20
                BaseTextSmall{
                    width: 30
                    height: parent.height
                    text: "单位"
                }
                BaseTextInput{
                    textBoxWidth:parent.width*3/5-50
                    textBoxHeight: 20
                    textContent: ""
                }
                TextButton{
                    buttonWidth: parent.width/5
                    buttonHeight: 20
                    buttonText: "复制"
                }
                TextButton{
                    buttonWidth: parent.width/5
                    buttonHeight: 20
                    buttonText: "粘贴"
                }
            }
            Rectangle{
                width:parent.width
                height: 30
                color: "#cfcfcf"
                Row{
                    width: parent.width
                    height: 30
                    Item {
                        width: parent.width*2/5
                        height: 30
                        anchors.verticalCenter: parent.verticalCenter
                        Item{
                            width: 50
                            height: 20
                            anchors.centerIn: parent
                            BaseTextSmall{
                                anchors.centerIn: parent
                                text: "度"
                            }
                        }
                    }

                    Rectangle{
                        anchors.verticalCenter: parent.verticalCenter
                        width: 2
                        height: 20
                        color: "#ffffff"
                    }
                    Item {
                        width: parent.width*2/5
                        height: 30
                        anchors.verticalCenter: parent.verticalCenter
                        Item{
                            width: 50
                            height: 20
                            anchors.centerIn: parent
                            BaseTextSmall{
                                anchors.centerIn: parent
                                text: "系数"
                            }
                        }
                    }
                    Rectangle{
                        anchors.verticalCenter: parent.verticalCenter
                        width: 2
                        height: 20
                        color: "#ffffff"
                    }
                    Item{
                        width: parent.width/5
                        height: 30
                        Rectangle{
                            id:addbutton
                            width: parent.width-40
                            height: 20
                            color: "#efefef"
                            anchors.centerIn: parent
                            BaseTextSmall{
                                anchors.centerIn: parent
                                text: "增加"
                            }
                            MouseArea{
                                anchors.fill: parent
                                onPressed: {
                                    addbutton.color="#a4a4a4"
                                    let component = Qt.createComponent("MultinomialChild.qml");
                                    if (component.status === Component.Ready)
                                    {
                                        component.createObject(layout);
                                    }
                                    else if (component.status === Component.Error) {
                                        console.log("Error loading component:", component.errorString());
                                    }
                                }
                                onReleased: {
                                    addbutton.color="#efefef"
                                }
                            }
                        }
                    }
                }
            }
            Item{
                height: parent.height-80
                width: parent.width
                Flickable  {
                    height: parent.height
                    width: parent.width
                    contentWidth: width
                    contentHeight: layout.height
                    clip: true
                    GridLayout {
                        id: layout
                        columns: 1
                        width: parent.width
                    }
                }
            }
        }
    }
}

