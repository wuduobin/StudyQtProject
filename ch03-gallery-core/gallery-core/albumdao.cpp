#include "albumdao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "databasemanager.h"
#include "album.h"

AlbumDao::AlbumDao(QSqlDatabase &database)
    : mDatabase{database}
{
}

void AlbumDao::init() const
{
    if (!mDatabase.tables().contains("albums")) {
        QSqlQuery query(mDatabase);
        if (!query.exec("CREATE TABLE albums (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT")) {
            //QSqlError err = QSqlQuery::lastError();
        }
        DatabaseManager::debugQuery(query);
    }
}

void AlbumDao::addAlum(Album &album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO album (name) VALUES (:name)");
    query.bindValue(":name", album.name());
    query.exec();
    album.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void AlbumDao::updateAlbum(const Album &album) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE albums SET name = (:name) WHERE id = (:id)");
    query.bindValue(":name", album.name());
    query.bindValue(":id", album.id());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void AlbumDao::removeAlbum(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM albums WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

std::unique_ptr<std::vector<std::unique_ptr<Album> > > AlbumDao::albums() const
{
    QSqlQuery query("SELECT * FROM albums", mDatabase);
    query.exec();
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> list(new std::vector<std::unique_ptr<Album>>());
    while (query.next()) {
        std::unique_ptr<Album> album(new Album()); // 不使用make_unique(C++14)是因为Mobile UI支持至C++11
        album->setId(query.value("id").toInt());
        album->setName(query.value("name").toString());
        list->emplace_back(std::move(album));
    }
    return list;
}
