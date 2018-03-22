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

#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>

class ListModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum ItemRole {
        ItemTextRole = Qt::DisplayRole,
        ItemSelectedRole,
        ItemHoverRole
    };

    ListModel(QObject *parent = nullptr);
    ~ListModel();

    int rowCount(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role) const;

    void setHoveredIndex(const QModelIndex &index);
    void setSelectedIndex(const QModelIndex &index);

public slots:
    void append(const QString &text);
    void clear();

private:
    QList<QString> m_options;
    QList<bool> m_selecteds;
    QModelIndex m_hoveredIndex;
};

#endif
