import QtQuick 2.15
import Themes 1.0
import Widgets 1.0
Text {
    property FontProperties fontskin: SkinManager.currentFont.fontproperty
    property FontProperties fontcol: SkinManager.currentSkin.fontproperty
    font.pointSize: fontskin.level2FontSize
    font.family: fontskin.fontFamily
    color: fontcol.fontColor
}
