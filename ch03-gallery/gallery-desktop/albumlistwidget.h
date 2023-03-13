#ifndef ALBUMLISTWIDGET_H
#define ALBUMLISTWIDGET_H

#include <QWidget>
#include <QItemSelectionModel>

namespace Ui {
class AlbumListWidget;
}

class AlbumModel;

class AlbumListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumListWidget(QWidget *parent = nullptr);
    ~AlbumListWidget();

    // 这个2个函数非常重要
    void setModel(AlbumModel* model);
    void setSelectionModel(QItemSelectionModel* selectionModel); // 处理视图中对选择。与不同的视图或部件共享相同的选择模型将帮助我们轻松地同步专辑选择

private slots:
    void createAlbum();

private:
    Ui::AlbumListWidget *ui;
    AlbumModel* mAlbumModel; // Model类提供对数据对访问
};

#endif // ALBUMLISTWIDGET_H
