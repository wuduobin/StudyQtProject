#include "picturedelegate.h"

#include <QPainter>

constexpr unsigned int BANNER_HEIGHT = 20;
constexpr unsigned int BANNER_COLOR = 0x303030;
constexpr unsigned int BANNER_ALPHA = 200;
constexpr unsigned int BANNER_TEXT_COLOR = 0xffffff;
constexpr unsigned int HIGHLIGHT_ALPHA = 100;

PictureDelegate::PictureDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}


void PictureDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save(); // 在做任何事前要保存一下painter状态

    QPixmap pixmap = index.model()->data(index, Qt::DecorationRole).value<QPixmap>(); // 查找缩略图
    painter->drawPixmap(option.rect.x(), option.rect.y(), pixmap); // 画出缩略图

    // 用QPainter::fillRect()函数在缩略图的顶部画一个半透明的灰色横幅
    QRect bannerRect = QRect(option.rect.x(), option.rect.y(), pixmap.width(), BANNER_HEIGHT);
    QColor bannerColor = QColor(BANNER_COLOR);
    bannerColor.setAlpha(BANNER_ALPHA);
    painter->fillRect(bannerRect, bannerColor);

    QString filename = index.model()->data(index, Qt::DisplayRole).toString(); // 查找item要显示的名字
    painter->setPen(BANNER_TEXT_COLOR);
    painter->drawText(bannerRect, Qt::AlignCenter, filename); // 将显示的名字画在横幅上

    // item选中状态，使用该item中的高亮色在顶部画一个半透明的矩形
    if (option.state.testFlag(QStyle::State_Selected)) {
        QColor selectedColor = option.palette.highlight().color();
        selectedColor.setAlpha(HIGHLIGHT_ALPHA);
        painter->fillRect(option.rect, selectedColor);
    }

    painter->restore(); // 恢复painter到原来的状态
}

QSize PictureDelegate::sizeHint(const QStyleOptionViewItem& /*option*/, const QModelIndex &index) const
{
    const QPixmap& pixmap = index.model()->data(index, Qt::DecorationRole).value<QPixmap>();
    return pixmap.size();
}
