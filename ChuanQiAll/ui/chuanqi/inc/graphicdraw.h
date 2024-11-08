#ifndef GRAPHICDRAW_H
#define GRAPHICDRAW_H

#include <QObject>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QVector>
#include <QJsonObject>
#include "qcustomplot.h"
#include <QWidget>
class GraphicDraw : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit GraphicDraw(QObject *parent = nullptr);
    ~GraphicDraw();

    //更新实时数据
    Q_INVOKABLE void updateRealData(double value);
    //绘制数据
    Q_INVOKABLE void DrawHistoryData(QJsonObject data);
    //清除数据
    Q_INVOKABLE void clearData();

private:
    virtual void paint(QPainter *painter);
    QCustomPlot *customPlot;
    double                  maxY;
    QVector<double>         X;
    QVector<double>         Y;
signals:
    void sigIllegalData();
};

#endif // GRAPHICDRAW_H
