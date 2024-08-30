#ifndef __API_CHUANQI_QUERIES__
#define __API_CHUANQI_QUERIES__

#define STATIC_CONTEXT(name, context_value, doc) const static char* name = context_value
#define READ_ONLY_PROPERTY(context_name, name, type, doc) const static char* context_name##_##name = #name
#define WRITE_ONLY_PROPERTY(context_name, name, type, doc) const static char* context_name##_##name = #name
#define READ_WRITE_PROPERTY(context_name, name, type, doc) const static char* context_name##_##name = #name

namespace cq
{
namespace queries
{
    //Current context strings use # as a separator in order to prevent conflict with config key names (ID:TRION/BoardId)
    //  and potential usage of xpath in the future

    STATIC_CONTEXT( PluginHost, "#PluginHost", "Properties and functionality of the plugin host application (not necessarily chuanqi)");

    READ_ONLY_PROPERTY( PluginHost,     VendorName,         IfStringValue,      "Vendor of the host application");
    READ_ONLY_PROPERTY( PluginHost,     Name,               IfStringValue,      "Name of the host application (without version)");
    READ_ONLY_PROPERTY( PluginHost,     VersionString,      IfStringValue,      "Version of the host application as a displayable string");
    READ_ONLY_PROPERTY( PluginHost,     LogPath,            IfStringValue,      "Absolute path to the directory where log files should be stored");

    STATIC_CONTEXT( ChuanQi,                 "#ChuanQi",                      "References global chuanqi properties");
    STATIC_CONTEXT( ChuanQiAcqStartTime,     "#ChuanQi#AcquisitionStartTime", "References (absolute) acquisition start time information");
    STATIC_CONTEXT( ChuanQiMeasStartTime,    "#ChuanQi#MeasurementStartTime", "References measurment start time information (relative to acquisition start)");
    STATIC_CONTEXT( ChuanQiMeasEndTime,      "#ChuanQi#MeasurementEndTime",   "References measurment end time (current time or end of file) information (relative to acquisition start)");
    STATIC_CONTEXT( ChuanQiRecording,        "#ChuanQi#Recording",            "References global chuanqi recording properties");


    READ_ONLY_PROPERTY( ChuanQi,                     AcquisitionState,      IfEnumValue,          "Current acquisition state");
    READ_ONLY_PROPERTY( ChuanQi,                     MasterTimebaseValue,   IfXMLValue,           "Current master time base value");
    READ_ONLY_PROPERTY( ChuanQi,                     AnalysisModeActive,    IfBooleanValue,       "Is currently in Analysis Mode currently");

    READ_ONLY_PROPERTY( ChuanQiAcqStartTime,         AbsISO,         IfStringValue,          "Returns the absolute time of acquisition start");
    READ_ONLY_PROPERTY( ChuanQiAcqStartTime,        AbsXML,         IfXMLValue,             "Returns the absolute time of acquisition start and timezone information in a verbose format");

    READ_ONLY_PROPERTY( ChuanQiMeasStartTime,        AbsISO,         IfStringValue,          "Returns the absolute time of measurement start (Armed, start recording)");
    READ_ONLY_PROPERTY( ChuanQiMeasStartTime,        AbsXML,         IfXMLValue,             "Returns the absolute time of measurement start and timezone information in a verbose format");
    READ_ONLY_PROPERTY( ChuanQiMeasStartTime,        RelSec,         IfFloatingPointValue,   "Returns the measurement start time in seconds relative to the acqusition start");
    READ_ONLY_PROPERTY( ChuanQiMeasStartTime,        RelXML,         IfXMLValue,             "Returns the measurement start time using a sample-exact description");

    READ_ONLY_PROPERTY( ChuanQiMeasEndTime,          AbsISO,         IfStringValue,          "Returns the absolute time of acquisition end (steadily increasing while measurement is running)");
    READ_ONLY_PROPERTY( ChuanQiMeasEndTime,          AbsXML,         IfXMLValue,             "Returns the absolute time of acquisition end and timezone information in a verbose format");
    READ_ONLY_PROPERTY( ChuanQiMeasEndTime,          RelSec,         IfFloatingPointValue,   "Returns the acquisition end time in seconds relative to the acquisition start");
    READ_ONLY_PROPERTY( ChuanQiMeasEndTime,          RelXML,         IfXMLValue,             "Returns the acquisition end time using a sample-exact description");

    STATIC_CONTEXT( ChuanQiHeaders, "#ChuanQi#Headers", "References global measurement headers");
    READ_ONLY_PROPERTY( ChuanQiHeaders,  List,                       IfXMLValue,            "Returns a list of headers and their display value");
    // #ChuanQi#Headers#<HeaderName>|DisplayValue                    get a displayable string describing the value (IfStringValue)

    STATIC_CONTEXT( ChuanQiChannels, "#ChuanQi#Channels", "References the channel list");
    READ_ONLY_PROPERTY( ChuanQiChannels,  AllIds,                    IfXMLValue,            "Returns a list of all channel ids");
    READ_ONLY_PROPERTY( ChuanQiChannels,  AllItemsEx,                IfXMLValue,            "Read the current value of all items as an xml document for each channel");
    READ_ONLY_PROPERTY( ChuanQiChannels,  AllConstraintsEx,          IfXMLValue,            "Read the constraints of all items as an xml document for each channel");
    READ_ONLY_PROPERTY( ChuanQiChannels,  AllTimebasesEx,            IfXMLValue,            "Read the timebase information (frequency, parents) required to convert channel ticks into seconds relative to acquisition start");
    // #ChuanQi#Channels#<ChId>#Config#<ConfigItemKey>|Value         read/write the current value of this config item (type depends on config item type)
    // #ChuanQi#Channels#<ChId>#Config#<ConfigItemKey>|ValueXML      read/write the current value of this config item in xml format
    // #ChuanQi#Channels#<ChId>#Config#<ConfigItemKey>|ConstraintsXML read/write the current constraints of this config item in xml format
    // #ChuanQi#Channels#<ChId>#Config|AllValues                     read the current value of all config items as an xml document
    // #ChuanQi#Channels#<ChId>#Config|AllIdValues                   read the current value of all ID items as an xml document
    // #ChuanQi#Channels#<ChId>#Config|AllItemsEx                    read the current value of all items as an xml document (unfiltered, with chain structure)
    // #ChuanQi#Channels#<ChId>#Config|AllConstraintsEx              read the constraints of all items as an xml document (unfiltered, with chain structure)
    // #ChuanQi#Channels#<ChId>|Name                                 get the name of the channel (IfStringValue; alias for corresponding config item)
    // #ChuanQi#Channels#<ChId>|LongName                             get the full name (including domain) of the channel (IfStringValue; alias for corresponding config item)
    // #ChuanQi#Channels#<ChId>|Timebase                             read the timebase information (frequency, parents) required to convert channel ticks into seconds relative to acquisition start
    // #ChuanQi#Channels#<ChId>|DataFormat                           Returns the data format-information for the given channel");

    STATIC_CONTEXT(ChuanQiTopology, "#ChuanQi#Topology", "References the system topology");
    READ_ONLY_PROPERTY(ChuanQiTopology, List,                       IfXMLValue,            "Returns the system topology as xml");

    STATIC_CONTEXT(ChuanQiPaths, "#ChuanQi#Paths", "Standard paths for ChuanQi files");
    READ_ONLY_PROPERTY(ChuanQiPaths, CommonAppDataDir,   IfStringValue, "Absolute path of the systems wide writeable application data folder");
    READ_ONLY_PROPERTY(ChuanQiPaths, AppDataDir,         IfStringValue, "Absolute path of the installed application data folder");
    READ_ONLY_PROPERTY(ChuanQiPaths, LogDir,             IfStringValue, "Absolute path of the chuanqi logging folder ");
    READ_ONLY_PROPERTY(ChuanQiPaths, RecordingDir,       IfStringValue, "Absolute path of the configured chuanqi recording folder ");
    READ_ONLY_PROPERTY(ChuanQiPaths, SetupDir,           IfStringValue, "Absolute path of the chuanqi setup folder ");

    STATIC_CONTEXT(ChuanQiExport, "#ChuanQi#Export", "Standard Export for ChuanQi");
    READ_WRITE_PROPERTY(ChuanQiExport, AutoExportDir,          IfStringValue, "Absolute path of the auto export data folder");
    READ_WRITE_PROPERTY(ChuanQiExport, AutoExport,             IfBooleanValue, "Enable/disable auto export");
}
}

#endif
