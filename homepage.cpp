#include "homepage.h"
#include "listitem.h"
#include <QSvgWidget>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent),
      m_mainLayout(new QVBoxLayout(this)),
      m_tipsLabel(new QLabel),
      m_listWidget(new ListWidget),
      m_scanButton(new QPushButton(tr("Scan")))
{
    QFont font;
    font.setPointSize(18);
    m_tipsLabel->setFont(font);
    m_tipsLabel->setText(tr("Select the items to clear"));

    QSvgWidget *homeIcon = new QSvgWidget(":/images/home-icon.svg");
    homeIcon->setFixedSize(65, 65);

    m_mainLayout->addWidget(homeIcon, 0, Qt::AlignHCenter);
    m_mainLayout->addSpacing(10);
    m_mainLayout->addWidget(m_tipsLabel, 0, Qt::AlignHCenter);
    m_mainLayout->setMargin(25);
    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_listWidget, 0, Qt::AlignVCenter);
    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_scanButton, 0, Qt::AlignVCenter);

    m_scanButton->setObjectName("BlueButton");

    connect(m_scanButton, &QPushButton::clicked, this, &HomePage::scanBtnClicked);
}
