import QtQuick 2.15;
import Widgets 1.0
import Themes 1.0
Rectangle {
    id:device
    property string devicename: ""
    property string boardcardname: ""
    property string modelnumber: ""
    property string name: ""
    property string idnumber: ""
    property string description: ""
    property bool active: false
    signal addconnect(int i);
    signal delconnect(int i);
    width: 200;
    height: 250;
    color: "#efefef";
    Column{
        anchors.fill: parent
        spacing: 5
        BaseTextModerate{
            text: devicename
            font.bold: true
            wrapMode: Text.WordWrap
            width: 200
            height: 40
        }
        Row{
            BaseTextSmall{
                width: 75
                text: "Name:"
            }
            BaseTextSmall{
                text: name
            }
        }
        Row{
            BaseTextSmall{
                width: 75
                text: "Id:"
            }
            BaseTextSmall{
                text: idnumber
            }
        }
        Row{
            BaseTextSmall{
                width: 75
                text: "Description:"
            }
            BaseTextSmall{
                text: description
            }
        }
        Row{
            BaseTextSmall{
                width: 75
                text: "Activate:"
            }
            BaseTextSmall{
                text: active
            }
        }

    }
    TextButton{
        id:btn
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        anchors.bottomMargin: 10
        buttonWidth: parent.width/2
        buttonHeight: 30
        text: model.Clicked===false?"连接":"断开"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                model.Clicked=!model.Clicked
                if (model.Clicked === true) {
                    var item=rootdevice.get(index)
                    activedevice.append(item)
                    rootdevice.remove(index)
                    device.addconnect(item.originalIndex)
                }
                else
                {
                    var item1 = activedevice.get(index);
                    var restoreIndex = item1.originalIndex !== undefined ? item1.originalIndex : rootdevice.count;
                    if (restoreIndex > rootdevice.count) {
                        restoreIndex = rootdevice.count;
                    }
                    rootdevice.insert(restoreIndex, item1);
                    activedevice.remove(index);
                    device.delconnect(item1.originalIndex)
                }
            }
        }
    }
}
