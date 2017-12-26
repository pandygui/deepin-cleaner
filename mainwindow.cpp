#include "mainwindow.h"
#include "dtitlebar.h"
#include "dhidpihelper.h"

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent),
      m_centralWidget(new QWidget),
      m_centralLayout(new QStackedLayout(m_centralWidget)),
      m_homePage(new HomePage),
      m_indicatorPage(new IndicatorPage),
      m_scanPage(new ScanPage)
{
    if (titlebar()) {
        titlebar()->setTitle("");
    }

    m_centralLayout->addWidget(m_homePage);
    m_centralLayout->addWidget(m_indicatorPage);
    m_centralLayout->addWidget(m_scanPage);

    setCentralWidget(m_centralWidget);

    connect(m_homePage, &HomePage::scanBtnClicked, this, &MainWindow::handleBtnClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::handleBtnClicked()
{
    m_centralLayout->setCurrentIndex(1);
}