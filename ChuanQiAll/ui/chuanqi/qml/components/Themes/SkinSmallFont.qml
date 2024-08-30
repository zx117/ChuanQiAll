pragma Singleton

import QtQuick 2.12
import QtQml 2.12

SkinFontBase {
    property int smallLevel1FontSize: 10
    property int smallLevel2FontSize: 9
    property int smallLevel3FontSize: 8
    fontproperty{
        level1FontSize: smallLevel1FontSize
        level2FontSize: smallLevel2FontSize
        level3FontSize: smallLevel3FontSize
    }
}
