#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
class MyData{
public:
    MyData(QString s,int v):myString(s),myValue(v){};
    QString myString;
    int myValue;

};

class ListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum MyRoleName{
        Name=Qt::DisplayRole+1,
        Value
    };
    Q_ENUM(MyRoleName);

    explicit ListModel(QObject *parent = nullptr);
    //获取实例
    static ListModel* getInstance();
    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int,QByteArray> roleNames() const override;

    QString getSomeValue();
private:
    QList<MyData> myData;



};

#endif //LISTMODEL_H
