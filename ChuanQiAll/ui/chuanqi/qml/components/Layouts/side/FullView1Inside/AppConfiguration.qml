import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Rectangle{
    id:appconfig
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    property bool loadapp: false

    function upAppInterFace(value) {
        console.log("fan",value)
        if(value>=0)
        {

            AppHost.loadApp(value,appset,"Setting")
        }
    }
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    Item {
        id: appset
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent

    }
}
