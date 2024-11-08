import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.15
import Widgets 1.0
import Themes 1.0
Item {
    id: sideslip
    width: parent.width
    height: parent.height
    signal displayApp(int num)
    signal hideApp(int num)
    signal sidebarChangel()
    property int appNum: -1


    onWidthChanged: {
        if(sidebar.state==="hidescreen")
        {
            sideslip.x=pageview.width-sidebar.width-1
        }
        else if(sidebar.state==="halfscreen")
        {
            sideslip.x=overlayRect.width * 4 / 5
        }
        else if(sidebar.state==="fullscreen")
        {
            sideslip.x=0
        }

    }

    RowLayout{
        anchors.fill: parent
        spacing: 0
        ColumnLayout{
            width: sidebar.width
            Layout.fillHeight: true
            spacing: 0
            Sidebar{
                id:sidebar
                width: 45
                height: 210
                Layout.alignment: Qt.AlignTop
            }
            Item {
                Layout.fillHeight: true
            }
        }
        Rectangle {
            id: overlayRect
            color: "#cfcfcf"
            Layout.fillHeight: true
            Layout.fillWidth:  true
            Loader {
                id: overloader
                width: overlayRect.width
                height: overlayRect.height
                onLoaded: {
                    if(item&&item.upAppInterFace) {
                        item.upAppInterFace(appNum)
                    }
                    if (typeof item.jumptoheaderfilewindow === 'function') {
                        item.jumptoheaderfilewindow.connect(function() {
                            sidebar.state="fullscreen"
                            sidebar.loadPage("FullView1.qml")
                            overloader.item.loadJumptoheaderfilewindow()
                        });
                    }
                    if (typeof item.displayApp === 'function') {
                        item.displayApp.connect(function(num) {
                            sideslip.displayApp(num);
                        });
                    }

                    if (typeof item.hideApp === 'function') {
                        item.hideApp.connect(function(num) {
                            sideslip.hideApp(num);
                        });
                    }

                }

            }
        }
    }
    Connections{
        target: pageview
        function onUpDataAppFace(value)
        {
            appNum=value
            sidebar.height=280
            if (overloader.item&&overloader.item.upAppInterFace) {
                overloader.item.upAppInterFace(appNum)
            }
        }
    }

    Connections {
        target: bottombar
        function  onApphide(){
            sidebar.height=210
            sidebarChangel()
        }
    }


}
