#ifndef GETDEVICEINFORMATION_H
#define GETDEVICEINFORMATION_H

#include <QObject>
#include "logoperations.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <cqdaq/cqdaq.h>
#include "getdevicedata.h"
#include <QVariantList>
#include <QList>
#include "listmodel.h"
struct DeviceData {
    Q_GADGET // 使用 Q_GADGET 宏
    Q_PROPERTY(double value MEMBER value)
    Q_PROPERTY(double time MEMBER time)

public:
    double value = 0;
    double time = 0;
};

class GetDeviceInformation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList deviceDataList READ getDeviceDataList NOTIFY deviceDataListChanged)
public:
    explicit GetDeviceInformation(QObject *parent = nullptr);
    ~GetDeviceInformation();
    void initialization();
    Q_INVOKABLE void initializationDeviceModel();
    Q_INVOKABLE void setDeviceActive(int deviceid,bool active);
    Q_INVOKABLE QString getRootDeviceName(int deviceid=0);
    Q_INVOKABLE QString getActivateDeviceName(int deviceid=0);
    Q_INVOKABLE int getRootDeviceNumber();
    Q_INVOKABLE int getActivateDeviceNumber();
    Q_INVOKABLE QString getRootDeviceTypeId(int deviceid=0);
    Q_INVOKABLE QString getRootDeviceTypeName(int deviceid=0);
    Q_INVOKABLE QString getRootDeviceDescription(int deviceid=0);
    Q_INVOKABLE bool getDeviceActive(int deviceid=0);
    Q_INVOKABLE QString getChannelGroupName(int deviceid=0);
    Q_INVOKABLE int getActiveDeviceChannelsNum(int deviceid=0);
    Q_INVOKABLE QString getActiveDeviceChannelsName(int deviceid=0,int channelid=0);
    Q_INVOKABLE void getDeviceData(int deviceid=0,int channelid=0,int signalid=0);
    Q_INVOKABLE void upDateDeviceData(int threadid);
    Q_INVOKABLE QVariantList getDeviceDataList();
    Q_INVOKABLE void cleanThread(GetDeviceData *thread);
    Q_INVOKABLE void setAttributeValue(int index,int role, const QVariant &value);
    ListModel *listmodel;
private:
    int threadCounter = 0;
    int deviceNum=0;
    daq::InstancePtr instance;
    daq::DevicePtr device;
    daq::ListPtr<daq::IDeviceInfo> availableDevices;
    QVariantList deviceDataList;
    QList<GetDeviceData*> threads;
    void onDataRead(int threadId, double value, double time);

signals:
    void deviceDataListChanged(int threadId);
    void deviceIndex(int index);
};


#endif // GETDEVICEINFORMATION_H
