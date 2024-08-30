import QtQuick 2.15
import QtQuick.Controls 2.5
import Widgets 1.0
import Themes 1.0
Rectangle{
    id:plugi
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    property bool dataLoaded: false
    signal displayApp(int num)
    signal hideApp(int num)
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    Component.onCompleted: {
        for(var i=0;i<AppHost.appCounts;i++)
        {
            listmodel.append({
                     "txt": AppHost.returnAppName(i),
                     "isOpen": AppHost.returnIsValidApp(i),
                     "registerInfo": AppHost.returnAppRegisterInfo(i),
                     "version": AppHost.returnAppVersion(i),
                     "isDisplay":true
                      });
        }
        console.log("111")

    }

    ListModel{
        id:listmodel

    }

    Item {
        id:setif
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            Rectangle{
                width: parent.width
                height: 30
                color: "#585858"
                BaseTextSmall{
                    text: "插件"
                    anchors.centerIn: parent
                    color: "#ffffff"
                }
            }
            ListView{
                width: setif.width
                height: setif.height
                clip: true
                model: listmodel
                delegate: Rectangle{
                    width: setif.width
                    height: setif.height/5
                    color: index % 2 === 0? "lightgray" : "#efefef"
                    Item {
                        width: parent.width-10
                        height: parent.height-10
                        anchors.centerIn: parent
                        Column{
                            spacing: 10
                            Row{
                                spacing: 50
                                BaseTextSmall{
                                    width: 200
                                    text: model.txt
                                }
                                BaseSwitch{
                                    ischecked:isDisplay
                                    onIscheckedChanged: {
                                        if(ischecked===false)
                                        {
                                            listmodel.set(index, { "isDisplay": false});
                                            plugi.hideApp(index)
                                        }
                                        else{
                                            listmodel.set(index, { "isDisplay": true});
                                            plugi.displayApp(index)
                                        }
                                    }
                                }
                                BaseTextSmall{
                                    text: "xxxxxxxxxxxxxxxxx"
                                }
                            }
                            Row{
                                spacing: 50
                                Row{
                                    spacing: 10
                                    width: 200
                                    BaseTextSmall{
                                        text: "供应商"
                                    }
                                    BaseTextSmall{
                                        text: "xxxxxx"
                                    }
                                }
                                Row{
                                    spacing: 10
                                    width: 200
                                    BaseTextSmall{
                                        text: "类型"
                                    }
                                    BaseTextSmall{
                                        text: "xxxxxx"
                                    }
                                }
                            }
                            Row{
                                spacing: 50
                                Row{
                                    spacing: 10
                                    width: 200
                                    BaseTextSmall{
                                        text: "版本"
                                    }
                                    BaseTextSmall{
                                        text: "xxxxxx"
                                    }
                                }
                                Row{
                                    spacing: 10
                                    width: 200
                                    BaseTextSmall{
                                        text: "状态"
                                    }
                                    BaseTextSmall{
                                        text: "xxxxxx"
                                    }
                                }
                            }
                        }
                    }
                }
            }

        }


    }

}
