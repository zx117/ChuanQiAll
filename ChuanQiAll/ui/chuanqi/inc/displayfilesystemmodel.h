#ifndef DISPLAYFILESYSTEMMODEL_H
#define DISPLAYFILESYSTEMMODEL_H

#include <QStandardItemModel>
#include <QStandardItem>
#include <QDir>
#include <QFileInfoList>
#include <QMutex>
class DisplayFileSystemModel : public QStandardItemModel
{
    Q_OBJECT

public:
    enum Roles {
        FileNameRole = Qt::UserRole + 100,
        FilePathRole ,
        IsDirRole,
        DepthRole,
        CheckedRole,
        SelectedRole,
        EmbellishRole
    };

    explicit DisplayFileSystemModel(QObject *parent = nullptr);
    ~DisplayFileSystemModel();

    Q_INVOKABLE void setRootPath(const QString &path);
    int getDepth(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE void updateChecked(const QString &path, bool checked);
    QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE void updateSelected(const QString &path, bool selected);

signals:
    void dirSet();

private:
    void loadDirectory(const QDir &dir, QStandardItem *parentItem);
    QStandardItem *root;
    QHash<QString, QStandardItem*> itemMap;
    QHash<QString, bool> checkedItems;
    QString selectedItem;
    QMutex mutex;

};

#endif // DISPLAYFILESYSTEMMODEL_H
