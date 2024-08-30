#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    horizontalHeaders << "Column 1" << "Column 2" << "Column 3";
    verticalHeaders << "Row 1" << "Row 2" << "Row 3";

    // 填充模型的数据结构
    for (int i = 0; i < verticalHeaders.size(); ++i) {
        QVector<QString> rowData;
        for (int j = 0; j < horizontalHeaders.size(); ++j) {
            rowData.append(QString("Data %1,%2").arg(i + 1).arg(j + 1));
        }
        tableData.append(rowData);
    }
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        return horizontalHeaders.at(section);
    } else {
        return verticalHeaders.at(section);
    }
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return verticalHeaders.size();

    // FIXME: Implement me!
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return horizontalHeaders.size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        return tableData[index.row()][index.column()];
    }

    return QVariant();
}
