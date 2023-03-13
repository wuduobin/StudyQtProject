#ifndef PICTUREWIDGET_H
#define PICTUREWIDGET_H

#include <QWidget>
#include <QItemSelection>

namespace Ui {
class PictureWidget;
}

class PictureModel;
class QItemSelectionModel;
class ThumbnailProxyModel;

class PictureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PictureWidget(QWidget *parent = nullptr);
    ~PictureWidget();

    void setModel(ThumbnailProxyModel* model);
    void setSelectionModel(QItemSelectionModel* selectionModel);

signals:
    void backToGallery();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override; // 确保使用所有可见区域来显示图片

private slots:
    void deletePicture();
    void loadPicture(const QItemSelection& selected); // 用指定的图片更新界面

private:
    void updatePicturePixmap(); // 辅助函数：根据当前widget的尺寸显示图片

private:
    Ui::PictureWidget *ui;
    ThumbnailProxyModel* mModel;
    QItemSelectionModel* mSelectionModel;
    QPixmap mPixmap;
};

#endif // PICTUREWIDGET_H
