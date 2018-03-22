/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "listdelegate.h"
#include "listmodel.h"
#include <QPainter>

ListDelegate::ListDelegate(QObject *parent)
    : QAbstractItemDelegate(parent)
{

}

ListDelegate::~ListDelegate()
{
}

void ListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const bool isHover = index.data(ListModel::ItemHoverRole).toBool();
    const QRect rect = option.rect;

    painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
    painter->setBrush(Qt::red);
    painter->setPen(Qt::black);

    if (isHover) {
        QPainterPath path;
        path.addRoundedRect(rect, 6, 6);
        painter->fillPath(path, QColor(0, 0, 0, 0.05 * 255));
    }

    painter->drawText(rect, Qt::AlignVCenter | Qt::AlignLeft, index.data(Qt::DisplayRole).toString());

    if (index.data(ListModel::ItemSelectedRole).toBool())
    {
        // const int x = option.rect.right() - 16 - 14;
        // const int y = option.rect.top() + (option.rect.height() - 16) / 2;
        // painter->drawPixmap(x, y, loadPixmap(":/images/check.svg"));

        painter->drawText(rect, Qt::AlignVCenter | Qt::AlignRight, "hhh");
    }
}

QSize ListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);

    return QSize(-1, 60);
}
