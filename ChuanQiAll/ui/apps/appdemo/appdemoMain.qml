import QtQuick 2.15
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Themes 1.0
import Widgets 1.0
Item {
    id: appdemoMain
    anchors.fill: parent
    property var main:AppHost.thisApp("appdemo")
    Component.onCompleted: {
        loadPage("Trend.qml")
    }

    Column{
        anchors.fill: parent
        Rectangle{
            width: parent.width
            height: parent.height
            color: "#ffffff"
            Loader{
                id:graphicdisplay
                width: parent.width
                height: parent.height

            }
        }
    }
    function loadPage(qmlfile){
        graphicdisplay.source="qrc:/Layout/"+qmlfile
    }

    Connections{
        target: main
        function onMainSwitch(path){
            loadPage(path)
        }
    }
}
