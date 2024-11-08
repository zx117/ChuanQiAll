#ifndef COMMANDSERVER_H
#define COMMANDSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include "devicehandler.h"
class CommandServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit CommandServer(QObject *parent = nullptr);
    ~CommandServer();
protected:
    QVector<DeviceHandler*> handlers;
    void incomingConnection(qintptr socketDescriptor) override;
private:

signals:
};

#endif // COMMANDSERVER_H
