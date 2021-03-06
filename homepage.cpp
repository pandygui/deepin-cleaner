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

#include "homepage.h"
#include <QVBoxLayout>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent),
      m_listView(new ListView),
      m_listModel(new ListModel)
{
    m_listModel->append("Package Caches");
    m_listModel->append("Crash Reports");
    m_listModel->append("Application Logs");
    m_listModel->append("Application Caches");

    m_listView->setModel(m_listModel);
    m_listView->setItemDelegate(new ListDelegate);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_listView);
    
    connect(m_listView, &ListView::entered, m_listModel, &ListModel::setHoveredIndex);
    connect(m_listView, &ListView::clicked, m_listModel, &ListModel::setSelectedIndex);
}

HomePage::~HomePage()
{
}
