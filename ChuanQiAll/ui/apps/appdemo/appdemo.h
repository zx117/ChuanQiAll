#ifndef APPDEMO_H
#define APPDEMO_H

#include <QQmlComponent>
#include <QQuickItem>
#include <QTimer>
#include "appsystem.h"
#include "iapphost.h"
#include <QRandomGenerator>
class AppDemo : public AbstractApp
{
    Q_OBJECT
public:
    explicit AppDemo(QObject *parent = nullptr);
    QString appName() const override;
    QString appVersion() const override;
    QString appRegisterInfo() const override;
    bool isValidApp() const override;
    void setHost(IAppHost* host) override;
    bool postMessage(MessageId msg_id, std::uint64_t key, const QVariant* param, const QVariant** ret = nullptr) override;
    bool addAppUI(QString ui_name, QQmlApplicationEngine* qml_engine, QObject* parent_item) override;
    void closeApp() override;
    //it is a function as demo
    Q_INVOKABLE void doFunction();
public slots:
    void onSwitchGraphics(const QString &path);

private:
    IAppHost*   m_host;
    QString     m_name;
    QString     m_version;
    QString     m_register;
    bool        m_valid;

    QQmlComponent* m_main_component;
    QQmlComponent* m_set_component;
    QQuickItem*    m_item;
signals:
    void data(double num);
    void mainSwitch(QString path);
};

#endif // APPDEMO_H
