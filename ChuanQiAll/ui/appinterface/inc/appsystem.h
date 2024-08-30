#ifndef APPSYSTEM_H
#define APPSYSTEM_H

#include <QObject>
#include <QVariant>
#include <QQmlApplicationEngine>

#include "appsystemglobal.h"
#include "app.h"

QT_BEGIN_NAMESPACE

class IAppHost;

class APP_LIBRARY_API AbstractApp : public QObject
{
    Q_OBJECT

public:
    virtual QString appName() const = 0;
    virtual QString appVersion() const = 0;
    virtual QString appRegisterInfo() const = 0;
    virtual bool isValidApp() const = 0;

    virtual void setHost(IAppHost* host) = 0;
    virtual bool postMessage(MessageId msg_id, std::uint64_t key, const QVariant* param, const QVariant** ret = nullptr) = 0;
    virtual bool addAppUI(QString ui_name, QQmlApplicationEngine* qml_engine, QObject* parent_item) = 0;
    virtual void closeApp()=0;
Q_SIGNALS:
    void stateChanged(AppSystem::State state);
    void notify();
};

QT_END_NAMESPACE

#endif // APPSYSTEM_H
