#include "indicatorpage.h"

IndicatorPage::IndicatorPage(QWidget *parent) :
    QWidget(parent),
    m_tipsLabel(new QLabel(tr("Scanning"))),
    m_layout(new QVBoxLayout(this))
{
    QFont font;
    font.setPointSize(20);
    m_tipsLabel->setFont(font);

    m_spinner = new DSpinner;
    m_spinner->setFixedSize(70, 70);
    m_spinner->start();

    m_layout->addStretch();
    m_layout->addWidget(m_spinner, 0, Qt::AlignHCenter);
    m_layout->addSpacing(30);
    m_layout->addWidget(m_tipsLabel, 0, Qt::AlignHCenter);
    m_layout->addStretch();
}
