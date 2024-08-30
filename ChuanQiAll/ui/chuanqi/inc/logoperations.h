#ifndef LOGOPERATIONS_H
#define LOGOPERATIONS_H
#include <QObject>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/fmt/fmt.h"
#include "spdlog/async.h"
#include <QObject>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <mutex>
#include <memory>
#include <QtQml>
#include <QQuickWindow>
#include "customformat.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"

class LogOperations : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit LogOperations(QObject *parent = nullptr);
    ~LogOperations();
    Q_INVOKABLE void createLogger(const QString &path, const QString &filename) ;
    Q_INVOKABLE void recordLog(const QString&moduleName, int level, const QString&information);
    Q_INVOKABLE void setFlushOn(int level);
    Q_INVOKABLE void setFlushOnTime(int time);
private:
    std::string moduleName;
    std::mutex mutex;
    std::shared_ptr<spdlog::logger> getLogger();
signals:
    void logMessage(const QString &message);

};

#endif // LOGOPERATIONS_H
