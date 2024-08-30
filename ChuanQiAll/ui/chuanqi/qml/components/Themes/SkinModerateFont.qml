pragma Singleton

import QtQuick 2.12
import QtQml 2.12
SkinFontBase {

    property int moderLevel1FontSize: 12
    property int moderLevel2FontSize: 11
    property int moderLevel3FontSize: 10
    fontproperty{
        level1FontSize: moderLevel1FontSize
        level2FontSize: moderLevel2FontSize
        level3FontSize: moderLevel3FontSize
    }
}
