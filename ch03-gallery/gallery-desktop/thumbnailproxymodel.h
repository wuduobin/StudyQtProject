#ifndef THUMBNAILPROXYMODEL_H
#define THUMBNAILPROXYMODEL_H

#include <QIdentityProxyModel>
#include <QHash>
#include <QPixmap>

class PictureModel;

class ThumbnailProxyModel : public QIdentityProxyModel
{
public:
    ThumbnailProxyModel(QObject* parent = Q_NULLPTR);

    // QAbstractItemModel interface
public:
    QVariant data(const QModelIndex &index, int role) const override; // 提供缩略图数据给客户端

    // QAbstractProxyModel interface
public:
    void setSourceModel(QAbstractItemModel *sourceModel) override; // 注册由sourceModel发出端信号

public:
    PictureModel* pictureModel() const; // 辅助函数，将sourceModel转换为PictureModel*

private:
    void generateThumbnails(const QModelIndex& startIndex, int count); // 负责给一组给定的图片生成QPixmap缩略图
    void reloadThumbnails(); // 辅助函数，调用generateThumbnails（）前清楚存储的缩略图

private:
    QHash<QString, QPixmap*> mThumbnails; // key是filepath，存储对应的QPixmap*
};

#endif // THUMBNAILPROXYMODEL_H
