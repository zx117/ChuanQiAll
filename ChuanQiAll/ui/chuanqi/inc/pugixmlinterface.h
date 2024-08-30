#ifndef PUGIXMLINTERFACE_H
#define PUGIXMLINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <QtQml>
#include <vector>
#include <QQuickWindow>
#include "pugixml.hpp"
#include <map>
struct Channel
{
    QString name{""};
    QString ChannelId{""};

};

struct ChannelGroup
{
    QString name{""};
    std::vector<Channel> channels;
};



struct Enclosure
{
    QString name{""};
    bool isMainEnclosure{1};
    QString pluginId{""};
    QString Id={""};
};

struct Device
{
    QString name{""};
};

struct Bus
{
    QString name{""};
    QString type{""};
};

struct ValueUnit {
    int value {0};
    QString unit {""};
};

struct RecordingSettings
{
    QString StoringMode {""};
    bool RecordingPretimeEnabled {false};
    ValueUnit RecordingPretime;
    bool RecordingPosttimeEnabled {false};
    ValueUnit RecordingPosttime;
    bool MaxRecordingDurationEnabled {false};
    ValueUnit MaxRecordingDuration;
    bool StopAfterDurationEnabled {false};
    ValueUnit StopAfterDuration;
    ValueUnit StatisticsTimeWindow;
    bool MeasurementAutoStart {false};
    bool AskForFilenameBeforeRecording {false};
    bool AdvancedRecordingSettings {false};
    bool RestartAcquisitionOnMeasurementStart {false};
    bool MultiFileRecording {false};
    bool CreateMultiFileFolder {true};
    QString FileSplitCriterion {""};
    ValueUnit MaxFileDuration;
    uint64_t MaxNumRecordingEvents {1};
    ValueUnit MaxAbsoluteStartFileDurationValue;
    QString MaxAbsoluteFileDurationStartDateTime {""};
};

struct SystemInfoSettings {
    QString name {""};
    QString version {""};
    QString hash {""};
    QString revision {""};
    QString build_date {""};
    QString licensee {""};
    QString serial {""};
};

struct MeasurementHeaderSettings {
    QString TimezoneID {""};
    ValueUnit TimezoneOffset;
};

struct MeasurementConfigSettings{
    QString xmlns {"http://xml.dewetron.com/oxygen/config"};
    QString version{"4.0"};

};

struct MeasurementTreeAndNodeSettings{
    QString xmlns {"http://xml.dewetron.com/oxygen/system_topology"};
    bool IsLocalNode {true};
    QString Name {"LocalNode"};
    QString Id {"0"};
    QString UniqueId {"8f0c7fe"};
};

struct ExtensionConfigurations
{
    QString UUID1{""};
    QString ExtensionConfiguration1{""};
    QString UUID2{""};
    QString ExtensionConfiguration2{""};
};

struct CustomHeaderFields
{
    QString name {""};
    QString type {""};
    QString value {""};
    bool mandatory {0};
    QString prompt {""};
};

struct SyncSettings
{
    QString name{""};
    bool boolvalue {true};
};

struct ConfigLock
{
    bool ChannelList {0};
    bool RecordingStop {0};
    bool ScreenDesign {0};
    bool SaveSetup {0};
    bool RecordingSetup {0};
};

struct ChannelsChannel
{
    QString id{""};
    QString frequency{""};
    QString sample_format{""};
    QString reduced_format{""};
    QString sample_dimension{""};

};

struct AcqSource
{
    QString uuid{""};
    QString name{""};
    QString channel_id{""};
};

struct ChainElement
{
    QString uuid{""};
    QString name{""};
};

struct ChannelsChannelConfigProperty
{
    QString name{""};
    QString type{""};
    QString stringValue{""};
    bool boolValue{0};
    unsigned int unsignedIntValue{1};
    ValueUnit scalarValue;
    QString enumname{""};
    QString enumvalue{""};
    double rangeMin {};
    double rangeMax {};
};
struct MeasurementScreens
{
    int active_screen{0};

};

struct ViewSetup
{
    QString channel_id{""};
    QString enumValue{""};
    ValueUnit subSecondPrecision;
    QString screen_name{""};
    int active_measurement_area{0};
    QString window_type{""};
    int window_x{0};
    int window_y{0};
    int window_width{1920};
    int window_height{1080};
    bool fullscreen{false};

};

struct ReportSetup
{
    QString paper_format{"paper_A4"};
    QString orientation{"paper_portrait"};
    QString text_size{"medium"};
};

struct ExportSetup
{
    QString plugin_uuid{""};
    QString format{"CSV"};
    QString decimalseparator{"."};
    QString cellseparator{","};
    unsigned int exportvalueprecision{12};
    bool waveform{false};
    bool statistic{true};
    bool exportreducedmin{false};
    bool exportreducedmax{1};
    bool exportreducedavg{1};
    bool exportreducedrms{1};
    bool separateunitheader{0};
    bool absolutetimestamps{0};
    bool aligntrigger{0};
    bool fillgaps{0};
    bool onmeasurementend{0};
    QString path{""};
};
struct Settings
{
    MeasurementConfigSettings      meaconSetting;
    MeasurementTreeAndNodeSettings meatreenodeSetting;
    ChannelGroup                   channelgroupSetting;
    Channel                        channelSetting;
    Enclosure                      encloSetting;
    Device                         deviceSetting;
    Bus                            busSetting;
    RecordingSettings              recSetting;
    SystemInfoSettings             sysSetting;
    MeasurementHeaderSettings      meaheadSetting;
    MeasurementScreens             meaScreenSetting;
    ExtensionConfigurations        extenSetting;
    CustomHeaderFields             cushfSetting;
    SyncSettings                   syncSetting;
    ConfigLock                     conlockSetting;
    ChannelsChannel                channelsSetting;
    AcqSource                      acqSourceSetting;
    ChainElement                   chainelementSetting;
    ChannelsChannelConfigProperty  configpropertySetting;
    ViewSetup                      viewSetupSetting;
    ReportSetup                    reportSetting;
    ExportSetup                    exportSetting;
};
Q_DECLARE_METATYPE(Settings)
class PugiXMLInterface:public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    PugiXMLInterface();
    ~PugiXMLInterface();

    void initialization(const QString &path);
    Q_INVOKABLE void importConfigurationFile(const QString &path) ;
    Q_INVOKABLE void exportConfigurationFile(const QString &path) ;
    // Q_INVOKABLE QString returnValue(const QString&valuepath, const QString&valuekey, int id=0) ;
    // Q_INVOKABLE void buildNodePath(const QString&path, const QString &key="", const QString &value="") ;
    // Q_INVOKABLE bool addAttribute(const QString&valuepath, const QString&valuekey, const QString &value, int id=0) ;
    // Q_INVOKABLE bool deleteAttribute(const QString&valuepath, const QString&valuekey, int id=0) ;
    // Q_INVOKABLE bool modifyAttribute(const QString&valuepath, const QString&valuekey, const QString &value, int id=0) ;

    //add SystemSetup information
    Q_INVOKABLE void channelGroupandChannelStructAddValue(const QString&name, const QString &channelname, const QString &channelid);

    Q_INVOKABLE void addMeasurementTree();
    Q_INVOKABLE void addEnclosure(const QString &parentNode, const QString &attribute, const QString &value);
    Q_INVOKABLE void addChannelGroup(const QString &parentNode, const QString &attribute, const QString &value);
    Q_INVOKABLE void addChannel(pugi::xml_node &group, const Channel &channel);
    Q_INVOKABLE void addSynchronization(const QString &parentNode, const QString&parentName="");
    Q_INVOKABLE void addDevice(const QString &parentNode, const QString &attribute, const QString &value);
    Q_INVOKABLE void addBus(const QString &parentNode, const QString &attribute, const QString &value, int slotsize);
    //add ProjectSetup information
    Q_INVOKABLE void addCustomHeaderFields();
    Q_INVOKABLE void addExtensionConfiguration();
    Q_INVOKABLE void addRecordingSettings();
    Q_INVOKABLE void addSyncSettings();
    Q_INVOKABLE void addConfigLock();
    //add Channels information
    Q_INVOKABLE void addChannelsChannel();
    Q_INVOKABLE void addAcqSource(const QString &id);
    Q_INVOKABLE void addChainElement(const QString &id);
    Q_INVOKABLE void addAcqSourceOrChainElementConfig(const QString&id, const QString &parentnode, const QString &parentname);
    //add SystemInfo information
    Q_INVOKABLE void addSystemInfo();
    Q_INVOKABLE void addMeasurementHeader();
    //add MeasurementScreens  information
    Q_INVOKABLE void addMeasurementScreen();
    //add viewSetup information
    Q_INVOKABLE void addViewSetup();
    //add ReportSetup information
    Q_INVOKABLE void addReportSetup();
    //add ExportSetup information
    Q_INVOKABLE void addExportSetup();
    //set struct value
    Q_INVOKABLE void setStructValue(const QString& key, const QVariant& value);
    //delete xml node
    Q_INVOKABLE void deleteNode(const QString&nodeName,const QString&attribute="",const QString&value="") ;
    //get xml value
    Q_INVOKABLE QVariant getNodeValue(const QString&parentNode, const QString&parentAttribute, const QString&AttributeValue, const QString &childNodeName);
    Q_INVOKABLE QVariant getAttributeValue(const QString&parentNode, const QString&parentAttribute, const QString&parentAttributeValue,
                                           const QString &childNodeName,const QString &childAttribute);
    //set xml value
    Q_INVOKABLE void setNodeValue(const QString&parentNode, const QString&parentAttribute, const QString&AttributeValue,
                                  const QString &childNodeName, const QVariant &childNodeOldValue,const QVariant &childNodeNewValue);
    Q_INVOKABLE void setAttributeValue(const QString &parentNode, const QString &parentAttribute, const QString &parentAttributeValue, const QString &childNodeName, const QString &childAttribute, const QVariant &childAttributeOldValue,
                                       const QVariant &childAttributeNewValue);
    //add node attribute
    Q_INVOKABLE void addNodeAttribute(const QString&Node, const QString&Attribute, const QString &AttributeValue,
                                      const QString &newAttributeName, const QString &newAttributeValue);

private:
    std::map<QString, std::function<void(QVariant)>> settingMap;
    Settings settings;
    QString filepath;
    pugi::xml_document doc;
    QVector<QString> splitPath(const QString&path);
    QVector<QString>  splitpath;
    void initSetting();
    void saveInformation();
    void configFramework();
    pugi::xml_node findOrAddChild(pugi::xml_node parent, const QString &name,const QString &attribute="",const QString &value="");
    void findOrAddAttribute(pugi::xml_node node, const QString &name, const QString &value="");
    pugi::xml_node findNodeByNameRecursive(pugi::xml_node node, const QString &nodename,const QString &attribute="",const QString &value="");
    pugi::xml_node findChannelGroupByName(pugi::xml_node& root,const QString &nodename,const QString &key , const QString &value);
    pugi::xml_node findNodeByName(const pugi::xml_node &parentnode,const QString &node, const QString &attribute="", const QString &value="");

};

#endif // PUGIXMLINTERFACE_H
