import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtGraphicalEffects 1.15
import QtQuick.Shapes 1.13
import Widgets 1.0
import Themes 1.0
import Layouts 1.0
Shape {
    id: sidebar
    width: 45
    height: 280
    antialiasing: true
    property var cornersRadius:[14,0,0,14]
    property int dragStartX: mainWindow.width
    property bool isDoubleCheck: false
    property SideBarStyle side : SkinManager.currentSkin.sideBar
    layer.samples: 16 // 增加采样数
    layer.smooth: true
    layer.enabled: true
    layer.effect: OpacityMask {
        maskSource: sidebar
    }

    Canvas {
        id: canvas
        width: sidebar.width
        height: sidebar.height
        antialiasing: true
        onPaint: {
            var ctx = canvas.getContext("2d");

            ctx.clearRect(0, 0, canvas.width, canvas.height);

            ctx.imageSmoothingEnabled = true;
            ctx.lineCap = "round";
            ctx.lineJoin = "round";

            ctx.beginPath();
            ctx.moveTo(cornersRadius[0], 5);

            ctx.lineTo(sidebar.width - cornersRadius[1], 0);
            ctx.quadraticCurveTo(sidebar.width, 5, sidebar.width, cornersRadius[1]);

            ctx.lineTo(sidebar.width, sidebar.height - cornersRadius[2]);
            ctx.quadraticCurveTo(sidebar.width, sidebar.height, sidebar.width - cornersRadius[2], sidebar.height);

            ctx.lineTo(cornersRadius[3], sidebar.height-5);
            ctx.quadraticCurveTo(0, sidebar.height-7, 0, sidebar.height - cornersRadius[3]);

            ctx.lineTo(0, cornersRadius[0]);
            ctx.quadraticCurveTo(0, 7, cornersRadius[0], 5);

            ctx.closePath();
            ctx.fillStyle = side.normalfillColor;
            ctx.fill();

            ctx.strokeStyle = side.activestrokeColor;
            ctx.lineWidth = 2;
            ctx.stroke();
        }
    }

    ListModel {
        id: listModel
        ListElement { txt: "项目" ;qmlFile: "FullView1.qml" ;qmlFile1: "HalfView1.qml";isActive:false}
        ListElement { txt: "通道" ; qmlFile: "FullView2.qml";qmlFile1: "HalfView2.qml";isActive:false}
        ListElement { txt: "系统" ; qmlFile: "FullView3.qml";qmlFile1: "HalfView3.qml";isActive:false}
        ListElement { txt: "APP" ; qmlFile: "FullView4.qml";qmlFile1: "HalfView4.qml";isActive:false}
    }

    states: [
        State {
            name: "hidescreen"
            PropertyChanges {
                target: sideslip
                x:pageview.width-sidebar.width-1
            }
        }
        ,
        State {
            name: "halfscreen"
            PropertyChanges {
                target: sideslip
                x:overlayRect.width * 4 / 5
            }
        },
        State {
            name: "fullscreen"
            PropertyChanges {
                target: sideslip
                x:0
            }
        }
    ]
    transitions: [
        Transition {
            from: "hidescreen"
            to: "halfscreen"
            NumberAnimation {
                target: sideslip
                property: "x"
                to: overlayRect.width * 4 / 5
                duration: 200
                easing.type: Easing.InOutQuad
            }
        },
        Transition {
            from:"halfscreen"
            to:"hidescreen"
            NumberAnimation {
                target: sideslip
                property: "x"
                to: overlayRect.width
                duration: 200
                easing.type: Easing.InOutQuad
            }
        },
        Transition {
            from:"hidescreen"
            to: "fullscreen"
            NumberAnimation {
                target: sideslip
                property: "x"
                to: 0
                duration: 200
                easing.type: Easing.InOutQuad
            }
        },
        Transition {
            from: "fullscreen"
            to: "hidescreen"
            NumberAnimation {
                target: sideslip
                property: "x"
                to: overlayRect.width
                duration: 200
                easing.type: Easing.InOutQuad
            }
        },
        Transition {
            from: "halfscreen"
            to:"fullscreen"
            NumberAnimation {
                target: sideslip
                property: "x"
                to: 0
                duration: 200
                easing.type: Easing.InOutQuad
            }
        },
        Transition {
            from: "fullscreen"
            to: "halfscreen"
            NumberAnimation {
                target: sideslip
                property: "x"
                to: overlayRect.width * 4 / 5
                duration: 200
                easing.type: Easing.InOutQuad
            }
        }
    ]
    ColumnLayout {
        spacing: 0
        Layout.fillHeight: true
        width: 43
        //anchors.centerIn: parent
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 1
        ListView {
            id: listView
            Layout.fillWidth: true
            height: sidebar.height
            model: listModel
            interactive: false
            delegate: Shape {
                id:button
                property bool checked: false

                width: 45
                height: 70
                antialiasing: true
                layer.samples: 16
                layer.smooth: true
                layer.enabled: true
                layer.effect: OpacityMask {
                    maskSource: button
                }
                Canvas {
                    id: btncanvas
                    property bool isActive: model.isActive
                    property string sidebarstate :sidebar.state
                    width: button.width
                    height: button.height
                    antialiasing: true

                    onPaint: {
                        var ctx = btncanvas.getContext("2d");

                        ctx.clearRect(0, 0, btncanvas.width, btncanvas.height);

                        ctx.imageSmoothingEnabled = true;
                        ctx.lineCap = "round";
                        ctx.lineJoin = "round";

                        ctx.beginPath();
                        ctx.moveTo(cornersRadius[0], 5);

                        ctx.lineTo(button.width - cornersRadius[1], 0);
                        ctx.quadraticCurveTo(button.width, 5, button.width, cornersRadius[1]);

                        ctx.lineTo(button.width, button.height - cornersRadius[2]);
                        ctx.quadraticCurveTo(button.width, button.height, button.width - cornersRadius[2], button.height);

                        ctx.lineTo(cornersRadius[3], button.height-5);
                        ctx.quadraticCurveTo(0, button.height-7, 0, button.height - cornersRadius[3]);

                        ctx.lineTo(0, cornersRadius[0]);
                        ctx.quadraticCurveTo(0, 7, cornersRadius[0], 5);

                        ctx.closePath();
                        ctx.fillStyle = sidebarstate!=="hidescreen"?(isActive?side.activefillColor:side.normalfillColor):side.normalfillColor
                        ctx.fill();

                        ctx.strokeStyle = sidebarstate!=="hidescreen"?(isActive?side.activestrokeColor:side.normalstrokeColor):side.normalstrokeColor
                        ctx.lineWidth = 1;
                        ctx.stroke();
                    }
                    onIsActiveChanged: {
                        btncanvas.requestPaint();
                    }
                }

                Component.onCompleted: {
                    sidebar.state="hidescreen"
                }
                BaseTextModerate {
                    id: text
                    text: txt
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
                Rectangle
                {
                    anchors.horizontalCenter: button.horizontalCenter
                    width: button.width/2
                    height: 1
                    visible: index===0?false:true
                    color: sidebar.state==="hidescreen"?"#a4a4a4":"transparent"
                }
                MouseArea {
                    anchors.fill: button
                    drag.target: sideslip
                    drag.axis:Drag.XAxis
                    drag.minimumX: 0//最小移动位置
                    drag.maximumX: overlayRect.width//最大移动位置
                    onClicked: {
                        timer.start()
                    }
                    onDoubleClicked:{
                        timer.stop()
                        isDoubleCheck=true
                        if(sidebar.state!=="fullscreen")
                        {
                            button.forceActiveFocus()
                            sidebar.state="fullscreen"
                            loadPage(model.qmlFile)
                            listView.currentIndex = index;
                            for (var i = 0; i < listModel.count; ++i) {
                                listModel.get(i).isActive = (i === index);
                            }

                        }
                        else
                        {
                            sidebar.state="hidescreen"
                            button.forceActiveFocus()
                            listView.currentIndex = index;
                            for (var i = 0; i < listModel.count; ++i) {
                                listModel.get(i).isActive = (i === index);
                            }
                        }
                        btncanvas.requestPaint()
                    }
                    onPressed: {
                        isDoubleCheck=false
                        dragStartX=sideslip.x
                    }
                    onPositionChanged: {
                        if(dragStartX>sideslip.x&&isDoubleCheck===false)
                        {
                            if(sideslip.x<sideslip.width&&sideslip.x>overlayRect.width * 4 / 5)
                            {
                                button.forceActiveFocus()
                                loadPage(model.qmlFile1)
                            }
                            else if(sideslip.x<overlayRect.width * 4 / 5&&sideslip.x>0)
                            {
                                button.forceActiveFocus()
                                loadPage(model.qmlFile)
                            }
                        }
                    }
                    onReleased: {
                        if(isDoubleCheck===false)
                        {
                            if(dragStartX>sideslip.x)
                            {
                                if(sideslip.x<mainWindow.width-sidebar.width&&sideslip.x>overlayRect.width * 4 / 5)
                                {
                                    sidebar.state="halfscreen"
                                    listView.currentIndex = index;
                                    for (var i = 0; i < listModel.count; ++i) {
                                        listModel.get(i).isActive = (i === index);
                                    }
                                }
                                else if(sideslip.x<overlayRect.width * 4 / 5&&sideslip.x>0)
                                {
                                    sidebar.state="fullscreen"
                                    listView.currentIndex = index;
                                    for (var i = 0; i < listModel.count; ++i) {
                                        listModel.get(i).isActive = (i === index);
                                    }
                                }
                            }
                            else
                            {
                                if(sideslip.x>0&&sideslip.x<overlayRect.width * 4 / 5)
                                {
                                    sidebar.state="halfscreen"
                                    button.forceActiveFocus()
                                    loadPage(model.qmlFile1)
                                    listView.currentIndex = index;
                                    for (var i = 0; i < listModel.count; ++i) {
                                        listModel.get(i).isActive = (i === index);
                                    }
                                }
                                else if(sideslip.x>overlayRect.width * 4 / 5&&sideslip.x<mainWindow.width-sidebar.width)
                                {
                                    sidebar.state="hidescreen"
                                    button.forceActiveFocus()
                                    loadPage(model.qmlFile1)
                                    listView.currentIndex = index;
                                    for (var i = 0; i < listModel.count; ++i) {
                                        listModel.get(i).isActive = (i === index);
                                    }
                                }
                            }
                        }

                    }
                }
                Timer {
                    id: timer
                    interval: 100
                    onTriggered: {
                        if(sidebar.state==="hidescreen")
                        {
                            button.forceActiveFocus()
                            sidebar.state="halfscreen"
                            loadPage(model.qmlFile1)
                            listView.currentIndex = index;
                            for (var i = 0; i < listModel.count; ++i) {
                                listModel.get(i).isActive = (i === index);
                            }
                        }
                        else
                        {
                            if(button.activeFocus)
                            {
                                if(sidebar.state==="halfscreen")
                                {
                                    sidebar.state="hidescreen"
                                    listView.currentIndex = index;
                                    for (var i = 0; i < listModel.count; ++i) {
                                        listModel.get(i).isActive = (i === index);
                                    }
                                }
                                else
                                {
                                    button.forceActiveFocus()
                                    sidebar.state="halfscreen"
                                    loadPage(model.qmlFile1)
                                    listView.currentIndex = index;
                                    for (var i = 0; i < listModel.count; ++i) {
                                        listModel.get(i).isActive = (i === index);
                                    }
                                }
                            }
                            else
                            {
                                if(sidebar.state==="halfscreen")
                                {
                                    button.forceActiveFocus()
                                    loadPage(model.qmlFile1)
                                    listView.currentIndex = index;
                                    for (var i = 0; i < listModel.count; ++i) {
                                        listModel.get(i).isActive = (i === index);
                                    }
                                }
                                else if(sidebar.state==="fullscreen")
                                {
                                    button.forceActiveFocus()
                                    loadPage(model.qmlFile)
                                    listView.currentIndex = index;
                                    for (var i = 0; i < listModel.count; ++i) {
                                        if(listModel.get(i).isActive===true)
                                        {
                                            if(i===index)
                                            {
                                                sidebar.state="halfscreen"
                                                loadPage(model.qmlFile1)
                                            }
                                        }
                                        listModel.get(i).isActive = (i === index);
                                    }
                                }
                            }
                        }
                        btncanvas.requestPaint()
                    }
                }
            }
        }

    }
    function loadPage(qmlFile) {
        var component = Qt.createComponent("qrc:/qml/components/Layouts/side/" + qmlFile);
            // 检查组件创建是否成功
            if (component.status === Component.Ready) {
                overloader.sourceComponent = component; // 成功加载时赋值给 sourceComponent
            } else if (component.status === Component.Error) {
                console.error("Component creation error: " + component.errorString());
            }
    }
    Connections{
        target: sideslip
        function onSidebarChangel()
        {
            listView.currentIndex=0
            for (var i = 0; i < listModel.count; ++i) {
                if(i===0)
                {
                    listModel.get(0).isActive = true
                }
                else{
                    listModel.get(i).isActive = false
                }
            }
            if(sidebar.state==="halfscreen")
            {
                loadPage(listModel.get(0).qmlFile1);
            }
            else if(sidebar.state==="fullscreen")
            {
                loadPage(listModel.get(0).qmlFile);
            }
        }
    }

}
