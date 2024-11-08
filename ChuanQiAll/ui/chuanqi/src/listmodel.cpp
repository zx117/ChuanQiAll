#include "listmodel.h"
ListModel::ListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

/**
 * @brief ListModel::headerData      获取模型的头部数据。对于简单的列表模型，这通常不需要实现。
 * @param section                    指定的列索引。
 * @param orientation                列的方向（水平或垂直）。
 * @param role                       请求的数据角色（如显示文本、背景色等）。
 * @return                           返回指定的头部数据；如果未实现，则返回一个空的 QVariant。
 */
QVariant ListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!  // 需要实现该方法以返回头部数据
    return {};
}

/**
 * @brief ListModel::rowCount     获取模型中的行数。
 * @param parent                  指定的父索引。在列表模型中，只有无效的父索引（根节点）返回列表的大小，
 *                                有效的父索引则返回 0，以确保它不会成为树模型。
 * @return                        返回模型中有效的行数。
 */
int ListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);  // 由于未使用 parent，这里进行标记以避免编译器警告
    return deviceDataList.size();  // 返回设备数据列表的大小
}

/**
 * @brief ListModel::data       获取指定索引处的数据。
 * @param index                 指定的数据索引。
 * @param role                  请求的数据角色（如文本、值、状态等）。
 * @return                      返回指定角色的数据；如果索引无效或超出范围，则返回一个空的 QVariant。
 */
QVariant ListModel::data(const QModelIndex &index, int role) const
{
     // 检查索引是否有效，并确保行数在有效范围内
    if (!index.isValid() || index.row() >= deviceDataList.size())
        return QVariant();
    // 获取对应行的 QVariantMap
    const QVariantMap &item = deviceDataList.at(index.row());
    switch (role) {
    case TextRole:
        return item.value("text");
    case ActiveDeviceRole:
        return item.value("activeDevice");
    case ValueRole:
        return item.value("value");
    case TimeRole:
        return item.value("time");
    case IsClickedRole:
        return item.value("isClicked");
    case IsVisibleRole:
        return item.value("isVisible");
    default:
        return QVariant();
    }
}

/**
 * @brief ListModel::roleNames       获取模型中每个角色的名称。
 * @return                           返回一个包含角色名称的 QHash，键为角色的整数值，值为对应的 QByteArray 名称。
 */
QHash<int, QByteArray> ListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TextRole] = "text";
    roles[ActiveDeviceRole] = "activeDevice";
    roles[ValueRole] = "value";
    roles[TimeRole] = "time";
    roles[IsClickedRole] = "isClicked";
    roles[IsVisibleRole] = "isVisible";
    return roles;
}

/**
 * @brief ListModel::setData     更新指定索引处的数据。
 * @param index                  指定的数据索引。
 * @param value                  要设置的新值。
 * @param role                   要更新的数据角色（如文本、数值等）。
 * @return                       如果成功更新数据返回 true，失败返回 false。
 */
bool ListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    // 检查索引是否有效及行数是否在有效范围内
    if (!index.isValid() || index.row() >= deviceDataList.size()) {
        return false;  // 无效索引，返回 false
    }
    // 获取对应行的 QVariantMap，以便直接修改
    QVariantMap item = deviceDataList[index.row()];
    // 根据角色设置对应的值
    switch (role) {
    case TextRole:
        item["text"] = value;
        break;
    case ActiveDeviceRole:
        item["activeDevice"] = value;
        break;
    case ValueRole:
        item["value"] = value;
        break;
    case TimeRole:
        item["time"] = value;
        break;
    case IsClickedRole:
        item["isClicked"] = value;
        break;
    case IsVisibleRole:
        item["isVisible"] = value;
        break;
    default:
        return false;
    }
    deviceDataList[index.row()] = item;
    emit dataChanged(index, index, {role});
    return true;
}

void ListModel::setDeviceData(const QVariantList &dataList)
{
    beginResetModel();
    deviceDataList.clear();
    // // 填充新的数据
    for (const QVariant &item : dataList) {
        if (item.canConvert<QVariantMap>()) {
            deviceDataList.append(item.toMap());
        }
    }
    endResetModel();
}

void ListModel::upData(int index, const QVariantMap &newData)
{
    if (index < 0 || index >= deviceDataList.size())
        return;
    QModelIndex modelIndex = this->index(index, 0);
    setData(modelIndex, newData.value("value"), ValueRole);
    setData(modelIndex, newData.value("time"), TimeRole);
    emit returnIndexValue(index,newData.value("value"));
}

QVariant ListModel::get(int row)
{
    if (row < 0 || row >= deviceDataList.size()) {
        return QVariant();
    }
    QVariantMap data=deviceDataList[row];
    return QVariant::fromValue(data.value("value"));
}

void ListModel::upDateAttribute(int index, int role, const QVariant &value)
{
    if (index < 0 || index >= deviceDataList.size())
        return;
    QModelIndex modelIndex = this->index(index, 0);
    switch (role) {
    case TextRole:
        setData(modelIndex, value, TextRole);
        break;
    case ActiveDeviceRole:
        setData(modelIndex, value, ActiveDeviceRole);
        break;
    case ValueRole:
        setData(modelIndex, value, ValueRole);
        break;
    case TimeRole:
        setData(modelIndex, value, TimeRole);
        break;
    case IsClickedRole:
        setData(modelIndex, value, IsClickedRole);
        break;
    case IsVisibleRole:
        setData(modelIndex, value, IsVisibleRole);
        break;
    }

}


