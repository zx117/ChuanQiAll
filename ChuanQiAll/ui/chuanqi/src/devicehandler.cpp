#include "devicehandler.h"
#include "qtcpsocket.h"
#include <QEventLoop>
DeviceHandler::DeviceHandler(qintptr socketDescriptor, QObject *parent)
   :socketDescriptor(socketDescriptor)
{
}

DeviceHandler::~DeviceHandler()
{

}

void DeviceHandler::run()
{
    QTcpSocket *socket = new QTcpSocket();
    // 设置 socket 的 socketDescriptor
    if (!socket->setSocketDescriptor(socketDescriptor)) {
        qDebug() << "Failed to set socket descriptor";
        socket->deleteLater();
        return;
    }
    else {
        qDebug() << "Socket connected with descriptor:" << socketDescriptor;
    }
    Command *cmd=new Command();
    connect(socket, &QTcpSocket::readyRead, [socket, cmd, this]() {
        processReceivedData(socket, cmd);
    });
    connect(socket, &QTcpSocket::disconnected, [socket]() {
        socket->deleteLater();
    });
    exec();
}
/**
 * @brief DeviceHandler::processReceivedData     接收数据后处理
 * @param data
 */
void DeviceHandler::processReceivedData(QTcpSocket *socket, Command *cmd)
{
    if (socket) {
        QByteArray data = socket->readAll();
        QString commandLine = QString::fromUtf8(data).trimmed();

        QStringList parts = commandLine.split(' ');
        if (parts.isEmpty()) {
            qDebug() << "未接收到有效命令。";
            return;
        }

        QString command = parts.at(0);
        QStringList params = parts.mid(1);
        cmd->getCommand(command);
        QString response = cmd->execute(params);
        if(!response.isEmpty())
        {
            QByteArray cmdData = response.toUtf8();
            socket->write(cmdData);
            socket->flush();
        }
    }
}

