import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
import MyListModel 1.0
Popup{
    id:setpopup
    property string name: "text"
    property color popcolor: "red"
    // property var fenestraWaveforms: []//小窗口波形显示
    // property var largeWaveforms: []//大窗口波形显示
    property var lineVisibility: []//波形显示
    property int offset: 0  // 偏移量控制移动
    property int fenoffset: 0  // 偏移量控制移动
    property int lineY: 0  // 偏移量控制移动
    // 假设每个波形的环形缓冲区大小
    property int fenestraBufferSize : 201;  // 小波形的缓冲区大小
    property int largeBufferSize : 723;     // 大波形的缓冲区大小

    // 初始化环形缓冲区
    property var fenestraWaveforms:[];  // 保存小波形的环形缓冲区
    property var largeWaveforms:[];      // 保存大波形的环形缓冲区
    property var fenestraWriteIndex:[];  // 小波形的写入索引
    property var largeWriteIndex:[];     // 大波形的写入索引

    Component.onCompleted: {
        loadPage("Formulamethod.qml");
        for (var i = 0; i < fenestraWaveforms.length; i++) {
            lineVisibility.push(false);
        }

    }
    Connections {
        target: full2
        function onWaveformDisplay(index) {
            // 重置所有线条为隐藏状态
            for (var i = 0; i < lineVisibility.length; i++) {
                lineVisibility[i] = false;
            }

            // 只显示选中的曲线
            lineVisibility[index] = true;
        }
    }
    Connections {
        target: MyListModel
        function onReturnIndexValue(index,data) {
            // 确保缓冲区存在
            while (fenestraWaveforms.length <= index) {
                fenestraWaveforms.push([]);  // 初始化为一个空数组（队列）
            }
            while (largeWaveforms.length <= index) {
                largeWaveforms.push([]);     // 初始化为一个空数组（队列）
            }

            // 添加新数据点到小波形队列（尾部）
            fenestraWaveforms[index].push(data);

            // 如果小波形超过缓冲区大小，从头部移除一个元素
            if (fenoffset > fenestra.width) {
                fenestraWaveforms[index].shift();
            }

            // 从小波形队列中取出最新数据，准备添加到大波形队列
            const largeWaveformDataPoint = fenestraWaveforms[index][fenestraWaveforms[index].length - 1];
            // 添加新数据点到大波形队列（尾部）
            largeWaveforms[index].push(largeWaveformDataPoint);

            // 如果大波形超过缓冲区大小，从头部移除一个元素
            if (offset > canvas.width) {
                largeWaveforms[index].shift();
            }
        }
    }

    function loadPage(qmlFile) {
        loader.source = "qrc:/qml/components/Layouts/side/FullView2Inside/"+qmlFile
    }
    closePolicy: Popup.NoAutoClose
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
                                    renderTarget: Canvas.FramebufferObject
                                    width: parent.width
                                    height: parent.height
                                    onPaint: {
                                        var ctx = canvas.getContext("2d");
                                        ctx.clearRect(0, 0, canvas.width, canvas.height);
                                        var minValue = -10;
                                        var maxValue = 10;
                                        var offsetY = canvas.height;
                                        var range = maxValue - minValue;
                                        var xScale = 1;  // 控制缩放，可以调整显示多个周期

                                        if (range === 0) {
                                            range = 1;
                                        }

                                        var yScale = canvas.height / range;  // 纵向缩放比例

                                        // 遍历每条波形并绘制
                                        for (var modelIndex = 0; modelIndex < largeWaveforms.length; modelIndex++) {
                                            if (!lineVisibility[modelIndex]) {
                                                continue;  // 如果该曲线不可见，跳过
                                            }
                                            var dataPoints = largeWaveforms[modelIndex];
                                            if (dataPoints.length === 0) {
                                                continue;  // 如果没有数据，跳过
                                            }

                                            ctx.beginPath();
                                            // 从最右侧开始绘制
                                            var startX = canvas.width- offset;  // 计算右侧的起点
                                            ctx.moveTo(startX, offsetY - (dataPoints[0] - minValue) * yScale);
                                            // 向右绘制波形，同时画布左移
                                            for (var i = 1; i < dataPoints.length; i++) {
                                                var x = startX + (i * xScale);
                                                var y = offsetY - (dataPoints[i] - minValue) * yScale;
                                                ctx.lineTo(x, y);
                                                lineY = y;
                                            }

                                            ctx.strokeStyle = "hsl(" + (modelIndex * 60) + ", 100%, 50%)";  // 每条波形不同颜色
                                            ctx.lineWidth = 2;
                                            ctx.stroke();

                                        }
                                        if (offset < canvas.width) {
                                            offset += 1;
                                        }
                                    }
                                }
                                Timer {
                                    id: scrollTimer
                                    interval: 16
                                    running: true
                                    repeat: true
                                    onTriggered: {
                                        fenestra.requestPaint()
                                        canvas.requestPaint()
                                        slash.requestPaint()
                                    }
                                }
                            }
                        }

                        Canvas {
                            width: parent.width / 10
                            height: parent.height
                            id:slash
                            renderTarget: Canvas.FramebufferObject
                            onPaint: {
                                var ctx = slash.getContext('2d');
                                ctx.clearRect(0, 0, slash.width, slash.height); // 清空画布

                                // 绘制背景矩形以调试 Canvas 区域
                                ctx.fillStyle = '#ffffff';
                                ctx.fillRect(0, 0, slash.width, slash.height);
                                // 从左下角绘制到右上角
                                var startX = 0;
                                var startY = lineY;
                                var endX = slash.width;
                                var endY = 0;

                                ctx.beginPath();
                                ctx.moveTo(startX, startY);  // 起点 (左下角)
                                ctx.lineTo(endX, endY);  // 终点 (右上角)
                                ctx.strokeStyle = '#a8bdda';  // 线条颜色
                                ctx.lineWidth = 5;  // 线条宽度
                                ctx.stroke();

                                var startX2 = 0;
                                var startY2 = lineY;  // 使用相同或另一个波形的 y 坐标（根据需求）
                                var endX2 = slash.width;
                                var endY2 = slash.height;

                                ctx.beginPath();
                                ctx.moveTo(startX2, startY2);
                                ctx.lineTo(endX2, endY2);
                                ctx.strokeStyle = '#a8bdda';  // 第二条线的颜色
                                ctx.lineWidth = 5;
                                ctx.stroke();
                            }
                        }
                        Rectangle{
                            anchors.verticalCenter: parent.verticalCenter
                            width: parent.width/6
                            height: parent.height
                            border.color: "#cfcfcf"
                            Canvas {
                                id: fenestra
                                renderTarget: Canvas.FramebufferObject
                                width: parent.width
                                height: parent.height
                                onPaint: {
                                    var ctx = fenestra.getContext("2d");
                                    ctx.clearRect(0, 0, fenestra.width, fenestra.height);

                                    var minValue = -5;
                                    var maxValue = 5;
                                    var offsetY = fenestra.height;
                                    var range = maxValue - minValue;
                                    var xScale = 1;

                                    if (range === 0) {
                                        range = 1;  // 避免除以零
                                    }

                                    var yScale = fenestra.height / range;  // 纵向缩放比例

                                    // 遍历每条波形并绘制
                                    for (var modelIndex = 0; modelIndex < fenestraWaveforms.length; modelIndex++) {
                                        if (!lineVisibility[modelIndex]) {
                                            continue;  // 如果该曲线不可见，跳过
                                        }
                                        var dataPoints = fenestraWaveforms[modelIndex];
                                        if (dataPoints.length === 0) {
                                            continue;  // 如果没有数据，跳过
                                        }

                                        ctx.beginPath();
                                        var startX = fenestra.width;
                                        ctx.moveTo(startX, offsetY - (dataPoints[0] - minValue) * yScale);  // 画起点

                                        for (var i = 1; i < dataPoints.length; i++) {
                                             var x = startX - (i * xScale);// 计算 x 坐标
                                            var y = offsetY - (dataPoints[i] - minValue) * yScale;  // 计算 y 坐标

                                            ctx.lineTo(x, y);
                                        }

                                        // 设置颜色并绘制
                                        ctx.strokeStyle = "hsl(" + (modelIndex * 60) + ", 100%, 50%)";  // 每条波形不同颜色
                                        ctx.lineWidth = 2;
                                        ctx.stroke();
                                    }
                                    if (fenoffset < fenestra.width) {
                                        fenoffset += 1;
                                    }
                                }

                            }
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
