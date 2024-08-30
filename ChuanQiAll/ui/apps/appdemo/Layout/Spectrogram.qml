import QtQuick 2.15
import QtCharts 2.3
import Qt.labs.settings 1.0
import Themes 1.0
import Widgets 1.0
Item {
    property string setpath: "./appdemoset/Setting.ini"
    Component.onCompleted: {
        if(setting.harmonic==="")
        {
            setting.harmonic=true
        }
        if(setting.interharmonic==="")
        {
            setting.interharmonic=false
        }
        if(setting.frequency==="")
        {
            setting.frequency=25
        }
        if(setting.yaxis==="")
        {
            setting.yaxis="Pecent"
        }
    }
    Settings {
        id:setting
        fileName:  setpath
        property bool harmonic:true
        property bool interharmonic:false
        property int  frequency: 25
        property string yaxis: "Pecent"
    }
    // Timer {
    //     id: timer
    //     interval: 1000 // 每秒触发一次定时器
    //     running: true // 启动定时器
    //     repeat: true // 重复执行定时器
    //     onTriggered: {
    //         setting.sync()
    //         console.log(setting.frequency)
    //     }
    // }
    anchors.fill: parent
    ChartView
    {
        id:barview
        property int count: setting.frequency
        anchors.fill: parent
        titleColor: "black"
        titleFont.bold: true
        legend.alignment: Qt.AlignBottom
        antialiasing: true   //反锯齿
        backgroundColor: "transparent"
        animationOptions: ChartView.NoAnimation

        //设置坐标轴
        BarCategoryAxis
        {
            id: axisX
            categories: generateCategories(barview.count)
            labelsVisible: true
        }

        ValueAxis
        {
            id: axisY
            min: 0
            max: 100
            labelsColor:"#111111"
            tickCount: 5
            labelsVisible: true
            titleText : "差值"
        }

        legend {
            enabled: true
            x: (barview.width - legend.width) / 2 // 水平居中
            y: 0 // y轴的顶部
        }
        // 柱形系列
        BarSeries
        {
            id: barSeries
            barWidth:0.5
            axisX: axisX
            axisY: axisY

            BarSet {
                label: "目前"
                color: "orange"
                values: generateCategories1(barview.count)
            }
        }
    }

    function generateCategories(count) {
        var result = [];

        for (var j = 1; j <= count; ++j) {
            result.push(j);
        }

        return result
    }
    function generateCategories1(count) {
        var result = [];
        for (var j = 1; j <= count; ++j) {
            result.push(j);
        }

        return result
    }
    function getGenerateCategoriesNum(num)
    {
        barview.count=num
        axisX.categories=generateCategories(num)
    }

}
