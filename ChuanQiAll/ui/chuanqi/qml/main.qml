import QtQuick 2.15
import QtQuick.Window 2.0
import QtGraphicalEffects 1.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import Dialogs 1.0
import Widgets 1.0
import Themes 1.0
import Layouts 1.0
ApplicationWindow {
    id:mainWindow
    property int windowWidth: 1200
    property int windowHeight: 800
    signal emitLog(string text);
    width: windowWidth
    height: windowHeight
    visibility: Window.Maximized
    visible: true

    Component.onCompleted: {
        getdevinf.initializationDeviceModel()
        pugixml.addMeasurementTree()
        pugixml.setStructValue("Enclosure_Name","Local Ports")
        pugixml.setStructValue("Enclosure_IsMainEnclosure",true)
        pugixml.setStructValue("Enclosure_PluginId","86aa763f-8904-43dd-b0ec-ab7e70208e3e")
        pugixml.setStructValue("Enclosure_Id","10000")
        pugixml.addEnclosure("MeasurementNode","Name","LocalNode")
    }

    OpenDataFile{
        id:opendatafile
        anchors.centerIn: parent
    }
    OpenSetFile{
        id:opensetfile
        anchors.centerIn: parent

    }
    SaveSetFile{
        id:savesetfile
        anchors.centerIn: parent
    }

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        spacing: 0
        TopSidebar{
            id:topsidebar
        }
        PageView{
            id:pageview
        }
        Bottombar{
            id:bottombar
        }
    }
    Connections {
        target: bottombar
        function onOpenDataFilePopup(){
            opendatafile.open()
        }

        function onOpenSetFilePopup(){
            opensetfile.open()
        }

        function onSaveSetFilePopup(){
            savesetfile.open()
        }
    }
}
