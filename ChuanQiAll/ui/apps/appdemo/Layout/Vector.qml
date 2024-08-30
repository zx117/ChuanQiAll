import QtQuick 2.15
import Themes 1.0
import Widgets 1.0
Item {

    Row
    {
        anchors.fill: parent
        spacing: 10
        Canvas {
            id: canvas
            width:parent.width/2-20
            height: parent.height*2/3
            anchors.verticalCenter: parent.verticalCenter
            onPaint: {
                var ctx = canvas.getContext("2d");
                var centerX = canvas.width / 2;
                var centerY = canvas.height / 2;
                var outerRadius = Math.min(canvas.width, canvas.height) / 2 - 20;
                var numRings = 5;
                var numTicks = 12;
                var angleStep = 2 * Math.PI / numTicks; // 每30度一个刻度

                // 清除画布
                ctx.clearRect(0, 0, canvas.width, canvas.height);

                // 绘制同心圆（实线）

                for (var i = 1; i <= numRings; ++i) {
                    var radius = outerRadius * i / numRings;
                    ctx.beginPath();
                    ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI);
                    ctx.strokeStyle = "#0000FF"; // 蓝色
                    ctx.lineWidth = 1;
                    ctx.stroke();
                }

                // 绘制最外层的圆（实线）
                ctx.beginPath();
                ctx.arc(centerX, centerY, outerRadius, 0, 2 * Math.PI);
                ctx.strokeStyle = "#0000FF"; // 蓝色
                ctx.lineWidth = 1;
                ctx.stroke();

                // 绘制刻度线和刻度标签
                for (var i = 0; i < numTicks; ++i) {
                    var angle = i * angleStep - Math.PI / 2;
                    var outerX = centerX + outerRadius * Math.cos(angle);
                    var outerY = centerY + outerRadius * Math.sin(angle);

                    // 绘制刻度线（实线）
                    ctx.beginPath();
                    ctx.moveTo(centerX, centerY);
                    ctx.lineTo(outerX, outerY);
                    ctx.strokeStyle = "#000000"; // 黑色
                    ctx.lineWidth = 1;
                    ctx.stroke();

                    // 绘制刻度标签
                    var textX = centerX + (outerRadius + 15) * Math.cos(angle);
                    var textY = centerY + (outerRadius + 15) * Math.sin(angle);
                    var degree = i * 360 / numTicks;
                    ctx.fillStyle = "#000000"; // 黑色
                    ctx.font = "14px Arial";
                    ctx.textAlign = "center";
                    ctx.textBaseline = "middle";
                    ctx.fillText(degree + "°", textX, textY);
                }
                var phases = 3;
                var phaseAngleStep = 2 * Math.PI / phases; // 每120度一个相位

                for (var i = 0; i < phases; ++i) {
                    var angle = i * phaseAngleStep - Math.PI / 2; // 使第一相位于顶部
                    var x = centerX + outerRadius * Math.cos(angle);
                    var y = centerY + outerRadius * Math.sin(angle);

                    // 绘制矢量线
                    ctx.setLineDash([]); // 确保矢量线为实线
                    ctx.beginPath();
                    ctx.moveTo(centerX, centerY);
                    ctx.lineTo(x, y);
                    ctx.strokeStyle = i == 0 ? "red" : i == 1 ? "green" : "blue"; // 三相电压颜色
                    ctx.lineWidth = 2;
                    ctx.stroke();

                    // 绘制箭头
                    ctx.beginPath();
                    ctx.moveTo(x, y);
                    ctx.lineTo(x - 10 * Math.cos(angle - Math.PI / 6), y - 10 * Math.sin(angle - Math.PI / 6));
                    ctx.lineTo(x - 10 * Math.cos(angle + Math.PI / 6), y - 10 * Math.sin(angle + Math.PI / 6));
                    ctx.lineTo(x, y);
                    ctx.fillStyle = i == 0 ? "red" : i == 1 ? "green" : "blue"; // 三相电压颜色
                    ctx.fill();

                    // 绘制相位标签
                    var phaseTextX = centerX + (outerRadius + 30) * Math.cos(angle);
                    var phaseTextY = centerY + (outerRadius + 30) * Math.sin(angle);
                    ctx.fillStyle = "#000000"; // 黑色
                    ctx.font = "14px Arial";
                    ctx.textAlign = "center";
                    ctx.textBaseline = "middle";
                    ctx.fillText("Phase " + (i + 1), phaseTextX, phaseTextY);
                }

            }

            Component.onCompleted: canvas.requestPaint();
        }

        Canvas {
            id: canvas2
            width:parent.width/2-20
            height: parent.height*2/3
            anchors.verticalCenter: parent.verticalCenter
            onPaint: {
                var ctx = canvas2.getContext("2d");
                var centerX = canvas2.width / 2;
                var centerY = canvas2.height / 2;
                var outerRadius = Math.min(canvas2.width, canvas2.height) / 2 - 20;
                var numRings = 5;
                var numTicks = 12;
                var angleStep = 2 * Math.PI / numTicks; // 每30度一个刻度

                // 清除画布
                ctx.clearRect(0, 0, canvas2.width, canvas2.height);

                // 绘制同心圆（实线）

                for (var i = 1; i <= numRings; ++i) {
                    var radius = outerRadius * i / numRings;
                    ctx.beginPath();
                    ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI);
                    ctx.strokeStyle = "#0000FF"; // 蓝色
                    ctx.lineWidth = 1;
                    ctx.stroke();
                }

                // 绘制最外层的圆（实线）
                ctx.beginPath();
                ctx.arc(centerX, centerY, outerRadius, 0, 2 * Math.PI);
                ctx.strokeStyle = "#0000FF"; // 蓝色
                ctx.lineWidth = 1;
                ctx.stroke();

                // 绘制刻度线和刻度标签
                for (var i = 0; i < numTicks; ++i) {
                    var angle = i * angleStep - Math.PI / 2;
                    var outerX = centerX + outerRadius * Math.cos(angle);
                    var outerY = centerY + outerRadius * Math.sin(angle);

                    // 绘制刻度线（实线）
                    ctx.beginPath();
                    ctx.moveTo(centerX, centerY);
                    ctx.lineTo(outerX, outerY);
                    ctx.strokeStyle = "#000000"; // 黑色
                    ctx.lineWidth = 1;
                    ctx.stroke();

                    // 绘制刻度标签
                    var textX = centerX + (outerRadius + 15) * Math.cos(angle);
                    var textY = centerY + (outerRadius + 15) * Math.sin(angle);
                    var degree = i * 360 / numTicks;
                    ctx.fillStyle = "#000000"; // 黑色
                    ctx.font = "14px Arial";
                    ctx.textAlign = "center";
                    ctx.textBaseline = "middle";
                    ctx.fillText(degree + "°", textX, textY);
                }
                var phases = 3;
                var phaseAngleStep = 2 * Math.PI / phases; // 每120度一个相位

                for (var i = 0; i < phases; ++i) {
                    var angle = i * phaseAngleStep - Math.PI / 2; // 使第一相位于顶部
                    var x = centerX + outerRadius * Math.cos(angle);
                    var y = centerY + outerRadius * Math.sin(angle);

                    // 绘制矢量线
                    ctx.setLineDash([]); // 确保矢量线为实线
                    ctx.beginPath();
                    ctx.moveTo(centerX, centerY);
                    ctx.lineTo(x, y);
                    ctx.strokeStyle = i == 0 ? "red" : i == 1 ? "green" : "blue"; // 三相电压颜色
                    ctx.lineWidth = 2;
                    ctx.stroke();

                    // 绘制箭头
                    ctx.beginPath();
                    ctx.moveTo(x, y);
                    ctx.lineTo(x - 10 * Math.cos(angle - Math.PI / 6), y - 10 * Math.sin(angle - Math.PI / 6));
                    ctx.lineTo(x - 10 * Math.cos(angle + Math.PI / 6), y - 10 * Math.sin(angle + Math.PI / 6));
                    ctx.lineTo(x, y);
                    ctx.fillStyle = i == 0 ? "red" : i == 1 ? "green" : "blue"; // 三相电压颜色
                    ctx.fill();

                    // 绘制相位标签
                    var phaseTextX = centerX + (outerRadius + 30) * Math.cos(angle);
                    var phaseTextY = centerY + (outerRadius + 30) * Math.sin(angle);
                    ctx.fillStyle = "#000000"; // 黑色
                    ctx.font = "14px Arial";
                    ctx.textAlign = "center";
                    ctx.textBaseline = "middle";
                   // ctx.fillText("Phase " + (i + 1), phaseTextX, phaseTextY);
                }

            }

            Component.onCompleted: canvas2.requestPaint();
        }

    }
}
