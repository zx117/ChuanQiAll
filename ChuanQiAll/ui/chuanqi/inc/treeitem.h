#ifndef TREEITEM_H
#define TREEITEM_H


#include <QAbstractItemModel>
#include <QXmlStreamReader>
#include <QVector>
#include <QList>
#include <QVariant>

class TreeItem
{
public:
    explicit TreeItem(const QVector<QVariant> &data, TreeItem *parentItem = nullptr);
    ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parentItem();

private:
    QList<TreeItem*> childItems;
    QVector<QVariant> itemData;
    TreeItem *parent;
};

#endif // TREEITEM_H
