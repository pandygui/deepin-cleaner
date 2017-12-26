#ifndef SCANPAGE_H
#define SCANPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "itemwidget.h"
#include <QFileInfo>

class ScanPage : public QWidget
{
    Q_OBJECT

public:
    ScanPage(QWidget *parent = nullptr);

    void start();

signals:
    void clearBtnClicked();

private:
    int scan(const QFileInfoList &infos);
    void scanPackageCaches();
    void scanCrashReports();
    void scanApplicationLogs();
    void scanApplicationCaches();

private:
    QVBoxLayout *m_layout;
    QLabel *m_tipsLabel;
    QLabel *m_totalLabel;
    QPushButton *m_clearButton;

    ItemWidget *m_pcWidget;
    ItemWidget *m_crWidget;
    ItemWidget *m_alWidget;
    ItemWidget *m_acWidget;
};

#endif // SCANPAGE_H
