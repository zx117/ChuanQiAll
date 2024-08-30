#include "listmodel.h"
ListModel::ListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    myData.append(MyData("zhangsan",111));
    myData.append(MyData("lisi",222));
    myData.append(MyData("wangwu",333));
    myData.append(MyData("maliu",444));
    myData.append(MyData("zhangsan",555));
    myData.append(MyData("lisi",666));
    myData.append(MyData("wangwu",777));
    myData.append(MyData("maliu",888));
}

ListModel *ListModel::getInstance()
{
    static ListModel *obj=new ListModel;
    return obj;
}

QVariant ListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return {};
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return myData.count();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role==MyRoleName::Name)
    {
        return myData[index.row()].myString;
    }
    else if(role==MyRoleName::Value)
    {
        return myData[index.row()].myValue;
    }
    return QVariant();
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[MyRoleName::Name]="name";
    roles[MyRoleName::Value]="value";
    return roles;
}
