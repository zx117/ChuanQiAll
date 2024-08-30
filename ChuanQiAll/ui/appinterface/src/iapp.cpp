
#include "app.h"
#include "iapp.h"
#include "appfactory.h"

QT_BEGIN_NAMESPACE
/*!
    Construct a new app and attach it to \a parent.
*/

IApp::IApp(const QString name, QObject *parent):
    QObject(parent)
{
    d = AppFactory::createApp(name);
    connect(d, SIGNAL(notify()), SIGNAL(notify()));
    connect(d, SIGNAL(stateChanged(AppSystem::State)), SIGNAL(stateChanged(AppSystem::State)));
}

/*!
    Destroy this audio input.
*/

IApp::~IApp()
{
    disconnect(d, 0, 0, 0);
    d->deleteLater();
}

QT_END_NAMESPACE

//#include "moc_iapp.cpp"

