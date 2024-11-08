#include "command.h"
#include <QDebug>
Command::Command(QObject *command)
{

}
const QHash<QString, Command::CommandType> Command::commandHash = {
    { "*IDN?", IDN_QUERY},
    { "*VER?", VER_QUERY},
    { "*CLS", CLS},
    { "*ESE", ESE},
    { "*ESE?", ESE_QUERY},
    { "*OPC", OPC},
    { "*OPC?", OPC_QUERY},
    { "*RST", RST},
    { "*SRE", SRE},
    { "*SRE?", SRE_QUERY},
    { "*STB?", STB_QUERY},
    { "*TST?", TST_QUERY},
    { "*WAI?", WAI_QUERY},
    { ":SETUP:LOAD", SETUP_LOAD},
    { ":SETUP:APPLY", SETUP_APPLY},
    { ":SETUP:SAVE", SETUP_SAVE},
    { ":SETUP:READ?", SETUP_READ_QUERY},
    { ":SETUP:NAME?", SETUP_NAME_QUERY},
    { ":SETUP:ASYNC:LOAD", SETUP_ASYNC_LOAD},
    { ":SETUP:ASYNC:STATE?", SETUP_ASYNC_STATE},
    { ":SYSTEM:DATE?", SYSTEM_DATE_QUERY},
    { ":SYSTEM:KLOCK", SYSTEM_KLOCK},
    { ":SYSTEM:KLOCK?", SYSTEM_KLOCK_QUERY},
    { ":SYSTEM:TIME?", SYSTEM_TIME_QUERY},
    { ":SYSTEM:TZONE?", SYSTEM_TZONE_QUERY},
    { ":COMMUNICATE:HEADER", COMMUNICATE_HEADER},
    { ":COMMUNICATE:HEADER?", COMMUNICATE_HEADER_QUERY},
    { ":COMMUNICATE:VERBOSE", COMMUNICATE_VERBOSE},
    { ":COMMUNICATE:VERBOSE?", COMMUNICATE_VERBOSE_QUERY},
    { ":ACQUISITION:START", ACQUISITION_START},
    { ":ACQUISITION:STOP", ACQUISITION_STOP},
    { ":ACQUISITION:RESTART", ACQUISITION_RESTART},
    { ":ACQUISITION:STATE?", ACQUISITION_STATE_QUERY},
    { ":STORE:FILE:NAME", STORE_FILE_NAME},
    { ":STORE:FILE:NAME?", STORE_FILE_NAME_QUERY},
    { ":STORE:START", STORE_START},
    { ":STORE:PAUSE", STORE_PAUSE},
    { ":STORE:STOP", STORE_STOP},
    { ":STORE:STATE?", STORE_STATE_QUERY},
    { ":STORE:WAVEFORM:MODE?", STORE_WAVEFORM_MODE_QUERY},
    { ":STORE:WAVEFORM:MODE", STORE_WAVEFORM_MODE},
    { ":STORE:WAVEFORM:CONTINUOUS", STORE_WAVEFORM_CONTINUOUS},
    { ":STORE:WAVEFORM:EVENTBASED", STORE_WAVEFORM_EVENTBASED},
    { ":STORE:WAVEFORM:DISABLED", STORE_WAVEFORM_DISABLED},
    { ":STORE:WAVEFORM:PRETIME?", STORE_WAVEFORM_PRETIME},
    { ":STORE:WAVEFORM:PRETIME", STORE_WAVEFORM_PRETIME_QUERY},
    { ":STORE:WAVEFORM:PAFTER?", STORE_WAVEFORM_PAFTER_QUERY},
    { ":STORE:WAVEFORM:PAFTER", STORE_WAVEFORM_PAFTER},
    { ":STORE:WAVEFORM:POSTTIME?", STORE_WAVEFORM_POSTTIME_QUERY},
    { ":STORE:WAVEFORM:POSTTIME", STORE_WAVEFORM_POSTTIME},
    { ":STORE:STATISTICS?", STORE_STATISTICS_QUERY},
    { ":STORE:STATISTICS", STORE_STATISTICS},
    { ":STORE:AUTOSTART?", STORE_AUTOSTART_QUERY},
    { ":STORE:AUTOSTART", STORE_AUTOSTART},
    { ":STORE:RACQUISITION?", STORE_RACQUISITION_QUERY},
    { ":STORE:RACQUISITION", STORE_RACQUISITION},
    { ":STORE:SAFTER?", STORE_SAFTER_QUERY},
    { ":STORE:SAFTER", STORE_SAFTER},
    { ":STORE:ADVANCED?", STORE_ADVANCED_QUERY},
    { ":STORE:ADVANCED", STORE_ADVANCED},
    { ":CHANNELLIST:NAMES?", CHANNELLIST_NAMES_QUERY},
    { ":CHANNELLIST:IDS?", CHANNELLIST_IDS_QUERY},
    { ":CHANNELLIST:ITEM:ID:ATTR:NAMES?", CHANNELLIST_ITEM_ID_ATTR_NAMES_QUERY},
    { ":CHANNELLIST:ITEM:ID:ATTR:VAL?", CHANNELLIST_ITEM_ID_ATTR_VAL_QUERY},
    { ":CHANNELLIST:PROPERTY?", CHANNELLIST_PROPERTY_QUERY},
    { ":CHANNELLIST:PROPERTY", CHANNELLIST_PROPERTY},
    { ":CHANNELLIST:CONSTRAINT?", CHANNELLIST_CONSTRAINT_QUERY},
    { ":CHANNELLIST:ITEM:ID:ACTION:ZERO", CHANNELLIST_ITEM_ID_ACTION_ZERO},
    { ":CHANNELLIST:TIMING:HIGHEST", CHANNELLIST_TIMING_HIGHEST_QUERY},
    { ":CHANNELLIST:TIMING:LOWEST?", CHANNELLIST_TIMING_LOWEST_QUERY},
    { ":CHANNELLIST:SATURATION:VALUE?", CHANNELLIST_SATURATION_VALUE_QUERY},
    { ":CHANNELLIST:SATURATION:RESET", CHANNELLIST_SATURATION_RESET},
    { ":CHANNELLIST:FIRESPONSE?", CHANNELLIST_FIRESPONSE},
    { ":RATE", RATE},
    { ":RATE?", RATE_QUERY},
    { ":NUMERIC:NORMAL:ITEMS", NUMERIC_NORMAL_ITEMS},
    { ":NUMERIC:NORMAL:ITEMS?", NUMERIC_NORMAL_ITEMS_QUERY},
    { ":NUMERIC:NORMAL:ITEM<X>", NUMERIC_NORMAL_ITEMSX},
    { ":NUMERIC:NORMAL:ITEM<X>?", NUMERIC_NORMAL_ITEMSX_QUERY},
    { ":NUMERIC:NORMAL:CLEAR", NUMERIC_NORMAL_CLEAR},
    { ":NUMERIC:NORMAL:DELETE", NUMERIC_NORMAL_DELETE},
    { ":NUMERIC:NORMAL:NUMBER", NUMERIC_NORMAL_NUMBER},
    { ":NUMERIC:NORMAL:NUMBER?", NUMERIC_NORMAL_NUMBER_QUERY},
    { ":NUMERIC:NORMAL:DIM<X>", NUMERIC_NORMAL_DIMX},
    { ":NUMERIC:NORMAL:DIM<X>?", NUMERIC_NORMAL_DIMX_QUERY},
    { ":NUMERIC:NORMAL:DIMS?", NUMERIC_NORMAL_DIMS_QUERY},
    { ":NUMERIC:NORMAL:FORMAT", NUMERIC_NORMAL_FORMAT},
    { ":NUMERIC:NORMAL:FORMAT?", NUMERIC_NORMAL_FORMAT_QUERY},
    { ":NUMERIC:NORMAL:VALUE?", NUMERIC_NORMAL_VALUE_QUERY},
    { ":ELOG:ITEMS", ELOG_ITEMS},
    { ":ELOG:ITEMS?", ELOG_ITEMS_QUERY},
    { ":ELOG:PERIOD", ELOG_PERIOD},
    { ":ELOG:PERIOD?", ELOG_PERIOD_QUERY},
    { ":ELOG:CALCULATIONS", ELOG_CALCULATIONS},
    { ":ELOG:CALCULATIONS?", ELOG_CALCULATIONS_QUERY},
    { ":ELOG:FORM", ELOG_FORMAT},
    { ":ELOG:FORM?", ELOG_FORMAT_QUERY},
    { ":ELOG:TIMESTAMP", ELOG_TIMESTAMP},
    { ":ELOG:TIMESTAMP?", ELOG_TIMESTAMP_QUERY},
    { ":ELOG:SRART", ELOG_START},
    { ":ELOG:FETCH?", ELOG_FETCH_QUERY},
    { ":ELOG:STOP", ELOG_STOP},
    { ":ELOG:RESET", ELOG_RESET},
    { ":ELOG:STATE?", ELOG_STATE_QUERY},
    { ":DSTREAM:ITEMS<X>", DSTREAM_ITEMS},
    { ":DSTREAM:ITEMS<X>?", DSTREAM_ITEMS_QUERY},
    { ":DSTREAM:PORT<X>", DSTREAM_PORT},
    { ":DSTREAM:PORT<X>?", DSTREAM_PORT_QUERY},
    { ":DSTREAM:INIT", DSTREAM_INIT},
    { ":DSTREAM:START", DSTREAM_START},
    { ":DSTREAM:STOP", DSTREAM_STOP},
    { ":DSTREAM:DELETE", DSTREAM_DELETE},
    { ":DSTREAM:RESET", DSTREAM_RESET},
    { ":DSTREAM:STATE?", DSTREAM_STATE_QUERY},
    { ":DSTREAM:TRIG", DSTREAM_TRIG},
    { ":DSTREAM:TRIG?", DSTREAM_TRIG_QUERY},
    { ":EXPORT:DIRECTORY?", EXPORT_DIRCTORY},
    { ":EXPORT:DIRECTORY", EXPORT_DIRECTORY_PATH},
    { ":EXPORT:AUTO?", EXPORT_AUTO_QUERY},
    { ":EXPORT:AUTO", EXPORT_AUTO},
    { ":MARK:ADD", MARKER_ADD},
    { ":SYNC:STATE?", SYNC_STATE_QUERY},
    { ":SCREEN:INSTRUMENTS:OUTPUTCHANNEL:START", SCREEN_INSTRUMENTS_OUTPUTCHANNEL_START},
    { ":SCREEN:INSTRUMENTS:OUTPUTCHANNEL:PAUSE", SCREEN_INSTRUMENTS_OUTPUTCHANNEL_PAUSE},
    { ":SCREEN:INSTRUMENTS:OUTPUTCHANNEL:STOP", SCREEN_INSTRUMENTS_OUTPUTCHANNEL_STOP},
    { ":SCREEN:INSTRUMENTS:OUTPUTCHANNEL:STATE?", SCREEN_INSTRUMENTS_OUTPUTCHANNEL_STATE_QUERY},
    { ":SCREEN:SAVE", SCREEN_SAVE},
    { ":SCREEN:ITEM:SAVE", SCREEN_ITEM_SAVE},
    { ":REPORT:SAVE:ALL", REPORT_SAVE_ALL},
    { ":REPORT:ITEM:SAVE", REPORT_ITEM_SAVE},
    { ":HEADER:ADD", HEADER_ADD},
    { ":HEADER:GET?", HEADER_GET_QUERY},
    { ":HEADER:GET", HEADER_GET},
    { ":HEADER:KEYS?", HEADER_KEYS_QUERY},
    { ":HEADER:KEYS", HEADER_KEYS},
    { ":HEADER:SET?", HEADER_SET},
    { ":HEADER:DELETE", HEADER_DELETE},
    { ":HEADER:VALUES?", HEADER_VALUES_QUERY},
    { ":SYSTEM:VERSION?", SYSTEM_VERSION_QUERY},
    { ":SYSTEM:HELP:HEADERS?", SYSTEM_HELP_HEADERS_QUERY},
    { ":TRIGGER:GET?", TRIGGER_GET_QUERY},
    { ":TRIGGER:RESET", TRIGGER_RESET},
    { ":TRIGGER:ADDEVENT", TRIGGER_ADDEVENT},
    { ":TRIGGER:EVENT:SETUP?", TRIGGER_EVENT_SETUP_QUERY},
    { ":TRIGGER:EVENT:SETUP", TRIGGER_EVENT_SETUP},
    { ":TRIGGER:EVENT:VALID?", TRIGGER_EVENT_VALID_QUERY},
    { ":TRIGGER:EVENT:DELETE", TRIGGER_EVENT_DELETE},
    { ":TRIGGER:EVENT:ADDCONDITION", TRIGGER_EVENT_ADDCONDITION},
    { ":TRIGGER:EVENT:ADDACTION", TRIGGER_EVENT_ADDACTION},
    { ":TRIGGER:EVENT:CONDETION:GET?", TRIGGER_EVENT_CONDITION_GET_QUERY},
    { ":TRIGGER:EVENT:CONDETION:VALID?", TRIGGER_EVENT_CONDITION_VALID_QUERY},
    { ":TRIGGER:EVENT:CONDETION:DELETE", TRIGGER_EVENT_CONDITION_DELETE},
    { ":TRIGGER:EVENT:CONDETION:HIGHLEVEL:SETUP", TRIGGER_EVENT_CONDITION_HIGHLEVEL_SETUP},
    { ":TRIGGER:EVENT:CONDETION:LOWLEVEL:SETUP", TRIGGER_EVENT_CONDITION_LOWLEVEL_SETUP},
    { ":TRIGGER:EVENT:CONDETION:INWINDOW:SETUP", TRIGGER_EVENT_CONDITION_INWINDOW_SETUP},
    { ":TRIGGER:EVENT:CONDETION:OUTWINDOW:SETUP", TRIGGER_EVENT_CONDITION_OUTWINDOW_SETUP},
    { ":TRIGGER:EVENT:CONDETION:KEYBOARD:SETUP", TRIGGER_EVENT_CONDITION_KEYBOARD_SETUP},
    { ":TRIGGER:EVENT:CONDETION:TIME:SETUP", TRIGGER_EVENT_CONDITION_TIME_SETUP},
    { ":TRIGGER:EVENT:ACTION:GET?", TRIGGER_EVENT_ACTION_GET_QUERY},
    { ":TRIGGER:EVENT:ACTION:VALID?", TRIGGER_EVENT_ACTION_VALID_QUERY},
    { ":TRIGGER:EVENT:ACTION:RECORDING:SETUP", TRIGGER_EVENT_ACTION_RECORDING_SETUP},
    { ":TRIGGER:EVENT:ACTION:DIGOUT:SETUP", TRIGGER_EVENT_ACTION_DIGOUT_SETUP},
    { ":TRIGGER:EVENT:ACTION:ALARM:SETUPP", TRIGGER_EVENT_ACTION_ALARM_SETUP},
    { ":TRIGGER:EVENT:ACTION:MARKER:SETUP", TRIGGER_EVENT_ACTION_MARKER_SETUP},
    { ":TRIGGER:EVENT:ACTION:SNAPSHOT:SETUP", TRIGGER_EVENT_ACTION_SNAPSHOT_SETUP},
    { ":TRIGGER:EVENT:ACTION:ARM:SETUP", TRIGGER_EVENT_ACTION_ARM_SETUP},
    { ":ANALYSIS:ACTIVE?", ANALYSIS_ACTIVE_QUERY},
    { ":ANALYSIS:OPEN", ANALYSIS_OPEN},
    { ":ANALYSIS:CLOSE", ANALYSIS_CLOSE},
    { ":ANALYSIS:FILE?", ANALYSIS_FILES_QUERY},
    { ":SYSTEM:ERR?", SYSTEM_ERROR_QUERY},
    { ":SYSTEM:ERROR:ALL?", SYSTEM_ERROR_ALL_QUERY},
    { ":SYSTEM:ERROR:CODE:ALL?", SYSTEM_ERROR_CODE_ALL_QUERY},
    { ":SYSTEM:ERROR:COUNT?", SYSTEM_ERROR_COUNT_QUERY},
    { ":SYSTEM:ERROR:ENABLE:ADD?", SYSTEM_ERROR_ENABLE_ADD},
    { ":SYSTEM:ERROR:ENABLE:DELETE", SYSTEM_ERROR_ENABLE_DELETE},
    { ":SYSTEM:ERROR:ENABLE:LIST?", SYSTEM_ERROR_ENABLE_LIST_QUERY}
};
QString Command::execute(const QStringList &params)
{
    switch (type) {
    case IDN_QUERY: return handleIdnQuery();
    case VER_QUERY: return handleVerQuery();
    case CLS: return handleCls();
    case ESE: return handleEse(params);
    case ESE_QUERY: return handleEseQuery();
    case OPC: return handleOpc();
    case OPC_QUERY: return handleOpcQuery();
    case RST: return handleRst();
    case SRE: return handleSre(params);
    case SRE_QUERY: return handleSreQuery();
    case STB_QUERY: return handleStbQuery();
    case TST_QUERY: return handleTstQuery();
    case WAI_QUERY: return handleWaiQuery();
    case SETUP_LOAD: return handleSetupLoad(params);
    case SETUP_APPLY: return handleSetupApplyXmlString();
    case SETUP_SAVE: return handleSetupSavePath(params);
    case SETUP_READ_QUERY: return handleSetupReadQuery();
    case SETUP_NAME_QUERY: return handleSetupNameQuery();
    case SETUP_ASYNC_LOAD: return handleSetupAsyncLoadPath();
    case SETUP_ASYNC_STATE: return handleSetupAsyncStateQuery();
    case SYSTEM_DATE_QUERY: return handleSystemDateQuery();
    case SYSTEM_KLOCK: return handleSystemKlock();
    case SYSTEM_KLOCK_QUERY: return handleSystemKlockQuery();
    case SYSTEM_TIME_QUERY: return handleSystemTimeQuery();
    case SYSTEM_TZONE_QUERY: return handleSystemTzoneQuery();
    case COMMUNICATE_HEADER: return handleCommunicateHeader();
    case COMMUNICATE_HEADER_QUERY: return handleCommunicateHeaderQuery();
    case COMMUNICATE_VERBOSE: return handleCommunicateVerbose();
    case COMMUNICATE_VERBOSE_QUERY: return handleCommunicateVerboseQuery();
    case ACQUISITION_START: return handleAcquisitionStart();
    case ACQUISITION_STOP: return handleAcquisitionStop();
    case ACQUISITION_RESTART: return handleAcquisitionRestart();
    case ACQUISITION_STATE_QUERY: return handleAcquisitionStateQuery();
    case STORE_FILE_NAME: return handleStoreFileName();
    case STORE_FILE_NAME_QUERY: return handleStoreFileNameQuery();
    case STORE_START: return handleStoreStart();
    case STORE_PAUSE: return handleStorePause();
    case STORE_STOP: return handleStoreStop();
    case STORE_STATE_QUERY: return handleStoreStateQuery();
    case STORE_WAVEFORM_MODE_QUERY: return handleStoreWaveformModeQuery();
    case STORE_WAVEFORM_MODE: return handleStoreWaveformMode();
    case STORE_WAVEFORM_CONTINUOUS: return handleStoreWaveformContinuous();
    case STORE_WAVEFORM_DISABLED: return handleStoreWaveformDisabled();
    case STORE_WAVEFORM_EVENTBASED: return handleStoreWaveformEventbased();
    case STORE_WAVEFORM_PRETIME: return handleStoreWaveformPretime();
    case STORE_WAVEFORM_PRETIME_QUERY: return handleStoreWaveformPretimeQuery();
    case STORE_WAVEFORM_PAFTER: return handleStoreWaveformPafter();
    case STORE_WAVEFORM_PAFTER_QUERY: return handleStoreWaveformPafterQuery();
    case STORE_WAVEFORM_POSTTIME_QUERY: return handleStoreWaveformPosttimeQuery();
    case STORE_WAVEFORM_POSTTIME: return handleStoreWaveformPosttime();
    case STORE_STATISTICS_QUERY: return handleStoreStatisticsQuery();
    case STORE_STATISTICS: return handleStoreStatistics();
    case STORE_AUTOSTART_QUERY: return handleStoreAutoStartQuery();
    case STORE_AUTOSTART: return handleStoreAutoStart();
    case STORE_RACQUISITION_QUERY: return handleStoreRacQuisitionQuery();
    case STORE_RACQUISITION: return handleStoreRacQuisition();
    case STORE_SAFTER_QUERY: return handleStoreSafterQuery();
    case STORE_SAFTER: return handleStoreSafter();
    case STORE_ADVANCED_QUERY: return handleStoreAdvancedQuery();
    case STORE_ADVANCED: return handleStoreAdvanced();
    case CHANNELLIST_NAMES_QUERY: return handleChannellistNamesQuery();
    case CHANNELLIST_IDS_QUERY: return handleChannellistIdsQuery();
    case CHANNELLIST_ITEM_ID_ATTR_NAMES_QUERY: return handleChannellistItemIdAttrNamesQuery();
    case CHANNELLIST_ITEM_ID_ATTR_VAL_QUERY: return handleChannellistItemIdAttrValQuery();
    case CHANNELLIST_PROPERTY_QUERY: return handleChannellistPropertyQuery();
    case CHANNELLIST_PROPERTY: return handleChannellistProperty();
    case CHANNELLIST_CONSTRAINT_QUERY: return handleChannellistConstraintQuery();
    case CHANNELLIST_ITEM_ID_ACTION_ZERO: return handleChannellistItemIdActionZero();
    case CHANNELLIST_TIMING_HIGHEST_QUERY: return handleChannellistTimingHighestQuery();
    case CHANNELLIST_TIMING_LOWEST_QUERY: return handleChannellistTimingLowestQuery();
    case CHANNELLIST_SATURATION_VALUE_QUERY: return handleChannellistSaturationValueQuery();
    case CHANNELLIST_SATURATION_RESET: return handleChannellistSaturationReset();
    case CHANNELLIST_FIRESPONSE: return handleChannellistFiresponse();
    case RATE: return handleRate(params);
    case RATE_QUERY: return handleRateQuery();
    case NUMERIC_NORMAL_ITEMS: return handleNumericNormalItems();
    case NUMERIC_NORMAL_ITEMS_QUERY: return handleNumericNormalItemsQuery();
    case NUMERIC_NORMAL_ITEMSX: return handleNumericNormalItemsX();
    case NUMERIC_NORMAL_ITEMSX_QUERY: return handleNumericNormalItemsXQuery();
    case NUMERIC_NORMAL_CLEAR: return handleNumericNormalClear();
    case NUMERIC_NORMAL_DELETE: return handleNumericNormalDelete();
    case NUMERIC_NORMAL_NUMBER: return handleNumericNormalNumber();
    case NUMERIC_NORMAL_NUMBER_QUERY: return handleNumericNormalNumberQuery();
    case NUMERIC_NORMAL_DIMX: return handleNumericNormalDimx();
    case NUMERIC_NORMAL_DIMX_QUERY: return handleNumericNormalDimxQuery();
    case NUMERIC_NORMAL_DIMS_QUERY: return handleNumericNormalDimsQuery();
    case NUMERIC_NORMAL_FORMAT: return handleNumericNormalFormat();
    case NUMERIC_NORMAL_FORMAT_QUERY: return handleNumericNormalFormatQuery();
    case NUMERIC_NORMAL_VALUE_QUERY: return handleNumericNormalValueQuery();
    case ELOG_ITEMS: return handleElogItems();
    case ELOG_ITEMS_QUERY: return handleElogItemsQuery();
    case ELOG_PERIOD: return handleElogPeriod();
    case ELOG_PERIOD_QUERY: return handleElogPeriodQuery();
    case ELOG_CALCULATIONS: return handleElogCalculations();
    case ELOG_CALCULATIONS_QUERY: return handleElogCalculationsQuery();
    case ELOG_FORMAT: return handleElogFormat();
    case ELOG_FORMAT_QUERY: return handleElogFormatQuery();
    case ELOG_TIMESTAMP: return handleElogTimestamp();
    case ELOG_TIMESTAMP_QUERY: return handleElogTimestampQuery();
    case ELOG_START: return handleElogStart();
    case ELOG_FETCH_QUERY: return handleElogFetchQuery();
    case ELOG_STOP: return handleElogStop();
    case ELOG_RESET: return handleElogReset();
    case ELOG_STATE_QUERY: return handleElogStateQuery();
    case DSTREAM_ITEMS: return handleDstreamItems();
    case DSTREAM_ITEMS_QUERY: return handleDstreamItemsQuery();
    case DSTREAM_PORT: return handleDstreamPort();
    case DSTREAM_PORT_QUERY: return handleDstreamPortQuery();
    case DSTREAM_INIT: return handleDstreamInit();
    case DSTREAM_START: return handleDstreamStart();
    case DSTREAM_STOP: return handleDstreamStop();
    case DSTREAM_DELETE: return handleDstreamDelete();
    case DSTREAM_RESET: return handleDstreamReset();
    case DSTREAM_STATE_QUERY: return handleElogStateQuery();
    case DSTREAM_TRIG: return handleDstreamTrig();
    case DSTREAM_TRIG_QUERY: return handleDstreamTrigQuery();
    case EXPORT_DIRCTORY: return handleExportDirectory();
    case EXPORT_DIRECTORY_PATH: return handleExportDirectoryPath();
    case EXPORT_AUTO_QUERY: return handleExportAutoQuery();
    case EXPORT_AUTO: return handleExportAuto();
    case MARKER_ADD: return handleMarkerAdd();
    case SYNC_STATE_QUERY: return handleSyncStateQuery();
    case SCREEN_INSTRUMENTS_OUTPUTCHANNEL_START: return handleScreenInsterumentsOutputchannelStart();
    case SCREEN_INSTRUMENTS_OUTPUTCHANNEL_PAUSE: return handleScreenInsterumentsOutputchannelPause();
    case SCREEN_INSTRUMENTS_OUTPUTCHANNEL_STOP: return handleScreenInsterumentsOutputchannelStop();
    case SCREEN_INSTRUMENTS_OUTPUTCHANNEL_STATE_QUERY: return handleScreenInsterumentsOutputchannelStateQuery();
    case SCREEN_SAVE: return handleScreenSave();
    case SCREEN_ITEM_SAVE: return handleScreenItemSave();
    case REPORT_SAVE_ALL: return handleReportSave();
    case REPORT_ITEM_SAVE: return handleReportItemSave();
    case HEADER_ADD: return handleheaderAdd();
    case HEADER_GET_QUERY: return handleheaderAdd();
    case HEADER_KEYS_QUERY: return handleheaderKeysQuery();
    case HEADER_SET: return handleheaderSet();
    case HEADER_DELETE: return handleheaderDelete();
    case HEADER_VALUES_QUERY: return handleheaderValuesQuery();
    case SYSTEM_VERSION_QUERY: return handleSystemVersionQuery();
    case SYSTEM_HELP_HEADERS_QUERY: return handleSystemHelpHeadersQuery();
    case TRIGGER_GET_QUERY: return handleTriggerGetQuery();
    case TRIGGER_RESET: return handleTriggerReset();
    case TRIGGER_ADDEVENT: return handleTriggerAddevent();
    case TRIGGER_EVENT_SETUP_QUERY: return handleTriggerEventSetupQuery();
    case TRIGGER_EVENT_SETUP: return handleTriggerEventSetup();
    case TRIGGER_EVENT_VALID_QUERY: return handleTriggerEventValidQuery();
    case TRIGGER_EVENT_DELETE: return handleTriggerEventDelete();
    case TRIGGER_EVENT_ADDCONDITION: return handleTriggerEventAddCondition();
    case TRIGGER_EVENT_ADDACTION: return handleTriggerEventAddAction();
    case TRIGGER_EVENT_CONDITION_GET_QUERY: return handleTriggerEventConditionGetQuery();
    case TRIGGER_EVENT_CONDITION_VALID_QUERY: return handleTriggerEventConditionValidQuery();
    case TRIGGER_EVENT_CONDITION_DELETE: return handleTriggerEventConditionDelete();
    case TRIGGER_EVENT_CONDITION_HIGHLEVEL_SETUP: return handleTriggerEventConditionHighlevelSetup();
    case TRIGGER_EVENT_CONDITION_LOWLEVEL_SETUP: return handleTriggerEventConditionLowlevelSetup();
    case TRIGGER_EVENT_CONDITION_INWINDOW_SETUP: return handleTriggerEventConditionInwindowSetup();
    case TRIGGER_EVENT_CONDITION_OUTWINDOW_SETUP: return handleTriggerEventConditionOutwindowSetup();
    case TRIGGER_EVENT_CONDITION_KEYBOARD_SETUP: return handleTriggerEventConditionKeyboardSetup();
    case TRIGGER_EVENT_CONDITION_TIME_SETUP: return handleTriggerEventConditionTimeSetup();
    case TRIGGER_EVENT_ACTION_GET_QUERY: return handleTriggerEventActionGetQuery();
    case TRIGGER_EVENT_ACTION_VALID_QUERY: return handleTriggerEventActionValidQuery();
    case TRIGGER_EVENT_ACTION_RECORDING_SETUP: return handleTriggerEventActionRecordingSetup();
    case TRIGGER_EVENT_ACTION_DIGOUT_SETUP: return handleTriggerEventActionDigoutSetup();
    case TRIGGER_EVENT_ACTION_ALARM_SETUP: return handleTriggerEventActionAlarmSetup();
    case TRIGGER_EVENT_ACTION_MARKER_SETUP: return handleTriggerEventActionMarkerSetup();
    case TRIGGER_EVENT_ACTION_SNAPSHOT_SETUP: return handleTriggerEventActionSnapshotSetup();
    case TRIGGER_EVENT_ACTION_ARM_SETUP: return handleTriggerEventActionArmSetup();
    case ANALYSIS_ACTIVE_QUERY: return handleAnalysisActiveQuery();
    case ANALYSIS_OPEN: return handleAnalysisOpen();
    case ANALYSIS_CLOSE: return handleAnalysisClose();
    case ANALYSIS_FILES_QUERY: return handleAnalysisFileQuery();
    case SYSTEM_ERROR_QUERY: return handleSystemErrorQuery();
    case SYSTEM_ERROR_ALL_QUERY: return handleSystemErrorAllQuery();
    case SYSTEM_ERROR_CODE_ALL_QUERY: return handleSystemErrorCodeAllQuery();
    case SYSTEM_ERROR_COUNT_QUERY: return handleSystemErrorCountQuery();
    case SYSTEM_ERROR_ENABLE_ADD: return handleSystemErrorEnableAdd();
    case SYSTEM_ERROR_ENABLE_DELETE: return handleSystemErrorEnableDelete();
    case SYSTEM_ERROR_ENABLE_LIST_QUERY: return handleSystemErrorEnableListQuery();
    default: return "Unknown Command";
    }
}

void Command::getCommand(const QString &command)
{
    type=commandHash.value(command, UNKNOWN_COMMAND);
}

/**
 * @brief DeviceHandler::handleIdn
 * @return
 */
QString Command::handleIdnQuery()
{
    return "*IDN DEWETRON,OXYGEN,00000001,6.7.3\n";
}
/**
 * @brief DeviceHandler::handleVer
 * @return
 */
QString Command::handleVerQuery()
{
    return "VER SCPI,\"1999.0\",RC_SCPI,\"1.21\",OXYGEN,\"6.7.3\"\n";
}
/**
 * @brief DeviceHandler::handleCls
 * @return
 */
QString Command::handleCls()
{
    return "";
}
/**
 * @brief DeviceHandler::handleEse
 * @return
 */
QString Command::handleEse(const QStringList &params)
{
    eseResult=params.at(0);
    return "";
}
/**
 * @brief DeviceHandler::handleEseQuery
 * @return
 */
QString Command::handleEseQuery()
{
    return eseResult+"\n";
}
/**
 * @brief DeviceHandler::handleOpc
 * @return
 */
QString Command::handleOpc()
{
    return "";
}
/**
 * @brief DeviceHandler::handleOpcQuery
 * @return
 */
QString Command::handleOpcQuery()
{
    return "1\n";
}
/**
 * @brief DeviceHandler::handleRst
 * @return
 */
QString Command::handleRst()
{
    return "*RST\n";
}
/**
 * @brief DeviceHandler::handleSre
 * @return
 */
QString Command::handleSre(const QStringList &params)
{
    sreResult=params.at(0);
    return "";
}
/**
 * @brief DeviceHandler::handleSreQuery
 * @return
 */
QString Command::handleSreQuery()
{
    return sreResult+"\n";
}
/**
 * @brief DeviceHandler::handleStbQuery
 * @return
 */
QString Command::handleStbQuery()
{
    return "4\n";
}
/**
 * @brief DeviceHandler::handleTstQuery
 * @return
 */
QString Command::handleTstQuery()
{
    return "0\n";
}
/**
 * @brief DeviceHandler::handleWaiQuery
 * @return
 */
QString Command::handleWaiQuery()
{
    return "";
}
/**
 * @brief DeviceHandler::handleSetupLoad
 * @return
 */
QString Command::handleSetupLoad(const QStringList &params)
{
    setupLoadPathResult=params.at(0);
    return "";
}
/**
 * @brief DeviceHandler::handleSetupApplyXmlString
 * @return
 */
QString Command::handleSetupApplyXmlString()
{
    return "";
}
/**
 * @brief DeviceHandler::handleSetupSavePath
 * @return
 */
QString Command::handleSetupSavePath(const QStringList &params)
{
    return ":SETUP:SAVE PATH\n";
}
/**
 * @brief DeviceHandler::handleSetupEeadQuery
 * @return
 */
QString Command::handleSetupReadQuery()
{
    return ":SETUP:READ\n";
}
/**
 * @brief DeviceHandler::handleSetupNameQuery
 * @return
 */
QString Command::handleSetupNameQuery()
{
    return ":SETUP:NAME?\n";
}
/**
 * @brief DeviceHandler::handleSetupAsyncLoadPath
 * @return
 */
QString Command::handleSetupAsyncLoadPath()
{
    return ":SETUP:ASYNC:LOAD:PATH\n";
}
/**
 * @brief DeviceHandler::handleSetupAsyncStateQuery
 * @return
 */
QString Command::handleSetupAsyncStateQuery()
{
    return ":SETUP:ASYNC:STATE?\n";
}
/**
 * @brief Command::handleSystemDateQuery
 * @return
 */
QString Command::handleSystemDateQuery()
{
    return ":SYSTEM:DATA?\n";
}
/**
 * @brief Command::handleSystemKlock
 * @return
 */
QString Command::handleSystemKlock()
{
    return ":SYSTEM:KLOCK\n";
}
/**
 * @brief Command::handleSystemKlockQuery
 * @return
 */
QString Command::handleSystemKlockQuery()
{
    return ":SYSTEM:KLOCK？\n";
}
/**
 * @brief Command::handleSystemTimeQuery
 * @return
 */
QString Command::handleSystemTimeQuery()
{
    return ":SYSTEM:TIME?\n";
}
/**
 * @brief Command::handleSystemTzoneQuery
 * @return
 */
QString Command::handleSystemTzoneQuery()
{
    return ":SYSTEM:TZONE?\n";
}
/**
 * @brief Command::handleCommunicateHeader
 * @return
 */
QString Command::handleCommunicateHeader()
{
    return ":COMMUNICATE:HRADER\n";
}
/**
 * @brief Command::handleCommunicateHeaderQuery
 * @return
 */
QString Command::handleCommunicateHeaderQuery()
{
    return ":COMMUNICATE:HRADER?\n";
}
/**
 * @brief Command::handleCommunicateVerbose
 * @return
 */
QString Command::handleCommunicateVerbose()
{
    return ":COMMUNICATE:VERBOSE";
}
/**
 * @brief Command::handleCommunicateVerboseQuery
 * @return
 */
QString Command::handleCommunicateVerboseQuery()
{
    return ":COMMUNICATE:VERBOSE?";
}
/**
 * @brief DeviceHandler::handleAcquisitionStart
 * @return
 */
QString Command::handleAcquisitionStart()
{
    return ":ACQUISITION:START";
}
/**
 * @brief DeviceHandler::handleAcquisitionStop
 * @return
 */
QString Command::handleAcquisitionStop()
{
    return ":ACQUISITION:STOP";
}
/**
 * @brief DeviceHandler::handleAcquisitionRestart
 * @return
 */
QString Command::handleAcquisitionRestart()
{
    return ":ACQUISITION:RESTART";
}
/**
 * @brief DeviceHandler::handleAcquisitionStateQuery
 * @return
 */
QString Command::handleAcquisitionStateQuery()
{
    return ":ACQUISITION:STATE";
}
/**
 * @brief DeviceHandler::handleStoreFileName
 * @return
 */
QString Command::handleStoreFileName()
{
    return ":STORe:FILE:NAME\n";
}
/**
 * @brief DeviceHandler::handleStoreFileNameQuery
 * @return
 */
QString Command::handleStoreFileNameQuery()
{
    return "STORE:FILE:NAME?";
}
/**
 * @brief Command::handleStoreStart
 * @return
 */
QString Command::handleStoreStart()
{
    return "STORE:START?";
}
/**
 * @brief Command::handleStorePause
 * @return
 */
QString Command::handleStorePause()
{
    return "STORE:PAUSE?";
}
/**
 * @brief Command::handleStoreStop
 * @return
 */
QString Command::handleStoreStop()
{
    return "STORE:STOP?";
}
/**
 * @brief Command::handleStoreStateQuery
 * @return
 */
QString Command::handleStoreStateQuery()
{
    return "STORE:STATE?";
}
/**
 * @brief Command::handleStoreWaveformModeQuery
 * @return
 */
QString Command::handleStoreWaveformModeQuery()
{
    return "STORE:WAVEFORM:MODE?";
}
/**
 * @brief Command::handleStoreWaveformMode
 * @return
 */
QString Command::handleStoreWaveformMode()
{
    return "STORE:WAVEFORM:MODE";
}
/**
 * @brief Command::handleStoreWaveformContinuous
 * @return
 */
QString Command::handleStoreWaveformContinuous()
{
    return "";
}
/**
 * @brief Command::handleStoreWaveformEventbased
 * @return
 */
QString Command::handleStoreWaveformEventbased()
{
    return "";
}
/**
 * @brief Command::handleStoreWaveformDisabled
 * @return
 */
QString Command::handleStoreWaveformDisabled()
{
    return "";
}
/**
 * @brief Command::handleStoreWaveformPretime
 * @return
 */
QString Command::handleStoreWaveformPretime()
{
    return "";
}

QString Command::handleStoreWaveformPretimeQuery()
{
    return "";
}
/**
 * @brief Command::handleStoreWaveformPafter
 * @return
 */
QString Command::handleStoreWaveformPafter()
{
    return "";
}
/**
 * @brief Command::handleStoreWaveformPafterQuery
 * @return
 */
QString Command::handleStoreWaveformPafterQuery()
{
    return "";
}
/**
 * @brief Command::handleStoreWaveformPosttimeQuery
 * @return
 */
QString Command::handleStoreWaveformPosttimeQuery()
{
    return "";
}
/**
 * @brief Command::handleStoreWaveformPosttime
 * @return
 */
QString Command::handleStoreWaveformPosttime()
{
    return "";
}
/**
 * @brief Command::handleStoreStatisticsQuery
 * @return
 */
QString Command::handleStoreStatisticsQuery()
{
    return "";
}
/**
 * @brief Command::handleStoreStatistics
 * @return
 */
QString Command::handleStoreStatistics()
{
    return "";
}
/**
 * @brief Command::handleStoreAutoStartQuery
 * @return
 */
QString Command::handleStoreAutoStartQuery()
{
    return "";
}
/**
 * @brief Command::handleStoreAutoStart
 * @return
 */
QString Command::handleStoreAutoStart()
{
    return "";
}
/**
 * @brief Command::handleStoreRacQuisitionQuery
 * @return
 */
QString Command::handleStoreRacQuisitionQuery()
{
    return "";
}
/**
 * @brief Command::handleStoreRacQuisition
 * @return
 */
QString Command::handleStoreRacQuisition()
{
    return "";
}
/**
 * @brief Command::handleStoreSafterQuery
 * @return
 */
QString Command::handleStoreSafterQuery()
{
    return "";
}
/**
 * @brief Command::handleStoreSafter
 * @return
 */
QString Command::handleStoreSafter()
{
    return "";
}
/**
 * @brief Command::handleStoreAdvancedQuery
 * @return
 */
QString Command::handleStoreAdvancedQuery()
{
    return "";
}
/**
 * @brief Command::handleStoreAdvanced
 * @return
 */
QString Command::handleStoreAdvanced()
{
    return "";
}
/**
 * @brief Command::handleChannellistNamesQuery
 * @return
 */
QString Command::handleChannellistNamesQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistIdsQuery
 * @return
 */
QString Command::handleChannellistIdsQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistItemIdAttrNamesQuery
 * @return
 */
QString Command::handleChannellistItemIdAttrNamesQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistItemIdAttrValQuery
 * @return
 */
QString Command::handleChannellistItemIdAttrValQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistPropertyQuery
 * @return
 */
QString Command::handleChannellistPropertyQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistProperty
 * @return
 */
QString Command::handleChannellistProperty()
{
    return "";
}
/**
 * @brief Command::handleChannellistConstraintQuery
 * @return
 */
QString Command::handleChannellistConstraintQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistItemIdActionZero
 * @return
 */
QString Command::handleChannellistItemIdActionZero()
{
    return "";
}
/**
 * @brief Command::handleChannellistActionZero
 * @return
 */
QString Command::handleChannellistActionZero()
{
    return "";
}
/**
 * @brief Command::handleChannellistTimingHighestQuery
 * @return
 */
QString Command::handleChannellistTimingHighestQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistTimingLowestQuery
 * @return
 */
QString Command::handleChannellistTimingLowestQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistSaturationValueQuery
 * @return
 */
QString Command::handleChannellistSaturationValueQuery()
{
    return "";
}
/**
 * @brief Command::handleChannellistSaturationReset
 * @return
 */
QString Command::handleChannellistSaturationReset()
{
    return "";
}
/**
 * @brief Command::handleChannellistFiresponse
 * @return
 */
QString Command::handleChannellistFiresponse()
{
    return "";
}
/**
 * @brief Command::handleRate
 * @return
 */
QString Command::handleRate(const QStringList &params)
{
    qDebug()<<params.at(0);
    return params.at(0);
}
/**
 * @brief Command::handleRateQuery
 * @return
 */
QString Command::handleRateQuery()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalItems
 * @return
 */
QString Command::handleNumericNormalItems()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalItemsQuery
 * @return
 */
QString Command::handleNumericNormalItemsQuery()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalItemsX
 * @return
 */
QString Command::handleNumericNormalItemsX()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalItemsXQuery
 * @return
 */
QString Command::handleNumericNormalItemsXQuery()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalClear
 * @return
 */
QString Command::handleNumericNormalClear()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalDelete
 * @return
 */
QString Command::handleNumericNormalDelete()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalNumber
 * @return
 */
QString Command::handleNumericNormalNumber()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalNumberQuery
 * @return
 */
QString Command::handleNumericNormalNumberQuery()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalDimx
 * @return
 */
QString Command::handleNumericNormalDimx()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalDimxQuery
 * @return
 */
QString Command::handleNumericNormalDimxQuery()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalDimsQuery
 * @return
 */
QString Command::handleNumericNormalDimsQuery()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalFormat
 * @return
 */
QString Command::handleNumericNormalFormat()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalFormatQuery
 * @return
 */
QString Command::handleNumericNormalFormatQuery()
{
    return "";
}
/**
 * @brief Command::handleNumericNormalValueQuery
 * @return
 */
QString Command::handleNumericNormalValueQuery()
{
    return "";
}
/**
 * @brief Command::handleElogItems
 * @return
 */
QString Command::handleElogItems()
{
    return "";
}
/**
 * @brief Command::handleElogItemsQuery
 * @return
 */
QString Command::handleElogItemsQuery()
{
    return "";
}
/**
 * @brief Command::handleElogPeriod
 * @return
 */
QString Command::handleElogPeriod()
{
    return "";
}
/**
 * @brief Command::handleElogPeriodQuery
 * @return
 */
QString Command::handleElogPeriodQuery()
{
    return "";
}
/**
 * @brief Command::handleElogCalculations
 * @return
 */
QString Command::handleElogCalculations()
{
    return "";
}
/**
 * @brief Command::handleElogCalculationsQuery
 * @return
 */
QString Command::handleElogCalculationsQuery()
{
    return "";
}
/**
 * @brief Command::handleElogFormat
 * @return
 */
QString Command::handleElogFormat()
{
    return "";
}
/**
 * @brief Command::handleElogFormatQuery
 * @return
 */
QString Command::handleElogFormatQuery()
{
    return "";
}
/**
 * @brief Command::handleElogTimestamp
 * @return
 */
QString Command::handleElogTimestamp()
{
    return "";
}
/**
 * @brief Command::handleElogTimestampQuery
 * @return
 */
QString Command::handleElogTimestampQuery()
{
    return "";
}
/**
 * @brief Command::handleElogStart
 * @return
 */
QString Command::handleElogStart()
{
    return "";
}
/**
 * @brief Command::handleElogFetchQuery
 * @return
 */
QString Command::handleElogFetchQuery()
{
    return "";
}
/**
 * @brief Command::handleElogStop
 * @return
 */
QString Command::handleElogStop()
{
    return "";
}
/**
 * @brief Command::handleElogReset
 * @return
 */
QString Command::handleElogReset()
{
    return "";
}
/**
 * @brief Command::handleElogStateQuery
 * @return
 */
QString Command::handleElogStateQuery()
{
    return "";
}
/**
 * @brief Command::handleDstreamItems
 * @return
 */
QString Command::handleDstreamItems()
{
    return "";
}
/**
 * @brief Command::handleDstreamItemsQuery
 * @return
 */
QString Command::handleDstreamItemsQuery()
{
    return "";
}
/**
 * @brief Command::handleDstreamPort
 * @return
 */
QString Command::handleDstreamPort()
{
    return "";
}
/**
 * @brief Command::handleDstreamPortQuery
 * @return
 */
QString Command::handleDstreamPortQuery()
{
    return "";
}
/**
 * @brief Command::handleDstreamInit
 * @return
 */
QString Command::handleDstreamInit()
{
    return "";
}
/**
 * @brief Command::handleDstreamStart
 * @return
 */
QString Command::handleDstreamStart()
{
    return "";
}
/**
 * @brief Command::handleDstreamStop
 * @return
 */
QString Command::handleDstreamStop()
{
    return "";
}
/**
 * @brief Command::handleDstreamDelete
 * @return
 */
QString Command::handleDstreamDelete()
{
    return "";
}
/**
 * @brief Command::handleDstreamReset
 * @return
 */
QString Command::handleDstreamReset()
{
    return "";
}
/**
 * @brief Command::handleDstreamStateQuery
 * @return
 */
QString Command::handleDstreamStateQuery()
{
    return "";
}
/**
 * @brief Command::handleDstreamTrig
 * @return
 */
QString Command::handleDstreamTrig()
{
    return "";
}
/**
 * @brief Command::handleDstreamTrigQuery
 * @return
 */
QString Command::handleDstreamTrigQuery()
{
    return "";
}
/**
 * @brief Command::handleExportDirectory
 * @return
 */
QString Command::handleExportDirectory()
{
    return "";
}
/**
 * @brief Command::handleExportDirectoryPath
 * @return
 */
QString Command::handleExportDirectoryPath()
{
    return "";
}
/**
 * @brief Command::handleExportAutoQuery
 * @return
 */
QString Command::handleExportAutoQuery()
{
    return "";
}
/**
 * @brief Command::handleExportAuto
 * @return
 */
QString Command::handleExportAuto()
{
    return "";
}
/**
 * @brief Command::handleMarkerAdd
 * @return
 */
QString Command::handleMarkerAdd()
{
    return "";
}
/**
 * @brief Command::handleSyncStateQuery
 * @return
 */
QString Command::handleSyncStateQuery()
{
    return "";
}
/**
 * @brief Command::handleScreenInsterumentsOutputchannelStart
 * @return
 */
QString Command::handleScreenInsterumentsOutputchannelStart()
{
    return "";
}
/**
 * @brief Command::handleScreenInsterumentsOutputchannelPause
 * @return
 */
QString Command::handleScreenInsterumentsOutputchannelPause()
{
    return "";
}
/**
 * @brief Command::handleScreenInsterumentsOutputchannelStop
 * @return
 */
QString Command::handleScreenInsterumentsOutputchannelStop()
{
    return "";
}
/**
 * @brief Command::handleScreenInsterumentsOutputchannelStateQuery
 * @return
 */
QString Command::handleScreenInsterumentsOutputchannelStateQuery()
{
    return "";
}
/**
 * @brief Command::handleScreenSave
 * @return
 */
QString Command::handleScreenSave()
{
    return "";
}
/**
 * @brief Command::handleScreenItemSave
 * @return
 */
QString Command::handleScreenItemSave()
{
    return "";
}
/**
 * @brief Command::handleReportSave
 * @return
 */
QString Command::handleReportSave()
{
    return "";
}
/**
 * @brief Command::handleReportItemSave
 * @return
 */
QString Command::handleReportItemSave()
{
    return "";
}
/**
 * @brief Command::handleheaderAdd
 * @return
 */
QString Command::handleheaderAdd()
{
    return "";
}
/**
 * @brief Command::handleheaderGetQuery
 * @return
 */
QString Command::handleheaderGetQuery()
{
    return "";
}
/**
 * @brief Command::handleheaderKeysQuery
 * @return
 */
QString Command::handleheaderKeysQuery()
{
    return "";
}
/**
 * @brief Command::handleheaderSet
 * @return
 */
QString Command::handleheaderSet()
{
    return "";
}
/**
 * @brief Command::handleheaderDelete
 * @return
 */
QString Command::handleheaderDelete()
{
    return "";
}
/**
 * @brief Command::handleheaderValuesQuery
 * @return
 */
QString Command::handleheaderValuesQuery()
{
    return "";
}
/**
 * @brief Command::handleSystemVersionQuery
 * @return
 */
QString Command::handleSystemVersionQuery()
{
    return "";
}
/**
 * @brief Command::handleSystemHelpHeadersQuery
 * @return
 */
QString Command::handleSystemHelpHeadersQuery()
{
    return "";
}
/**
 * @brief Command::handleTriggerGetQuery
 * @return
 */
QString Command::handleTriggerGetQuery()
{
    return "";
}
/**
 * @brief Command::handleTriggerReset
 * @return
 */
QString Command::handleTriggerReset()
{
    return "";
}
/**
 * @brief Command::handleTriggerAddevent
 * @return
 */
QString Command::handleTriggerAddevent()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventSetupQuery
 * @return
 */
QString Command::handleTriggerEventSetupQuery()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventSetup
 * @return
 */
QString Command::handleTriggerEventSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventValidQuery
 * @return
 */
QString Command::handleTriggerEventValidQuery()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventDelete
 * @return
 */
QString Command::handleTriggerEventDelete()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventAddCondition
 * @return
 */
QString Command::handleTriggerEventAddCondition()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventAddAction
 * @return
 */
QString Command::handleTriggerEventAddAction()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionGetQuery
 * @return
 */
QString Command::handleTriggerEventConditionGetQuery()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionValidQuery
 * @return
 */
QString Command::handleTriggerEventConditionValidQuery()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionDelete
 * @return
 */
QString Command::handleTriggerEventConditionDelete()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionHighlevelSetup
 * @return
 */
QString Command::handleTriggerEventConditionHighlevelSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionLowlevelSetup
 * @return
 */
QString Command::handleTriggerEventConditionLowlevelSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionInwindowSetup
 * @return
 */
QString Command::handleTriggerEventConditionInwindowSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionOutwindowSetup
 * @return
 */
QString Command::handleTriggerEventConditionOutwindowSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionKeyboardSetup
 * @return
 */
QString Command::handleTriggerEventConditionKeyboardSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventConditionTimeSetup
 * @return
 */
QString Command::handleTriggerEventConditionTimeSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionGetQuery
 * @return
 */
QString Command::handleTriggerEventActionGetQuery()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionValidQuery
 * @return
 */
QString Command::handleTriggerEventActionValidQuery()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionDelete
 * @return
 */
QString Command::handleTriggerEventActionDelete()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionRecordingSetup
 * @return
 */
QString Command::handleTriggerEventActionRecordingSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionDigoutSetup
 * @return
 */
QString Command::handleTriggerEventActionDigoutSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionAlarmSetup
 * @return
 */
QString Command::handleTriggerEventActionAlarmSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionMarkerSetup
 * @return
 */
QString Command::handleTriggerEventActionMarkerSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionSnapshotSetup
 * @return
 */
QString Command::handleTriggerEventActionSnapshotSetup()
{
    return "";
}
/**
 * @brief Command::handleTriggerEventActionArmSetup
 * @return
 */
QString Command::handleTriggerEventActionArmSetup()
{
    return "";
}
/**
 * @brief Command::handleAnalysisActiveQuery
 * @return
 */
QString Command::handleAnalysisActiveQuery()
{
    return "";
}
/**
 * @brief Command::handleAnalysisOpen
 * @return
 */
QString Command::handleAnalysisOpen()
{
    return "";
}
/**
 * @brief Command::handleAnalysisClose
 * @return
 */
QString Command::handleAnalysisClose()
{
    return "";
}
/**
 * @brief Command::handleAnalysisFileQuery
 * @return
 */
QString Command::handleAnalysisFileQuery()
{
    return "";
}
/**
 * @brief Command::handleSystemErrorQuery
 * @return
 */
QString Command::handleSystemErrorQuery()
{
    return "";
}
/**
 * @brief Command::handleSystemErrorAllQuery
 * @return
 */
QString Command::handleSystemErrorAllQuery()
{
    return "";
}
/**
 * @brief Command::handleSystemErrorCodeQuery
 * @return
 */
QString Command::handleSystemErrorCodeQuery()
{
    return "";
}
/**
 * @brief Command::handleSystemErrorCodeAllQuery
 * @return
 */
QString Command::handleSystemErrorCodeAllQuery()
{
    return "";
}
/**
 * @brief Command::handleSystemErrorCountQuery
 * @return
 */
QString Command::handleSystemErrorCountQuery()
{
    return "";
}
/**
 * @brief Command::handleSystemErrorEnableAdd
 * @return
 */
QString Command::handleSystemErrorEnableAdd()
{
    return "";
}
/**
 * @brief Command::handleSystemErrorEnableDelete
 * @return
 */
QString Command::handleSystemErrorEnableDelete()
{
    return "";
}
/**
 * @brief Command::handleSystemErrorEnableListQuery
 * @return
 */
QString Command::handleSystemErrorEnableListQuery()
{
    return "";
}



