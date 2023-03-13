#ifndef ALBUMWIDGET_H
#define ALBUMWIDGET_H

#include <QWidget>
#include <QModelIndex>

namespace Ui {
class AlbumWidget;
}

class AlbumModel;
class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

class AlbumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumWidget(QWidget *parent = nullptr);
    ~AlbumWidget();

    void setAlbumModel(AlbumModel* albumModel);
    void setAlbumSelectionModel(QItemSelectionModel* albumSelectionModel);
    void setPictureModel(ThumbnailProxyModel* pictureModel);
    void setPictureSelectionModel(QItemSelectionModel* selectionModel);

signals:
    void pictureActivated(const QModelIndex& index); // 用户双击缩略图

private slots:
    void deleteAlbum();
    void editAlbum();
    void addPictures();

private:
    void clearUi(); // 清楚此UI所有显示信息
    void loadAlbum(const QModelIndex& albumIndex); // 更新特定专辑的用户界面

private:
    Ui::AlbumWidget *ui;
    AlbumModel* mAlbumModel;
    QItemSelectionModel* mAlbumSelectionModel; // 处理其他widgets和view,例如AlbumListWidget

    ThumbnailProxyModel* mPictureModel;
    QItemSelectionModel* mPictureSelectionModel; // 处理其他widgets和view,例如AlbumListWidget
};

#endif // ALBUMWIDGET_H
