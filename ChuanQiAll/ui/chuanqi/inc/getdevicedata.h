#ifndef GETDEVICEDATA_H
#define GETDEVICEDATA_H

#include <QObject>
#include <QThread>
#include "logoperations.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <cqdaq/cqdaq.h>
class GetDeviceData : public QThread
{
    Q_OBJECT
public:
    GetDeviceData(daq::InstancePtr instance,int deviceid, int channelid, int signalid ,int threadid,QObject *parent = nullptr)
        : QThread(parent), instance(instance), deviceid(deviceid), channelid(channelid),signalid(signalid),threadid(threadid){};
    void run() override ;
    void stop();
private:
    daq::InstancePtr instance;
    int deviceid;
    int channelid;
    int signalid;
    int threadid;
    std::atomic<bool> stopRequested;
signals:
    void dataRead(int threadid,double value, double time);
};

#endif // GETDEVICEDATA_H
