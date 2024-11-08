#include "appplugindemo.h"
#include "appsystem.h"

#include "fastfrequency.h"

AppPluginDemo::AppPluginDemo(QObject *parent)
{

}


AppPluginDemo::~AppPluginDemo()
{

}

AbstractApp* AppPluginDemo::createApp()
{
    return new FastFrequency();
}
