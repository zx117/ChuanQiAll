#include "treeitem.h"

TreeItem::TreeItem(const QVector<QVariant> &data, TreeItem *parentItem)
{
    parent = parentItem;
    itemData = data;
}

TreeItem::~TreeItem()
{
    qDeleteAll(childItems);
}

void TreeItem::appendChild(TreeItem *child)
{
    childItems.append(child);
}

TreeItem *TreeItem::child(int row)
{
    return childItems.value(row);
}

int TreeItem::childCount() const
{
    return childItems.count();
}

int TreeItem::columnCount() const
{
    return itemData.count();
}

QVariant TreeItem::data(int column) const
{
    return itemData.value(column);
}

int TreeItem::row() const
{
    if (parent)
        return parent->childItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

TreeItem *TreeItem::parentItem()
{
    return parent;
}
