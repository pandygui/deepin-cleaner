#include "listwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

ListWidget::ListWidget(QWidget *parent)
    : QWidget(parent),
      m_layout(new QVBoxLayout(this)),
      m_packageCachesWidget(new ListItem(tr("Package Caches"))),
      m_crashReportsWidget(new ListItem(tr("Crash Reports"))),
      m_appLogsWidget(new ListItem(tr("Application Logs"))),
      m_appCachesWidget(new ListItem(tr("Application Caches"), false))
{
    m_layout->setMargin(0);
    m_layout->addWidget(m_packageCachesWidget);
    m_layout->addWidget(m_crashReportsWidget);
    m_layout->addWidget(m_appLogsWidget);
    m_layout->addWidget(m_appCachesWidget);

    setFixedHeight(240);
}

void ListWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QColor("#bbbbbb"));
    painter.setBrush(Qt::white);
    painter.drawRoundedRect(rect(), 8, 8);
}

void ListWidget::mousePressEvent(QMouseEvent *e)
{
    const int currentIndex = e->y() / 60;

    switch (currentIndex) {
    case 0:
        if (m_packageCachesWidget->isChecked())
            m_packageCachesWidget->setChecked(false);
        else
            m_packageCachesWidget->setChecked(true);
        break;
    case 1:
        if (m_crashReportsWidget->isChecked())
            m_crashReportsWidget->setChecked(false);
        else
            m_crashReportsWidget->setChecked(true);
        break;
    case 2:
        if (m_appLogsWidget->isChecked())
            m_appLogsWidget->setChecked(false);
        else
            m_appLogsWidget->setChecked(true);
        break;
    case 3:
        if (m_appCachesWidget->isChecked())
            m_appCachesWidget->setChecked(false);
        else
            m_appCachesWidget->setChecked(true);
        break;
    }
}
