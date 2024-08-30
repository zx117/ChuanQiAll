#ifndef APPHOST_H
#define APPHOST_H

#include <QQmlApplicationEngine>
#include <QObject>
#include <QList>

#include "iapphost.h"

class IAppHost;
class AbstractApp;
class AppHost : public QObject, public IAppHost
{
    Q_OBJECT

    Q_PROPERTY(int appCounts READ appCounts NOTIFY appCountsChanged FINAL)

public:
    //it is a function as demo
    Q_INVOKABLE AbstractApp* thisApp(QString name);
    Q_INVOKABLE void loadApp(QVariant app_index, QObject* item, QString ui_name="",QVariant param=QVariant());
    Q_INVOKABLE void closeApp(QVariant app_index, QObject *item, QVariant param=QVariant());
    Q_INVOKABLE QUrl appImage(int i);
    Q_INVOKABLE QString returnAppName(QVariant app_index);
    Q_INVOKABLE QString returnAppVersion(QVariant app_index);
    Q_INVOKABLE QString returnAppRegisterInfo(QVariant app_index);
    Q_INVOKABLE bool returnIsValidApp(QVariant app_index);


public:
    AppHost();

    void init(QQmlApplicationEngine *qml_engine);

    std::uint64_t messageSync(MessageId msg_id, std::uint64_t key, const QVariant* param, const QVariant** ret = nullptr) override;

    std::uint64_t messageSyncData(MessageId msg_id, std::uint64_t key, const void* param, std::uint64_t param_size, const QVariant** ret = nullptr) override;

    std::uint64_t messageAsync(MessageId msg_id, std::uint64_t key, const QVariant* param) override;

    const QVariant* query(const char* context, const char* item, const QVariant* param) override;

    const QVariant* queryXML(const char* context, const char* item, const char* xml, std::uint64_t xml_size) override;

signals:
    void appCountsChanged(int cnt);

private:
    int appCounts() const;

private:
    QList<AppSystem::AppRegisterInfo> m_app_infos;    
    QHash<QString, AbstractApp*>      m_apps;

    QQmlApplicationEngine   *m_qml_engine;
};

#endif // APPHOST_H
