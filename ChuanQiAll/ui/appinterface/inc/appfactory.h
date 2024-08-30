#ifndef APPFACTORY_H
#define APPFACTORY_H

#include <QObject>
#include <QString>
#include <QStringList>

#include "appsystemglobal.h"

QT_BEGIN_NAMESPACE

class AbstractApp;
class IAppHost;

class APP_LIBRARY_API AppFactory
{
public:
    static QStringList  validAppNames();
    static AbstractApp* createApp(QString name);
};

QT_END_NAMESPACE

#endif // APPFACTORY_H
