#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <QStackedLayout>
#include "homepage.h"
#include "indicatorpage.h"
#include "scanpage.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleBtnClicked();
    void handleClearBtnClicked();

private:
    QWidget *m_centralWidget;
    QStackedLayout *m_centralLayout;
    HomePage *m_homePage;
    IndicatorPage *m_indicatorPage;
    ScanPage *m_scanPage;
};

#endif // MAINWINDOW_H
