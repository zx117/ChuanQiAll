import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Rectangle{
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    anchors.fill: parent
    Item {
        id:setif
        width: parent.width-20
        height: parent.height
        anchors.centerIn: parent
        Column{
            spacing: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            BaseCheckBox{
                checkText: "自动"
            }
        }
    }
}
