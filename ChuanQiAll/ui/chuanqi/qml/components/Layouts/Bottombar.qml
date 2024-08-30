import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.4
import Widgets 1.0
import Themes 1.0
Rectangle{
    id:buttombar
    Layout.fillWidth: true
    height: 50
    property RectangelStyle skinButtom :SkinManager.currentSkin.topbottomRectangel
    signal apphide()
    signal openDataFilePopup()
    signal openSetFilePopup()
    signal saveSetFilePopup()
    signal beOnline()
    signal beOffline()
    clip: true
    color: skinButtom.backgroundColor

    RowLayout{
        anchors.fill: parent
        clip: true
        Item {
            id:tirect
            width: 170
            clip: true
            Layout.fillHeight: true
            Component.onCompleted: {
                time.start()
            }
            property string currentTime: Qt.formatDateTime(new Date(),  "hh:mm:ss(UTC+8) \n yyyy-MM-dd")
            RowLayout{
                anchors.fill: parent
                spacing: 5
                clip: true
                Rectangle{
                    width: 40
                    height: 40
                    color: "#808080"
                    radius: 50
                    BaseTextSmall {
                        text: "实时数据"
                        anchors.centerIn: parent
                        font.pointSize: 7
                        color: "#ffffff"
                    }

                }
                Rectangle{
                    width: 40
                    height: 40
                    color: "#808080"
                    radius: 50
                    BaseTextSmall {
                        text: "SYNC"
                        anchors.centerIn: parent
                        font.pointSize: 7
                        color: "#ffffff"
                    }

                }
                BaseTextSmall {
                    id: timeText
                    Layout.alignment: Qt.AlignVCenter
                    wrapMode: Text.WordWrap
                    width: 40
                    elide: Text.ElideRight
                    text: tirect.currentTime
                    font.pointSize: 7
                    color: "#ffffff"
                }
            }
            Timer {
                id: time
                interval: 1000 // 每秒更新
                repeat: true
                onTriggered: {
                    timeText.text = Qt.formatDateTime(new Date(),  "hh:mm:ss(UTC+8) \n yyyy-MM-dd")
                }
            }
        }
        Item{
            Layout.fillWidth: true
        }
        Rectangle{
            width: 185
            height:35
            radius: 20
            Layout.alignment: Qt.AlignVCenter
            color: skinButtom.menuBackColor
            Row{
                Layout.fillHeight: true
                Layout.fillWidth: true
                anchors.centerIn: parent
                spacing: 1

                Button{
                    id:rcbtm
                    width: 40
                    height: 30
                    property bool ischecked: false
                    property ButtonStyle skin: SkinManager.currentSkin.bottomRCButton
                    BaseTextModerate {
                        text: "RC"
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                        color: "white"
                    }
                    background: Rectangle{
                        id: rcback
                        radius: 5
                        anchors.fill: parent
                        color: skinButtom.menuBackColor
                    }
                    onClicked: {
                        ischecked=!ischecked
                        rcback.color=ischecked?skin.buttonPressedColor:skin.buttonNormalColor
                    }
                }
                Rectangle{
                    width: 1
                    height: 25
                    color: skinButtom.backgroundColor
                    anchors.verticalCenter: parent.verticalCenter
                }
                IconButton{
                    toolTip:"编辑模式"
                    buttonWidth: 40
                    buttonHeight: 30
                    iconWidth: 25
                    iconHeight:25
                    iconSource:"qrc:/qml/images/BottomIcon/EditMode"
                    skin: SkinManager.currentSkin.iconButton
                }
                Rectangle{
                    width: 1
                    height: 25
                    color: skinButtom.backgroundColor
                    anchors.verticalCenter: parent.verticalCenter
                }
                IconButton{
                    toolTip:"Data labels"
                    buttonWidth: 40
                    buttonHeight: 30
                    iconWidth: 25
                    iconHeight:25
                    iconSource:"qrc:/qml/images/BottomIcon/label"
                    skin: SkinManager.currentSkin.iconButton
                }
                Rectangle{
                    width: 1
                    height: 25
                    color: skinButtom.backgroundColor
                    anchors.verticalCenter: parent.verticalCenter
                }
                IconButton{
                    toolTip:"冻结"
                    buttonWidth: 40
                    buttonHeight: 30
                    iconWidth: 25
                    iconHeight:25
                    iconSource:"qrc:/qml/images/BottomIcon/freeze_white"
                    skin: SkinManager.currentSkin.iconButton
                }
            }
        }
        Item {
            Layout.fillWidth: true
        }
        Item {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignCenter
            Rectangle{
                id:btngroup
                width: 180
                height:35
                color: skinButtom.menuBackColor
                anchors.centerIn: parent
                Row{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    anchors.centerIn: parent
                    spacing: 1
                    IconButton{
                        id:pausebtn
                        toolTip:"暂停"
                        buttonWidth: 45
                        buttonHeight: 25
                        iconWidth: 15
                        iconHeight:15
                        iconSource:"qrc:/qml/images/BottomIcon/pause"
                        skin: SkinManager.currentSkin.iconButton
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                pausebtn.isChecked=!pausebtn.isChecked
                                startbutton.state="start"
                            }
                        }
                    }
                    Rectangle{
                        width: 1
                        height: 25
                        color: skinButtom.backgroundColor
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    IconButton{
                        toolTip:"前进"
                        buttonWidth: 45
                        buttonHeight: 25
                        iconWidth: 15
                        iconHeight:15
                        iconSource:"qrc:/qml/images/BottomIcon/back"
                        skin: SkinManager.currentSkin.iconButton
                    }
                    Rectangle{
                        width: 1
                        height: 25
                        color: skinButtom.backgroundColor
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    IconButton{
                        toolTip:"后退"
                        buttonWidth: 45
                        buttonHeight: 25
                        iconWidth: 15
                        iconHeight:15
                        iconSource:"qrc:/qml/images/BottomIcon/forward"
                        skin: SkinManager.currentSkin.iconButton
                    }
                }
            }
            Rectangle{
                id:startrec
                width: 70
                height: 48
                color: "#272727"
                border.color: "#585858"
                border.width: 3
                radius: 30
                anchors.verticalCenter: parent.verticalCenter
                x:btngroup.x-55
                Button{
                    id:startbutton
                    property ButtonStyle skin: SkinManager.currentSkin.redButton
                    ToolTip.visible: hovered
                    ToolTip.text: "启动"
                    ToolTip.delay: 500
                    width: parent.width-10
                    height: parent.height-10
                    anchors.centerIn: parent
                    smooth: true
                    states: [
                        State {
                            name: "start"
                            PropertyChanges {
                                target: startbutton
                                icon.source:"qrc:/qml/images/BottomIcon/circle"
                                icon.color: "red"
                            }
                        }
                        ,
                        State {
                            name: "running"
                            PropertyChanges {
                                target: startbutton
                                icon.source:"qrc:/qml/images/BottomIcon/Circle_run"
                                icon.color: "white"
                            }
                        },
                        State {
                            name: "pause"
                            PropertyChanges {
                                target: startbutton
                                icon.source:"qrc:/qml/images/BottomIcon/Circle_run"
                                icon.color: "red"
                            }
                        }
                    ]
                    onStateChanged: {
                        if (state === "running") {
                            startbackrect.opacity = 1.0
                            opacityAnimation.start();
                        } else {
                            startbackrect.opacity = 0
                            opacityAnimation.stop();
                        }
                    }
                    background:Rectangle{
                        id:startbackrect
                        color: "red"
                        anchors.fill: parent
                        anchors.centerIn: parent
                        radius: 20
                        SequentialAnimation on opacity {
                            id: opacityAnimation
                            loops: Animation.Infinite
                            PropertyAnimation { to: 0.5; duration: 1000; easing.type: Easing.InOutQuad }
                            PropertyAnimation { to: 1.0; duration: 1000; easing.type: Easing.InOutQuad }
                        }
                    }

                    Component.onCompleted: {
                        startbackrect.opacity = 0
                        opacityAnimation.stop()
                        startbutton.state="start"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            if(startbutton.state==="start")
                            {
                                startbutton.state="running"
                            }
                            else if(startbutton.state==="running")
                            {
                                startbutton.state="pause"
                            }
                            else if(startbutton.state==="pause")
                            {
                                startbutton.state="running"
                            }
                        }
                    }
                }
            }
            Rectangle{
                id:openrec
                width: 70
                height: 48
                color: "#272727"
                border.color: "#585858"
                border.width: 3
                radius: 30
                anchors.verticalCenter: parent.verticalCenter
                x:btngroup.x+btngroup.width-15
                Button{
                    id:openbtn
                    property bool isChecked: false
                    property ButtonStyle skin: SkinManager.currentSkin.iconButton
                    ToolTip.visible: hovered
                    ToolTip.text: "打开数据文件"
                    ToolTip.delay: 500
                    width: parent.width-10
                    height: parent.height-10
                    anchors.centerIn: parent
                    icon.source: "qrc:/qml/images/BottomIcon/file"
                    icon.color:"white"
                    smooth: true
                    background:Rectangle{
                        color: openbtn.isChecked?"#005bb6":"#272727"
                        anchors.fill: parent
                        anchors.centerIn: parent
                        radius: 20
                    }
                    MouseArea{
                        anchors.fill: parent

                        onClicked: {

                            if(openbtn.isChecked===false)
                            {
                                buttombar.openDataFilePopup()
                                buttombar.beOnline
                            }
                            else
                            {
                                buttombar.beOffline
                            }
                        }
                        onPressed: {
                            openbtn.isChecked=true
                        }
                        onReleased: {
                            openbtn.isChecked=false
                        }
                    }
                }
            }
        }
        Item {
            Layout.fillWidth: true
        }
        Rectangle{
            width: 180
            height:35
            radius: 20
            Layout.alignment: Qt.AlignVCenter
            color: skinButtom.menuBackColor
            Row{
                Layout.fillHeight: true
                Layout.fillWidth: true
                anchors.centerIn: parent
                spacing: 1
                IconButton{
                    toolTip:"保存"
                    buttonWidth: 40
                    buttonHeight: 30
                    iconWidth: 25
                    iconHeight:25
                    iconSource:"qrc:/qml/images/BottomIcon/save"
                    skin: SkinManager.currentSkin.iconButton
                }
                Rectangle{
                    width: 1
                    height: 25
                    color: skinButtom.backgroundColor
                    anchors.verticalCenter: parent.verticalCenter
                }
                IconButton{
                    id:opensetfilebtn
                    toolTip:"打开设置文件"
                    buttonWidth: 40
                    buttonHeight: 30
                    iconWidth: 25
                    iconHeight:25
                    iconSource:"qrc:/qml/images/BottomIcon/opensetfile"
                    skin: SkinManager.currentSkin.iconButton
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            buttombar.openSetFilePopup()
                        }
                        onPressed: {
                            opensetfilebtn.isChecked=true
                        }
                        onReleased: {
                            opensetfilebtn.isChecked=false
                        }

                    }
                }
                Rectangle{
                    width: 1
                    height: 25
                    color: skinButtom.backgroundColor
                    anchors.verticalCenter: parent.verticalCenter
                }
                IconButton{
                    id:savesetfilebtn
                    toolTip:"保存设置文件"
                    buttonWidth: 40
                    buttonHeight: 30
                    iconWidth: 25
                    iconHeight:25
                    iconSource:"qrc:/qml/images/BottomIcon/savesetfile"
                    skin: SkinManager.currentSkin.iconButton
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            buttombar.saveSetFilePopup()
                        }
                        onPressed: {
                            savesetfilebtn.isChecked=true
                        }
                        onReleased: {
                            savesetfilebtn.isChecked=false
                        }

                    }
                }
                Rectangle{
                    width: 1
                    height: 25
                    color: skinButtom.backgroundColor
                    anchors.verticalCenter: parent.verticalCenter
                }
                IconButton{
                    toolTip:"添加标记"
                    buttonWidth: 40
                    buttonHeight: 30
                    iconWidth: 25
                    iconHeight:25
                    iconSource:"qrc:/qml/images/BottomIcon/flag"
                    skin: SkinManager.currentSkin.iconButton
                }
            }
        }
        Item{
            Layout.fillWidth: true
        }
        Item {
            width: 170
            clip: true
            Layout.fillHeight: true
            Rectangle {
                width: 100
                height:35
                radius: 20
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                color: skinButtom.menuBackColor
                Row{
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    anchors.centerIn: parent
                    spacing: 1
                    IconButton{
                        toolTip:"提示"
                        buttonWidth: 40
                        buttonHeight: 30
                        iconWidth: 25
                        iconHeight:25
                        iconSource:"qrc:/qml/images/BottomIcon/guide"
                        skin: SkinManager.currentSkin.iconButton
                    }
                    Rectangle{
                        width: 1
                        height: 25
                        color: skinButtom.backgroundColor
                        anchors.verticalCenter: parent.verticalCenter
                    }
                    IconButton{
                        toolTip:"返回"
                        buttonWidth: 40
                        buttonHeight: 30
                        iconWidth: 25
                        iconHeight:25
                        iconSource:"qrc:/qml/images/BottomIcon/return"
                        skin: SkinManager.currentSkin.iconButton
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                buttombar.apphide()
                            }
                        }
                    }
                }
            }
        }
    }
}

