#include "appfactory.h"
#include "apploader.h"
#include "appsystem.h"
#include "appsystemplugin.h"


#if !defined (QT_NO_LIBRARY) && !defined(QT_NO_SETTINGS)
Q_GLOBAL_STATIC_WITH_ARGS(AppLoader, appLoader,
                          (AppSystemFactoryInterface_iid, QLatin1String("apps")))
#endif

class QNullApp : public AbstractApp
{
public:
    QString appName() const override {return "Null";}
    QString appVersion() const override {return "";}
    QString appRegisterInfo() const override {return "";}
    bool isValidApp() const override {return false;}
    void setHost(IAppHost* host) override {Q_UNUSED(host);}
    bool postMessage(MessageId msg_id, std::uint64_t key, const QVariant* param, const QVariant** ret = nullptr) override {return false;}
    bool addAppUI(QString ui_name, QQmlApplicationEngine* qml_engine, QObject* parent_item) override {return false;}
    void closeApp()override {}
};

QStringList  AppFactory::validAppNames()
{
    return appLoader()->keys();
}

AbstractApp* AppFactory::createApp(QString name)
{
    if (name.isNull() || name.isEmpty())
        return new QNullApp();

#if !defined (QT_NO_LIBRARY) && !defined(QT_NO_SETTINGS)
    AppSystemFactoryInterface* plugin =
        qobject_cast<AppSystemFactoryInterface*>(appLoader()->instance(name));

    if (plugin) {
        AbstractApp* app = plugin->createApp();
        return app;
    }
#endif

    return new QNullApp();
}
