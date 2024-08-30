import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import MyTreeModel 1.0
import Widgets 1.0
import Themes 1.0
Popup{
    id:setpopup
    property string name: "text"
    property color popcolor: "red"
    property real frequency: 1.0
    property real amplitude: 100
    property real phase: 0
    Component.onCompleted: {
        loadPage("Formulamethod.qml");
    }
    function updateData(newFrequency, newAmplitude, newPhase) {
        frequency = newFrequency
        amplitude = newAmplitude
        phase = newPhase
        if(canvas)
        {
            canvas.requestPaint()
        }

    }
    function loadPage(qmlFile) {
        loader.source = "qrc:/qml/components/Layouts/side/FullView2Inside/"+qmlFile
    }
    closePolicy: Popup.NoAutoClose
    //modal: true
    focus: true
    background:Rectangle{
        anchors.fill: parent
        color: "#ffffff"
        border.color: "#cfcfcf"
    }

        Column{
            anchors.fill: parent
            spacing: 10
            Row{
                width: parent.width
                height: 30
                spacing: 10
                BaseSwitch{
                    id:nameswitch
                    anchors.verticalCenter: parent.verticalCenter
                    switchWidth: parent.width/7
                    switchHeight: parent.width/45
                    switchText: setpopup.name
                    ischecked: true
                }

                BaseTextInput{
                    anchors.verticalCenter: parent.verticalCenter
                    width: parent.width*3/4-nameswitch.width
                    height: parent.width/45
                    textContent: setpopup.name
                }
                Rectangle{
                    anchors.verticalCenter: parent.verticalCenter
                    width: 25
                    height:25
                    color: setpopup.popcolor
                }
                IconButton{
                    anchors.verticalCenter: parent.verticalCenter
                    buttonWidth: 25
                    buttonHeight: 25
                    buttonRadius:2
                    iconWidth: 15
                    iconHeight: 15
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/treeIcon/treedown.png"
                }
                IconButton{
                    anchors.verticalCenter: parent.verticalCenter
                    buttonWidth: 25
                    buttonHeight: 25
                    buttonRadius:2
                    iconWidth: 15
                    iconHeight: 15
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/treeIcon/twoleft.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            if (currentIndex > 0) {
                                currentIndex--;
                            } else {
                                currentIndex = leafNodeModel.count - 1;
                            }
                            setpopup.name = leafNodeModel.get(currentIndex).text;
                            setpopup.popcolor = leafNodeModel.get(currentIndex).color;
                        }
                    }
                }
                IconButton{
                    anchors.verticalCenter: parent.verticalCenter
                    buttonWidth: 25
                    buttonHeight: 25
                    buttonRadius:2
                    iconWidth: 15
                    iconHeight: 15
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/treeIcon/tworight.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            if (currentIndex < leafNodeModel.count - 1) {
                                currentIndex++;
                            } else {
                                currentIndex = 0;
                            }
                            setpopup.name = leafNodeModel.get(currentIndex).text;
                            setpopup.popcolor = leafNodeModel.get(currentIndex).color;
                        }
                    }
                }
                IconButton{
                    anchors.verticalCenter: parent.verticalCenter
                    buttonWidth: 25
                    buttonHeight: 25
                    buttonRadius:2
                    iconWidth: 15
                    iconHeight: 15
                    skin: SkinManager.currentSkin.screeniconButton
                    iconSource: "qrc:/qml/images/treeIcon/close.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            setpopup.close()
                        }
                    }
                }
            }
            Row{
                width: parent.width
                height: (parent.height-30)/2
                spacing: 5
                Rectangle{
                    width: parent.width/3-5
                    height: parent.height
                    border.color: "#cfcfcf"
                    clip: true
                    Column{
                        anchors.fill: parent
                        spacing: 5
                        width: parent.width
                        height: parent.height
                        Rectangle{
                            width: parent.width
                            height: 20
                            color: "#cfcfcf"
                            BaseTextSmall{
                                text: "放大器选项"
                            }
                        }
                        Item {
                            width: parent.width-10
                            height: parent.height-20
                            anchors.horizontalCenter: parent.horizontalCenter
                            Flickable{
                                width: parent.width
                                height: parent.height
                                contentWidth: parent.width
                                contentHeight: parent.height+40
                                clip: true
                                Column{
                                    spacing: 5
                                    width: parent.width
                                    height: parent.height
                                    Row{
                                        spacing: 10
                                        width: parent.width
                                        height: 20
                                        BaseTextSmall{
                                            width: parent.width/4
                                            height: parent.height
                                            text: "测量类型"
                                        }
                                        ListModel {
                                            id: testtype
                                            ListElement { text: "电压" }
                                            ListElement { text: "电流" }
                                        }
                                        BaseCombobox{
                                            id:  comboboxtesttype
                                            combWidth: parent.width*2/3
                                            combHeight: parent.height
                                            model: testtype
                                            currentIndex: 0
                                            onCurrentIndexChanged: {
                                                comboboxmeasuringrange.currentIndex=comboboxtesttype.currentIndex
                                            }
                                        }
                                    }
                                    Row{
                                        spacing: 10
                                        width: parent.width
                                        height: 20
                                        BaseTextSmall{
                                            width: parent.width/4
                                            height: parent.height
                                            text: "量程"
                                        }
                                        ListModel {
                                            id: measuringrange
                                            ListElement { text: "-10V...10V" }
                                            ListElement { text: "-200ma...200ma" }
                                        }
                                        BaseCombobox{
                                            id:comboboxmeasuringrange
                                            combWidth: parent.width*2/3
                                            combHeight: parent.height
                                            model: measuringrange
                                            currentIndex: 0
                                        }
                                    }
                                    Row{
                                        spacing: 10
                                        width: parent.width
                                        height: 20
                                        BaseTextSmall{
                                            width: parent.width/4
                                            height: parent.height
                                            text: "低通滤波"
                                        }
                                        ListModel {
                                            id: lowpassfilter
                                            ListElement { text: "Auto" }
                                            ListElement { text: "关" }
                                            ListElement { text: "1kHz" }
                                            ListElement { text: "2kHz" }
                                            ListElement { text: "3kHz" }
                                            ListElement { text: "4kHz" }
                                        }
                                        BaseCombobox{
                                            combWidth: parent.width*2/3
                                            combHeight: parent.height
                                            model: lowpassfilter
                                            currentIndex: 1
                                        }
                                    }
                                    Row{
                                        spacing: 10
                                        width: parent.width
                                        height: 20
                                        Item{
                                            width: parent.width/4
                                            height: parent.height
                                        }
                                        ListModel {
                                            id: num
                                            ListElement { text: "2" }
                                            ListElement { text: "4" }
                                            ListElement { text: "6" }
                                            ListElement { text: "8" }
                                        }
                                        BaseCombobox{
                                            combWidth: parent.width/3-5
                                            combHeight: parent.height
                                            model: num
                                            currentIndex: 1
                                        }
                                        ListModel {
                                            id: type
                                            ListElement { text: "Butterworth" }
                                            ListElement { text: "Bessel" }

                                        }
                                        BaseCombobox{
                                            combWidth: parent.width/3-5
                                            combHeight: parent.height
                                            model: type
                                            currentIndex: 1
                                        }
                                    }
                                    Row{
                                        spacing: 10
                                        width: parent.width
                                        height: 20
                                        BaseTextSmall{
                                            width: parent.width/4
                                            height: parent.height
                                            text: "延迟补偿"
                                        }
                                        ListModel {
                                            id: delaycompensation
                                            ListElement { text: "0" }
                                        }
                                        BaseCombobox{
                                            combWidth: parent.width*2/3
                                            combHeight: parent.height
                                            model: delaycompensation
                                            currentIndex: 1
                                        }
                                    }
                                    Row{
                                        spacing: 10
                                        width: parent.width
                                        height: 20
                                        BaseTextSmall{
                                            clip: true
                                            elide: Text.ElideRight
                                            width: parent.width/4
                                            height: parent.height
                                            text: "有效的延时补偿"
                                        }
                                        BaseTextInput{
                                            width: parent.width*2/3-20
                                            height: parent.height
                                            textContent: "0"
                                        }
                                        BaseTextSmall{
                                            width: 5
                                            height: parent.height
                                            text: "ns"
                                        }
                                    }
                                    Row{
                                        spacing: 10
                                        width: parent.width
                                        height: 20
                                        BaseTextSmall{
                                            clip: true
                                            elide: Text.ElideRight
                                            width: parent.width/4
                                            height: parent.height
                                            text: "Sensor delay compensate"
                                        }
                                        BaseTextInput{
                                            width: parent.width*2/3-20
                                            height: parent.height
                                            textContent: "0"
                                        }
                                        BaseTextSmall{
                                            width: 5
                                            height: parent.height
                                            text: "ms"
                                        }
                                    }
                                    Row{
                                        spacing: 10
                                        width: parent.width
                                        height: 20
                                        BaseTextSmall{
                                            clip: true
                                            elide: Text.ElideRight
                                            width: parent.width/4
                                            height: parent.height
                                            text: "Effective Sensor delay compensate"
                                        }
                                        BaseTextInput{
                                            width: parent.width*2/3-20
                                            height: parent.height
                                            textContent: "0"
                                        }
                                        BaseTextSmall{
                                            width: 5
                                            height: parent.height
                                            text: "ms"
                                        }
                                    }

                                }
                            }

                        }

                    }
                }
                Rectangle{
                    width: parent.width/3-5
                    height: parent.height
                    border.color: "#cfcfcf"
                    Column{
                        anchors.fill: parent
                        spacing: 5
                        Rectangle{
                            width: parent.width
                            height: 20
                            color: "#cfcfcf"
                            BaseTextSmall{
                                text: !comboboxtesttype.currentIndex?"电压测试设置":"电流测试设置"
                            }
                        }
                        Item {
                            width: parent.width-10
                            height: parent.height-20
                            anchors.horizontalCenter: parent.horizontalCenter
                            Column
                            {
                                anchors.fill: parent
                                spacing: 5
                                Row{
                                    spacing: 10
                                    width: parent.width
                                    height: 20
                                    BaseTextSmall{
                                        width: parent.width/4
                                        height: parent.height
                                        text: "输入类型"
                                    }
                                    ListModel {
                                        id: inputtype
                                        ListElement { text: "差分" }

                                    }
                                    BaseCombobox{
                                        combWidth: parent.width*2/3
                                        combHeight: parent.height
                                        model: inputtype
                                        currentIndex:0
                                    }
                                }
                                Row{
                                    spacing: 10
                                    width: parent.width
                                    height: 20
                                    BaseTextSmall{
                                        width: parent.width/4
                                        height: parent.height
                                        text: "分流电阻"
                                    }
                                    ListModel {
                                        id: groupingcurrent
                                        ListElement { text: "ATO-1mR" }
                                        ListElement { text: "ATO-500mR" }
                                        ListElement { text: "Maxi-500mR" }
                                        ListElement { text: "Mini-500mR" }
                                        ListElement { text: "Shunt1" }
                                        ListElement { text: "Shunt2" }
                                        ListElement { text: "Shunt4" }
                                        ListElement { text: "Shunt5" }
                                        ListElement { text: "Shunt6" }
                                        ListElement { text: "Shunt7" }
                                        ListElement { text: "Shunt-BR1" }
                                        ListElement { text: "Shunt-BR5" }
                                        ListElement { text: "Strip-0.2mR" }
                                        ListElement { text: "Strip-500mR" }
                                    }
                                    BaseCombobox{
                                        combWidth: parent.width/3-5
                                        combHeight: parent.height
                                        model: groupingcurrent
                                        currentIndex: 0
                                    }
                                    ListModel {
                                        id: unit
                                        ListElement { text: "1mΩ" }
                                        ListElement { text: "50Ω" }
                                    }
                                    BaseCombobox{
                                        combWidth: parent.width/3-5
                                        combHeight: parent.height
                                        model: unit
                                        currentIndex: 0
                                    }
                                }
                                Row{
                                    spacing: 10
                                    width: parent.width
                                    height: 20
                                    BaseTextSmall{
                                        width: parent.width/4
                                        height: parent.height
                                        text: "最大功率"
                                    }
                                    ListModel {
                                        id: maxpvalue
                                        ListElement { text: "900mW" }

                                    }
                                    BaseCombobox{
                                        combWidth: parent.width/3-5
                                        combHeight: parent.height
                                        model: maxpvalue
                                        currentIndex: 0
                                    }
                                }
                                Row{
                                    spacing: 10
                                    width: parent.width
                                    height: 20
                                    BaseTextSmall{
                                        width: parent.width/4
                                        height: parent.height
                                        text: "最大电流"
                                    }
                                    ListModel {
                                        id: maxaunit
                                        ListElement { text: "30A" }
                                    }
                                    BaseCombobox{
                                        combWidth: parent.width/3-5
                                        combHeight: parent.height
                                        model: maxaunit
                                        currentIndex: 0
                                    }
                                }

                            }
                        }

                    }
                }

                Rectangle{
                    width: parent.width/3-5
                    height: parent.height
                    border.color: "#cfcfcf"
                    Column{
                        anchors.fill: parent
                        spacing: 5
                        width: parent.width
                        height: parent.height
                        Rectangle{
                            width: parent.width
                            height: 20
                            color: "#cfcfcf"
                            BaseTextSmall{
                                text: "传感器系数"
                            }
                        }
                        Row{
                            width: parent.width
                            height: 20
                            spacing: 5
                            Item {
                                width: 5
                                height: parent.height
                            }
                            BaseTextSmall{
                                text: "缩放类型"
                            }
                            ListModel {
                                id: model
                                ListElement { text: "公式法" }
                                ListElement { text: "两点法" }
                                ListElement { text: "表格"}
                                ListElement { text: "多项式"}
                            }
                            BaseCombobox{
                                id:combobox
                                width: parent.width*2/3
                                height: parent.height
                                model: model
                                onCurrentIndexChanged: {
                                    if(combobox.currentIndex==0)
                                    {
                                        loadPage("Formulamethod.qml");
                                    }
                                    else if(combobox.currentIndex==1)
                                    {
                                        loadPage("TwoPointMethod.qml");
                                    }
                                    else if(combobox.currentIndex==2)
                                    {
                                        loadPage("Form.qml");
                                    }
                                    else if(combobox.currentIndex==3)
                                    {
                                        loadPage("Multinomial.qml");
                                    }
                                }
                            }
                            TextButton{
                                width: 50
                                height: 20
                                buttonText: "Enum"
                            }
                        }

                        Item {
                            width: parent.width
                            height: parent.height-40
                            Loader {
                                id: loader
                                anchors.centerIn: parent
                                width: parent.width-3
                                height: parent.height-3
                            }
                        }
                    }
                }
            }
            Column{
                spacing: 0
                width: parent.width
                height: (parent.height-30)/2
                Rectangle{
                    width: parent.width
                    height: 20
                    color: "#cfcfcf"
                    BaseTextSmall{
                        text: "预览"
                    }
                }
                Rectangle{
                    border.color: "#cfcfcf"
                    width: parent.width
                    height: parent.height-30
                    Item {
                        width: parent.width
                        height: parent.height
                        Row{
                            spacing: 0
                            width: parent.width-20
                            height: parent.height-10
                            anchors.centerIn: parent
                            Rectangle{
                                anchors.verticalCenter: parent.verticalCenter
                                width: parent.width*3/5
                                height: parent.height
                                border.color: "#cfcfcf"
                                Item {
                                    anchors.fill: parent
                                    Canvas {
                                        id: canvas
                                        width: parent.width
                                        height: parent.height
                                        onPaint: {
                                            var ctx = canvas.getContext("2d")
                                            ctx.clearRect(0, 0, canvas.width, canvas.height)

                                            var offsetY = canvas.height / 2
                                            var sampleRate = 0.01

                                            ctx.beginPath()
                                            ctx.moveTo(0, offsetY)

                                            for (var x = 0; x < canvas.width; x++) {
                                                var y = amplitude * Math.sin(2 * Math.PI * frequency * x * sampleRate + phase)
                                                ctx.lineTo(x, offsetY - y)
                                            }

                                            ctx.strokeStyle = "blue"
                                            ctx.lineWidth = 2
                                            ctx.stroke()
                                        }
                                    }
                                    Timer {
                                        id: dataTimer
                                        interval: 100 // 100 ms interval for data update
                                        running: true
                                        repeat: true
                                        onTriggered: {
                                            // Simulate incoming data
                                            var newFrequency = Math.random() * 5
                                            var newAmplitude = 50 + Math.random() * 150
                                            var newPhase = Math.random() * 2 * Math.PI
                                            updateData(newFrequency, newAmplitude, newPhase)
                                        }
                                    }
                                }
                            }

                            Canvas {
                                width: parent.width / 10
                                height: parent.height
                                id:slash
                                onPaint: {
                                    var ctx = slash.getContext('2d');
                                    ctx.clearRect(0, 0, slash.width, slash.height); // 清空画布

                                    // 绘制背景矩形以调试 Canvas 区域
                                    ctx.fillStyle = '#ffffff';
                                    ctx.fillRect(0, 0, slash.width, slash.height);

                                    // 打印 Canvas 大小以调试
                                    console.log("Canvas size:", slash.width, slash.height);

                                    // 从左下角绘制到右上角
                                    var startX = 0;
                                    var startY = slash.height;
                                    var endX = slash.width;
                                    var endY = 0;

                                    ctx.beginPath();
                                    ctx.moveTo(startX, startY);  // 起点 (左下角)
                                    ctx.lineTo(endX, endY);  // 终点 (右上角)
                                    ctx.strokeStyle = 'black';  // 线条颜色
                                    ctx.lineWidth = 2;  // 线条宽度
                                    ctx.stroke();
                                }
                            }
                            Rectangle{
                                anchors.verticalCenter: parent.verticalCenter
                                width: parent.width/6
                                height: parent.height
                                border.color: "#cfcfcf"
                            }
                            Rectangle {
                                width: 70
                                height: parent.height*2/3
                                border.color: "#cfcfcf"
                                Column{
                                    width: parent.width-2
                                    height: parent.height-2
                                    anchors.centerIn: parent
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/8
                                        color: "#cfcfcf"
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: "最大值"
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/8
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: "NaN"
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/8
                                        color: "#cfcfcf"
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: "有效值"
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/8
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: "NaN"
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/8
                                        color: "#cfcfcf"
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: "平均值"
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/8
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: "NaN"
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/8
                                        color: "#cfcfcf"
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: "最小值"
                                        }
                                    }
                                    Rectangle{
                                        width: parent.width
                                        height: parent.height/8
                                        BaseTextSmall{
                                            anchors.centerIn: parent
                                            text: "NaN"
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
