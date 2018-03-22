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

#include "listmodel.h"
#include <QDebug>

ListModel::ListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

ListModel::~ListModel()
{
}

int ListModel::rowCount(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return m_options.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case ItemTextRole:  return m_options.at(index.row());
    case ItemHoverRole: return m_hoveredIndex == index;
    case ItemSelectedRole: return m_selecteds.at(index.row());
    default: ;
    }

    return QVariant();
}

void ListModel::setHoveredIndex(const QModelIndex &index)
{
    m_hoveredIndex = index;

    emit dataChanged(index, index);
}

void ListModel::setSelectedIndex(const QModelIndex &index)
{
    const int rowIndex = index.row();

    if (m_selecteds.at(rowIndex)) {
        m_selecteds[rowIndex] = false;
    } else {
        m_selecteds[rowIndex] = true;
    }

    emit dataChanged(index, index);
}

void ListModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, m_options.size());
    m_options.clear();
    m_selecteds.clear();
    endRemoveRows();
}

void ListModel::append(const QString &text)
{
    beginInsertRows(QModelIndex(), m_options.size(), m_options.size());
    m_options.append(text);
    m_selecteds.append(false);
    endInsertRows();
}
