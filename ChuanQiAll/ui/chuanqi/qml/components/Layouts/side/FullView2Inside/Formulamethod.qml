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
                height: 30
                ExclusiveGroup { id: buttonGroup }
                BaseRadioButton{
                    radioWidth: 100
                    radioHeight: 30
                    radioButtonText: "比例系数"
                    exclusiveGroup: buttonGroup
                    enabled: true
                    checked: true
                }
                BaseRadioButton{
                    radioWidth: 100
                    radioHeight: 30
                    radioButtonText: "灵敏度"
                    exclusiveGroup: buttonGroup
                    enabled: true
                }
            }
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
                    textBoxWidth:parent.width-60
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
                    width: 50
                    text: "比例系数"
                }

                BaseTextInput{
                    textBoxWidth:parent.width-60
                    textBoxHeight: 20
                    textContent: "1"
                }
            }
            Row{
                spacing: 10
                width: parent.width
                height: 20
                BaseTextSmall{
                    height: 20
                    width: 50
                    text: "单位:"
                }
                BaseTextInput{
                    textBoxWidth:parent.width-110
                    textBoxHeight: 20
                    textContent: ""
                }
                TextButton{
                    buttonText: "置零"
                    buttonWidth: 40
                    buttonHeight: 20
                }
            }

        }
    }
}

