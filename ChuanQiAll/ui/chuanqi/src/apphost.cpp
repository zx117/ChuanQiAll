#include <QVariant>
#include <QDebug>
#include <QBuffer>
#include "appsystem.h"
#include "appfactory.h"

#include "apphost.h"
#include "app.h"


AppHost::AppHost()
{

}

void AppHost::init(QQmlApplicationEngine *qml_engine)
{
    m_qml_engine = qml_engine;

    QStringList app_names = AppFactory::validAppNames();
    foreach(auto an, app_names)
    {
        AbstractApp* app = AppFactory::createApp(an);
        app->setHost(this);
        app->postMessage(AppSystem::APP_INIT,0,nullptr);
        m_apps[an] = app;

    }
}

AbstractApp* AppHost::thisApp(QString name)
{
    return m_apps[name];
}

void AppHost::loadApp(QVariant app_index, QObject* item, QString ui_name ,QVariant param)
{
    QString name = m_app_infos.at(app_index.toInt()).app_name;
    auto app = m_apps[name];
    if(ui_name=="Main")
    {
        app->addAppUI(ui_name, m_qml_engine, item);
    }
    else if(ui_name=="Setting")
    {
        app->addAppUI(ui_name, m_qml_engine, item);
    }
    else if(ui_name=="AppSet")
    {
        app->addAppUI(ui_name, m_qml_engine, item);
    }

}

void AppHost::closeApp(QVariant app_index, QObject *item, QVariant param)
{
    qDebug() <<Q_FUNC_INFO;
    QString name = m_app_infos.at(app_index.toInt()).app_name;
    auto app = m_apps[name];
    app->closeApp();
}

QUrl AppHost::appImage(int i)
{
    QImage image = m_app_infos.at(i).app_desktop;
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "png");
    QString base64 = QString::fromUtf8(byteArray.toBase64());
    return  QString("data:image/png;base64,") + base64;
}

QString AppHost::returnAppName(QVariant app_index)
{
    QString name = m_app_infos.at(app_index.toInt()).app_name;
    auto app = m_apps[name];
    QString appname=app->appName();
    return appname;
}

QString AppHost::returnAppVersion(QVariant app_index)
{
    QString name = m_app_infos.at(app_index.toInt()).app_name;
    auto app = m_apps[name];
    QString appVersion= app->appVersion();
    return appVersion;
}

QString AppHost::returnAppRegisterInfo(QVariant app_index)
{
    QString name = m_app_infos.at(app_index.toInt()).app_name;
    auto app = m_apps[name];
    QString appRegisterInfo=app->appRegisterInfo();
    return appRegisterInfo;
}

bool AppHost::returnIsValidApp(QVariant app_index)
{
    QString name = m_app_infos.at(app_index.toInt()).app_name;
    auto app = m_apps[name];
    bool isValidApp=app->isValidApp();
    return isValidApp;
}

std::uint64_t AppHost::messageSync(MessageId msg_id, std::uint64_t key, const QVariant* param, const QVariant** ret)
{
    switch (msg_id) {
    case AppSystem::APP_REGISTER:
    {
        AppSystem::AppRegisterInfo info = param->value<AppSystem::AppRegisterInfo>();
        m_app_infos.append( info );

        emit appCountsChanged( m_app_infos.count() );
        break;
    }
    default:
        break;
    }
    return 1;
}

std::uint64_t AppHost::messageSyncData(MessageId msg_id, std::uint64_t key, const void* param, std::uint64_t param_size, const QVariant** ret)
{
    return 0;
}

std::uint64_t AppHost::messageAsync(MessageId msg_id, std::uint64_t key, const QVariant* param)
{
    return 0;
}

const QVariant* AppHost::query(const char* context, const char* item, const QVariant* param)
{
    return 0;
}

const QVariant* AppHost::queryXML(const char* context, const char* item, const char* xml, std::uint64_t xml_size)
{
    return 0;
}

int AppHost::appCounts() const
{
    qDebug() << Q_FUNC_INFO << m_app_infos.count();
    return m_app_infos.count();
}
