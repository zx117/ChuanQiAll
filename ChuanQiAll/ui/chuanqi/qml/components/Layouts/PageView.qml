import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.1
import QtQuick.Shapes 1.15
import QtQml.Models 2.15
import Widgets 1.0
import Themes 1.0

Rectangle {
    id:pageview
    Layout.fillWidth: true
    Layout.fillHeight: true

    property RectangelStyle maininterface :SkinManager.currentSkin.mainInterface
    property int pageCount: Math.ceil(AppHost.appCounts / 24)
    property int num: 0
    signal upDataAppFace(int value)
    color: maininterface.backgroundColor

    SwipeView {
        id: swipeView
        anchors.fill: parent
        Repeater {
            id:pagerect
            model: pageCount
            delegate: Item {
                id:rect
                width: swipeView.width
                height: swipeView.height
                property int rectindex: index
                Grid {
                    id:grid
                    columns: 6
                    rows: 4
                    spacing: parent.width / 60
                    anchors.centerIn: parent
                    Repeater {
                        model: {
                            var startIndex = index *24
                            var remainingApps = AppHost.appCounts - startIndex;
                            return Math.min(24, remainingApps);
                        }
                        delegate: Button {
                            id:btn
                            width: rect.width / 8
                            height: rect.height / 5

                            background: Rectangle {
                                anchors.fill: parent
                                color: "transparent"
                            }
                            Image {
                                width:rect.width / 8>((rect.height / 5)*108)/126?((rect.height / 5)*108)/126:rect.width / 8
                                height: rect.height / 5>((rect.width / 8)*126)/108?((rect.width / 8)*126)/108:rect.height / 5
                                anchors.centerIn: parent
                                source: AppHost.appImage(rect.rectindex*24+index)
                            }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    wind.visible = true
                                    AppHost.loadApp(swipeView.currentIndex*24+index, wind,"Main")
                                    pageview.upDataAppFace(swipeView.currentIndex*24+index)
                                    num=swipeView.currentIndex*24+index
                                }
                            }
                            Connections{
                                target: sideface
                                function onDisplayApp(num)
                                {
                                    if(AppHost.appCounts<=24)
                                    {
                                        if(num===index)
                                        {
                                            visible=true
                                        }
                                    }
                                    else
                                    {
                                        if(num===rect.rectindex*24+index)
                                        {
                                            visible=true
                                        }
                                    }
                                }
                                function onHideApp(num)
                                {
                                    if(AppHost.appCounts<=24)
                                    {
                                        if(num===index)
                                        {
                                            visible=false
                                        }
                                    }
                                    else
                                    {
                                        if(num===rect.rectindex*24+index)
                                        {
                                            visible=false
                                        }
                                    }
                                }
                            }
                        }
                    }
                    Repeater {
                        model: 24 - AppHost.appCounts
                        delegate: Item {
                            width: rect.width / 8
                            height: rect.height / 5
                        }
                    }
                }
            }
        }
    }
    Row {
        id: indicatorRow
        spacing: 8
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        Repeater {
            model: pageCount
            delegate: Rectangle {
                width: 10
                height: 10
                radius: 5
                color: swipeView.currentIndex === index ? "#a4a4a4" : "lightgray"
            }
        }
    }

    SideInterface{
        id:sideface
        z:1
        width: parent.width
        height: parent.height
    }
    Rectangle {
        id: wind
        visible: false
        width: pageview.width
        height: pageview.height
        color: "#585858"
    }
    Connections {
        target: bottombar
        function  onApphide(){
            if(wind.visible===true)
            {
                wind.visible=false
                AppHost.closeApp(num,wind)
                pageview.upDataAppFace(-1)
            }
        }
    }
}


