
#include <QDebug>
#include "fastfrequency.h"

FastFrequency::FastFrequency(QObject *parent)
    : m_host(nullptr)
    , m_name("fastfrequency")
    , m_version("1.0.0")
    , m_register("")
    , m_valid(true)
    , m_main_component(nullptr)
    , m_set_component(nullptr)
{
    Q_INIT_RESOURCE(fastfrequency);

}

QString FastFrequency::appName() const
{
    return m_name;
}

QString FastFrequency::appVersion() const
{
    return m_version;
}

QString FastFrequency::appRegisterInfo() const
{
    return m_register;
}

bool FastFrequency::isValidApp() const
{
    return m_valid;
}

void FastFrequency::setHost(IAppHost* host)
{
    m_host = host;
}

bool FastFrequency::postMessage(MessageId msg_id, std::uint64_t key, const QVariant* param, const QVariant** ret)
{
    switch (msg_id) {
    case AppSystem::APP_INIT: {
        AppSystem::AppRegisterInfo register_info;
        register_info.app_name = m_name;
        register_info.app_version = m_version;
        register_info.app_license = m_register;
        QString image_file = QString::fromUtf8(":/images/nav_10.png");
        QImage img;
        img.load(image_file, "PNG");
        register_info.app_desktop = img;

        QVariant info = QVariant::fromValue(register_info);
        m_host->messageSync(AppSystem::APP_REGISTER, 0, &info );
        break;
    }
    default:
        break;
    }
    return true;
}

bool FastFrequency::addAppUI(QString ui_name, QQmlApplicationEngine* qml_engine, QObject* parent_item)
{
    if (ui_name == "Setting") {
        m_set_component = new QQmlComponent(qml_engine, QUrl("qrc:/fastfrequencySetting.qml"));
        m_item = qobject_cast<QQuickItem*>(m_set_component->create());

        if (m_item) {
            m_item->setProperty("anchors.fill", "parent");
            m_item->setParentItem(qobject_cast<QQuickItem*>(parent_item));
        }

        return true;
    }

    if (ui_name == "AppSet") {
        m_set_component = new QQmlComponent(qml_engine, QUrl("qrc:/fastfrequencyAppSet.qml"));
        m_item = qobject_cast<QQuickItem*>(m_set_component->create());

        if (m_item) {
            m_item->setProperty("anchors.fill", "parent");
            m_item->setParentItem(qobject_cast<QQuickItem*>(parent_item));
            m_item->setObjectName("appset");
            QObject::connect(m_item, SIGNAL(switchGraphics(QString)), this, SLOT(onSwitchGraphics(QString)));
        }

        return true;
    }

    if (!m_main_component && ui_name == "Main") {
        m_main_component = new QQmlComponent(qml_engine, QUrl("qrc:/fastfrequencyMain.qml"));
        m_item = qobject_cast<QQuickItem*>(m_main_component->create());
        qDebug()<<m_main_component->status()<<m_item;
        const QList<QQmlError> errors = m_main_component->errors();
        for (const QQmlError &error : errors) {
            qWarning() << error.toString();
        }
        if (m_item) {
            m_item->setProperty("anchors.fill", "parent");
            m_item->setParentItem(qobject_cast<QQuickItem*>(parent_item));
        }

        return true;
    }

    return false;
}

void FastFrequency::closeApp()
{
    if (m_set_component) {
        delete m_set_component;
        m_set_component = nullptr;
    }
    if (m_main_component) {
        delete m_main_component;
        m_main_component = nullptr;
    }
    if (m_item) {
        QObject::disconnect(m_item);
        m_item->setParentItem(nullptr);
        delete m_item;
        m_item = nullptr;
    }
}

void FastFrequency::doFunction()
{

    for(int i=0;i<1000;i++)
    {
        emit data(i);
    }

}

void FastFrequency::onSwitchGraphics(const QString &path)
{
    emit mainSwitch(path);
}
