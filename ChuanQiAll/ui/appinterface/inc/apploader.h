#ifndef APPLOADER_H
#define APPLOADER_H

#include <QString>
#include <QJsonObject>

class AppLoader
{
public:
    AppLoader(const char *iid, const QString &location = QString());
    ~AppLoader();

    QStringList keys() const;
    QObject* instance(QString const &key);
    QList<QObject*> instances(QString const &key);

    QUrl url(QString const &key);
    QList<QUrl> urls(QString const &key);


private:
    void loadMetadata(int i, QJsonObject& jsonobj);
    void loadPlugins();

    QByteArray  m_iid;
    QString     m_location;
    QMap<QString, QList<QJsonObject> > m_metadata;
    QList<QObject*> m_plugins;
};

#endif // APPLOADER_H
