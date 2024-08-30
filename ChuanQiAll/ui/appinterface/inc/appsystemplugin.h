#ifndef APPSYSTEMPLUGIN_H
#define APPSYSTEMPLUGIN_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QPlugin.h>

#include "app.h"
#include "iapp.h"

QT_BEGIN_NAMESPACE

class IAppHost;

class AppSystemFactoryInterface
{
    /**
 * Interface that has to be implemented by all apps.
 */
public:
    /**
     * Create the plugin app.
     */
    virtual AbstractApp* createApp() = 0;

    ~AppSystemFactoryInterface() = default; // no virtual destructor to keep the vtable clean
};


#define AppSystemFactoryInterface_iid "cq.appsystemfactory/1.0"
Q_DECLARE_INTERFACE(AppSystemFactoryInterface, AppSystemFactoryInterface_iid)

class AppSystemPlugin : public QObject, public AppSystemFactoryInterface
{
    Q_OBJECT
    Q_INTERFACES(AppSystemFactoryInterface)

public:
    explicit AppSystemPlugin(QObject *parent = nullptr);
    ~AppSystemPlugin();
};


QT_END_NAMESPACE

#endif // AISYSTEMPLUGIN_H
