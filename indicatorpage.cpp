#include "indicatorpage.h"

IndicatorPage::IndicatorPage(QWidget *parent) :
    QWidget(parent),
    m_tipsLabel(new QLabel(tr("Scanning"))),
    m_layout(new QVBoxLayout(this))
{
    QFont font;
    font.setPointSize(15);
    m_tipsLabel->setFont(font);

    m_spinner = new DSpinner;
    m_spinner->setBackgroundColor(Qt::transparent);
    m_spinner->setFixedSize(40, 40);

    m_layout->addStretch();
    m_layout->addWidget(m_spinner, 0, Qt::AlignHCenter);
    m_layout->addSpacing(20);
    m_layout->addWidget(m_tipsLabel, 0, Qt::AlignHCenter);
    m_layout->addStretch();
}

void IndicatorPage::animationStart()
{
    m_spinner->start();
}

void IndicatorPage::animationStop()
{
    m_spinner->stop();
}
