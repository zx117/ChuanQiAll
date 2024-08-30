#include "appplugindemo.h"
#include "appsystem.h"

#include "appdemo.h"

AppPluginDemo::AppPluginDemo(QObject *parent)
{

}


AppPluginDemo::~AppPluginDemo()
{

}

AbstractApp* AppPluginDemo::createApp()
{
    return new AppDemo();
}
