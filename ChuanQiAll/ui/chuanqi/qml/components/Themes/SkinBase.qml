import QtQuick 2.12
import QtQml 2.12
import "./WidgetsStyle"
import "./Font"
QtObject {
    id: control

    property FontProperties fontproperty: FontProperties{}
    property ButtonStyle iconButton: ButtonStyle{}
    property SideBarStyle sideBar: SideBarStyle{}

    property FontProperties whitefont: FontProperties{
        fontColor:"#ffffff"
    }

    property ButtonStyle screeniconButton: ButtonStyle{
        iconNormalColor: "#585858"
        iconPressedColor: "#cfcfcf"
        buttonNormalColor: "#ffffff"
        buttonPressedColor: "#005bb6"
        borderColor: "#272727"
    }

    property RectangelStyle topbottomRectangel: RectangelStyle{
        backgroundColor: "#585858"
        borderColor: "#a4a4a4"
        menuBackColor: "#272727"
    }

    property ButtonStyle redButton: ButtonStyle{
        iconNormalColor: "red"
        iconPressedColor: "white"
        buttonNormalColor: "#272727"
        buttonPressedColor: "red"
    }

    property RectangelStyle mainInterface: RectangelStyle{
        backgroundColor: "#efefef"
    }

    property RectangelStyle sideBarInterface: RectangelStyle{
        backgroundColor: "#cfcfcf"
        borderColor: "#a4a4a4"
        headBackColor: "#dddddd"

    }

    property ButtonStyle textButton: ButtonStyle{
        buttonNormalColor: "#efefef"
        buttonPressedColor: "#cfcfcf"
    }

    property ButtonStyle bottomRCButton: ButtonStyle{
        buttonNormalColor: "transparent"
        buttonPressedColor: "#005bb6"
    }
}
