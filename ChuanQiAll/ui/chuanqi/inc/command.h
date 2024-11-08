#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>

class Command : public QObject
{
    Q_OBJECT
public:
    explicit Command(QObject *parent = nullptr);
    enum CommandType{
        IDN_QUERY,
        VER_QUERY,
        CLS,
        ESE,
        ESE_QUERY,
        OPC,
        OPC_QUERY,
        RST,
        SRE,
        SRE_QUERY,
        STB_QUERY,
        TST_QUERY,
        WAI_QUERY,
        SETUP_LOAD,
        SETUP_APPLY,
        SETUP_SAVE,
        SETUP_READ_QUERY,
        SETUP_NAME_QUERY,
        SETUP_ASYNC_LOAD,
        SETUP_ASYNC_STATE,
        SYSTEM_DATE_QUERY,
        SYSTEM_KLOCK,
        SYSTEM_KLOCK_QUERY,
        SYSTEM_TIME_QUERY,
        SYSTEM_TZONE_QUERY,
        COMMUNICATE_HEADER,
        COMMUNICATE_HEADER_QUERY,
        COMMUNICATE_VERBOSE,
        COMMUNICATE_VERBOSE_QUERY,
        ACQUISITION_START,
        ACQUISITION_STOP,
        ACQUISITION_RESTART,
        ACQUISITION_STATE_QUERY,
        STORE_FILE_NAME,
        STORE_FILE_NAME_QUERY,
        STORE_START,
        STORE_PAUSE,
        STORE_STOP,
        STORE_STATE_QUERY,
        STORE_WAVEFORM_MODE_QUERY,
        STORE_WAVEFORM_MODE,
        STORE_WAVEFORM_CONTINUOUS,
        STORE_WAVEFORM_EVENTBASED,
        STORE_WAVEFORM_DISABLED,
        STORE_WAVEFORM_PRETIME,
        STORE_WAVEFORM_PRETIME_QUERY,
        STORE_WAVEFORM_PAFTER_QUERY,
        STORE_WAVEFORM_PAFTER,
        STORE_WAVEFORM_POSTTIME_QUERY,
        STORE_WAVEFORM_POSTTIME,
        STORE_STATISTICS_QUERY,
        STORE_STATISTICS,
        STORE_AUTOSTART_QUERY,
        STORE_AUTOSTART,
        STORE_RACQUISITION_QUERY,
        STORE_RACQUISITION,
        STORE_SAFTER_QUERY,
        STORE_SAFTER,
        STORE_ADVANCED_QUERY,
        STORE_ADVANCED,
        CHANNELLIST_NAMES_QUERY,
        CHANNELLIST_IDS_QUERY,
        CHANNELLIST_ITEM_ID_ATTR_NAMES_QUERY,
        CHANNELLIST_ITEM_ID_ATTR_VAL_QUERY,
        CHANNELLIST_PROPERTY_QUERY,
        CHANNELLIST_PROPERTY,
        CHANNELLIST_CONSTRAINT_QUERY,
        CHANNELLIST_ITEM_ID_ACTION_ZERO,
        CHANNELLIST_TIMING_HIGHEST_QUERY,
        CHANNELLIST_TIMING_LOWEST_QUERY,
        CHANNELLIST_SATURATION_VALUE_QUERY,
        CHANNELLIST_SATURATION_RESET,
        CHANNELLIST_FIRESPONSE,
        RATE,
        RATE_QUERY,
        NUMERIC_NORMAL_ITEMS,
        NUMERIC_NORMAL_ITEMS_QUERY,
        NUMERIC_NORMAL_ITEMSX,
        NUMERIC_NORMAL_ITEMSX_QUERY,
        NUMERIC_NORMAL_CLEAR,
        NUMERIC_NORMAL_DELETE,
        NUMERIC_NORMAL_NUMBER,
        NUMERIC_NORMAL_NUMBER_QUERY,
        NUMERIC_NORMAL_DIMX,
        NUMERIC_NORMAL_DIMX_QUERY,
        NUMERIC_NORMAL_DIMS_QUERY,
        NUMERIC_NORMAL_FORMAT,
        NUMERIC_NORMAL_FORMAT_QUERY,
        NUMERIC_NORMAL_VALUE_QUERY,
        ELOG_ITEMS,
        ELOG_ITEMS_QUERY,
        ELOG_PERIOD,
        ELOG_PERIOD_QUERY,
        ELOG_CALCULATIONS,
        ELOG_CALCULATIONS_QUERY,
        ELOG_FORMAT,
        ELOG_FORMAT_QUERY,
        ELOG_TIMESTAMP,
        ELOG_TIMESTAMP_QUERY,
        ELOG_START,
        ELOG_FETCH_QUERY,
        ELOG_STOP,
        ELOG_RESET,
        ELOG_STATE_QUERY,
        DSTREAM_ITEMS,
        DSTREAM_ITEMS_QUERY,
        DSTREAM_PORT,
        DSTREAM_PORT_QUERY,
        DSTREAM_INIT,
        DSTREAM_START,
        DSTREAM_STOP,
        DSTREAM_DELETE,
        DSTREAM_RESET,
        DSTREAM_STATE_QUERY,
        DSTREAM_TRIG,
        DSTREAM_TRIG_QUERY,
        EXPORT_DIRCTORY,
        EXPORT_DIRECTORY_PATH,
        EXPORT_AUTO_QUERY,
        EXPORT_AUTO,
        MARKER_ADD,
        SYNC_STATE_QUERY,
        SCREEN_INSTRUMENTS_OUTPUTCHANNEL_START,
        SCREEN_INSTRUMENTS_OUTPUTCHANNEL_PAUSE,
        SCREEN_INSTRUMENTS_OUTPUTCHANNEL_STOP,
        SCREEN_INSTRUMENTS_OUTPUTCHANNEL_STATE_QUERY,
        SCREEN_SAVE,
        SCREEN_ITEM_SAVE,
        REPORT_SAVE_ALL,
        REPORT_ITEM_SAVE,
        HEADER_ADD,
        HEADER_GET_QUERY,
        HEADER_GET,
        HEADER_KEYS_QUERY,
        HEADER_KEYS,
        HEADER_SET,
        HEADER_DELETE,
        HEADER_VALUES_QUERY,
        SYSTEM_VERSION_QUERY,
        SYSTEM_HELP_HEADERS_QUERY,
        TRIGGER_GET_QUERY,
        TRIGGER_RESET,
        TRIGGER_ADDEVENT,
        TRIGGER_EVENT_SETUP_QUERY,
        TRIGGER_EVENT_SETUP,
        TRIGGER_EVENT_VALID_QUERY,
        TRIGGER_EVENT_DELETE,
        TRIGGER_EVENT_ADDCONDITION,
        TRIGGER_EVENT_ADDACTION,
        TRIGGER_EVENT_CONDITION_GET_QUERY,
        TRIGGER_EVENT_CONDITION_VALID_QUERY,
        TRIGGER_EVENT_CONDITION_DELETE,
        TRIGGER_EVENT_CONDITION_HIGHLEVEL_SETUP,
        TRIGGER_EVENT_CONDITION_LOWLEVEL_SETUP,
        TRIGGER_EVENT_CONDITION_INWINDOW_SETUP,
        TRIGGER_EVENT_CONDITION_OUTWINDOW_SETUP,
        TRIGGER_EVENT_CONDITION_KEYBOARD_SETUP,
        TRIGGER_EVENT_CONDITION_TIME_SETUP,
        TRIGGER_EVENT_ACTION_GET_QUERY,
        TRIGGER_EVENT_ACTION_VALID_QUERY,
        TRIGGER_EVENT_ACTION_RECORDING_SETUP,
        TRIGGER_EVENT_ACTION_DIGOUT_SETUP,
        TRIGGER_EVENT_ACTION_ALARM_SETUP,
        TRIGGER_EVENT_ACTION_MARKER_SETUP,
        TRIGGER_EVENT_ACTION_SNAPSHOT_SETUP,
        TRIGGER_EVENT_ACTION_ARM_SETUP,
        ANALYSIS_ACTIVE_QUERY,
        ANALYSIS_OPEN,
        ANALYSIS_CLOSE,
        ANALYSIS_FILES_QUERY,
        SYSTEM_ERROR_QUERY,
        SYSTEM_ERROR_ALL_QUERY,
        SYSTEM_ERROR_CODE_ALL_QUERY,
        SYSTEM_ERROR_COUNT_QUERY,
        SYSTEM_ERROR_ENABLE_ADD,
        SYSTEM_ERROR_ENABLE_DELETE,
        SYSTEM_ERROR_ENABLE_LIST_QUERY,
        UNKNOWN_COMMAND
    };
    QString execute(const QStringList& params);
    QString command;
    void getCommand(const QString &command);
    static const QHash<QString, CommandType> commandHash;
private:
    CommandType type;
    QString handleIdnQuery();
    QString handleVerQuery();
    QString handleCls();
    QString handleEse(const QStringList &params);
    QString handleEseQuery();
    QString handleEsrQuery();
    QString handleOpc();
    QString handleOpcQuery();
    QString handleRst();
    QString handleSre(const QStringList &params);
    QString handleSreQuery();
    QString handleStbQuery();
    QString handleTstQuery();
    QString handleWaiQuery();
    //Application control
    //Setup
    QString handleSetupLoad(const QStringList &params);
    QString handleSetupApplyXmlString();
    QString handleSetupSavePath(const QStringList &params);
    QString handleSetupReadQuery();
    QString handleSetupNameQuery();
    QString handleSetupAsyncLoadPath();
    QString handleSetupAsyncStateQuery();
    //UI Control
    QString handleSystemDateQuery();
    QString handleSystemKlock();
    QString handleSystemKlockQuery();
    QString handleSystemTimeQuery();
    QString handleSystemTzoneQuery();
    QString handleCommunicateHeader();
    QString handleCommunicateHeaderQuery();
    QString handleCommunicateVerbose();
    QString handleCommunicateVerboseQuery();
    //Acquisition Control
    QString handleAcquisitionStart();
    QString handleAcquisitionStop();
    QString handleAcquisitionRestart();
    QString handleAcquisitionStateQuery();
    //Recording Control
    QString handleStoreFileName();
    QString handleStoreFileNameQuery();
    QString handleStoreStart();
    QString handleStorePause();
    QString handleStoreStop();
    QString handleStoreStateQuery();
    //Waveform access
    QString handleStoreWaveformModeQuery();
    QString handleStoreWaveformMode();
    QString handleStoreWaveformContinuous();
    QString handleStoreWaveformEventbased();
    QString handleStoreWaveformDisabled();
    QString handleStoreWaveformPretime();
    QString handleStoreWaveformPretimeQuery();
    QString handleStoreWaveformPafter();
    QString handleStoreWaveformPafterQuery();
    QString handleStoreWaveformPosttimeQuery();
    QString handleStoreWaveformPosttime();
    QString handleStoreStatisticsQuery();
    QString handleStoreStatistics();
    QString handleStoreAutoStartQuery();
    QString handleStoreAutoStart();
    QString handleStoreRacQuisitionQuery();
    QString handleStoreRacQuisition();
    QString handleStoreSafterQuery();
    QString handleStoreSafter();
    QString handleStoreAdvancedQuery();
    QString handleStoreAdvanced();
    //Channellist access
    QString handleChannellistNamesQuery();
    QString handleChannellistIdsQuery();
    QString handleChannellistItemIdAttrNamesQuery();
    QString handleChannellistItemIdAttrValQuery();
    QString handleChannellistPropertyQuery();
    QString handleChannellistProperty();
    QString handleChannellistConstraintQuery();
    QString handleChannellistItemIdActionZero();
    QString handleChannellistActionZero();
    QString handleChannellistTimingHighestQuery();
    QString handleChannellistTimingLowestQuery();
    QString handleChannellistSaturationValueQuery();
    QString handleChannellistSaturationReset();
    QString handleChannellistFiresponse();
    //Measurement Values
    QString handleRate(const QStringList &params);
    QString handleRateQuery();
    QString handleNumericNormalItems();
    QString handleNumericNormalItemsQuery();
    QString handleNumericNormalItemsX();
    QString handleNumericNormalItemsXQuery();
    QString handleNumericNormalClear();
    QString handleNumericNormalDelete();
    QString handleNumericNormalNumber();
    QString handleNumericNormalNumberQuery();
    QString handleNumericNormalDimx();
    QString handleNumericNormalDimxQuery();
    QString handleNumericNormalDimsQuery();
    QString handleNumericNormalFormat();
    QString handleNumericNormalFormatQuery();
    QString handleNumericNormalValueQuery();
    //External Data Logging
    QString handleElogItems();
    QString handleElogItemsQuery();
    QString handleElogPeriod();
    QString handleElogPeriodQuery();
    QString handleElogCalculations();
    QString handleElogCalculationsQuery();
    QString handleElogFormat();
    QString handleElogFormatQuery();
    QString handleElogTimestamp();
    QString handleElogTimestampQuery();
    QString handleElogStart();
    QString handleElogFetchQuery();
    QString handleElogStop();
    QString handleElogReset();
    QString handleElogStateQuery();
    //Data Streaming
    QString handleDstreamItems();
    QString handleDstreamItemsQuery();
    QString handleDstreamPort();
    QString handleDstreamPortQuery();
    QString handleDstreamInit();
    QString handleDstreamStart();
    QString handleDstreamStop();
    QString handleDstreamDelete();
    QString handleDstreamReset();
    QString handleDstreamStateQuery();
    QString handleDstreamTrig();
    QString handleDstreamTrigQuery();
    //Export Commands
    QString handleExportDirectory();
    QString handleExportDirectoryPath();
    QString handleExportAutoQuery();
    QString handleExportAuto();
    //Marker Commands
    QString handleMarkerAdd();
    //Synchronisation State
    QString handleSyncStateQuery();
    //Measurement Screen Commands
    QString handleScreenInsterumentsOutputchannelStart();
    QString handleScreenInsterumentsOutputchannelPause();
    QString handleScreenInsterumentsOutputchannelStop();
    QString handleScreenInsterumentsOutputchannelStateQuery();
    QString handleScreenSave();
    QString handleScreenItemSave();
    //Measurement Report Commands
    QString handleReportSave();
    QString handleReportItemSave();
    //Measurement Header Datd
    QString handleheaderAdd();
    QString handleheaderGetQuery();
    QString handleheaderKeysQuery();
    QString handleheaderSet();
    QString handleheaderDelete();
    QString handleheaderValuesQuery();
    //Utility Commands
    QString handleSystemVersionQuery();
    QString handleSystemHelpHeadersQuery();
    //Trigger Events
    QString handleTriggerGetQuery();
    QString handleTriggerReset();
    QString handleTriggerAddevent();
    QString handleTriggerEventSetupQuery();
    QString handleTriggerEventSetup();
    QString handleTriggerEventValidQuery();
    QString handleTriggerEventDelete();
    QString handleTriggerEventAddCondition();
    QString handleTriggerEventAddAction();
    QString handleTriggerEventConditionGetQuery();
    QString handleTriggerEventConditionValidQuery();
    QString handleTriggerEventConditionDelete();
    QString handleTriggerEventConditionHighlevelSetup();
    QString handleTriggerEventConditionLowlevelSetup();
    QString handleTriggerEventConditionInwindowSetup();
    QString handleTriggerEventConditionOutwindowSetup();
    QString handleTriggerEventConditionKeyboardSetup();
    QString handleTriggerEventConditionTimeSetup();
    QString handleTriggerEventActionGetQuery();
    QString handleTriggerEventActionValidQuery();
    QString handleTriggerEventActionDelete();
    QString handleTriggerEventActionRecordingSetup();
    QString handleTriggerEventActionDigoutSetup();
    QString handleTriggerEventActionAlarmSetup();
    QString handleTriggerEventActionMarkerSetup();
    QString handleTriggerEventActionSnapshotSetup();
    QString handleTriggerEventActionArmSetup();
    //Analysis Control
    QString handleAnalysisActiveQuery();
    QString handleAnalysisOpen();
    QString handleAnalysisClose();
    QString handleAnalysisFileQuery();
    //Error handling
    QString handleSystemErrorQuery();
    QString handleSystemErrorAllQuery();
    QString handleSystemErrorCodeQuery();
    QString handleSystemErrorCodeAllQuery();
    QString handleSystemErrorCountQuery();
    QString handleSystemErrorEnableAdd();
    QString handleSystemErrorEnableDelete();
    QString handleSystemErrorEnableListQuery();
    QString eseResult;
    QString sreResult;
    QString setupLoadPathResult;
signals:
};

#endif // COMMAND_H
