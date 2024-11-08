import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Popup{
    id:applypopup
    background:Rectangle{
        anchors.fill: parent
        color: "#585858"
    }
    Column
    {
        spacing: 1
        anchors.fill: parent
        Item{
            width: parent.width
            height: 25
            Row{
                anchors.fill: parent
                spacing: 0
                IconButton{
                    buttonWidth: 30
                    buttonHeight: 20
                    buttonRadius:2
                    iconWidth: 15
                    iconHeight: 15
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/treeIcon/atoz.png"

                }
                IconButton{
                    buttonWidth: 30
                    buttonHeight: 20
                    buttonRadius:2
                    iconWidth: 15
                    iconHeight: 15
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/treeIcon/ztoa.png"
                }
                Item {
                    width: parent.width-90
                    height: parent.height
                }
                IconButton{
                    buttonWidth: 30
                    buttonHeight: 20
                    buttonRadius:2
                    iconWidth: 15
                    iconHeight: 15
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/treeIcon/noscreen.png"
                }
            }

        }
        BaseTextInput{
            textContent: ""
            width: parent.width
            height: 25
        }
        TextButton{
            width: parent.width
            height: 25
            buttonText: "是"
        }
    }

}
