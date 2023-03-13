#ifndef PICTUREDELEGATE_H
#define PICTUREDELEGATE_H

#include <QStyledItemDelegate>

 // 此类将缩略图名字放到一个横幅里，此横幅在图片上方相邻
class PictureDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    PictureDelegate(QObject* parent = Q_NULLPTR);

    // QAbstractItemDelegate interface
public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override; // 将允许我们按照我们想要的方式绘制Item项目
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override; // 被用来指定Item项目的大小
};

#endif // PICTUREDELEGATE_H
