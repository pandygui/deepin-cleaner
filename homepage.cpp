#include "homepage.h"

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
    m_listWidget->setFixedHeight(300);

    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_tipsLabel, 0, Qt::AlignHCenter);
    m_mainLayout->addStretch();
    m_mainLayout->setMargin(25);
    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_listWidget, 0, Qt::AlignVCenter);
    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_scanButton, 0, Qt::AlignVCenter);

    m_scanButton->setObjectName("BlueButton");
    m_scanButton->setStyleSheet("#BlueButton {"
                                "color: #2CA7F8;"
                                "border: 1px solid #2ca7f8;"
                                "border-radius: 4px;"
                                "width: 120px;"
                                "height: 36px;"
                                "}"
                                "#BlueButton:hover {"
                                "color: white;"
                                "background-color: qlineargradient(x1:0 y1:0, x2:0 y2:1, stop:0 #8ccfff, stop:1 #4bb8ff);"
                                "}"
                                "#BlueButton:pressed {"
                                "background-color: qlineargradient(x1:0 y1:0, x2:0 y2:1, stop:0 #0b8cff, stop:1 #0aa1ff);"
                                "}");

    connect(m_scanButton, &QPushButton::clicked, this, &HomePage::scanBtnClicked);
}
