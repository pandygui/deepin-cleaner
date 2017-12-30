#include "listitem.h"
#include <QPainter>

ListItem::ListItem(const QString &title, bool isVisible, QWidget *parent)
    : QWidget(parent),
      m_isSeparatorVisible(isVisible),
      m_mainLayout(new QHBoxLayout(this)),
      m_titleLabel(new QLabel),
      m_checkBox(new QCheckBox)
{
    m_titleLabel->setText(title);
    m_mainLayout->addSpacing(10);
    m_mainLayout->addWidget(m_titleLabel);
    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_checkBox);
    m_mainLayout->addSpacing(10);

    m_checkBox->setFocusPolicy(Qt::NoFocus);
    m_checkBox->setChecked(true);
    setFixedHeight(60);
}

bool ListItem::isChecked()
{
    return m_checkBox->isChecked();
}

void ListItem::setChecked(bool isCheck)
{
    m_checkBox->setChecked(isCheck);
}

void ListItem::paintEvent(QPaintEvent *)
{
    if (!m_isSeparatorVisible) {
        return;
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor("#e4e4e4"));
    painter.drawRect(QRect(20, rect().height() - 1, rect().width() - 40, 1));
}
