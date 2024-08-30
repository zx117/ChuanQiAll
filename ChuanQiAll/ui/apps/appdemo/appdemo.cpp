
#include <QDebug>
#include "appdemo.h"

AppDemo::AppDemo(QObject *parent)
    : m_host(nullptr)
    , m_name("appdemo")
    , m_version("1.0.0")
    , m_register("")
    , m_valid(true)
    , m_main_component(nullptr)
    , m_set_component(nullptr)
{
    Q_INIT_RESOURCE(appdemo);

}

QString AppDemo::appName() const
{
    return m_name;
}

QString AppDemo::appVersion() const
{
    return m_version;
}

QString AppDemo::appRegisterInfo() const
{
    return m_register;
}

bool AppDemo::isValidApp() const
{
    return m_valid;
}

void AppDemo::setHost(IAppHost* host)
{
    m_host = host;
}

bool AppDemo::postMessage(MessageId msg_id, std::uint64_t key, const QVariant* param, const QVariant** ret)
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

bool AppDemo::addAppUI(QString ui_name, QQmlApplicationEngine* qml_engine, QObject* parent_item)
{
    if (ui_name == "Setting") {
        m_set_component = new QQmlComponent(qml_engine, QUrl("qrc:/AppdemoSetting.qml"));
        m_item = qobject_cast<QQuickItem*>(m_set_component->create());

        if (m_item) {
            m_item->setProperty("anchors.fill", "parent");
            m_item->setParentItem(qobject_cast<QQuickItem*>(parent_item));
        }

        return true;
    }

    if (ui_name == "AppSet") {
        m_set_component = new QQmlComponent(qml_engine, QUrl("qrc:/AppdemoAppSet.qml"));
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
        m_main_component = new QQmlComponent(qml_engine, QUrl("qrc:/appdemoMain.qml"));
        m_item = qobject_cast<QQuickItem*>(m_main_component->create());

        if (m_item) {
            m_item->setProperty("anchors.fill", "parent");
            m_item->setParentItem(qobject_cast<QQuickItem*>(parent_item));
        }

        return true;
    }

    return false;
}

void AppDemo::closeApp()
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

void AppDemo::doFunction()
{

    for(int i=0;i<1000;i++)
    {
        emit data(i);
    }

}

void AppDemo::onSwitchGraphics(const QString &path)
{
    emit mainSwitch(path);
}
