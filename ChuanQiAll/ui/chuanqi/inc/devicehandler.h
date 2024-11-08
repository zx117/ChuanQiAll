#ifndef DEVICEHANDLER_H
#define DEVICEHANDLER_H

#include <QThread>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QRunnable>
#include <QMap>
#include "command.h"
class DeviceHandler : public QThread
{
    Q_OBJECT
public:
    explicit DeviceHandler(qintptr socketDescriptor,QObject *parent = nullptr);
    ~DeviceHandler();
    void run() override;
private:
    qintptr socketDescriptor;
    void processReceivedData(QTcpSocket *socket, Command *cmd);
signals:
};

#endif // DEVICEHANDLER_H
