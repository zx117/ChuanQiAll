pragma Singleton

import QtQuick 2.12
import QtQml 2.12

SkinFontBase {

    property int largeLevel1FontSize: 14
    property int largeLevel2FontSize: 13
    property int largeLevel3FontSize: 12
    fontproperty{
        level1FontSize: largeLevel1FontSize
        level2FontSize: largeLevel2FontSize
        level3FontSize: largeLevel3FontSize
    }
}
