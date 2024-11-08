#include "commandserver.h"
#include "qtcpsocket.h"

CommandServer::CommandServer(QObject *parent)
    : QTcpServer{parent}
{
    if (!this->listen(QHostAddress::Any, 10001)) {
        qCritical() << "Could not start server";
    } else {
        qDebug() << "Server listening on port 10001...";
    }
}

CommandServer::~CommandServer()
{
    for (const auto handler : handlers) {
        delete handler;
    }
    handlers.clear();
}
/**
 * @brief CommandServer::incomingConnection       当有链接时自动调用
 * @param socketDescriptor
 */
void CommandServer::incomingConnection(qintptr socketDescriptor)
{
    DeviceHandler *handler = new DeviceHandler(socketDescriptor);
    QThread *thread = new QThread;
    handler->moveToThread(thread);
    connect(thread, &QThread::started, handler, &DeviceHandler::run);
    connect(thread, &QThread::finished, thread, &QObject::deleteLater);
    thread->start();
    handlers.append(handler);
}
