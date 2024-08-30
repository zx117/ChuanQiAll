import QtQuick 2.15
import QtCharts 2.3
import Themes 1.0
import Widgets 1.0

Item {
    anchors.fill: parent
    ChartView {
        id: chartView
        anchors.fill: parent
        antialiasing: true
        legend.visible: false

        // 缩放步进
        property int zoomStep: 1
        property int tmpYPosition: 0
        // 控制X轴时间模式
        property bool isRealTimeMode: true

        property bool enableDrag: false
        property bool enableZoom: false
        // 实时时间属性，单位：秒
        property int readDataMin: 0
        property int readDataMax: 10

        function appendPoint(x, y) {
            lineSeries.append(x, y);
        }

        ValueAxis {
            id: axisX
            min: chartView.readDataMin
            max: chartView.readDataMax
        }

        ValueAxis {
            id: axisY
            min: 0
            max: 100
        }

        LineSeries {
            id: lineSeries
            useOpenGL: true
            axisX: axisX
            axisY: axisY
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: enabled
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            cursorShape: (chartView.enableDrag ? Qt.OpenHandCursor : Qt.ArrowCursor)

            onPressed: {
                if (mouse.button === Qt.LeftButton) {
                    chartView.enableZoom = false;
                    chartView.enableDrag = true;
                    chartView.tmpYPosition = mouseY;
                }
                var app=AppHost.thisApp("appdemo")
                app.doFunction()
            }

            onReleased: {
                if (mouse.button === Qt.LeftButton) {
                    chartView.enableZoom = true;
                    chartView.enableDrag = false;
                }
            }

            onPositionChanged: {
                if (chartView.enableDrag) {
                    var moveY = mouseY - chartView.tmpYPosition;

                    if (moveY > 0) {
                        chartView.moveUp(Math.abs(moveY));
                    } else {
                        chartView.moveDown(Math.abs(moveY));
                    }

                    chartView.tmpYPosition = mouseY;
                }
            }

            onWheel: {
                if (chartView.enableZoom) {
                    var hoveredPoint = chartView.mapToValue(Qt.point(mouseX, mouseY), lineSeries);
                    if (hoveredPoint.x > axisX.min && hoveredPoint.x < axisX.max) {
                        if (wheel.angleDelta.y > 0) {
                            chartView.zoomIn(hoveredPoint);
                        } else {
                            chartView.zoomOut(hoveredPoint);
                        }
                    }
                }
            }
        }

        function zoomIn(hoveredPoint) {
            let minTime = axisX.min;
            let maxTime = axisX.max;
            let zoomStepSecs = zoomStep;

            if ((hoveredPoint.x - minTime) <= zoomStepSecs) {
                return;
            }

            let scaleX = (hoveredPoint.x - minTime) / (maxTime - minTime);
            minTime += zoomStepSecs;
            maxTime = (hoveredPoint.x - minTime) / scaleX + minTime;

            axisX.min = minTime;
            axisX.max = maxTime;
        }

        function zoomOut(hoveredPoint) {
            let minTime = axisX.min;
            let maxTime = axisX.max;
            let zoomStepSecs = zoomStep;

            let scaleX = (hoveredPoint.x - minTime) / (maxTime - minTime);
            minTime -= zoomStepSecs;
            maxTime = (hoveredPoint.x - minTime) / scaleX + minTime;

            axisX.min = minTime;
            axisX.max = maxTime;
        }

        function zoomReset() {
            if (isRealTimeMode) {
                axisX.min = chartView.realTimeMin;
                axisX.max = chartView.realTimeMax;
            } else {
                axisX.min = chartView.readTimeMin;
                axisX.max = chartView.readTimeMax;
            }
        }

        function moveUp(pixels) {
            axisY.min -= pixels;
            axisY.max -= pixels;
        }

        function moveDown(pixels) {
            axisY.min += pixels;
            axisY.max += pixels;
        }
    }
}
