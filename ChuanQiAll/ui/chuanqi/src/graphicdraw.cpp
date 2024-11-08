#include "graphicdraw.h"
#include "qobjectdefs.h"

GraphicDraw::GraphicDraw(QObject *parent)
{
    customPlot=new QCustomPlot;
    customPlot->rescaleAxes(true);
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(14);
    font.setBold(false);
    customPlot->xAxis->setLabelColor(QColor(Qt::black));//轴标体色
    customPlot->yAxis->setLabelColor(QColor(Qt::black));
    customPlot->xAxis->setBasePen(QPen(QColor(Qt::black), 2));//轴色
    customPlot->yAxis->setBasePen(QPen(QColor(Qt::black), 2));
    customPlot->xAxis->setTickPen(QPen(QColor(Qt::black), 2));//轴主标色
    customPlot->yAxis->setTickPen(QPen(QColor(Qt::black), 2));
    customPlot->xAxis->setSubTickPen(QPen(QColor(Qt::black), 2));//轴次标色
    customPlot->yAxis->setSubTickPen(QPen(QColor(Qt::black), 2));
    customPlot->xAxis->setTickLabelFont(font);
    customPlot->yAxis->setTickLabelFont(font);
    customPlot->xAxis->setTickLabelColor(QColor(Qt::black));//轴标文本色
    customPlot->yAxis->setTickLabelColor(QColor(Qt::black));
    customPlot->setBackground(QBrush(QColor(Qt::white)));
    customPlot->setGeometry(0, 0, width(), height());
    customPlot->setMultiSelectModifier(Qt::KeyboardModifier::ControlModifier);
    //设置边距
    QCPMarginGroup *marginGroup = new QCPMarginGroup(customPlot);
    customPlot->plotLayout()->setMargins(QMargins(40, 20, 20, 40));
    customPlot->axisRect()->setMarginGroup(QCP::msLeft | QCP::msRight | QCP::msTop | QCP::msBottom, marginGroup);
    customPlot->setAntialiasedElements(QCP::aeAll);
    //设置时间轴
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setTickCount(5);
    dateTicker->setDateTimeFormat("hh:mm:ss");  // 24小时制
    dateTicker->setDateTimeSpec(Qt::LocalTime);  // 使用本地时间，避免时区问题
    customPlot->xAxis->setTicker(dateTicker);

    // 获取当前时间，并将时间戳转为秒
    QDateTime current = QDateTime::currentDateTime();
    qint64 currentSecs = current.toSecsSinceEpoch();  // 转换为秒
    // 设置 X 轴的范围为当前时间至未来 60 秒
    customPlot->xAxis->setRange(currentSecs, currentSecs + 60);

    //纵轴
    QSharedPointer<QCPAxisTicker> ticker(new QCPAxisTicker);
    ticker->setTickCount(5);
    customPlot->yAxis->setTicker(ticker);
    customPlot->yAxis->setRange(0, 200);
    //添加数据曲线图形
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue,1));
}

GraphicDraw::~GraphicDraw()
{
    customPlot->deleteLater();
    customPlot = nullptr;
}
/**
 * @brief GraphicDraw::updateRealData
 * @param value
 */
void GraphicDraw::updateRealData(double value)
{
    // 获取当前的毫秒级时间戳
    qint64 currentMillis = QDateTime::currentMSecsSinceEpoch();

    // 设置初始 X 轴范围，保持 60 秒显示范围（转换为毫秒）
    if (X.size() == 0) {
        customPlot->xAxis->setRange(currentMillis, currentMillis + 60);
    }

    // 防止重复添加相同时间点的数据（基于毫秒级时间戳）
    if (X.size() > 0 && X.last() == currentMillis) return;

    // 保持数据点限制为 60 秒内的数据
    while (X.size() >= 60) {
        X.takeFirst();
        Y.takeFirst();
    }

    // 添加新数据
    X.push_back(currentMillis);
    Y.push_back(value);

    // 更新 Y 轴范围
    if (maxY < value) {
        maxY = value;
        maxY = (maxY / 10 + 1) * 10; // 向上取整
        customPlot->yAxis->setRange(-10, 10);
    }

    // 如果当前时间已经超过 X 轴右边界，滚动 X 轴
    if (currentMillis > customPlot->xAxis->range().upper) {
        // 向右滚动 X 轴，保持 60 秒的范围
        customPlot->xAxis->setRange(currentMillis - 60, currentMillis);
    }

    // 更新数据并重新绘制
    customPlot->graph(0)->setData(X, Y);
    customPlot->replot(); // 立即重绘
    update(); // 刷新显示
}

/**
 * @brief GraphicDraw::DrawHistoryData
 * @param data
 */
void GraphicDraw::DrawHistoryData(QJsonObject data)
{
    QString maxLiquidLevelHeight = data["maxLiquidLevelHeight"].toString();
    QString times = data["time"].toString();
    maxLiquidLevelHeight.remove('\n');
    times.remove('\n');
    QStringList heightList = maxLiquidLevelHeight.split(",", QString::SkipEmptyParts);
    QStringList timeList = times.split(",", QString::SkipEmptyParts);
    if (heightList.count() != timeList.count()) {
        return;
    }
    for (int i = 0; i < heightList.count(); i++) {
        QDateTime time = QDateTime::fromString(timeList[i], "yyyy-MM-dd HH:mm:ss");
        if(!time.isValid()) {//存在非法数据
            emit sigIllegalData();
            return;
        }
        uint value = heightList[i].toInt();
        X.append(time.toTime_t());
        Y.append(value);
        if(maxY < value) {//更新最大值
            maxY = value;
            maxY = (maxY / 10 + 1) * 10;
            customPlot->yAxis->setRange(0, maxY);
        }
    }
    customPlot->xAxis->setRange(X.first(), X.last());
    customPlot->graph(0)->setData(X, Y);
    customPlot->replot();//刷新曲线
    update();//刷新显示

}
/**
 * @brief GraphicDraw::clearData
 */
void GraphicDraw::clearData()
{
    maxY = 200;
    X.clear();
    Y.clear();
    customPlot->graph(0)->setData(X, Y);
    customPlot->replot();//刷新曲线
    update();//刷新显示
}
/**
 * @brief GraphicDraw::paint
 * @param painter
 */
void GraphicDraw::paint(QPainter *painter)
{
    customPlot->setGeometry(0,0,this->width()*1.6,this->height()*1.6);
    painter->drawPixmap(0,0,this->width(),this->height(), customPlot->toPixmap());

}


