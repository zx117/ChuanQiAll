#include "getdeviceinformation.h"

GetDeviceInformation::GetDeviceInformation(QObject *parent)
    : QObject{parent}
{

}

GetDeviceInformation::~GetDeviceInformation()
{
    for (GetDeviceData *thread : threads) {
        cleanThread(thread);
    }
    threads.clear();
}

/**
 * @brief GetDeviceInformation::initialization   初始化
 */
void GetDeviceInformation::initialization()
{
    instance = daq::Instance("");
    // Find and connect to a device hosting an OPC UA TMS server找到并连接到承载OPC UA TMS服务器的设备
    availableDevices = instance.getAvailableDevices();
    for (const auto& deviceInfo : availableDevices)
    {
        device = instance.addDevice(deviceInfo.getConnectionString());
        const auto config = device.saveConfiguration();
    }
}
/**
 * @brief GetDeviceInformation::initializationDeviceModel  初始化设备数据模型
 */
void GetDeviceInformation::initializationDeviceModel()
{
    for(int i=0;i<getActivateDeviceNumber();i++)
    {
        int num=getActiveDeviceChannelsNum(i);
        QString devicename=getActivateDeviceName(i);
        for(int j=0;j<num;j++)
        {
            getDeviceData(i,j,0);
            QVariantMap item;
            item["text"] = getActiveDeviceChannelsName(i,j);
            item["activeDevice"] = devicename;
            item["value"] = 0;
            item["time"] = 0;
            item["isClicked"] = false;
            item["isVisible"] = getDeviceActive(i);
            deviceDataList.append(item);
        }
    }
    listmodel->setDeviceData(deviceDataList);
}

/**
 * @brief GetDeviceInformation::setDeviceActive    设置板卡的激活属性
 * @param active
 */
void GetDeviceInformation::setDeviceActive(int deviceid,bool active)
{
    instance.getDevices().getItemAt(deviceid).setActive(active);
}
/**
 * @brief GetDeviceInformation::getActivateDeviceNumber     返回检测到的板卡中激活板卡的数量
 * @return
 */
int GetDeviceInformation::getActivateDeviceNumber()
{
    return instance.getDevices().getCount();

}
/**
 * @brief GetDeviceInformation::getActivateDeviceName    获取激活板卡名称
 * @param i                                              设备在链表中的位置
 */
QString GetDeviceInformation::getActivateDeviceName(int deviceid)
{
    return QString::fromStdString(instance.getDevices().getItemAt(deviceid).getInfo().getName());
}
/**
 * @brief GetDeviceInformation::getDeviceChannels        获取板卡通道数
 * @param i
 * @return
 */
int GetDeviceInformation::getActiveDeviceChannelsNum(int deviceid)
{
    return  instance.getDevices().getItemAt(deviceid).getChannels().getCount();
}
/**
 * @brief GetDeviceInformation::getActiveDeviceChannelsName    获取板卡通道名
 * @param i
 * @return
 */
QString GetDeviceInformation::getActiveDeviceChannelsName(int deviceid,int channelid)
{
    return QString::fromStdString(instance.getDevices().getItemAt(deviceid).getChannels()[channelid].getName());

}
/**
 * @brief GetDeviceInformation::getDeviceData      获取通道数据
 * @param i
 * @return
 */
void GetDeviceInformation::getDeviceData(int deviceid,int channelid,int signalid)
{
    int threadId = threadCounter++;
    emit deviceDataListChanged(threadId);
    GetDeviceData *thread = new GetDeviceData(instance,deviceid, channelid, signalid,threadId);
    connect(thread, &GetDeviceData::dataRead, this, &::GetDeviceInformation::onDataRead);
    connect(thread, &QThread::finished, thread, &QObject::deleteLater);
    threads.append(thread);
    thread->start();
}
/**
 * @brief GetDeviceInformation::updateDeviceData  更新数据
 * @param threadid
 */
void GetDeviceInformation::upDateDeviceData(int threadid)
{
    if (threadid >= 0 && threadid < deviceDataList.size()) {
        listmodel->upData(threadid,deviceDataList[threadid].toMap());
    }
}
/**
 * @brief GetDeviceInformation::getDeviceDataList
 * @return
 */
QVariantList GetDeviceInformation::getDeviceDataList()
{
    return deviceDataList;
}
/**
 * @brief GetDeviceInformation::cleanThread    关闭线程
 * @param thread    要关闭的线程
 */
void GetDeviceInformation::cleanThread(GetDeviceData *thread)
{
    if (thread) {
        thread->stop(); // 请求线程退出
        thread->wait(); // 等待线程退出
        threads.removeAll(thread); // 从容器中移除
        thread->deleteLater(); // 删除线程对象
    }
}
/**
 * @brief GetDeviceInformation::setAttributeValue
 * @param index
 * @param attName
 * @param value
 */
void GetDeviceInformation::setAttributeValue(int index, int role, const QVariant &value)
{
    listmodel->upDateAttribute(index,role,value);
    emit deviceIndex(index);
}
/**
 * @brief GetDeviceInformation::onDataRead
 */
void GetDeviceInformation::onDataRead(int threadId, double value, double time)
{
    if (threadId >= 0 && threadId < deviceDataList.size()) {
        QVariantMap data;
        data["value"] = value;
        data["time"] = time;
        deviceDataList[threadId] = data;
        emit deviceDataListChanged(threadId);
    }
}
/**
 * @brief GetDeviceInformation::getRootDeviceName    获取检测到的所有板卡
 * @param i                                          设备在链表中的位置
 * @return
 */
QString GetDeviceInformation::getRootDeviceName(int i)
{
    return QString::fromStdString(availableDevices.getItemAt(i).getName());
}
/**
 * @brief GetDeviceInformation::getRootDeviceNumber        返回检测到的所有板卡的数量
 * @return
 */
int GetDeviceInformation::getRootDeviceNumber()
{
    return availableDevices.getCount();
}
/**
 * @brief GetDeviceInformation::getRootDeviceId              返回板卡类型Id
 * @param i
 * @return
 */
QString GetDeviceInformation::getRootDeviceTypeId(int i)
{
    return QString::fromStdString(availableDevices.getItemAt(i).getDeviceType().getId());
}
/**
 * @brief GetDeviceInformation::getRootDeviceTypeName       返回板卡类型名
 * @param i
 * @return
 */
QString GetDeviceInformation::getRootDeviceTypeName(int i)
{
    return QString::fromStdString(availableDevices.getItemAt(i).getDeviceType().getName());
}
/**
 * @brief GetDeviceInformation::getRootDeviceDescription      返回板卡描述
 * @param i
 * @return
 */
QString GetDeviceInformation::getRootDeviceDescription(int i)
{
    return QString::fromStdString(availableDevices.getItemAt(i).getDeviceType().getDescription());
}
/**
 * @brief GetDeviceInformation::getRootDeviceActive           返回板卡激活状态
 * @param i
 * @return
 */
bool GetDeviceInformation::getDeviceActive(int i)
{
    return  instance.getDevices().getItemAt(i).getActive();
}
/**
 * @brief GetDeviceInformation::getChannelGroupName            返回通道组的名称
 * @param deviceid
 * @return
 */
QString GetDeviceInformation::getChannelGroupName(int deviceid)
{
    return QString::fromStdString(instance.getDevices().getItemAt(deviceid).getName());
}

