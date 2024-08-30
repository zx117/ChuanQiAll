#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include <QtQml>
#include <QQuickWindow>
class Interface : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit Interface(QObject *parent = nullptr);
    Q_INVOKABLE void renderInterface(QString renderingmethod);


signals:
};

#endif // INTERFACE_H
