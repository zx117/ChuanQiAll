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
                    height: 20
                    width: 50
                    text: "单位"
                }
                BaseTextInput{
                    textBoxWidth:parent.width/2
                    textBoxHeight: 20
                    textContent: "..."
                }
            }
            Row{
                spacing: 10
                width: parent.width
                height: 20
                BaseTextSmall{
                    height: 20
                    width: 40
                    text: "第一点:"
                }
                Column{
                    spacing: 10
                    width: (parent.width-120)/2
                    height: parent.height
                    BaseTextInput{
                        textBoxWidth:parent.width
                        textBoxHeight: 20
                        textContent: "0"
                    }
                    Row{
                        spacing: 10
                        width: parent.width
                        height: 20
                        TextButton{
                            height: parent.height
                            width: parent.width/2-5
                            buttonText: "平均值"
                        }
                        TextButton{
                            height: parent.height
                            width: parent.width/2-5
                            buttonText: "有效值"
                        }
                    }
                    BaseTextInput{
                        textBoxWidth:parent.width
                        textBoxHeight: 20
                    }
                }
                BaseTextSmall{
                    height: 20
                    width: 40
                    text: "第二点:"
                }
                Column{
                    spacing: 10
                    width: (parent.width-120)/2
                    height: parent.height
                    BaseTextInput{
                        textBoxWidth:parent.width
                        textBoxHeight: 20
                        textContent: "0"
                    }
                    Row{
                        spacing: 10
                        width: parent.width
                        height: 20
                        TextButton{
                            height: parent.height
                            width: parent.width/2-5
                            buttonText: "平均值"
                        }
                        TextButton{
                            height: parent.height
                            width: parent.width/2-5
                            buttonText: "有效值"
                        }
                    }
                    BaseTextInput{
                        textBoxWidth:parent.width
                        textBoxHeight: 20
                    }
                }
            }
        }
    }
}

