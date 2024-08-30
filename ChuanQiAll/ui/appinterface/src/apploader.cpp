#include "apploader.h"

#include <QCoreApplication>
#include <QPluginLoader>
#include <QJsonArray>
#include <QDir>
#include <QUrl>

#ifdef Q_OS_WIN
static const QString LibPrefix = "";
static const QString LibExtension = "dll";
#elif defined Q_OS_MACX
static const QString LibExtension = "dylib";
static const QString LibPrefix = "lib";
#else
static const QString LibExtension = "so";
static const QString LibPrefix = "lib";
#endif

AppLoader::AppLoader(const char *iid, const QString &location)
    : m_iid(iid)
    , m_location(location)
{
    m_plugins.clear();
    loadPlugins();
}

AppLoader::~AppLoader()
{

}

QStringList AppLoader::keys() const
{
    return m_metadata.keys();
}

QObject* AppLoader::instance(QString const &key)
{
    if (!m_metadata.contains(key))
        return 0;

    double idx = m_metadata.value(key).first().value(QStringLiteral("index")).toDouble();
    if (idx < 0.0)
        return 0;

    return m_plugins.at(idx);
}

QUrl AppLoader::url(QString const &key)
{
    if (!m_metadata.contains(key))
        return QUrl("");

    QUrl url = m_metadata.value(key).first().value(QStringLiteral("url")).toString();

    return url;
}

QList<QUrl> AppLoader::urls(QString const &key)
{
    if (!m_metadata.contains(key))
        return QList<QUrl>();

    QList<QUrl> objects;
    const auto list = m_metadata.value(key);
    for (const QJsonObject &jsonobj : list) {
        QUrl url = jsonobj.value(QStringLiteral("url")).toString();

        if (!objects.contains(url)) objects.append(url);
    }

    return objects;
}

QList<QObject*> AppLoader::instances(QString const &key)
{
    if (!m_metadata.contains(key))
        return QList<QObject*>();

    QList<QObject *> objects;
    const auto list = m_metadata.value(key);
    for (const QJsonObject &jsonobj : list) {
        int idx = jsonobj.value(QStringLiteral("index")).toDouble();
        if (idx < 0)
            continue;

        QObject *object = m_plugins.at(idx);
        if (!objects.contains(object)) {
            objects.append(object);
        }
    }

    return objects;
}

void AppLoader::loadPlugins()
{
    QDir pluginsDir = QDir(qApp->applicationDirPath());

    pluginsDir.cd(m_location);

    QStringList pluginFilter;
    pluginFilter << QString("*.%1").arg(LibExtension);
    QStringList pluginsList = pluginsDir.entryList(pluginFilter);
    for(int i=0; i<pluginsList.count(); i++) {
        QString candidate = pluginsList.at(i);
        QString fileName = QString("%1").arg(pluginsDir.absoluteFilePath(candidate));

        QStringList titles = fileName.split( "/");
        QString title = titles.last();

        QPluginLoader pluginLoader( fileName );
        QJsonObject metaData = pluginLoader.metaData();

        QString pluginTypeString;

        if (pluginLoader.isLoaded() || pluginLoader.load())
        {
            if(metaData.value("IID").toString() == QString(m_iid)) {
                QObject* plugin = pluginLoader.instance();
                if (plugin) {
                    metaData = metaData.value("MetaData").toObject();
                    metaData.insert(QStringLiteral("url"), fileName);
                    int idx = m_plugins.count();
                    loadMetadata( idx, metaData );
                    m_plugins.append(plugin);
                }
                else {
                    pluginLoader.unload();
                }
            }
            else {
                pluginLoader.unload();
            }
        }
    }
}

void AppLoader::loadMetadata(int i, QJsonObject& jsonobj)
{
    QString pluginName = jsonobj.value("name").toString();
    if (pluginName.isEmpty()) {
        return;
    }

    QString pluginVersion = jsonobj.value("version").toString();
    if (pluginVersion.isEmpty()) {
        return;
    }

    jsonobj.insert(QStringLiteral("index"), i);

    //int pluginVersionNumber=pluginVersion.replace(".","").toInt();

    QString pluginRegisted = jsonobj.value("registered").toString();
    if (pluginRegisted.isEmpty()) {
        return;
    }

    m_metadata[pluginName].append(jsonobj);
}
