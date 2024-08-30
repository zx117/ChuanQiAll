#include "treemodel.h"
#include <QFile>
#include <QDebug>

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent),
    rootItem(new TreeItem({"Root"}, nullptr))
{
}

TreeModel::~TreeModel()
{
    delete rootItem;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return rootItem->columnCount();
}

void TreeModel::parseXmlFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Failed to open XML file:" << file.errorString();
        return;
    }

    QXmlStreamReader xml(&file);
    setupModelDataFromXml(xml, rootItem);

    file.close();
}

void TreeModel::setupModelDataFromXml(QXmlStreamReader &xml, TreeItem *parent)
{
    QVector<TreeItem*> parents;
    parents << parent;

    while (!xml.atEnd()) {
        xml.readNext();
        if (xml.isStartElement()) {
            QString tagName = xml.name().toString();
            QVector<QVariant> itemData;
            itemData.append(tagName);

            TreeItem *item = new TreeItem(itemData, parents.last());
            parents.last()->appendChild(item);
            parents << item;
        } else if (xml.isEndElement()) {
            parents.pop_back();
        }
    }

    if (xml.error() && xml.error() != QXmlStreamReader::PrematureEndOfDocumentError) {
        qDebug() << "XML Parse Error:" << xml.errorString();
    }
}
