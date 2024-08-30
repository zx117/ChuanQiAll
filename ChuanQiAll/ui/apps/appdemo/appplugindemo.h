#ifndef APPPLUGINDEMO_H
#define APPPLUGINDEMO_H

#include "appsystemplugin.h"

class AppPluginDemo : public AppSystemPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "cq.appsystemfactory/1.0" FILE "appdemo.json")
    Q_INTERFACES(AppSystemFactoryInterface)

public:
    explicit AppPluginDemo(QObject *parent = 0);
    virtual ~AppPluginDemo();

    AbstractApp* createApp() override;

};

#endif // APPPLUGINDEMO_H
