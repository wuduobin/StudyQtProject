#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include <QAbstractListModel>
#include <QHash>
#include <vector>
#include <memory>

#include "gallery-core_global.h"
#include "album.h"
#include "databasemanager.h"

class GALLERYCORE_EXPORT AlbumModel : public QAbstractListModel
{
    Q_OBJECT
public:

    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole
    };

    AlbumModel(QObject* parent = Q_NULLPTR);

    QModelIndex addAlbum(const Album& album);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override; // get the list size
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override; // get a specific piece of information about the data to display
    bool setData(const QModelIndex &index, const QVariant &value, int role) override; // update data
    bool removeRows(int row, int count, const QModelIndex &parent) override; // remove data
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb; // model与数据层进行交互
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> mAlbums;
};

#endif // ALBUMMODEL_H
