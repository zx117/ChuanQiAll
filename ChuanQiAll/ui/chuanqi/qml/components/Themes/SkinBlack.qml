pragma Singleton

import QtQuick 2.12
import QtQml 2.12

SkinBase {

    property color blackIconNormalColor: "#cfcfcf"
    property color blackIconPressedColor: "#ffffff"
    property color blackButtonNormalColor: "#5c5c5c"
    property color blackButtonPressedColor: "#005bb6"

    whitefont: FontProperties{
        fontColor:"black"
    }

    iconButton{
        iconNormalColor: blackIconNormalColor
        iconPressedColor: blackIconPressedColor
        buttonNormalColor: blackButtonNormalColor
        buttonPressedColor: blackButtonPressedColor
    }
    redButton{
        iconNormalColor: blackIconNormalColor
        iconPressedColor: "red"
        buttonNormalColor: blackButtonNormalColor
        buttonPressedColor: blackButtonPressedColor
    }

    topbottomRectangel{
        backgroundColor: "#272727"
        borderColor: "#a4a4a4"
        menuBackColor: "#585858"
    }

    mainInterface{
        property color mainInterfaceBlackGroundColorColor: "#3e3e3e"
        backgroundColor: mainInterfaceBlackGroundColorColor
    }

    sideBarInterface{
        backgroundColor: "#656565"
        borderColor: "#272727"
        headBackColor: "#474747"
        menuBackColor:"#a4a4a4"
    }

    fontproperty {
        property color fontcolor: "white"
        fontColor: fontcolor
    }

    sideBar {
        normalstrokeColor: "#a4a4a4"
        activestrokeColor: "#272727"
        normalfillColor: "#a4a4a4"
        activefillColor: "#3d3d3d"
    }

}
