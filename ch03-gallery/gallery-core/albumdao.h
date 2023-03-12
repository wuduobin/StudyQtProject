#ifndef ALBUMDAO_H
#define ALBUMDAO_H

#include <memory>
#include <vector>

class QSqlDatabase;
class Album;

//dao = data access object. This class CRUD operate database
class AlbumDao
{
public:
    explicit AlbumDao(QSqlDatabase& database);
    void init() const; // create the albums table and should be called when mDatabase is opened

    void addAlum(Album& album) const;
    void updateAlbum(const Album& album) const;
    void removeAlbum(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Album>>> albums() const;

private:
    QSqlDatabase& mDatabase;
};

#endif // ALBUMDAO_H
