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
        property int tmpXPosition: 0
        property int tmpYPosition: 0
        // 控制X轴时间模式
        property bool isRealTimeMode: true

        property bool enableDrag: false
        property bool enableZoom: false
        // 实时时间属性
        property var readDataMin: new Date("2024-04-29 14:41:42.479")
        property var readDataMax: new Date("2024-04-29 15:41:42.479")

        function appendPoint(x, y) {
            lineSeries.append(x, y);
        }

        DateTimeAxis {
            id: axisX
            format: "yyyy-MM-dd HH:mm:ss.zzz"
            min: chartView.isRealTimeMode ? new Date().toISOString() : readDataMin.toISOString()
            max: chartView.isRealTimeMode ? (new Date(new Date().getTime() + 86400000)).toISOString() : readDataMax.toISOString()
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
                let minTime = new Date(axisX.min).getTime();
                let maxTime = new Date(axisX.max).getTime();
                let zoomStepMillis = zoomStep * 1000;

                if ((hoveredPoint.x - minTime) <= zoomStepMillis) {
                    return;
                }

                let scaleX = (hoveredPoint.x - minTime) / (maxTime - minTime);
                minTime += zoomStepMillis;
                maxTime = (hoveredPoint.x - minTime) / scaleX + minTime;

                axisX.min = new Date(minTime).toISOString();
                axisX.max = new Date(maxTime).toISOString();
            }

            function zoomOut(hoveredPoint) {
                let minTime = new Date(axisX.min).getTime();
                let maxTime = new Date(axisX.max).getTime();
                let zoomStepMillis = zoomStep * 1000;

                let scaleX = (hoveredPoint.x - minTime) / (maxTime - minTime);
                minTime -= zoomStepMillis;
                maxTime = (hoveredPoint.x - minTime) / scaleX + minTime;

                axisX.min = new Date(minTime).toISOString();
                axisX.max = new Date(maxTime).toISOString();
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

            axisY.min -= pixels
            axisY.max -= pixels
        }

        function moveDown(pixels) {

            axisY.min += pixels
            axisY.max += pixels
        }
    }
}
