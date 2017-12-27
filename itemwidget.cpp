#include "itemwidget.h"

ItemWidget::ItemWidget(QWidget *parent)
    : QWidget(parent),
      m_layout(new QHBoxLayout(this)),
      m_titleLabel(new QLabel),
      m_sizeLabel(new QLabel("0.0 MB"))
{
    m_layout->addWidget(m_titleLabel);
    m_layout->addStretch();
    m_layout->addWidget(m_sizeLabel);
    m_sizeLabel->setStyleSheet("QLabel { color: #585858; }");

    setFixedHeight(40);
}

void ItemWidget::setTitle(const QString &text)
{
    m_titleLabel->setText(text);
}

void ItemWidget::setSize(const QString &text)
{
    m_sizeLabel->setText(text);
}


