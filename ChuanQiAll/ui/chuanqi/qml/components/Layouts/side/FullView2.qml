import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
import MyListModel 1.0
import "../side/FullView2Inside/Popup"
Rectangle{
    id:full2

    SetPopup{
        id:setpopup
    }
    ApplyPopup{
        id:applypopup
    }
    SavePopup{
        id:savepopup
    }
    AddPopup{
        id:addpopup
    }
    IdPopup{
        id:idpopup
    }

    anchors.fill: parent
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    property bool group: false
    property real widthchanged: 0.0
    property real leftwidth: 0.0
    property real rightwidth: 0.0
    property int  currentIndex: -1
    property int  i:0;
    signal waveformDisplay(int index)
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor

    Connections {
        target: getdevinf
        function onDeviceDataListChanged(threadid){
            getdevinf.upDateDeviceData(threadid);
        }
    }
    Column{
        anchors.fill: parent
        Row{
            height: parent.height/4
            width: parent.width
            spacing: 10
            Rectangle{
                width: 150
                height: parent.height
                border.color: "#cfcfcf"
                color: "#ffffff"
                Flickable{
                    anchors.fill: parent
                    clip: true
                    contentHeight: parent.height
                    ScrollBar.vertical: ScrollBar{}

                    Column{
                        anchors.fill: parent
                        ListModel{
                            id:ippath
                            ListElement{text:"LocalNode"}
                        }
                        ListView{
                            width: parent.width
                            height: parent.height
                            model:ippath
                            delegate: Rectangle{
                                height: 50
                                width: parent.width
                                color: "#efefef"
                                border.color: "#cfcfcf"
                                BaseTextSmall{
                                    text: model.text
                                    anchors.centerIn: parent
                                }
                            }
                        }
                    }
                }
            }
            Rectangle{
                width: 150
                height: parent.height
                border.color: "#cfcfcf"
                color: "#ffffff"
                Flickable{
                    anchors.fill: parent
                    clip: true
                    contentHeight: parent.height
                    ScrollBar.vertical: ScrollBar{}
                    Component.onCompleted: {
                        for(var i=0;i<getdevinf.getActivateDeviceNumber();i++)
                        {
                            machine.append({"text": getdevinf.getActivateDeviceName(i),"active":getdevinf.getDeviceActive(i),"isClicked":false})

                        }
                        for(var i=0;i<getdevinf.getActiveDeviceChannelsNum(0);i++)
                        {
                            boardcard1.append({"text": getdevinf.getActiveDeviceChannelsName(0,i),"activeDevice":getdevinf.getActivateDeviceName(0),"isClicked":false})
                            boardcard2.append({"text": getdevinf.getActiveDeviceChannelsName(0,i),"activeDevice":getdevinf.getActivateDeviceName(0),"isClicked":false})
                        }
                    }

                    Column{
                        anchors.fill: parent
                        ListModel{
                            id:machine
                        }
                        ListView{
                            width: parent.width
                            height: parent.height
                            model:machine
                            delegate: Rectangle{
                                height: model.active===true?50:0
                                width: parent.width
                                color: model.isClicked?"#b7c9db":"#efefef"
                                border.color: "#cfcfcf"
                                visible: model.active
                                BaseTextSmall{
                                    wrapMode: Text.WordWrap
                                    width: parent.width
                                    text: model.text
                                    font.pointSize: 7
                                    anchors.centerIn: parent
                                }
                                MouseArea{
                                    anchors.fill: parent
                                    onClicked: {
                                        for (var i = 0; i < machine.count; i++) {
                                            machine.setProperty(i, "isClicked", false);
                                        }
                                        machine.setProperty(index, "isClicked", true);
                                        boardcard1.clear()
                                        boardcard2.clear()

                                        for(var i=0;i<getdevinf.getActiveDeviceChannelsNum(index);i++)
                                        {
                                            boardcard1.append({"text": getdevinf.getActiveDeviceChannelsName(index,i),"activeDevice":getdevinf.getActivateDeviceName(index),"isClicked":false})
                                            boardcard2.append({"text": getdevinf.getActiveDeviceChannelsName(index,i),"activeDevice":getdevinf.getActivateDeviceName(index),"isClicked":false})
                                        }
                                        for(var i=0;i<MyListModel.count;i++)
                                        {
                                            for(var j=0;j<boardcard1.count;j++)
                                            {
                                                if(MyListModel.get(i).activeDevice===boardcard1.get(j).activeDevice&&MyListModel.get(i).text===boardcard1.get(j).text)
                                                {
                                                    boardcard1.get(j).isClicked=MyListModel.get(i).isClicked
                                                }
                                            }
                                            for(var j=0;j<boardcard2.count;j++)
                                            {
                                                if(MyListModel.get(i).activeDevice===boardcard2.get(j).activeDevice&&MyListModel.get(i).text===boardcard2.get(j).text)
                                                {
                                                    boardcard2.get(j).isClicked=MyListModel.get(i).isClicked
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Rectangle{
                width: parent.width/2
                height: parent.height
                border.color: "#cfcfcf"
                color: "#cfcfcf"
                Column{
                    width: parent.width
                    height: parent.height
                    Row{
                        width: parent.width/2
                        height: parent.height/2
                        spacing: 5

                        Column{
                            id:num
                            height: parent.height
                            width: 50
                            visible: false
                            Rectangle{
                                height: parent.height/2
                                width: parent.height/2
                                border.color: "#cfcfcf"
                                color: "#ffffff"
                                BaseTextModerate{
                                    anchors.centerIn: parent
                                    text: "1"
                                }
                            }
                            Rectangle{
                                height: parent.height/2
                                width: parent.height/2
                                border.color: "#cfcfcf"
                                color: "#ffffff"
                                BaseTextModerate{
                                    anchors.centerIn: parent
                                    text: "2"
                                }
                            }
                        }
                        Rectangle{
                            id:boardcardrect
                            visible: false
                            width: parent.width
                            height: parent.height
                            border.color: "#cfcfcf"
                            ListModel{
                                id:boardcard1
                            }
                            ListView{
                                width: parent.width
                                height: parent.height
                                model: boardcard1
                                orientation: ListView.Horizontal
                                delegate: Rectangle{
                                    width: 50
                                    height: boardcardrect2.height
                                    border.color: isClicked==false?"#cfcfcf":"#6794c2"
                                    color: isClicked==false?"#efefef":"#b7c9db"
                                    Column{
                                        anchors.fill:parent
                                        Item {
                                            width: parent.width
                                            height:parent.height/2
                                            Rectangle{
                                                anchors.centerIn: parent
                                                width: 40
                                                height: 40
                                                radius: 20
                                                border.color: "#585858"
                                                border.width: 5
                                                color: "#000000"
                                                Rectangle{
                                                    anchors.centerIn: parent
                                                    width: 20
                                                    height: 20
                                                    radius: 20
                                                    border.color: "#585858"
                                                    border.width: 5
                                                    color: "#000000"
                                                }
                                            }
                                        }
                                        Item {
                                            width: parent.width
                                            height:parent.height/2
                                            Rectangle{
                                                anchors.centerIn: parent
                                                width: 40
                                                height: 40
                                                radius: 20
                                                border.color: "#ff4f34"
                                                border.width: 5
                                                color: "#80281a"
                                                Rectangle{
                                                    anchors.centerIn: parent
                                                    width: 20
                                                    height: 20
                                                    radius: 20
                                                    border.color: "#ff4f34"
                                                    border.width: 5
                                                    color: "#80281a"
                                                }
                                            }
                                        }
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            for(var i=0;i<MyListModel.count;i++)
                                            {
                                                if(MyListModel.get(i).activeDevice===model.activeDevice&&MyListModel.get(i).text===model.text)
                                                {
                                                    isClicked=!isClicked
                                                    MyListModel.get(i).isClicked=!MyListModel.get(i).isClicked
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                        }

                    }

                    Row{
                        width: parent.width/2
                        height: parent.height/2
                        spacing: 5

                        Column{
                            height: parent.height
                            width: 50
                            Rectangle{
                                height: parent.height/2
                                width: parent.height/2
                                border.color: "#cfcfcf"
                                color: "#ffffff"
                                BaseTextModerate{
                                    anchors.centerIn: parent
                                    text: "1"
                                }
                            }
                            Rectangle{
                                height: parent.height/2
                                width: parent.height/2
                                border.color: "#cfcfcf"
                                color: "#ffffff"
                                BaseTextModerate{
                                    anchors.centerIn: parent
                                    text: "2"
                                }
                            }
                        }
                        Rectangle{
                            id:boardcardrect2
                            width: parent.width
                            height: parent.height
                            border.color: "#cfcfcf"
                            ListModel{
                                id:boardcard2
                            }
                            ListView{
                                width: parent.width
                                height: parent.height
                                model: boardcard2
                                orientation: ListView.Horizontal
                                delegate: Rectangle{
                                    width: 50
                                    height: boardcardrect2.height
                                    border.color: isClicked==false?"#cfcfcf":"#6794c2"
                                    color: isClicked==false?"#efefef":"#b7c9db"
                                    Column{
                                        anchors.fill:parent
                                        Item {
                                            width: parent.width
                                            height:parent.height/2
                                            Rectangle{
                                                anchors.centerIn: parent
                                                width: 40
                                                height: 40
                                                radius: 20
                                                border.color: "#585858"
                                                border.width: 5
                                                color: "#000000"
                                                Rectangle{
                                                    anchors.centerIn: parent
                                                    width: 20
                                                    height: 20
                                                    radius: 20
                                                    border.color: "#585858"
                                                    border.width: 5
                                                    color: "#000000"
                                                }
                                            }
                                        }
                                        Item {
                                            width: parent.width
                                            height:parent.height/2
                                            Rectangle{
                                                anchors.centerIn: parent
                                                width: 40
                                                height: 40
                                                radius: 20
                                                border.color: "#ff4f34"
                                                border.width: 5
                                                color: "#80281a"
                                                Rectangle{
                                                    anchors.centerIn: parent
                                                    width: 20
                                                    height: 20
                                                    radius: 20
                                                    border.color: "#ff4f34"
                                                    border.width: 5
                                                    color: "#80281a"
                                                }
                                            }
                                        }
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            for(var i=0;i<MyListModel.count;i++)
                                            {
                                                if(MyListModel.get(i).activeDevice===model.activeDevice&&MyListModel.get(i).text===model.text)
                                                {
                                                    isClicked=!isClicked
                                                    MyListModel.get(i).isClicked=!MyListModel.get(i).isClicked
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                        }
                    }
                }
            }
        }
        Rectangle {
            id:titlritem
            width: parent.width
            height: 60
            color: "#cfcfcf"
            border.color: "#585858"
            Row{
                anchors.fill: parent
                spacing: 0
                Item {
                    id:passagewayrect
                    width: parent.width/2
                    height: parent.height
                    Column{
                        spacing: 0
                        anchors.fill: parent
                        Item{
                            width: parent.width
                            height: parent.height/2
                            Row{
                                spacing: 5
                                anchors.fill: parent
                                Item {
                                    width: 5
                                    height: parent.height
                                }
                                IconButton{
                                    buttonWidth: 50
                                    buttonHeight: parent.height-5
                                    anchors.verticalCenter: parent.verticalCenter
                                    buttonRadius:2
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: "qrc:/qml/images/treeIcon/screen.png"
                                }
                                TextButton{
                                    buttonWidth: parent.width/10
                                    buttonHeight: parent.height-5
                                    text: "Analog"
                                    anchors.verticalCenter: parent.verticalCenter
                                    buttonRadius: 2
                                }
                                TextButton{
                                    buttonWidth: parent.width/10
                                    buttonHeight: parent.height-5
                                    text: "Counter"
                                    anchors.verticalCenter: parent.verticalCenter
                                    buttonRadius: 2
                                }
                                TextButton{
                                    buttonWidth: parent.width/10
                                    buttonHeight: parent.height-5
                                    text: "Video"
                                    buttonRadius: 2
                                    anchors.verticalCenter: parent.verticalCenter
                                }

                                BaseTextInput{
                                    textContent: "搜索"
                                    width: 150
                                    height: parent.height-5
                                    anchors.verticalCenter: parent.verticalCenter
                                }
                                IconButton{
                                    buttonWidth: 50
                                    buttonHeight: parent.height-5
                                    anchors.verticalCenter: parent.verticalCenter
                                    buttonRadius:2
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: "qrc:/qml/images/treeIcon/noscreen.png"
                                }
                                IconButton{
                                    id:branch
                                    buttonWidth: 50
                                    buttonHeight: parent.height-5
                                    anchors.verticalCenter: parent.verticalCenter
                                    buttonRadius:2
                                    iconWidth: 15
                                    iconHeight: 15
                                    isChecked:false
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: branch.isChecked?"qrc:/qml/images/treeIcon/branchwhite.png":"qrc:/qml/images/treeIcon/branch.png"
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            branch.isChecked=!branch.isChecked
                                            group=branch.isChecked
                                        }
                                    }
                                }

                            }
                        }
                        Rectangle{
                            width: parent.width
                            height: parent.height/2
                            color: "#585858"
                            Row{
                                anchors.fill: parent
                                spacing:1
                                IconButton{
                                    id:select
                                    buttonWidth: parent.height
                                    buttonHeight: parent.height
                                    buttonRadius:2
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: select.isChecked?"qrc:/qml/images/treeIcon/noSelectAll.png":"qrc:/qml/images/treeIcon/SelectAll.png"
                                }
                                IconButton{
                                    buttonWidth: parent.height
                                    buttonHeight: parent.height
                                    buttonRadius:2
                                    visible: group
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: "qrc:/qml/images/treeIcon/left.png"
                                }
                                IconButton{
                                    buttonWidth: parent.height
                                    buttonHeight: parent.height
                                    buttonRadius:2
                                    visible: group
                                    iconWidth: 15
                                    iconHeight: 15
                                    skin: SkinManager.currentSkin.screeniconButton
                                    iconSource: "qrc:/qml/images/treeIcon/right.png"
                                }

                                Item {
                                    id:iditem
                                    width: group?150:212
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "ID"
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            idpopup.x=iditem.x
                                            idpopup.y=titlritem.y+titlritem.height
                                            idpopup.width=iditem.width
                                            idpopup.height=180
                                            idpopup.open()
                                        }
                                    }
                                }
                                Column{
                                    width: 1
                                    height: parent.height/3
                                    spacing: 3
                                    anchors.verticalCenter: parent.verticalCenter
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }

                                Item{
                                    id:coloritem
                                    width: 60
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "颜色"
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }
                                Item{
                                    id:setitem
                                    width: 60
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "设置"
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }
                                Item{
                                    id:useitem
                                    width: 60
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "使用"

                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            applypopup.x=setitem.x
                                            applypopup.y=titlritem.y+titlritem.height
                                            applypopup.width=setitem.width*3+15
                                            applypopup.height=100
                                            applypopup.open()
                                        }
                                    }
                                }
                                Column{
                                    width: 1
                                    height: parent.height/3
                                    spacing: 3
                                    anchors.verticalCenter: parent.verticalCenter
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }
                                Item{
                                    id:saveitem
                                    width: 60
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.centerIn: parent
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "存储"

                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: {
                                            savepopup.x=setitem.x
                                            savepopup.y=titlritem.y+titlritem.height
                                            savepopup.width=setitem.width*3+15
                                            savepopup.height=100
                                            savepopup.open()
                                        }
                                    }
                                }
                                Column{
                                    width: 1
                                    height: parent.height/3
                                    spacing: 3
                                    anchors.verticalCenter: parent.verticalCenter
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                    Rectangle{
                                        width: 1
                                        height: 1
                                    }
                                }
                                Rectangle{
                                    width: 1
                                    height: parent.height/2
                                    anchors.verticalCenter: parent.verticalCenter
                                    color: "#ffffff"
                                }
                                Item {
                                    id:valueitem
                                    width: group?(parent.width-parent.height*3-iditem.width-270):(parent.width-parent.height-iditem.width-268)
                                    height: parent.height
                                    BaseTextSmall{
                                        anchors.fill: parent
                                        elide: Text.ElideRight
                                        fontcol: SkinManager.currentSkin.whitefont
                                        text: "换算值"
                                        horizontalAlignment: Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                    }
                                }
                                Rectangle{
                                    id:slidbarrect
                                    width: 4
                                    height: parent.height
                                    color: "#585858"
                                    border.color: "#ffffff"
                                    MouseArea {
                                        anchors.fill: parent
                                        drag.target: determine//要拖动的项目的ID
                                        drag.axis: Drag.XAxis//拖动的轴方向
                                        drag.minimumX: 0
                                        drag.maximumX:  titlritem.width
                                        onPressed: {
                                            determine.visible=true
                                            widthchanged=determine.x
                                            determine.x=slidbarrect.x
                                            leftwidth=valueitem.width

                                        }
                                        //slidbarrect     选择区域
                                        //determine       当前滑动条
                                        //passagewayrect  左侧全部
                                        //setrect         右侧全部
                                        onReleased: {
                                            determine.visible=false
                                            if(determine.x<widthchanged)
                                            {
                                                if(determine.x<(valueitem.x+30))
                                                {
                                                    passagewayrect.width=passagewayrect.width-valueitem.width+30
                                                    setrect.width=setrect.width+(leftwidth-30)
                                                    valueitem.width=30
                                                }
                                                else
                                                {
                                                    valueitem.width=valueitem.width-(widthchanged-determine.x)
                                                    passagewayrect.width=passagewayrect.width-(widthchanged-determine.x)
                                                    setrect.width=setrect.width+(widthchanged-determine.x)
                                                }

                                            }
                                            else if(determine.x>widthchanged)
                                            {
                                                if(determine.x>full2.width-50)
                                                {
                                                    valueitem.width=(full2.width-valueitem.x-50)
                                                    setrect.width=50
                                                }
                                                else{
                                                    valueitem.width=valueitem.width+(determine.x-widthchanged)
                                                    passagewayrect.width=passagewayrect.width+(determine.x-widthchanged)
                                                    setrect.width=setrect.width-(determine.x-widthchanged)
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                Rectangle{
                    id:setrect
                    width: parent.width/2
                    height: parent.height
                    color: "#585858"
                    Column{
                        anchors.fill: parent
                        Row{
                            width: parent.width
                            height: parent.height/2
                            Item{
                                width: parent.height
                                height: parent.height
                                Image {
                                    anchors.centerIn: parent
                                    width: parent.height
                                    height: parent.height
                                    source: "qrc:/qml/images/treeIcon/doubleleft.png"
                                }
                            }
                            Item{
                                width: parent.width-parent.height*2
                                height: parent.height
                                BaseSlider{
                                    sliderWidth:parent.width
                                    slideHeight:parent.height/3
                                    backWidth:parent.width
                                    backHeight: parent.height/3
                                    backRadius:3
                                    backColor:"#ffffff"
                                    slideOverColor:"#ffffff"
                                    blockWidth:parent.width/3
                                    blockHeight:parent.height/3
                                    blockColor:"#585858"
                                    blockBroderColor:"#585858"
                                    blockRadius:3
                                    anchors.centerIn: parent
                                }
                            }
                            Item{
                                width: parent.height
                                height: parent.height
                                Image {
                                    anchors.centerIn: parent
                                    width: parent.height
                                    height: parent.height
                                    source: "qrc:/qml/images/treeIcon/doubleright.png"
                                }
                            }
                        }
                        Row{
                            width: parent.width
                            height: parent.height/2
                            Item {
                                id:mileageitem
                                width: parent.width/3
                                height: parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    elide: Text.ElideRight
                                    fontcol: SkinManager.currentSkin.whitefont
                                    text: "里程"
                                }
                            }
                            Rectangle{
                                width: 1
                                height: parent.height/2
                                anchors.verticalCenter: parent.verticalCenter
                                color: "#ffffff"
                            }
                            Item {
                                id:coefficientitem
                                width: parent.width*2/3
                                height: parent.height
                                BaseTextSmall{
                                    anchors.centerIn: parent
                                    fontcol: SkinManager.currentSkin.whitefont
                                    elide: Text.ElideRight
                                    text: "比例系数"
                                }
                            }
                        }
                    }
                }

            }
            onYChanged: {
                if(idpopup.visible)
                {
                    idpopup.x=iditem.x
                    idpopup.y=y+titlritem.height
                    idpopup.width=iditem.width
                    idpopup.height=180
                }
                if(applypopup.visible)
                {
                    applypopup.x=setitem.x
                    applypopup.y=y+titlritem.height
                    applypopup.width=setitem.width*3+15
                    applypopup.height=100
                }
                if(savepopup.visible)
                {
                    savepopup.x=setitem.x
                    savepopup.y=y+titlritem.height
                    savepopup.width=setitem.width*3+15
                    savepopup.height=100
                }
                if(setpopup.visible)
                {
                    setpopup.width=listitem.width*2/3
                    setpopup.height=listitem.height
                    setpopup.x=listitem.x+listitem.width/3
                    setpopup.y=titlritem.y+titlritem.height
                }

            }
        }
        Item{
            id:listitem
            width: parent.width
            height: parent.height-parent.height/4-titlritem.height-41

            Flickable{
                anchors.fill: parent
                contentWidth: parent.width
                contentHeight: parent.height
                clip: true
                ScrollBar.vertical: ScrollBar{}
                Row{
                    anchors.fill: parent
                    ListView {
                        id:mytree
                        width: parent.width//passagewayrect.width
                        height: parent.height
                        model: MyListModel
                        delegate: Rectangle{
                            property double displayValue: 0.0
                            width: parent.width
                            height: isVisible==true?select.height:0
                            color: isClicked==false?index%2===0?"#efefef":"#ffffff":"#b7c9db"
                            border.color: isClicked==false?index%2===0?"#efefef":"#ffffff":"#6794c2"
                            visible: isVisible
                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    isClicked=!isClicked
                                    for(var i=0;i<boardcard2.count;i++)
                                    {
                                        if(MyListModel.get(index).activeDevice===boardcard2.get(i).activeDevice&&MyListModel.get(index).text===boardcard2.get(i).text)
                                        {
                                            boardcard2.get(i).isClicked=isClicked
                                        }
                                    }
                                }
                            }

                            Row{
                                anchors.fill: parent
                                Row{
                                    width: passagewayrect.width
                                    height: parent.height
                                    Item {
                                        width: select.width
                                        height: parent.height
                                        BaseCheckBox{
                                            id:treecheckbox
                                            anchors.centerIn: parent
                                            checkBackColorVisible:false
                                            onCheckedChanged:{
                                                model.checked = checked
                                                isClicked=checked
                                                for(var i=0;i<boardcard2.count;i++)
                                                {
                                                    if(MyListModel.get(index).activeDevice===boardcard2.get(i).activeDevice&&MyListModel.get(index).text===boardcard2.get(i).text)
                                                    {
                                                        boardcard2.get(i).isClicked=isClicked
                                                    }
                                                }
                                            }
                                            checked: isClicked

                                        }
                                    }
                                    Item {
                                        width: select.width
                                        height: parent.height
                                        visible: group
                                    }
                                    Item {
                                        width: select.width
                                        height: parent.height
                                        visible: group
                                    }
                                    Item {
                                        width: iditem.width+6
                                        height: parent.height
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: model.text
                                        }
                                    }
                                    Item{
                                        width: coloritem.width+2
                                        height: parent.height
                                        Rectangle{
                                            width: parent.height-10
                                            height: parent.height-10
                                            anchors.centerIn: parent
                                            radius: 5
                                            color: model.color
                                        }

                                    }
                                    Item{
                                        width: setitem.width+2
                                        height: parent.height-2
                                        anchors.verticalCenter: parent.verticalCenter
                                        Item{
                                            width: parent.height
                                            height: parent.height
                                            anchors.fill: parent
                                            Image {
                                                width: 15
                                                height: 15
                                                anchors.centerIn: parent
                                                source: "qrc:/qml/images/RightIcon/set.png"
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        full2.waveformDisplay(index)
                                                        setpopup.visible=true
                                                        setpopup.width=listitem.width*2/3
                                                        setpopup.height=listitem.height
                                                        setpopup.x=listitem.x+listitem.width/3
                                                        setpopup.y=titlritem.y+titlritem.height
                                                        setpopup.name=model.text
                                                        setpopup.popcolor=model.color
                                                        currentIndex=index
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    Item {
                                        width: useitem.width+8
                                        height: parent.height
                                        BaseSwitch{
                                            switchWidth: parent.width
                                            switchHeight: parent.height
                                            anchors.centerIn: parent
                                            switchText: ""
                                            ischecked: true
                                        }
                                    }
                                    Item{
                                        id:save
                                        width: saveitem.width+2
                                        height: parent.height
                                        property bool issave: true
                                        Rectangle{
                                            width: 20
                                            height: 20
                                            color: save.issave===false?"#ffffff":"red"
                                            border.color: "#cfcfcf"
                                            anchors.centerIn: parent
                                            radius: 5
                                            Rectangle{
                                                width: 10
                                                height: 10
                                                color: save.issave===false?"#efefef":"#ffffff"
                                                radius: 10
                                                anchors.centerIn: parent
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        save.issave=!save.issave
                                                    }
                                                }
                                            }
                                            MouseArea{
                                                anchors.fill: parent
                                                onClicked: {
                                                    save.issave=!save.issave
                                                }
                                            }
                                        }

                                    }
                                    Item{
                                        width: valueitem.width
                                        height: parent.height
                                        Column{
                                            width: valueitem.width
                                            height: parent.height
                                            Row{
                                                width: parent.width
                                                height: parent.height/2
                                                Item {
                                                    width: 30
                                                    height: parent.height
                                                    BaseTextSmall{
                                                        font.pointSize: 6
                                                        text: displayValue
                                                    }
                                                    Timer {
                                                        interval: 200
                                                        repeat: true
                                                        running: true
                                                        onTriggered: {
                                                            displayValue = value
                                                        }
                                                    }
                                                }
                                                Item {
                                                    width: parent.width-60
                                                    height: parent.height
                                                }
                                                Item{
                                                    width: 30
                                                    height: parent.height
                                                    BaseTextSmall{
                                                        font.pointSize: 6
                                                        text: "平均值"
                                                    }
                                                }
                                            }
                                            Rectangle{
                                                width: parent.width
                                                height: parent.height/2-4
                                                border.color: "#cfcfcf"
                                            }
                                        }
                                    }


                                }
                                Row{
                                    width: setrect.width
                                    height: parent.height
                                    Item{
                                        width: mileageitem.width
                                        height:parent.height
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: model.mileage
                                        }
                                    }
                                    Item{
                                        width: coefficientitem.width
                                        height: parent.height
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: model.coefficient
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        Rectangle{
            width: parent.width
            height: 1
            color: "#585858"
        }

        Item{
            width: parent.width
            height: 40
            Row{
                anchors.fill: parent
                spacing: 10
                IconButton{
                    buttonWidth: 70
                    buttonHeight: parent.height-5
                    anchors.verticalCenter: parent.verticalCenter
                    buttonRadius:2
                    iconWidth: 30
                    iconHeight: 30
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/LeftIcon/add.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            addpopup.open()
                            addpopup.width=full2.width/2
                            addpopup.height=full2.height*2/3
                        }
                    }
                }
                IconButton{
                    buttonWidth: 70
                    buttonHeight: parent.height-5
                    anchors.verticalCenter: parent.verticalCenter
                    buttonRadius:2
                    iconWidth: 30
                    iconHeight: 30
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/LeftIcon/sub.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            for (var i = MyListModel.rowCount() - 1; i >= 0; --i) {
                                if (MyListModel.get(i).checked) {
                                    MyListModel.remove(i);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    Rectangle{
        id:determine
        visible: false
        z:1
        width: 4
        height: mytree.height
        x: slidbarrect.x
        y: titlritem.y+60
        color: "#585858"
    }



}
