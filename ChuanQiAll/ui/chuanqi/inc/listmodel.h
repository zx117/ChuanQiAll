#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include <QVariantList>
#include <QDebug>
class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum DeviceRoles {
        TextRole = 0,
        ActiveDeviceRole,
        ValueRole,
        TimeRole,
        IsClickedRole,
        IsVisibleRole
    };
    Q_ENUM(DeviceRoles);

    explicit ListModel(QObject *parent = nullptr);
    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int,QByteArray> roleNames() const override;

    QString getSomeValue();
    bool setData(const QModelIndex &index, const QVariant &value, int role)  override;
    void setDeviceData(const QVariantList &dataList);
    Q_INVOKABLE void upData(int index, const QVariantMap &newData);
    Q_INVOKABLE QVariant get(int row);
    Q_INVOKABLE void upDateAttribute(int index, int role, const QVariant &value);
private:
    QList<QVariantMap> deviceDataList;
signals:
    void returnIndexValue(int index,QVariant value);


};

#endif //LISTMODEL_H
