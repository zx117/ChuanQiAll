import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Themes 1.0
import Widgets 1.0
import GraphicDraw 1.0
import MyListModel 1.0
Item {
    anchors.fill: parent
    property  int index: -1
    Connections {
        target: getdevinf
        function onDeviceIndex(i){
            index=i
        }
    }
    Connections {
        target: getdevinf
        function onDeviceDataListChanged(threadid){
            getdevinf.upDateDeviceData(threadid);
            if(threadid===index)
            {

                graphic.updateRealData(MyListModel.get(index))
            }
        }
    }
    GraphicDraw{
        id:graphic
        anchors.fill: parent
        onSigIllegalData: {
            popuTip.text = qsTr("数据异常 ！");
            popuTip.visible = true;

        }

    }
}
