#include "displayFileSystemModel.h"
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

DisplayFileSystemModel::DisplayFileSystemModel(QObject *parent) : QStandardItemModel(parent)
{

}

DisplayFileSystemModel::~DisplayFileSystemModel()
{

}

int DisplayFileSystemModel::getDepth(const QModelIndex &index) const
{
    int depth = 0;
    QModelIndex parentIndex = index.parent();
    while (parentIndex.isValid()) {
        depth++;
        parentIndex = parentIndex.parent();
    }
    return depth;
}

QVariant DisplayFileSystemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    QStandardItem *item = itemFromIndex(index);

    switch (role) {
    case FileNameRole:
        return item->data(FileNameRole);
    case EmbellishRole:
        return item->data(EmbellishRole);
    case DepthRole:
        return getDepth(index);
    case CheckedRole: {
        QString path = item->data(FilePathRole).toString(); // 获取路径数据
        return checkedItems.value(path, false);
    }
    case SelectedRole: {
        QString path = item->data(FilePathRole).toString(); // 获取路径数据
        return path == selectedItem;
    }
    default:
        return QStandardItemModel::data(index, role);
    }
}

void DisplayFileSystemModel::setRootPath(const QString &path)
{

    clear();
    itemMap.clear();
    if(path!="disk")
    {
        QDir dir(path);
        if (!dir.exists()) {
            return;
        }

        QStandardItem *parentItem = invisibleRootItem();
        QtConcurrent::run(this, &DisplayFileSystemModel::loadDirectory, dir, parentItem);
    }
    else
    {
        foreach(QFileInfo info, QDir::drives())
        {
            QDir dir(info.absolutePath());
            if (!dir.exists()) {
                return;
            }
            QStandardItem *parentItem = new QStandardItem();
            parentItem->setData(dir.absolutePath(), FileNameRole);
            parentItem->setData(dir.absolutePath(), FilePathRole);
            parentItem->setData("qrc:/qml/images/treeIcon/disk", EmbellishRole);
            appendRow(parentItem);
            QtConcurrent::run(this, &DisplayFileSystemModel::loadDirectory, dir, parentItem);
        }
    }

}

void DisplayFileSystemModel::loadDirectory(const QDir &dir, QStandardItem *parentItem)
{
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QFileInfo &info : list) {
        // 如果文件的扩展名是.gpkg或.qgz，就跳过这个文件
        if (info.isFile()&&info.suffix()!= "dmd") {
            continue;
        }

        QStandardItem *item = new QStandardItem();
        item->setData(info.fileName(), FileNameRole);
        item->setData(info.absoluteFilePath(), FilePathRole);
        if (info.isDir()) {
            item->setData("qrc:/qml/images/treeIcon/file", EmbellishRole);
        }
        mutex.lock();
        parentItem->appendRow(item);
        itemMap[info.absoluteFilePath()] = item;
        mutex.unlock();

        if (info.isDir()) {
            loadDirectory(QDir(info.absoluteFilePath()), item);
        }
    }

}

void DisplayFileSystemModel::updateChecked(const QString &path, bool checked)
{
    if (!itemMap.contains(path)) {
        return;
    }

    if (checkedItems[path] != checked) {
        checkedItems[path] = checked;
        QStandardItem *item = itemMap.value(path);
        QModelIndex parentIndex = item->parent() ? item->parent()->index() : QModelIndex();
        QModelIndex firstIndex = this->index(item->row(), 0, parentIndex);
        QModelIndex lastIndex = this->index(item->row(), this->columnCount(parentIndex) - 1, parentIndex);
        emit dataChanged(firstIndex, lastIndex, { CheckedRole });
    }
}

QHash<int, QByteArray> DisplayFileSystemModel::roleNames() const
{
    QHash<int, QByteArray> roles = QStandardItemModel::roleNames();
    roles[FileNameRole] = "filename";
    roles[FilePathRole] = "filepath";
    roles[IsDirRole] = "isdir";
    roles[DepthRole] = "depth";
    roles[CheckedRole] = "checked";
    roles[SelectedRole] = "selected";
    roles[EmbellishRole] = "embellish";
    return roles;
}

void DisplayFileSystemModel::updateSelected(const QString &path, bool selected)
{
    if (!itemMap.contains(path)) {
        return;
    }

    if (selected) {
        if (!selectedItem.isEmpty()) {
            QString oldSelectedItem = selectedItem;
            selectedItem.clear();
            QStandardItem *oldItem = itemMap.value(oldSelectedItem);
            QModelIndex parentIndex = oldItem->parent() ? oldItem->parent()->index() : QModelIndex();
            QModelIndex firstIndex = this->index(oldItem->row(), 0, parentIndex);
            QModelIndex lastIndex = this->index(oldItem->row(), this->columnCount(parentIndex) - 1, parentIndex);
            emit dataChanged(firstIndex, lastIndex, { SelectedRole });
        }
        // 选中新的行
        selectedItem = path;
    } else {
        selectedItem.clear();
    }
    QStandardItem *item = itemMap.value(path);
    QModelIndex parentIndex = item->parent() ? item->parent()->index() : QModelIndex();
    QModelIndex firstIndex = this->index(item->row(), 0, parentIndex);
    QModelIndex lastIndex = this->index(item->row(), this->columnCount(parentIndex) - 1, parentIndex);
    emit dataChanged(firstIndex, lastIndex, { SelectedRole });
}
