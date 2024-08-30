#ifndef APP_H
#define APP_H

#include <QObject>
#include <QString>
#include <QImage>

#include "appsystemglobal.h"

QT_BEGIN_NAMESPACE

typedef std::uint64_t MessageId;

namespace AppSystem
{
    enum State {INIT, READY, ACTIVED, EXCEPTION};
    enum AppMessage {
        APP_NONE = 0,
        APP_INIT = 1,
        APP_DEINIT = 2,

    };
    enum HostMessage {
        APP_REGISTER = 1,
    };

    struct AppRegisterInfo {
        QString app_name;
        QString app_version;
        QString app_license;
        QImage  app_desktop;
    };
}

#ifndef QT_NO_DEBUG_STREAM
APP_LIBRARY_API QDebug operator<<(QDebug dbg, AppSystem::State state);
#endif

QT_END_NAMESPACE

Q_DECLARE_METATYPE(AppSystem::State)
Q_DECLARE_METATYPE(AppSystem::AppMessage)
Q_DECLARE_METATYPE(AppSystem::HostMessage)
Q_DECLARE_METATYPE(AppSystem::AppRegisterInfo)

#endif // APP_H
