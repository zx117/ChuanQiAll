#include "pugixmlinterface.h"
#include <sstream>

PugiXMLInterface::PugiXMLInterface()
{
    settingMap["MeasurementConfigSettings_Xmlns"] = [this](QVariant value) {settings.meaconSetting.xmlns = value.toString();};
    settingMap["MeasurementConfigSettings_Version"] = [this](QVariant value) {settings.meaconSetting.version = value.toString();};

    settingMap["MeasurementConfigSettings_Xmlns"] = [this](QVariant value) {settings.meatreenodeSetting.xmlns = value.toString();};
    settingMap["MeasurementConfigSettings_IsLocalNode"] = [this](QVariant value) {settings.meatreenodeSetting.IsLocalNode = value.toBool();};
    settingMap["MeasurementConfigSettings_Name"] = [this](QVariant value) {settings.meatreenodeSetting.Name = value.toString();};
    settingMap["MeasurementConfigSettings_UniqueId"] = [this](QVariant value) {settings.meatreenodeSetting.UniqueId = value.toString();};
    settingMap["MeasurementConfigSettings_Id"] = [this](QVariant value) {settings.meatreenodeSetting.Id = value.toString();};

    settingMap["Enclosure_Name"] = [this](QVariant value) {settings.encloSetting.name = value.toString();};
    settingMap["Enclosure_IsMainEnclosure"] = [this](QVariant value) {settings.encloSetting.isMainEnclosure = value.toBool();};
    settingMap["Enclosure_PluginId"] = [this](QVariant value) {settings.encloSetting.pluginId = value.toString();};
    settingMap["Enclosure_Id"] = [this](QVariant value) {settings.encloSetting.Id = value.toString();};

    settingMap["Bus_Name"] = [this](QVariant value) {settings.busSetting.name = value.toString();};
    settingMap["Bus_Typr"] = [this](QVariant value) {settings.busSetting.type = value.toString();};

    settingMap["Device_Name"] = [this](QVariant value) {settings.deviceSetting.name = value.toString();};

    settingMap["MeaheadSetting_TimezoneID"] = [this](QVariant value) {settings.meaheadSetting.TimezoneID = value.toString();};
    settingMap["MeaheadSetting_TimezoneOffsetValue"] = [this](QVariant value) {settings.meaheadSetting.TimezoneOffset.value = value.toInt();};
    settingMap["MeaheadSetting_TimezoneOffsetUnit"] = [this](QVariant value) {settings.meaheadSetting.TimezoneOffset.unit = value.toString();};

    settingMap["AcqSource_Uuid"] = [this](QVariant value) {settings.acqSourceSetting.uuid = value.toString();};
    settingMap["AcqSource_ChannelId"] = [this](QVariant value) {settings.acqSourceSetting.channel_id = value.toString();};
    settingMap["AcqSource_Name"] = [this](QVariant value) {settings.acqSourceSetting.name = value.toString();};

    settingMap["ChainElement_Name"] = [this](QVariant value) {settings.chainelementSetting.name = value.toString();};
    settingMap["ChainElement_Uuid"] = [this](QVariant value) {settings.chainelementSetting.uuid = value.toString();};

    settingMap["ChannelsChannel_Id"] = [this](QVariant value) {settings.channelsSetting.id = value.toString();};
    settingMap["ChannelsChannel_Frequency"] = [this](QVariant value) {settings.channelsSetting.frequency = value.toString();};
    settingMap["ChannelsChannel_ReducedFormat"] = [this](QVariant value) {settings.channelsSetting.reduced_format = value.toString();};
    settingMap["ChannelsChannel_SampleFormat"] = [this](QVariant value) {settings.channelsSetting.sample_format = value.toString();};
    settingMap["ChannelsChannel_SampleDimension"] = [this](QVariant value) {settings.channelsSetting.sample_dimension = value.toString();};

    settingMap["ChannelsChannelConfigProperty_Name"] = [this](QVariant value) {settings.configpropertySetting.name = value.toString();};
    settingMap["ChannelsChannelConfigProperty_String"] = [this](QVariant value) {settings.configpropertySetting.stringValue = value.toString();};
    settingMap["ChannelsChannelConfigProperty_Bool"] = [this](QVariant value) {settings.configpropertySetting.boolValue = value.toBool();};
    settingMap["ChannelsChannelConfigProperty_EnumName"] = [this](QVariant value) {settings.configpropertySetting.enumname = value.toString();};
    settingMap["ChannelsChannelConfigProperty_EnumValue"] = [this](QVariant value) {settings.configpropertySetting.enumvalue = value.toString();};
    settingMap["ChannelsChannelConfigProperty_UInt"] = [this](QVariant value) {settings.configpropertySetting.unsignedIntValue = value.toInt();};
    settingMap["ChannelsChannelConfigProperty_Type"] = [this](QVariant value) {settings.configpropertySetting.type = value.toString();};
    settingMap["ChannelsChannelConfigProperty_ScalarValue"] = [this](QVariant value) {settings.configpropertySetting.scalarValue.value = value.toInt();};
    settingMap["ChannelsChannelConfigProperty_ScalarUnit"] = [this](QVariant value) {settings.configpropertySetting.scalarValue.unit = value.toString();};
    settingMap["ChannelsChannelConfigProperty_RangeMin"] = [this](QVariant value) {settings.configpropertySetting.rangeMin = value.toInt();};
    settingMap["ChannelsChannelConfigProperty_RangeMax"] = [this](QVariant value) {settings.configpropertySetting.rangeMax = value.toInt();};

    settingMap["RecordingSettings_StoringMode"] = [this](QVariant value) {settings.recSetting.StoringMode = value.toString();};
    settingMap["RecordingSettings_RecordingPretimeEnabled"] = [this](QVariant value) {settings.recSetting.RecordingPretimeEnabled = value.toBool();};
    settingMap["RecordingSettings_RecordingPretimeValue"] = [this](QVariant value) {settings.recSetting.RecordingPretime.value = value.toInt();};
    settingMap["RecordingSettings_RecordingPretimeUnit"] = [this](QVariant value) {settings.recSetting.RecordingPretime.unit = value.toString();};
    settingMap["RecordingSettings_RecordingPosttimeEnabled"] = [this](QVariant value) {settings.recSetting.RecordingPosttimeEnabled = value.toBool();};
    settingMap["RecordingSettings_RecordingPosttimeValue"] = [this](QVariant value) {settings.recSetting.RecordingPosttime.value = value.toInt();};
    settingMap["RecordingSettings_RecordingPosttimeUnit"] = [this](QVariant value) {settings.recSetting.RecordingPosttime.unit = value.toString();};
    settingMap["RecordingSettings_MaxRecordingDurationEnabled"] = [this](QVariant value) {settings.recSetting.MaxRecordingDurationEnabled = value.toBool();};
    settingMap["RecordingSettings_MaxRecordingDurationValue"] = [this](QVariant value) {settings.recSetting.MaxRecordingDuration.value = value.toInt();};
    settingMap["RecordingSettings_StopAfterDurationEnabled"] = [this](QVariant value) {settings.recSetting.MaxRecordingDuration.unit = value.toString();};
    settingMap["RecordingSettings_MaxRecordingDurationUnit"] = [this](QVariant value) {settings.recSetting.StopAfterDurationEnabled = value.toBool();};
    settingMap["RecordingSettings_StopAfterDurationValue"] = [this](QVariant value) {settings.recSetting.StopAfterDuration.value = value.toInt();};
    settingMap["RecordingSettings_StopAfterDurationUnit"] = [this](QVariant value) {settings.recSetting.StopAfterDuration.unit = value.toString();};
    settingMap["RecordingSettings_StatisticsTimeWindowValue"] = [this](QVariant value) {settings.recSetting.StatisticsTimeWindow.value = value.toInt();};
    settingMap["RecordingSettings_StatisticsTimeWindowUnit"] = [this](QVariant value) {settings.recSetting.StatisticsTimeWindow.unit = value.toString();};
    settingMap["RecordingSettings_MeasurementAutoStart"] = [this](QVariant value) {settings.recSetting.MeasurementAutoStart = value.toBool();};
    settingMap["RecordingSettings_AskForFilenameBeforeRecording"] = [this](QVariant value) {settings.recSetting.AskForFilenameBeforeRecording = value.toBool();};
    settingMap["RecordingSettings_AdvancedRecordingSettings"] = [this](QVariant value) {settings.recSetting.AdvancedRecordingSettings = value.toBool();};
    settingMap["RecordingSettings_RestartAcquisitionOnMeasurementStart"] = [this](QVariant value) {settings.recSetting.RestartAcquisitionOnMeasurementStart = value.toBool();};
    settingMap["RecordingSettings_MultiFileRecording"] = [this](QVariant value) {settings.recSetting.MultiFileRecording = value.toBool();};
    settingMap["RecordingSettings_CreateMultiFileFolder"] = [this](QVariant value) {settings.recSetting.CreateMultiFileFolder = value.toBool();};
    settingMap["RecordingSettings_FileSplitCriterion"] = [this](QVariant value) {settings.recSetting.FileSplitCriterion = value.toString();};
    settingMap["RecordingSettings_MaxFileDurationValue"] = [this](QVariant value) {settings.recSetting.MaxFileDuration.value = value.toInt();};
    settingMap["RecordingSettings_MaxFileDurationUnit"] = [this](QVariant value) {settings.recSetting.MaxFileDuration.unit = value.toString();};
    settingMap["RecordingSettings_MaxNumRecordingEvents"] = [this](QVariant value) {settings.recSetting.MaxNumRecordingEvents = value.toInt();};
    settingMap["RecordingSettings_MaxAbsoluteStartFileDurationValue"] = [this](QVariant value) {settings.recSetting.MaxAbsoluteStartFileDurationValue.value = value.toInt();};
    settingMap["RecordingSettings_MaxAbsoluteStartFileDurationUnit"] = [this](QVariant value) {settings.recSetting.MaxAbsoluteStartFileDurationValue.unit = value.toString();};
    settingMap["RecordingSettings_MaxAbsoluteFileDurationStartDateTime"] = [this](QVariant value) {settings.recSetting.MaxAbsoluteFileDurationStartDateTime = value.toString();};

    settingMap["SyncSettings_Name"] = [this](QVariant value) {settings.syncSetting.name = value.toString();};
    settingMap["SyncSettings_Value"] = [this](QVariant value) {settings.syncSetting.boolvalue = value.toBool();};

    settingMap["SystemInfoSettings_Name"] = [this](QVariant value) {settings.sysSetting.name = value.toString();};
    settingMap["SystemInfoSettings_BuildDate"] = [this](QVariant value) {settings.sysSetting.build_date = value.toString();};
    settingMap["SystemInfoSettings_Hash"] = [this](QVariant value) {settings.sysSetting.hash = value.toString();};
    settingMap["SystemInfoSettings_Licensee"] = [this](QVariant value) {settings.sysSetting.licensee = value.toString();};
    settingMap["SystemInfoSettings_Revision"] = [this](QVariant value) {settings.sysSetting.revision = value.toString();};
    settingMap["SystemInfoSettings_Serial"] = [this](QVariant value) {settings.sysSetting.serial = value.toString();};
    settingMap["SystemInfoSettings_Version"] = [this](QVariant value) {settings.sysSetting.version = value.toString();};


    settingMap["ConfigLock_ChannelList"] = [this](QVariant value) {settings.conlockSetting.ChannelList = value.toBool();};
    settingMap["ConfigLock_RecordingStop"] = [this](QVariant value) {settings.conlockSetting.RecordingStop = value.toBool();};
    settingMap["ConfigLock_ScreenDesign"] = [this](QVariant value) {settings.conlockSetting.ScreenDesign = value.toBool();};
    settingMap["ConfigLock_SaveSetup"] = [this](QVariant value) {settings.conlockSetting.SaveSetup = value.toBool();};
    settingMap["ConfigLock_RecordingSetup"] = [this](QVariant value) {settings.conlockSetting.RecordingSetup = value.toBool();};

    settingMap["MeasurementScreens_ActiveScreen"] = [this](QVariant value) {settings.meaScreenSetting.active_screen = value.toInt();};

    settingMap["ViewSetup_ChannelId"] = [this](QVariant value) {settings.viewSetupSetting.channel_id = value.toString();};
    settingMap["ViewSetup_EnumValue"] = [this](QVariant value) {settings.viewSetupSetting.enumValue = value.toString();};
    settingMap["ViewSetup_SubSecondPrecisionValue"] = [this](QVariant value) {settings.viewSetupSetting.subSecondPrecision.value = value.toInt();};
    settingMap["ViewSetup_SubSecondPrecisionUnit"] = [this](QVariant value) {settings.viewSetupSetting.subSecondPrecision.unit = value.toString();};
    settingMap["ViewSetup_ScreenName"] = [this](QVariant value) {settings.viewSetupSetting.screen_name = value.toString();};
    settingMap["ViewSetup_ActiveMeasurementArea"] = [this](QVariant value) {settings.viewSetupSetting.active_measurement_area = value.toInt();};
    settingMap["ViewSetup_WindowType"] = [this](QVariant value) {settings.viewSetupSetting.window_type = value.toString();};
    settingMap["ViewSetup_WindowX"] = [this](QVariant value) {settings.viewSetupSetting.window_x = value.toInt();};
    settingMap["ViewSetup_WindowY"] = [this](QVariant value) {settings.viewSetupSetting.window_y = value.toInt();};
    settingMap["ViewSetup_WindowWidth"] = [this](QVariant value) {settings.viewSetupSetting.window_width = value.toInt();};
    settingMap["ViewSetup_WindowHeight"] = [this](QVariant value) {settings.viewSetupSetting.window_height = value.toInt();};
    settingMap["ViewSetup_Fullscreen"] = [this](QVariant value) {settings.viewSetupSetting.fullscreen = value.toBool();};

    settingMap["ReportSetup_PaperFormat"] = [this](QVariant value) {settings.reportSetting.paper_format = value.toString();};
    settingMap["ReportSetup_Orientation"] = [this](QVariant value) {settings.reportSetting.orientation = value.toString();};
    settingMap["ReportSetup_TextSize"] = [this](QVariant value) {settings.reportSetting.text_size = value.toString();};

    settingMap["ExportSetup_PluginUuid"] = [this](QVariant value) {settings.exportSetting.plugin_uuid = value.toString();};
    settingMap["ExportSetup_Format"] = [this](QVariant value) {settings.exportSetting.format = value.toString();};
    settingMap["ExportSetup_DecimalSeparator"] = [this](QVariant value) {settings.exportSetting.decimalseparator = value.toString();};
    settingMap["ExportSetup_CellSeparator"] = [this](QVariant value) {settings.exportSetting.cellseparator = value.toString();};
    settingMap["ExportSetup_ExportValuePrecision"] = [this](QVariant value) {settings.exportSetting.exportvalueprecision = value.toInt();};
    settingMap["ExportSetup_Waveform"] = [this](QVariant value) {settings.exportSetting.waveform = value.toBool();};
    settingMap["ExportSetup_Statistic"] = [this](QVariant value) {settings.exportSetting.statistic = value.toBool();};
    settingMap["ExportSetup_ExportReducedMin"] = [this](QVariant value) {settings.exportSetting.exportreducedmin = value.toBool();};
    settingMap["ExportSetup_ExportReducedMax"] = [this](QVariant value) {settings.exportSetting.exportreducedmax = value.toBool();};
    settingMap["ExportSetup_ExportReducedAvg"] = [this](QVariant value) {settings.exportSetting.exportreducedavg = value.toBool();};
    settingMap["ExportSetup_ExportReducedRms"] = [this](QVariant value) {settings.exportSetting.exportreducedrms = value.toBool();};
    settingMap["ExportSetup_SeparateUnitHeader"] = [this](QVariant value) {settings.exportSetting.separateunitheader = value.toBool();};
    settingMap["ExportSetup_AbsoluteTimestamps"] = [this](QVariant value) {settings.exportSetting.absolutetimestamps = value.toBool();};
    settingMap["ExportSetup_AlignTrigger"] = [this](QVariant value) {settings.exportSetting.aligntrigger = value.toBool();};
    settingMap["ExportSetup_Fillgaps"] = [this](QVariant value) {settings.exportSetting.fillgaps = value.toBool();};
    settingMap["ExportSetup_OnMeasurementend"] = [this](QVariant value) {settings.exportSetting.onmeasurementend = value.toBool();};
    settingMap["ExportSetup_Path"] = [this](QVariant value) {settings.exportSetting.path = value.toString();};

}

PugiXMLInterface::~PugiXMLInterface()
{
    saveInformation();
}
/**
 * @brief PugiXMLInterface::initialization   初始化
 */
void PugiXMLInterface::initialization(const QString&filepath)
{
    pugi::xml_parse_result result = doc.load_file(std::string(filepath.toUtf8()).c_str());
    if (!result) {
        qDebug()<<Q_FUNC_INFO<<"Load result: " << result.description();
    }
    else
    {
        qDebug()<<Q_FUNC_INFO<<"Load success";
    }
    configFramework();

}

/**
 * @brief PugiXMLInterface::configFramework  配置文件框架
 */

void PugiXMLInterface::configFramework()
{

    pugi::xml_node root;
    if(!doc.child("MeasurementConfig"))
    {
        root = doc.append_child("MeasurementConfig");
        // 设置 xmlns 和 version 属性
        findOrAddAttribute(root,"xmlns",settings.meaconSetting.xmlns);
        findOrAddAttribute(root,"version",settings.meaconSetting.version);
        // 检查并添加子节点
        findOrAddChild(root, "SystemSetup");
        findOrAddChild(root, "SystemInfo");
        findOrAddChild(root, "MeasurementHeader");
        findOrAddChild(root, "ProjectSetup");
        findOrAddChild(root, "Calculations");
        findOrAddChild(root, "Channels");
        pugi::xml_node MeasurementScreens=findOrAddChild(root, "MeasurementScreens");
        findOrAddAttribute(MeasurementScreens,"active_screen",QString::number(settings.meaScreenSetting.active_screen));
        findOrAddChild(root, "ViewSetup");
        findOrAddChild(root, "ReportSetup");
        findOrAddChild(root, "ExportSetup");
    }
    saveInformation();
}

/**
 * @brief PugiXMLInterface::addMeasurementTree  添加MeasurementTree与MeasurementNode节点与属性
 * @param xmlns                                 xmlns属性值
 * @param isLocalNode                           IsLocalNode属性值
 * @param name                                  Name属性值
 * @param id                                    Id属性值
 * @param niqueId                               UniqueId属性值
 */
void PugiXMLInterface::addMeasurementTree()
{
    // 获取或添加 SystemSetup 节点
    pugi::xml_node systemSetupNode = findOrAddChild(doc.child("MeasurementConfig"), "SystemSetup");
    // 在 SystemSetup 节点下添加 MeasurementTree 节点
    pugi::xml_node measurementTreeNode = findOrAddChild(systemSetupNode, "MeasurementTree");
    // 设置 xmlns 属性
    findOrAddAttribute(measurementTreeNode,"xmlns",settings.meatreenodeSetting.xmlns);
    // 添加 MeasurementNode 子节点并设置属性
    pugi::xml_node measurementNode=findOrAddChild(measurementTreeNode,"MeasurementNode");
    findOrAddAttribute(measurementNode,"IsLocalNode",settings.meatreenodeSetting.IsLocalNode?"True":"False");
    findOrAddAttribute(measurementNode,"Name",settings.meatreenodeSetting.Name);
    findOrAddAttribute(measurementNode,"Id",settings.meatreenodeSetting.Id);
    findOrAddAttribute(measurementNode,"UniqueId",settings.meatreenodeSetting.UniqueId);
    // 保存 XML 文档
    saveInformation();
}
/**
 * @brief PugiXMLInterface::channelGroupandChannelStructAddValue  向通道组与通道结构体中存值
 * @param name
 * @param channelname
 * @param channelid
 */
void PugiXMLInterface::channelGroupandChannelStructAddValue(const QString &name,const QString&channelname,const QString&channelid)
{
    if(settings.channelgroupSetting.name!=name)
    {
        ChannelGroup cg;
        settings.channelgroupSetting=cg;
        settings.channelgroupSetting.name=name;
        if(channelname!=""&&channelid!="")
        {
            settings.channelgroupSetting.channels.push_back(Channel{channelname, channelid});
        }
    }
    else
    {
        settings.channelgroupSetting.channels.push_back(Channel{channelname, channelid});
    }
}
/**
 * @brief PugiXMLInterface::addChannelGroup    添加通道组
 * @param node
 * @param type
 * @param name
 * @param defaultColor
 */
void PugiXMLInterface::addChannelGroup(const QString &parentNode,const QString &attribute,const QString &value)
{
    pugi::xml_node root = doc.child("MeasurementConfig");
    pugi::xml_node Node = findChannelGroupByName(root,parentNode,attribute,value);
    if(Node)
    {
        pugi::xml_node groupnode;
        groupnode =findOrAddChild(Node,"ChannelGroup","Name",settings.channelgroupSetting.name);
        findOrAddAttribute(groupnode,"Name",settings.channelgroupSetting.name);
        for (const auto& channel : settings.channelgroupSetting.channels) {
            addChannel(groupnode, channel);
        }
    }
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addChannel    添加通道
 * @param group
 * @param channel
 */
void PugiXMLInterface::addChannel(pugi::xml_node& group, const Channel& channel)
{
    pugi::xml_node channelnode =findOrAddChild(group,"Channel","Name",channel.name);
    findOrAddAttribute(channelnode,"Name",channel.name);
    findOrAddAttribute(channelnode,"ChannelId",channel.ChannelId);
    saveInformation();
}

/**
 * @brief PugiXMLInterface::addSystemInfo       添加系统信息
 * @param name
 * @param version
 * @param hash
 * @param revision
 * @param builddate
 * @param licensee
 * @param serial
 */
void PugiXMLInterface::addSystemInfo()
{
    // 获取或添加 SystemInfo 节点
    pugi::xml_node systemInfoNode = findOrAddChild(doc.child("MeasurementConfig"), "SystemInfo");
    // 在 SystemInfo 节点下添加 MeasurementTree 节点
    pugi::xml_node applicationInfo = findOrAddChild(systemInfoNode, "ApplicationInfo");
    findOrAddAttribute(applicationInfo,"Name",settings.sysSetting.name);
    findOrAddAttribute(applicationInfo,"Version",settings.sysSetting.version);
    findOrAddAttribute(applicationInfo,"Hash",settings.sysSetting.hash);
    findOrAddAttribute(applicationInfo,"Revision",settings.sysSetting.revision);
    findOrAddAttribute(applicationInfo,"builddate",settings.sysSetting.build_date);
    // 添加 applicationInfo 子节点并设置属性
    pugi::xml_node applicationLicense =findOrAddChild(applicationInfo,"ApplicationLicense");
    findOrAddAttribute(applicationLicense,"IsLocalNode",settings.sysSetting.licensee);
    findOrAddAttribute(applicationLicense,"serial",settings.sysSetting.serial);
    // 保存 XML 文档
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addMeasurementHeader    添加测量标题
 * @param timeZoneIDValue
 * @param timeZoneOffSetValue
 * @param timeZoneOffSetUnit
 */
void PugiXMLInterface::addMeasurementHeader()
{
    pugi::xml_node MeasurementHeaderNode = findOrAddChild(doc.child("MeasurementConfig"), "MeasurementHeader");
    pugi::xml_node timezoneID = findOrAddChild(MeasurementHeaderNode, "Property","name","TimezoneID");
    findOrAddAttribute(timezoneID,"name",std::string("TimezoneID").c_str());
    findOrAddChild(timezoneID, "StringValue","",settings.meaheadSetting.TimezoneID);
    pugi::xml_node timezoneOffset = findOrAddChild(MeasurementHeaderNode, "Property","name","TimezoneOffset");
    findOrAddAttribute(timezoneOffset,"name",std::string("TimezoneOffset").c_str());
    findOrAddChild(timezoneOffset, "Value","",QString::number(settings.meaheadSetting.TimezoneOffset.value));
    findOrAddChild(timezoneOffset, "Unit","",settings.meaheadSetting.TimezoneOffset.unit);
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addMeasurementScreen
 */
void PugiXMLInterface::addMeasurementScreen()
{
    pugi::xml_node MeasurementScreens = findOrAddChild(doc.child("MeasurementConfig"), "MeasurementScreens");
    pugi::xml_node timezoneID = findOrAddChild(MeasurementScreens, "Property","name","TimezoneID");
    findOrAddAttribute(timezoneID,"name",std::string("TimezoneID").c_str());
    findOrAddChild(timezoneID, "StringValue","",settings.meaheadSetting.TimezoneID);
    pugi::xml_node timezoneOffset = findOrAddChild(MeasurementScreens, "Property","name","TimezoneOffset");
    findOrAddAttribute(timezoneOffset,"name",std::string("TimezoneOffset").c_str());
    findOrAddChild(timezoneOffset, "Value","",QString::number(settings.meaheadSetting.TimezoneOffset.value));
    findOrAddChild(timezoneOffset, "Unit","",settings.meaheadSetting.TimezoneOffset.unit);
    saveInformation();
}

/**
 * @brief PugiXMLInterface::addViewSetup     添加安装信息
 */
void PugiXMLInterface::addViewSetup()
{
    pugi::xml_node ViewSetup = findOrAddChild(doc.child("MeasurementConfig"), "ViewSetup");
    pugi::xml_node OverviewBar = findOrAddChild(ViewSetup, "OverviewBar");
    pugi::xml_node SelectedChannel  = findOrAddChild(OverviewBar, "SelectedChannel");
    findOrAddAttribute(SelectedChannel,"channel_id",settings.viewSetupSetting.channel_id);
    pugi::xml_node Markers = findOrAddChild(ViewSetup, "Markers");
    pugi::xml_node TimeLabelType  = findOrAddChild(Markers, "Property","name","TimeLabelType");
    findOrAddAttribute(TimeLabelType,"name","TimeLabelType");
    pugi::xml_node EnumValue= findOrAddChild(TimeLabelType, "EnumValue","",settings.viewSetupSetting.enumValue);
    findOrAddAttribute(EnumValue,"enum","MarkerTimeLabelType");
    pugi::xml_node SubSecondPrecision  = findOrAddChild(Markers, "Property","name","SubSecondPrecision");
    findOrAddAttribute(SubSecondPrecision,"name","SubSecondPrecision");
    pugi::xml_node ScalarValue= findOrAddChild(SubSecondPrecision, "ScalarValue");
    findOrAddChild(ScalarValue, "Value","",QString::number(settings.viewSetupSetting.subSecondPrecision.value));
    findOrAddChild(ScalarValue, "Unit","",settings.viewSetupSetting.subSecondPrecision.unit);
    pugi::xml_node Windows  = findOrAddChild(Markers, "Windows");
    pugi::xml_node window= findOrAddChild(Windows, "window");
    findOrAddAttribute(window,"screen_name",settings.viewSetupSetting.screen_name);
    findOrAddAttribute(window,"active_measurement_area",QString::number(settings.viewSetupSetting.active_measurement_area));
    findOrAddAttribute(window,"window_type",settings.viewSetupSetting.window_type);
    findOrAddAttribute(window,"window_x",QString::number(settings.viewSetupSetting.window_x));
    findOrAddAttribute(window,"window_y",QString::number(settings.viewSetupSetting.window_y));
    findOrAddAttribute(window,"window_width",QString::number(settings.viewSetupSetting.window_width));
    findOrAddAttribute(window,"window_height",QString::number(settings.viewSetupSetting.window_height));
    findOrAddAttribute(window,"fullscreen",settings.viewSetupSetting.fullscreen?"True":"False");
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addReportSetup      添加报告生成设置
 */
void PugiXMLInterface::addReportSetup()
{
    pugi::xml_node ReportSetup = findOrAddChild(doc.child("MeasurementConfig"), "ReportSetup");
    pugi::xml_node Report = findOrAddChild(ReportSetup, "Report");
    findOrAddAttribute(Report,"paper_format",settings.reportSetting.paper_format);
    findOrAddAttribute(Report,"orientation",settings.reportSetting.orientation);
    findOrAddAttribute(Report,"text_size",settings.reportSetting.text_size);
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addExportSetup     添加导出设置
 */
void PugiXMLInterface::addExportSetup()
{
    pugi::xml_node ExportSetup = findOrAddChild(doc.child("MeasurementConfig"), "ExportSetup");
    pugi::xml_node ExportSettings  = findOrAddChild(ExportSetup, "ExportSettings");
    findOrAddAttribute(ExportSettings ,"plugin_uuid",settings.reportSetting.paper_format);
    findOrAddAttribute(ExportSettings ,"format",settings.reportSetting.orientation);
    pugi::xml_node ExportProperties  = findOrAddChild(ExportSettings, "ExportProperties");
    pugi::xml_node DECIMALSEPARATOR  = findOrAddChild(ExportProperties, "Property","name","DECIMAL_SEPARATOR");
    findOrAddAttribute(DECIMALSEPARATOR ,"name","DECIMAL_SEPARATOR");
    findOrAddChild(DECIMALSEPARATOR, "StringValue","",settings.exportSetting.decimalseparator);
    pugi::xml_node CELLSEPARATOR  = findOrAddChild(ExportProperties, "Property","name","CELL_SEPARATOR");
    findOrAddAttribute(CELLSEPARATOR ,"name","CELL_SEPARATOR");
    findOrAddChild(CELLSEPARATOR, "StringValue","",settings.exportSetting.cellseparator);
    pugi::xml_node EXPORTVALUEPRECISION  = findOrAddChild(ExportProperties, "Property","name","EXPORT_VALUE_PRECISION");
    findOrAddAttribute(EXPORTVALUEPRECISION ,"name","CELL_SEPARATOR");
    findOrAddChild(EXPORTVALUEPRECISION, "UnsignedInt64","",QString::number(settings.exportSetting.exportvalueprecision));
    pugi::xml_node WAVEFORM  = findOrAddChild(ExportProperties, "Property","name","WAVEFORM");
    findOrAddAttribute(WAVEFORM ,"name","WAVEFORM");
    findOrAddChild(WAVEFORM, "BooleanValue","",settings.exportSetting.waveform?"True":"False");
    pugi::xml_node STATISTIC  = findOrAddChild(ExportProperties, "Property","name","STATISTIC");
    findOrAddAttribute(STATISTIC ,"name","WAVEFORM");
    findOrAddChild(STATISTIC, "BooleanValue","",settings.exportSetting.statistic?"True":"False");
    pugi::xml_node EXPORTREDUCEDMIN  = findOrAddChild(ExportProperties, "Property","name","EXPORT_REDUCED_MIN");
    findOrAddAttribute(EXPORTREDUCEDMIN ,"name","EXPORT_REDUCED_MIN");
    findOrAddChild(EXPORTREDUCEDMIN, "BooleanValue","",settings.exportSetting.exportreducedmin?"True":"False");
    pugi::xml_node EXPORTREDUCEDMAX  = findOrAddChild(ExportProperties, "Property","name","EXPORT_REDUCED_MAX");
    findOrAddAttribute(EXPORTREDUCEDMAX ,"name","EXPORT_REDUCED_MAX");
    findOrAddChild(EXPORTREDUCEDMAX, "BooleanValue","",settings.exportSetting.exportreducedmax?"True":"False");
    pugi::xml_node EXPORTREDUCEDAVG  = findOrAddChild(ExportProperties, "Property","name","EXPORT_REDUCED_AVG");
    findOrAddAttribute(EXPORTREDUCEDAVG ,"name","EXPORT_REDUCED_AVG");
    findOrAddChild(EXPORTREDUCEDAVG, "BooleanValue","",settings.exportSetting.exportreducedavg?"True":"False");
    pugi::xml_node EXPORTREDUCEDRMS  = findOrAddChild(ExportProperties, "Property","name","EXPORT_REDUCED_RMS");
    findOrAddAttribute(EXPORTREDUCEDRMS ,"name","EXPORT_REDUCED_RMS");
    findOrAddChild(EXPORTREDUCEDRMS, "BooleanValue","",settings.exportSetting.exportreducedrms?"True":"False");
    pugi::xml_node SEPARATEUNITHEADER  = findOrAddChild(ExportProperties, "Property","name","SEPARATE_UNIT_HEADER");
    findOrAddAttribute(SEPARATEUNITHEADER ,"name","SEPARATE_UNIT_HEADER");
    findOrAddChild(SEPARATEUNITHEADER, "BooleanValue","",settings.exportSetting.separateunitheader?"True":"False");
    pugi::xml_node ABSOLUTETIMESTAMPS  = findOrAddChild(ExportProperties, "Property","name","ABSOLUTE_TIMESTAMPS");
    findOrAddAttribute(ABSOLUTETIMESTAMPS ,"name","ABSOLUTE_TIMESTAMPS");
    findOrAddChild(ABSOLUTETIMESTAMPS, "BooleanValue","",settings.exportSetting.absolutetimestamps?"True":"False");
    pugi::xml_node ALIGNTRIGGER  = findOrAddChild(ExportProperties, "Property","name","ALIGN_TRIGGER");
    findOrAddAttribute(ALIGNTRIGGER ,"name","ALIGN_TRIGGER");
    findOrAddChild(ALIGNTRIGGER, "BooleanValue","",settings.exportSetting.aligntrigger?"True":"False");
    pugi::xml_node FILLGAPS  = findOrAddChild(ExportProperties, "Property","name","FILL_GAPS");
    findOrAddAttribute(FILLGAPS ,"name","FILL_GAPS");
    findOrAddChild(FILLGAPS, "BooleanValue","",settings.exportSetting.fillgaps?"True":"False");
    pugi::xml_node AutoExport  = findOrAddChild(ExportSettings, "AutoExport");
    findOrAddAttribute(AutoExport ,"onMeasurementEnd",settings.exportSetting.onmeasurementend?"True":"False");
    findOrAddAttribute(AutoExport ,"path",settings.exportSetting.path);
    saveInformation();

}
/**
 * @brief PugiXMLInterface::setStructValue     设置结构体的值
 * @param key
 * @param value
 */
void PugiXMLInterface::setStructValue(const QString &key, const QVariant &value)
{
    auto it = settingMap.find(key);
    if (it != settingMap.end()) {
        it->second(value);
    } else {
        qDebug()<< "Key not found: "<< key;
    }
}
/**
 * @brief PugiXMLInterface::deleteNodePath    删除节点
 * @param nodeName
 * @param attribute
 * @param value
 * @return
 */
void PugiXMLInterface::deleteNode(const QString &nodeName, const QString &attribute, const QString &value)
{
    pugi::xml_node delNode=findNodeByName(doc,nodeName,attribute,value);
    if (delNode) {
        pugi::xml_node parent = delNode.parent();
        if (parent.remove_child(delNode)) {
            qDebug() << "Deleted node successfully.";
        } else {
            qDebug() << "Failed to delete node.";
        }
    } else {
        qDebug() << "Node not found.";
    }
    saveInformation();
}
/**
 * @brief PugiXMLInterface::getNodeValue     获取节点的值
 * @param parentNode
 * @param parentAttribute
 * @param AttributeValue
 * @return
 */
QVariant PugiXMLInterface::getNodeValue(const QString &parentNode, const QString &parentAttribute, const QString &AttributeValue,const QString &childNodeName)
{
    pugi::xml_node getNode=findNodeByName(doc,parentNode,parentAttribute,AttributeValue);
    QString value;
    if(getNode)
    {

        value=getNode.child(childNodeName.toUtf8().constData()).child_value();
    }
    return value;
}
/**
 * @brief PugiXMLInterface::getAttributeValue   获取属性的值
 * @param parentNode
 * @param childNodeName
 * @param childAttribute
 * @param parentAttribute
 * @param AttributeValue
 * @return
 */
QVariant PugiXMLInterface::getAttributeValue(const QString &parentNode,const QString &parentAttribute,const QString &parentAttributeValue,
                                             const QString &childNodeName, const QString &childAttribute)
{
    pugi::xml_node getNode=findNodeByName(doc,parentNode,parentAttribute,parentAttributeValue);
    QString value;
    if(getNode)
    {
        value=getNode.child(childNodeName.toUtf8().constData()).attribute(childAttribute.toUtf8().constData()).value();
    }
    return value;
}
/**
 * @brief PugiXMLInterface::setNodeValue   设置节点的值
 * @param parentNode
 * @param parentAttribute
 * @param AttributeValue
 * @param childNodeName
 * @return
 */
void PugiXMLInterface::setNodeValue(const QString &parentNode, const QString &parentAttribute, const QString &parentAttributeValue,
                                    const QString &childNodeName, const QVariant &childNodeOldValue, const QVariant &childNodeNewValue)
{
    pugi::xml_node getNode=findNodeByName(doc,parentNode,parentAttribute,parentAttributeValue);
    if(getNode)
    {
       QVariant value=getNode.child(childNodeName.toUtf8().constData()).child_value();
       if(childNodeOldValue==value)
       {
           getNode.child(childNodeName.toUtf8().constData()).text().set(childNodeNewValue.toString().toUtf8().constData());
       }
    }
}
/**
 * @brief PugiXMLInterface::setAttributeValue    设置属性的值
 * @param parentNode
 * @param childNodeName
 * @param childNodeOldValue
 * @param childNodeNewValue
 * @param childAttribute
 * @param parentAttribute
 * @param parentAttributeValue
 */
void PugiXMLInterface::setAttributeValue(const QString &parentNode, const QString &parentAttribute, const QString &parentAttributeValue,const QString &childNodeName,const QString &childAttribute, const QVariant &childAttributeOldValue,
                                         const QVariant &childAttributeNewValue)
{
    pugi::xml_node getNode=findNodeByName(doc,parentNode,parentAttribute,parentAttributeValue);
    if(getNode)
    {
        QVariant value=getNode.child(childNodeName.toUtf8().constData()).attribute(childAttribute.toUtf8().constData()).value();
        if(childAttributeOldValue==value)
        {
            getNode.child(childNodeName.toUtf8().constData()).attribute(childAttribute.toUtf8().constData()).set_value(childAttributeNewValue.toString().toUtf8().constData());
        }
    }
}
/**
 * @brief PugiXMLInterface::addNodeAttribute      向节点添加属性
 * @param parentNode
 * @param parentAttribute
 * @param parentAttributeValue
 * @param AttributeName
 * @param AttributeValue
 */
void PugiXMLInterface::addNodeAttribute(const QString &Node, const QString &Attribute, const QString &AttributeValue,
                                        const QString &newAttributeName, const QString &newAttributeValue)
{
    pugi::xml_node getNode=findNodeByName(doc,Node,Attribute,AttributeValue);
    if(getNode)
    {
        findOrAddAttribute(getNode,newAttributeName,newAttributeValue);
    }
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addEnclosure    添加设备信息
 * @param parentNode
 * @param attribute
 * @param value
 */
void PugiXMLInterface::addEnclosure(const QString &parentNode,const QString &attribute,const QString &value)
{
    pugi::xml_node Node=findNodeByName(doc,parentNode,attribute,value);
    pugi::xml_node group;
    if(Node)
    {
        group =findOrAddChild(Node,"Enclosure","Name",settings.encloSetting.name);
        findOrAddAttribute(group,"Name",settings.encloSetting.name);
        findOrAddAttribute(group,"IsMainEnclosure",settings.encloSetting.isMainEnclosure?"True":"False");
        findOrAddAttribute(group,"pluginId",settings.encloSetting.pluginId);
        findOrAddAttribute(group,"id",settings.encloSetting.Id);
    }
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addSynchronization    添加同步
 * @param name
 */
void PugiXMLInterface::addSynchronization(const QString &parentNode, const QString &name)
{
    pugi::xml_node Node=findNodeByName(doc,parentNode,"Name",name);
    pugi::xml_node root;
    if(!Node.child("Synchronization"))
    {
        root =findOrAddChild(Node,"Synchronization","Name",name);
        // 检查并添加子节点
        pugi::xml_node SyncIn=findOrAddChild(root, "SyncIn");
        findOrAddAttribute(SyncIn,"Current","None");
        findOrAddAttribute(SyncIn,"ConnectorLabel","None");
        pugi::xml_node SyncOut2=findOrAddChild(root, "SyncOut2");
        findOrAddAttribute(SyncOut2,"Current","None");
        findOrAddAttribute(SyncOut2,"ConnectorLabel","None");
        findOrAddAttribute(SyncOut2,"Detected","None");
        pugi::xml_node SyncOutAux=findOrAddChild(root, "SyncOutAux");
        findOrAddAttribute(SyncOutAux,"Current","None");
        findOrAddAttribute(SyncOutAux,"ConnectorLabel","None");
        pugi::xml_node SyncOutIRIG=findOrAddChild(root, "SyncOutIRIG");
        findOrAddAttribute(SyncOutIRIG,"Current","None");
        findOrAddAttribute(SyncOutIRIG,"ConnectorLabel","None");
        pugi::xml_node SyncOutPtp=findOrAddChild(root, "SyncOutPtp");
        findOrAddAttribute(SyncOutPtp,"Current","None");
        findOrAddAttribute(SyncOutPtp,"ConnectorLabel","None");

    }
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addDevice     添加设备
 * @param parentNode                      父节点属性
 * @param attribute                       父节点属性值
 * @param value                           设备名
 */
void PugiXMLInterface::addDevice(const QString &parentNode, const QString &attribute,const QString &value)
{
    pugi::xml_node Node=findNodeByName(doc,parentNode,attribute,value);
    pugi::xml_node device;
    if(Node)
    {
        device =findOrAddChild(Node,"Device","Name",settings.deviceSetting.name);
        findOrAddAttribute(device,"Name",settings.deviceSetting.name);
    }
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addBus    添加总线
 * @param parentNode                  父节点
 * @param attribute                   父节点的属性
 * @param value                       属性值
 * @param slotsize                    插槽的数量
 * @param name                        bus的name属性
 * @param type                        bus的type属性
 */
void PugiXMLInterface::addBus(const QString &parentNode, const QString &attribute="", const QString &value="", int slotsize=0)
{
    pugi::xml_node Node=findNodeByName(doc,parentNode,attribute,value);
    pugi::xml_node bus;
    if(Node)
    {
        bus =findOrAddChild(Node,"Bus","Name",settings.busSetting.name);
        findOrAddAttribute(bus,"Name",settings.busSetting.name);
        findOrAddAttribute(bus,"Type",settings.busSetting.type);
        for(int i=0;i<slotsize;i++)
        {
            pugi::xml_node slot =findOrAddChild(bus,"Slot","Id",QString::number(i));
            findOrAddAttribute(slot,"Id",std::string(QString::number(i).toUtf8()).c_str());
        }
    }
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addCustomHeaderFields    添加自定义标题字段
 * @param name
 * @param type
 * @param value
 * @param mandatory
 * @param prompt
 */
void PugiXMLInterface::addCustomHeaderFields()
{
    pugi::xml_node ProjectSetup = findOrAddChild(doc.child("MeasurementConfig"), "ProjectSetup");
    pugi::xml_node CustomHeaderFields = findOrAddChild(ProjectSetup, "CustomHeaderFields");
    pugi::xml_node nameNode = findOrAddChild(CustomHeaderFields, "Property","name",settings.cushfSetting.name);
    findOrAddAttribute(nameNode,"name",settings.cushfSetting.name);
    pugi::xml_node PropertyListValue = findOrAddChild(nameNode, "PropertyListValue");

    pugi::xml_node typeNode = findOrAddChild(PropertyListValue, "Property","name","type");
    findOrAddAttribute(typeNode,"name","type");
    pugi::xml_node EnumValue= findOrAddChild(typeNode, "EnumValue","",settings.cushfSetting.type);
    findOrAddAttribute(EnumValue,"enum","HeaderType");

    pugi::xml_node valueNode = findOrAddChild(PropertyListValue, "Property","name","value");
    findOrAddAttribute(valueNode,"name","value");
    findOrAddChild(valueNode, "StringValue","",settings.cushfSetting.value);

    pugi::xml_node mandatoryNode = findOrAddChild(PropertyListValue, "Property","name","mandatory");
    findOrAddAttribute(mandatoryNode,"name","mandatory");
    findOrAddChild(mandatoryNode, "StringValue","",settings.cushfSetting.mandatory?"True":"False");

    pugi::xml_node promptNode = findOrAddChild(PropertyListValue, "Property","name","prompt");
    findOrAddAttribute(promptNode,"name","prompt");
    pugi::xml_node promptEnumValue= findOrAddChild(promptNode, "EnumValue","",settings.cushfSetting.prompt);
    findOrAddAttribute(promptEnumValue,"enum","Prompts");
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addExtensionConfiguration    添加扩展配置
 * @param stringValue                                    扩展xml语句
 */
void PugiXMLInterface::addExtensionConfiguration()
{
    pugi::xml_node ProjectSetup = findOrAddChild(doc.child("MeasurementConfig"), "ProjectSetup");
    pugi::xml_node ExtensionConfigurations = findOrAddChild(ProjectSetup, "ExtensionConfigurations");
    pugi::xml_node namenode=findOrAddChild(ExtensionConfigurations, "Property","name","Extension1");
    findOrAddAttribute(namenode,"name","Extension1");
    pugi::xml_node PropertyListValue=findOrAddChild(namenode, "PropertyListValue");
    pugi::xml_node uuidNode = findOrAddChild(PropertyListValue, "Property","name","UUID");
    findOrAddAttribute(uuidNode,"name","UUID");
    findOrAddChild(uuidNode, "StringValue","",settings.extenSetting.UUID1);

    pugi::xml_node ExtensionConfiguration = findOrAddChild(PropertyListValue, "Property","name","ExtensionConfiguration");
    findOrAddAttribute(ExtensionConfiguration,"name","ExtensionConfiguration");
    findOrAddChild(ExtensionConfiguration, "StringValue","",settings.extenSetting.ExtensionConfiguration1);

    pugi::xml_node namenode2=findOrAddChild(ExtensionConfigurations, "Property","name","Extension2");
    findOrAddAttribute(namenode2,"name","Extension2");
    pugi::xml_node PropertyListValue2=findOrAddChild(namenode2, "PropertyListValue");
    pugi::xml_node uuidNode2 = findOrAddChild(PropertyListValue2, "Property","name","UUID");
    findOrAddAttribute(uuidNode2,"name","UUID");
    findOrAddChild(uuidNode2, "StringValue","",settings.extenSetting.UUID2);

    pugi::xml_node ExtensionConfiguration2 = findOrAddChild(PropertyListValue2, "Property","name","ExtensionConfiguration");
    findOrAddAttribute(ExtensionConfiguration2,"name","ExtensionConfiguration");
    findOrAddChild(ExtensionConfiguration2, "StringValue","",settings.extenSetting.ExtensionConfiguration2);
    saveInformation();

}
/**
 * @brief PugiXMLInterface::addRecordingSettings      添加录制设置
 */
void PugiXMLInterface::addRecordingSettings()
{
    pugi::xml_node ProjectSetup = findOrAddChild(doc.child("MeasurementConfig"), "ProjectSetup");
    pugi::xml_node RecordingSettings = findOrAddChild(ProjectSetup, "RecordingSettings");
    pugi::xml_node namenode=findOrAddChild(RecordingSettings, "Property","name","StoringMode");
    findOrAddAttribute(namenode,"name","StoringMode");
    pugi::xml_node EnumValue= findOrAddChild(namenode, "EnumValue","",settings.recSetting.StoringMode);
    findOrAddAttribute(EnumValue,"enum","StoringMode");

    pugi::xml_node RecordingPretimeEnabled=findOrAddChild(RecordingSettings, "Property","name","RecordingPretimeEnabled");
    findOrAddAttribute(RecordingPretimeEnabled,"name","RecordingPretimeEnabled");
    findOrAddChild(RecordingPretimeEnabled, "BooleanValue","",settings.recSetting.RecordingPretimeEnabled?"True":"False");

    pugi::xml_node RecordingPretime = findOrAddChild(RecordingSettings, "Property","name","RecordingPretime");
    findOrAddAttribute(RecordingPretime,"name","RecordingPretime");
    pugi::xml_node ScalarValue = findOrAddChild(RecordingPretime, "ScalarValue");
    findOrAddChild(ScalarValue, "Value","",QString::number(settings.recSetting.RecordingPretime.value));
    findOrAddChild(ScalarValue, "Unit","",settings.recSetting.RecordingPretime.unit);

    pugi::xml_node RecordingPosttimeEnabled=findOrAddChild(RecordingSettings, "Property","name","RecordingPosttimeEnabled");
    findOrAddAttribute(RecordingPosttimeEnabled,"name","RecordingPosttimeEnabled");
    findOrAddChild(RecordingPosttimeEnabled, "BooleanValue","",settings.recSetting.RecordingPosttimeEnabled?"True":"False");

    pugi::xml_node RecordingPosttime = findOrAddChild(RecordingSettings, "Property","name","RecordingPosttime");
    findOrAddAttribute(RecordingPosttime,"name","RecordingPosttime");
    pugi::xml_node ScalarValue1 = findOrAddChild(RecordingPosttime, "ScalarValue");
    findOrAddChild(ScalarValue1, "Value","",QString::number(settings.recSetting.RecordingPosttime.value));
    findOrAddChild(ScalarValue1, "Unit","",settings.recSetting.RecordingPosttime.unit);

    pugi::xml_node MaxRecordingDurationEnabled=findOrAddChild(RecordingSettings, "Property","name","MaxRecordingDurationEnabled");
    findOrAddAttribute(MaxRecordingDurationEnabled,"name","MaxRecordingDurationEnabled");
    findOrAddChild(MaxRecordingDurationEnabled, "BooleanValue","",settings.recSetting.MaxRecordingDurationEnabled?"True":"False");

    pugi::xml_node MaxRecordingDuration = findOrAddChild(RecordingSettings, "Property","name","MaxRecordingDuration");
    findOrAddAttribute(MaxRecordingDuration,"name","MaxRecordingDuration");
    pugi::xml_node ScalarValue2 = findOrAddChild(MaxRecordingDuration, "ScalarValue");
    findOrAddChild(ScalarValue2, "Value","",QString::number(settings.recSetting.MaxRecordingDuration.value));
    findOrAddChild(ScalarValue2, "Unit","",settings.recSetting.MaxRecordingDuration.unit);

    pugi::xml_node StopAfterDurationEnabled=findOrAddChild(RecordingSettings, "Property","name","StopAfterDurationEnabled");
    findOrAddAttribute(StopAfterDurationEnabled,"name","StopAfterDurationEnabled");
    findOrAddChild(StopAfterDurationEnabled, "BooleanValue","",settings.recSetting.StopAfterDurationEnabled?"True":"False");

    pugi::xml_node StopAfterDuration = findOrAddChild(RecordingSettings, "Property","name","StopAfterDuration");
    findOrAddAttribute(StopAfterDuration,"name","StopAfterDuration");
    pugi::xml_node ScalarValue3 = findOrAddChild(StopAfterDuration, "ScalarValue");
    findOrAddChild(ScalarValue3, "Value","",QString::number(settings.recSetting.StopAfterDuration.value));
    findOrAddChild(ScalarValue3, "Unit","",settings.recSetting.StopAfterDuration.unit);

    pugi::xml_node StatisticsTimeWindow = findOrAddChild(RecordingSettings, "Property","name","StatisticsTimeWindow");
    findOrAddAttribute(StatisticsTimeWindow,"name","StatisticsTimeWindow");
    pugi::xml_node ScalarValue4 = findOrAddChild(StatisticsTimeWindow, "ScalarValue");
    findOrAddChild(ScalarValue4, "Value","",QString::number(settings.recSetting.StatisticsTimeWindow.value));
    findOrAddChild(ScalarValue4, "Unit","",settings.recSetting.StatisticsTimeWindow.unit);

    pugi::xml_node MeasurementAutoStart=findOrAddChild(RecordingSettings, "Property","name","MeasurementAutoStart");
    findOrAddAttribute(MeasurementAutoStart,"name","MeasurementAutoStart");
    findOrAddChild(MeasurementAutoStart, "BooleanValue","",settings.recSetting.MeasurementAutoStart?"True":"False");

    pugi::xml_node AskForFilenameBeforeRecording=findOrAddChild(RecordingSettings, "Property","name","AskForFilenameBeforeRecording");
    findOrAddAttribute(AskForFilenameBeforeRecording,"name","AskForFilenameBeforeRecording");
    findOrAddChild(AskForFilenameBeforeRecording, "BooleanValue","",settings.recSetting.AskForFilenameBeforeRecording?"True":"False");

    pugi::xml_node AdvancedRecordingSettings=findOrAddChild(RecordingSettings, "Property","name","AdvancedRecordingSettings");
    findOrAddAttribute(AdvancedRecordingSettings,"name","AdvancedRecordingSettings");
    findOrAddChild(AdvancedRecordingSettings, "BooleanValue","",settings.recSetting.AdvancedRecordingSettings?"True":"False");

    pugi::xml_node RestartAcquisitionOnMeasurementStart=findOrAddChild(RecordingSettings, "Property","name","RestartAcquisitionOnMeasurementStart");
    findOrAddAttribute(RestartAcquisitionOnMeasurementStart,"name","RestartAcquisitionOnMeasurementStart");
    findOrAddChild(RestartAcquisitionOnMeasurementStart, "BooleanValue","",settings.recSetting.RestartAcquisitionOnMeasurementStart?"True":"False");

    pugi::xml_node MultiFileRecording=findOrAddChild(RecordingSettings, "Property","name","MultiFileRecording");
    findOrAddAttribute(MultiFileRecording,"name","MultiFileRecording");
    findOrAddChild(MultiFileRecording, "BooleanValue","",settings.recSetting.MultiFileRecording?"True":"False");

    pugi::xml_node CreateMultiFileFolder=findOrAddChild(RecordingSettings, "Property","name","CreateMultiFileFolder");
    findOrAddAttribute(CreateMultiFileFolder,"name","CreateMultiFileFolder");
    findOrAddChild(CreateMultiFileFolder, "BooleanValue","",settings.recSetting.CreateMultiFileFolder?"True":"False");

    pugi::xml_node FileSplitCriterion=findOrAddChild(RecordingSettings, "Property","name","FileSplitCriterion");
    findOrAddAttribute(FileSplitCriterion,"name","FileSplitCriterion");
    pugi::xml_node EnumValue2 = findOrAddChild(FileSplitCriterion, "EnumValue","",settings.recSetting.FileSplitCriterion);
    findOrAddAttribute(EnumValue2,"enum","FileSplitCriterion");

    pugi::xml_node MaxFileDuration = findOrAddChild(RecordingSettings, "Property","name","MaxFileDuration");
    findOrAddAttribute(MaxFileDuration,"name","MaxFileDuration");
    pugi::xml_node ScalarValue5 = findOrAddChild(MaxFileDuration, "ScalarValue");
    findOrAddChild(ScalarValue5, "Value","",QString::number(settings.recSetting.MaxFileDuration.value));
    findOrAddChild(ScalarValue5, "Unit","",settings.recSetting.MaxFileDuration.unit);

    pugi::xml_node MaxNumRecordingEvents=findOrAddChild(RecordingSettings, "Property","name","MaxNumRecordingEvents");
    findOrAddAttribute(MaxNumRecordingEvents,"name","MaxNumRecordingEvents");
    findOrAddChild(MaxNumRecordingEvents, "UnsignedInt64","",QString::number(settings.recSetting.MaxNumRecordingEvents));

    pugi::xml_node MaxAbsoluteStartFileDurationValue = findOrAddChild(RecordingSettings, "Property","name","MaxAbsoluteStartFileDurationValue");
    findOrAddAttribute(MaxAbsoluteStartFileDurationValue,"name","MaxAbsoluteStartFileDurationValue");
    pugi::xml_node ScalarValue6 = findOrAddChild(MaxAbsoluteStartFileDurationValue, "ScalarValue");
    findOrAddChild(ScalarValue6, "Value","",QString::number(settings.recSetting.MaxFileDuration.value));
    findOrAddChild(ScalarValue6, "Unit","",settings.recSetting.MaxFileDuration.unit);

    pugi::xml_node MaxAbsoluteFileDurationStartDateTime=findOrAddChild(RecordingSettings, "Property","name","MaxAbsoluteFileDurationStartDateTime");
    findOrAddAttribute(MaxAbsoluteFileDurationStartDateTime,"name","MaxAbsoluteFileDurationStartDateTime");
    findOrAddChild(MaxAbsoluteFileDurationStartDateTime, "DateTimeValue","",settings.recSetting.MaxAbsoluteFileDurationStartDateTime);
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addSyncSettings     添加同步设置
 */
void PugiXMLInterface::addSyncSettings()
{
    pugi::xml_node ProjectSetup = findOrAddChild(doc.child("MeasurementConfig"), "ProjectSetup");
    pugi::xml_node SyncSettings = findOrAddChild(ProjectSetup, "SyncSettings");
    pugi::xml_node Properties = findOrAddChild(SyncSettings, "Properties");
    pugi::xml_node namenode=findOrAddChild(Properties, "Property","name",settings.syncSetting.name);
    findOrAddAttribute(namenode,"name",settings.syncSetting.name);
    findOrAddChild(namenode, "BooleanValue","",settings.syncSetting.boolvalue?"True":"False");
    saveInformation();
}
/**
 * @brief PugiXMLInterface::addConfigLock    添加配置锁
 */
void PugiXMLInterface::addConfigLock()
{
    pugi::xml_node ProjectSetup = findOrAddChild(doc.child("MeasurementConfig"), "ProjectSetup");
    pugi::xml_node ChannelList = findOrAddChild(ProjectSetup, "Property","name","ChannelList");
    findOrAddAttribute(ChannelList,"name",std::string("ChannelList").c_str());
    findOrAddChild(ChannelList, "StringValue","",settings.conlockSetting.ChannelList?"True":"False");

    pugi::xml_node RecordingStop = findOrAddChild(ProjectSetup, "Property","name","RecordingStop");
    findOrAddAttribute(RecordingStop,"name",std::string("RecordingStop").c_str());
    findOrAddChild(RecordingStop, "StringValue","",settings.conlockSetting.RecordingStop?"True":"False");

    pugi::xml_node ScreenDesign = findOrAddChild(ProjectSetup, "Property","name","ScreenDesign");
    findOrAddAttribute(ScreenDesign,"name",std::string("ScreenDesign").c_str());
    findOrAddChild(ScreenDesign, "StringValue","",settings.conlockSetting.ScreenDesign?"True":"False");

    pugi::xml_node SaveSetup = findOrAddChild(ProjectSetup, "Property","name","SaveSetup");
    findOrAddAttribute(SaveSetup,"name",std::string("RecordingStop").c_str());
    findOrAddChild(SaveSetup, "StringValue","",settings.conlockSetting.SaveSetup?"True":"False");

    pugi::xml_node RecordingSetup = findOrAddChild(ProjectSetup, "Property","name","RecordingSetup");
    findOrAddAttribute(RecordingSetup,"name",std::string("RecordingSetup").c_str());
    findOrAddChild(RecordingSetup, "StringValue","",settings.conlockSetting.RecordingSetup?"True":"False");
}
/**
 * @brief PugiXMLInterface::addChannelsChannel     添加通道
 */
void PugiXMLInterface::addChannelsChannel()
{
    pugi::xml_node Channels = findOrAddChild(doc.child("MeasurementConfig"), "Channels");
    pugi::xml_node Channel = findOrAddChild(Channels, "Channel","id",settings.channelsSetting.id);
    findOrAddAttribute(Channel,"id",settings.channelsSetting.id);
    pugi::xml_node DataFormat=findOrAddChild(Channel, "DataFormat");
    findOrAddAttribute(DataFormat,"frequency",settings.channelsSetting.frequency);
    findOrAddAttribute(DataFormat,"sample_format",settings.channelsSetting.sample_format);
    findOrAddAttribute(DataFormat,"reduced_format",settings.channelsSetting.reduced_format);
    findOrAddAttribute(DataFormat,"sample_dimension",settings.channelsSetting.sample_dimension);
    findOrAddChild(Channel, "MeasurementChain");

}

void PugiXMLInterface::addAcqSource(const QString &id)
{
    pugi::xml_node channel = findNodeByName(doc,"Channel","id",id);
    pugi::xml_node MeasurementChain = findOrAddChild(channel, "MeasurementChain");
    if(MeasurementChain)
    {
        pugi::xml_node AcqSource = findOrAddChild(MeasurementChain, "AcqSource","name",settings.acqSourceSetting.name);
        findOrAddAttribute(AcqSource,"uuid",settings.acqSourceSetting.uuid);
        findOrAddAttribute(AcqSource,"name",settings.acqSourceSetting.name);
        findOrAddAttribute(AcqSource,"channel_id",settings.acqSourceSetting.channel_id);
        findOrAddChild(AcqSource, "ChannelConfig");
    }


}

void PugiXMLInterface::addChainElement(const QString &id)
{
    pugi::xml_node channel = findNodeByName(doc,"Channel","id",id);
    pugi::xml_node MeasurementChain = findOrAddChild(channel, "MeasurementChain");
    if(MeasurementChain)
    {
        pugi::xml_node ChainElement = findOrAddChild(MeasurementChain, "ChainElement","name",settings.chainelementSetting.name);
        findOrAddAttribute(ChainElement,"uuid",settings.chainelementSetting.uuid);
        findOrAddAttribute(ChainElement,"name",settings.chainelementSetting.name);
        findOrAddChild(ChainElement, "ChannelConfig");
    }
}
/**
 * @brief PugiXMLInterface::addAcqSourceOrChainElementConfig    添加通道设置
 * @param id
 */
void PugiXMLInterface::addAcqSourceOrChainElementConfig(const QString &id,const QString &parentnode,const QString &parentname)
{
    pugi::xml_node channel = findNodeByName(doc,"Channel","id",id);
    pugi::xml_node MeasurementChain = findOrAddChild(channel, "MeasurementChain");
    pugi::xml_node node = findOrAddChild(MeasurementChain, parentnode,"name",parentname);
    if(settings.configpropertySetting.type=="Bool")
    {
        pugi::xml_node Node=findNodeByName(node,"ChannelConfig");
        pugi::xml_node BooleanValue=findOrAddChild(Node, "Property","name",settings.configpropertySetting.name);
        findOrAddAttribute(BooleanValue,"name",settings.configpropertySetting.name);
        findOrAddChild(BooleanValue, "BooleanValue","",settings.configpropertySetting.boolValue?"True":"False");
    }
    else if(settings.configpropertySetting.type=="String")
    {
        pugi::xml_node Node=findNodeByName(node,"ChannelConfig");
        pugi::xml_node stringValue=findOrAddChild(Node, "Property","name",settings.configpropertySetting.name);
        findOrAddAttribute(stringValue,"name",settings.configpropertySetting.name);
        findOrAddChild(stringValue, "StringValue","",settings.configpropertySetting.stringValue);
    }
    else if(settings.configpropertySetting.type=="Enum")
    {

        pugi::xml_node Node=findNodeByName(node,"ChannelConfig");
        pugi::xml_node enumvalue=findOrAddChild(Node, "Property","name",settings.configpropertySetting.name);
        findOrAddAttribute(enumvalue,"name",settings.configpropertySetting.name);
        pugi::xml_node enumnode=findOrAddChild(enumvalue, "EnumValue","",settings.configpropertySetting.enumvalue);
        findOrAddAttribute(enumnode,"enum",settings.configpropertySetting.enumname);
    }
    else if(settings.configpropertySetting.type=="Time")
    {
        pugi::xml_node Node=findNodeByName(node,"ChannelConfig");
        pugi::xml_node SampleRate=findOrAddChild(Node, "Property","name",settings.configpropertySetting.name);
        findOrAddAttribute(SampleRate,"name",settings.configpropertySetting.name);
        pugi::xml_node SCalarValue=findOrAddChild(SampleRate, "SCalarValue");
        findOrAddChild(SCalarValue, "Value","",QString::number(settings.configpropertySetting.scalarValue.value));
        findOrAddChild(SCalarValue, "Unit","",settings.configpropertySetting.scalarValue.unit);
    }
    else if(settings.configpropertySetting.type=="UInt")
    {
        pugi::xml_node Node=findNodeByName(node,"ChannelConfig");
        pugi::xml_node UnsignedValue=findOrAddChild(Node, "Property","name",settings.configpropertySetting.name);
        findOrAddAttribute(UnsignedValue,"name",settings.configpropertySetting.name);
        findOrAddChild(UnsignedValue, "UnsignedValue","",QString::number(settings.configpropertySetting.unsignedIntValue));

    }
    else if(settings.configpropertySetting.type=="Range")
    {
        pugi::xml_node Node=findNodeByName(node,"ChannelConfig");
        pugi::xml_node RangeValue=findOrAddChild(Node, "Property","name",settings.configpropertySetting.name);
        findOrAddAttribute(RangeValue,"name",settings.configpropertySetting.name);
        pugi::xml_node RangeValuenode=findOrAddChild(RangeValue, "RangeValue");
        findOrAddChild(RangeValuenode, "RangeMin","",QString::number(settings.configpropertySetting.rangeMin));
        findOrAddChild(RangeValuenode, "RangeMax","",QString::number(settings.configpropertySetting.rangeMax));
    }
    saveInformation();
}

/**
 * @brief PugiXMLInterface::findOrAddChild    查找子节点是否存在，不存在则创建节点
 * @param parent                              父节点
 * @param name                                子节点
 * @return
 */
pugi::xml_node PugiXMLInterface::findOrAddChild(pugi::xml_node parent, const QString &name,const QString &attribute,const QString &value) {
    // 查找子节点，如果不存在则添加
    pugi::xml_node node = parent.child(std::string(name.toUtf8()).c_str());
    bool createNewNode = false;
    // 遍历所有同名子节点
    for (pugi::xml_node sibling = node; sibling; sibling = sibling.next_sibling(std::string(name.toUtf8()).c_str())) {
        // 比较属性值
        if (sibling.attribute(std::string(attribute.toUtf8()).c_str()).value() == value) {
            createNewNode = true;
            node=sibling;
            break;
        }
        if(attribute.isEmpty()&&!value.isEmpty())
        {
            node=sibling;
            createNewNode = true;
            break;
        }
    }
    if (!createNewNode) {
        node = parent.append_child(std::string(name.toUtf8()).c_str());
    }
    if(attribute==""&&value!="")
    {
        pugi::xml_node textNode = node.first_child();
        if (textNode.type() == pugi::node_pcdata) {
            textNode.set_value(value.toUtf8().constData());
        } else {
            node.append_child(pugi::node_pcdata).set_value(value.toUtf8().constData());
        }
    }
    return node;
}
/**
 * @brief PugiXMLInterface::findOrAddAttribute  查找属性，属性存在就更新值，不存在就创建
 * @param node                                  节点
 * @param name                                  属性名
 * @param value                                 属性值
 */
void PugiXMLInterface::findOrAddAttribute(pugi::xml_node node, const QString &name, const QString &value) {
    // 查找属性，如果不存在则添加，如果存在则更新
    pugi::xml_attribute attr = node.attribute(std::string(name.toUtf8()).c_str());
    if (!attr) {
        if(value!="")
        {
            node.append_attribute(std::string(name.toUtf8()).c_str()).set_value(std::string(value.toUtf8()).c_str());
        }
    } else {
        if(value!="")
        {

            attr.set_value(std::string(value.toUtf8()).c_str());
        }
    }
}
/**
 * @brief PugiXMLInterface::findChannelGroupByName       寻找通道组节点
 * @param root                                           根节点
 * @param nameToFind                                     想要寻找的通道组的Name属性的值
 * @return
 */
pugi::xml_node PugiXMLInterface::findChannelGroupByName(pugi::xml_node& root, const QString &nodename, const QString &key , const QString &value) {
    for (pugi::xml_node node = root.first_child(); node; node = node.next_sibling()) {
        if (std::string(node.name()) == std::string(nodename.toUtf8()).c_str() && node.attribute(std::string(key.toUtf8()).c_str()).value() == value) {
            return node; // 返回匹配的节点
        }
        // 递归遍历子节点
        pugi::xml_node foundNode = findChannelGroupByName(node,nodename,key,value);
        if (foundNode) {
            return foundNode;
        }
    }
    return pugi::xml_node();
}
/**
 * @brief PugiXMLInterface::findNodeByName       寻找节点
 * @param node                                   节点名
 * @return
 */
pugi::xml_node PugiXMLInterface::findNodeByName(const pugi::xml_node &parentnode,const QString &node,const QString &attribute,const QString &value) {
    return findNodeByNameRecursive(parentnode, node,attribute,value);
}
/**
 * @brief PugiXMLInterface::findNodeByNameRecursive   遍历寻找节点
 * @param node                                        根节点
 * @param nodename                                    要寻找的节点
 * @param attribute                                   要寻找的节点具有的属性
 * @param value                                       属性值
 * @return
 */
pugi::xml_node PugiXMLInterface::findNodeByNameRecursive(pugi::xml_node node, const QString &nodename,const QString &attribute,const QString &value) {
    // 遍历当前节点的所有子节点
    for (pugi::xml_node child : node.children()) {
        if(attribute=="")
        {
            if (QString::fromUtf8(child.name()) == nodename) {
                return child;
            }
        }
        else
        {
            if (QString::fromUtf8(child.attribute(attribute.toUtf8().constData()).value()) == value) {
                return child;
            }
        }

        // 递归查找子节点
        pugi::xml_node result = findNodeByNameRecursive(child, nodename,attribute,value);
        if (result) {
            return result;
        }
    }
    // 如果未找到则返回空节点
    return pugi::xml_node();
}
/**
 * @brief PugiXMLInterface::saveInformation  保存信息
 */
void PugiXMLInterface::saveInformation()
{
    QString filepath=QCoreApplication::applicationDirPath()+"/xmldms/configurationfiles.xml";
    doc.save_file(std::string(filepath.toUtf8()).c_str());
}
/**
 * @brief PugiXMLInterface::importConfigurationFile  导入配置文件
 * @param path  选择的配置文件的地址
 */
void PugiXMLInterface::importConfigurationFile(const QString&path)
{
    filepath=path;
    //加载配置文件
    pugi::xml_parse_result result = doc.load_file(std::string(path.toUtf8()).c_str());
    if (!result) {
        qDebug()<<Q_FUNC_INFO<<"Load result: " << result.description();
    }
    else
    {
        qDebug()<<Q_FUNC_INFO<<"Load success";
    }
}
/**
 * @brief PugiXMLInterface::exportConfigurationFile  导出配置文件
 * @param path   保存的地址
 */
void PugiXMLInterface::exportConfigurationFile(const QString &path)
{
    //保存配置文件
    bool save=doc.save_file(std::string(path.toUtf8()).c_str());
    if(!save)
    {
        qDebug()<<Q_FUNC_INFO<<"Save fail";
    }
    else
    {
        qDebug()<<Q_FUNC_INFO<<"Save success";
    }
}
// /**
//  * @brief PugiXMLInterface::returnValue  返回配置文件中对应地址下所求的属性的值
//  * @param valuepath  属性所在的地址
//  * @param valuekey   属性名
//  * @return           返回属性的值
//  * @param id         重复节点中需要返回的属性的位置
//  */
// QString PugiXMLInterface::returnValue(const QString&valuepath,const QString&valuekey,int id)
// {

//     QString value="";
//     if(!valuepath.isEmpty()&&!valuekey.isEmpty())
//     {
//         pugi::xpath_node_set nodes = doc.select_nodes(std::string(valuepath.toLocal8Bit()).c_str());

//         if(nodes.size()==1)
//         {
//             value = QString::fromStdString(nodes[0].node().attribute(std::string(valuekey.toLocal8Bit()).c_str()).value());
//         }
//         else if(nodes.size()>1)
//         {
//             if(id==0)
//             {
//                 QVector<QString> pathComponents = splitPath(valuepath);
//                 if (pathComponents.isEmpty()) {
//                     qDebug() << "Failed to split path.";
//                 }
//                 pugi::xml_node currentNode = doc;
//                 for (int i = 0; i < pathComponents.size() - 1; ++i) {
//                     const QString &nodeName = pathComponents[i];
//                     pugi::xml_node childNode = currentNode.child(std::string(nodeName.toLocal8Bit()).c_str());
//                     if (!childNode) {
//                         qDebug()<<"valuepath is null";
//                     }
//                     currentNode = childNode;
//                 }
//                 if (currentNode) {
//                     for(pugi::xml_node childNode : currentNode.children())
//                     {
//                         for (pugi::xml_attribute attr : childNode.attributes()) {
//                             QString attributeName = QString::fromLocal8Bit(attr.name());
//                             if (attributeName == valuekey) {
//                                 value=QString::fromLocal8Bit(attr.value());
//                                 break;
//                             }
//                         }
//                     }
//                 }
//             }
//             else
//             {
//                 value = QString::fromStdString(nodes[id].node().attribute(std::string(valuekey.toLocal8Bit()).c_str()).value());

//             }

//         }
//         else
//         {
//             qDebug()<<"Unable to find the node and attribute that needs to be queried";
//         }
//     }
//     return value;
// }
// /**
//  * @brief PugiXMLInterface::addAttribute  增加属性
//  * @param filepath  配置文件地址
//  * @param valuepath 想要增加的节点地址
//  * @param valuekey  想要增加的属性名
//  * @param value     想要增加的属性值
//  * @param id        重复节点中需要添加的属性的位置
//  */
// bool PugiXMLInterface::addAttribute(const QString &valuepath, const QString &valuekey, const QString &value,int id)
// {
//     bool operationSuccess = false;
//     if (!valuepath.isEmpty() && !valuekey.isEmpty()) {
//         pugi::xpath_node_set nodes = doc.select_nodes(std::string(valuepath.toLocal8Bit()).c_str());
//         if (nodes.size() > id) {
//             pugi::xml_attribute attribute = nodes[id].node().attribute(std::string(valuekey.toLocal8Bit()).c_str());
//             if (attribute) {
//                 // 属性存在，更新属性值
//                 operationSuccess = attribute.set_value(std::string(value.toLocal8Bit()).c_str());
//                 if (operationSuccess) {
//                     qDebug() << "Attribute updated successfully.";
//                 } else {
//                     qDebug() << "Failed to update attribute.";
//                 }
//             } else {
//                 // 属性不存在，添加新属性
//                 pugi::xml_node node = nodes[id].node();
//                 pugi::xml_attribute newAttribute = node.append_attribute(std::string(valuekey.toLocal8Bit()).c_str());
//                 if (newAttribute) {
//                     operationSuccess = newAttribute.set_value(std::string(value.toLocal8Bit()).c_str());
//                     if (operationSuccess) {
//                         qDebug() << "Attribute added successfully.";
//                     } else {
//                         qDebug() << "Failed to add attribute.";
//                     }
//                 } else {
//                     qDebug() << "Failed to add attribute.";
//                 }
//             }
//         } else {
//             qDebug() << "Unable to find the required nodes and attributes.";
//         }
//     }
//     saveInformation();
//     return operationSuccess;
// }
// /**
//  * @brief PugiXMLInterface::deleteAttribute  删除属性
//  * @param filepath    配置文件地址
//  * @param valuepath   想要删除的节点地址
//  * @param valuekey    先要删除的属性名
//  * @param id          重复节点中需要删除的属性的位置
//  */
// bool PugiXMLInterface::deleteAttribute(const QString &valuepath, const QString &valuekey,int id)
// {
//     bool del=false;
//     if(!valuepath.isEmpty()&&!valuekey.isEmpty())
//     {
//         pugi::xpath_node_set nodes = doc.select_nodes(std::string(valuepath.toLocal8Bit()).c_str());
//         if(nodes.size()==1)
//         {
//             del = nodes[0].node().remove_attribute(std::string(valuekey.toLocal8Bit()).c_str());
//             if (del) {
//                 qDebug() << "Attribute removed successfully.";
//             } else {
//                 qDebug() << "Failed to remove attribute.";
//             }
//         }
//         else if(nodes.size()>1)
//         {
//             if(id==0)
//             {
//                 QVector<QString> pathComponents = splitPath(valuepath);
//                 if (pathComponents.isEmpty()) {
//                     qDebug() << "Failed to split path.";
//                 }
//                 pugi::xml_node currentNode = doc;
//                 for (int i = 0; i < pathComponents.size() - 1; ++i) {
//                     const QString &nodeName = pathComponents[i];
//                     pugi::xml_node childNode = currentNode.child(std::string(nodeName.toLocal8Bit()).c_str());
//                     if (!childNode) {
//                         qDebug()<<"valuepath is null";
//                     }
//                     currentNode = childNode;
//                 }
//                 if (currentNode) {
//                     for(pugi::xml_node childNode : currentNode.children())
//                     {
//                         for (pugi::xml_attribute attr : childNode.attributes()) {
//                             QString attributeName = QString::fromLocal8Bit(attr.name());
//                             if (attributeName == valuekey) {
//                                 childNode.remove_attribute(attr);
//                                 break;
//                             }
//                         }
//                     }
//                 }
//             }
//             else
//             {
//                 del = nodes[id].node().remove_attribute(std::string(valuekey.toLocal8Bit()).c_str());
//                 if (del) {
//                     qDebug() << "Attribute removed successfully.";
//                 } else {
//                     qDebug() << "Failed to remove attribute.";
//                 }
//             }

//         }
//         else
//         {
//             qDebug()<<"Unable to find the nodes and attributes required for deletion";
//         }
//     }
//     saveInformation();
//     return del;
// }
// /**
//  * @brief PugiXMLInterface::modifyAttribute   修改属性
//  * @param filepath    配置文件地址
//  * @param valuepath   想要修改的节点地址
//  * @param valuekey    想要修改的属性名
//  * @param value       想要修改的属性值
//  * @param id          重复节点中需要修改的属性的位置
//  */
// bool PugiXMLInterface::modifyAttribute(const QString &valuepath, const QString &valuekey, const QString &value,int id)
// {
//     bool modify=false;
//     if(!valuepath.isEmpty()&&!valuekey.isEmpty()&&!value.isEmpty())
//     {
//         pugi::xpath_node_set nodes = doc.select_nodes(std::string(valuepath.toLocal8Bit()).c_str());
//         if(nodes.size()==1)
//         {
//             pugi::xml_attribute attr = nodes[0].node().attribute(std::string(valuekey.toLocal8Bit()).c_str());
//             // 确保属性存在
//             if (attr) {
//                 modify=attr.set_value(value.toStdString().c_str());
//                 if (modify) {
//                     qDebug() << "Attribute modify successfully.";
//                 } else {
//                     qDebug() << "Failed to modify attribute.";
//                 }

//             } else {
//                 // 如果属性不存在，可能需要根据需要处理这种情况
//                 qDebug()<<Q_FUNC_INFO << "Attribute" << valuekey << "not found.";
//             }
//         }
//         else if(nodes.size()>1)
//         {
//             if(id==0)
//             {
//                 QVector<QString> pathComponents = splitPath(valuepath);
//                 if (pathComponents.isEmpty()) {
//                     qDebug() << "Failed to split path.";
//                 }
//                 pugi::xml_node currentNode = doc;
//                 for (int i = 0; i < pathComponents.size() - 1; ++i) {
//                     const QString &nodeName = pathComponents[i];
//                     pugi::xml_node childNode = currentNode.child(std::string(nodeName.toLocal8Bit()).c_str());
//                     if (!childNode) {
//                         qDebug()<<"valuepath is null";
//                     }
//                     currentNode = childNode;
//                 }
//                 if (currentNode) {
//                     for(pugi::xml_node childNode : currentNode.children())
//                     {
//                         for (pugi::xml_attribute attr : childNode.attributes()) {
//                             QString attributeName = QString::fromLocal8Bit(attr.name());
//                             if (attributeName == valuekey) {
//                                 modify=attr.set_value(std::string(value.toLocal8Bit()).c_str());
//                                 break;
//                             }
//                         }
//                     }
//                 }
//             }
//             else{
//                 pugi::xml_attribute attr = nodes[id].node().attribute(std::string(valuekey.toLocal8Bit()).c_str());
//                 // 确保属性存在
//                 if (attr) {
//                     modify=attr.set_value(value.toStdString().c_str());
//                     if (modify) {
//                         qDebug() << "Attribute modify successfully.";
//                     } else {
//                         qDebug() << "Failed to modify attribute.";
//                     }

//                 } else {
//                     // 如果属性不存在，可能需要根据需要处理这种情况
//                     qDebug()<<Q_FUNC_INFO << "Attribute" << valuekey << "not found.";
//                 }
//             }

//         }
//         else
//         {
//             qDebug()<<"Unable to find the nodes and attributes required for modification";
//         }
//     }
//     saveInformation();
//     return modify;
// }


// /**
//  * @brief PugiXMLInterface::splitPath  拆分路径为添加节点做准备
//  * @param path     需要拆分的路径
//  * @return         返回拆分好的地址
//  */
// QVector<QString> PugiXMLInterface::splitPath(const QString &path)
// {
//     splitpath.clear();
//     if (!path.isEmpty()) {
//         splitpath=path.split('/',Qt::SkipEmptyParts).toVector();
//     }
//     return splitpath;
// }

// /**
//  * @brief PugiXMLInterface::buildNodePath  构建节点
//  * @param path      需要构建的节点地址
//  * @return          返回是否构建成功
//  */
// void PugiXMLInterface::buildNodePath(const QString &path,const QString &key,const QString &value)
// {
//     if (path.isEmpty()) {
//         qDebug() << "Empty path provided.";
//     }

//     QVector<QString> pathComponents = splitPath(path);
//     if (pathComponents.isEmpty()) {
//         qDebug() << "Failed to split path.";
//     }

//     // 从根节点开始查找或创建路径
//     pugi::xml_node currentNode = doc;
//     for (int i = 0; i < pathComponents.size() - 1 ; ++i) {
//         const QString &nodeName = pathComponents[i];
//         pugi::xml_node childNode = currentNode.child(std::string(nodeName.toLocal8Bit()).c_str());
//         if (!childNode) {
//             // 节点不存在，创建节点
//             childNode = currentNode.append_child(std::string(nodeName.toLocal8Bit()).c_str());
//         }
//         currentNode = childNode;
//     }

//     // 检查节点下是否存在同名节点
//     pugi::xml_node sameNameNode = currentNode.child(std::string(pathComponents.last().toLocal8Bit()).c_str());
//     if (sameNameNode) {
//         bool attributesMatch = true;
//         for(pugi::xml_node childNode : currentNode.children())
//         {
//             for (pugi::xml_attribute attr : childNode.attributes()) {
//                 QString attributeName = QString::fromLocal8Bit(attr.name());
//                 QString attributeValue = QString::fromLocal8Bit(attr.value());
//                 if (attributeName == key && attributeValue == value) {
//                     attributesMatch = false;
//                     break;
//                 }
//             }
//         }

//         if (attributesMatch==true) {
//             // 属性值不匹配，添加新节点
//             pugi::xml_node newNode = currentNode.append_child(std::string(pathComponents.last().toLocal8Bit()).c_str());
//             pugi::xml_attribute newAttr = newNode.append_attribute(std::string(key.toLocal8Bit()).c_str());
//             if (newAttr) {
//                 newAttr.set_value(std::string(value.toLocal8Bit()).c_str());
//                 qDebug() << "New node and attribute added successfully.";
//             } else {
//                 qDebug() << "Failed to add new attribute.";
//             }
//         }
//     } else {
//         // 不存在同名节点，直接添加新节点
//         pugi::xml_node newNode = currentNode.append_child(std::string(pathComponents.last().toLocal8Bit()).c_str());
//         pugi::xml_attribute newAttr = newNode.append_attribute(std::string(key.toLocal8Bit()).c_str());
//         if (newAttr) {
//             newAttr.set_value(std::string(value.toLocal8Bit()).c_str());
//             qDebug() << "New node and attribute added successfully.";
//         } else {
//             qDebug() << "Failed to add new attribute.";
//         }
//     }
//     saveInformation();
// }



