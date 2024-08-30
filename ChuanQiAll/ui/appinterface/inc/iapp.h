#ifndef IAPP_H
#define IAPP_H

#include <QObject>

#include "appsystemglobal.h"
#include "appsystem.h"
#include "app.h"

class AbstractApp;

QT_BEGIN_NAMESPACE

class APP_LIBRARY_API IApp : public QObject
{
    Q_OBJECT

public:
    explicit IApp(const QString name, QObject *parent = nullptr);
    virtual ~IApp();

    AppSystem::State state() const;

Q_SIGNALS:
    void stateChanged(AppSystem::State state);
    void notify();

private:
    Q_DISABLE_COPY(IApp)

    AbstractApp* d;
};

QT_END_NAMESPACE

#endif // IAPP_H
