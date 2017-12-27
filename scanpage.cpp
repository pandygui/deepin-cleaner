#include "scanpage.h"
#include "utils.h"

ScanPage::ScanPage(QWidget *parent)
    : QWidget(parent),
      m_layout(new QVBoxLayout(this)),
      m_tipsLabel(new QLabel(tr("Total Size"))),
      m_totalLabel(new QLabel),
      m_clearButton(new QPushButton(tr("Clean up now"))),
      m_pcWidget(new ItemWidget),
      m_crWidget(new ItemWidget),
      m_alWidget(new ItemWidget),
      m_acWidget(new ItemWidget)
{
    QFont font;
    font.setPointSize(27);
    m_tipsLabel->setFont(font);

    font.setPointSize(17);
    m_totalLabel->setText("0.0 MB");
    m_totalLabel->setFont(font);

    m_clearButton->setFixedHeight(40);

    // init ItemWidget
    m_pcWidget->setTitle(tr("Package Caches"));
    m_crWidget->setTitle(tr("Crash Reports"));
    m_alWidget->setTitle(tr("Application Logs"));
    m_acWidget->setTitle(tr("Application Caches"));

    m_layout->setMargin(25);
    m_layout->addWidget(m_tipsLabel, 0, Qt::AlignHCenter);
    m_layout->addWidget(m_totalLabel, 0, Qt::AlignHCenter | Qt::AlignTop);
    m_layout->addSpacing(20);
    m_layout->addWidget(m_pcWidget);
    m_layout->addWidget(m_crWidget);
    m_layout->addWidget(m_alWidget);
    m_layout->addWidget(m_acWidget);
    m_layout->addStretch();
    m_layout->addWidget(m_clearButton);
    m_layout->addSpacing(5);

    connect(m_clearButton, &QPushButton::clicked, this, &ScanPage::clearBtnClicked);

    start();
}

void ScanPage::start()
{
    scanPackageCaches();
    scanCrashReports();
    scanApplicationLogs();
    scanApplicationCaches();
}

int ScanPage::scan(const QFileInfoList &infos)
{
    quint64 totalSize = 0;

    for (const QFileInfo &i : infos) {
        const QString path = i.absoluteFilePath();
        quint64 size = Utils::getFileSize(path);

        totalSize += size;
    }

    return totalSize;
}

void ScanPage::scanPackageCaches()
{
    m_pcWidget->setSize(Utils::formatBytes(scan(Utils::getDpkgPackages())));
    m_pcWidget->show();
}

void ScanPage::scanCrashReports()
{
    m_crWidget->setSize(Utils::formatBytes(scan(Utils::getCrashReports())));
    m_crWidget->show();
}

void ScanPage::scanApplicationLogs()
{
    m_alWidget->setSize(Utils::formatBytes(scan(Utils::getAppLogs())));
    m_alWidget->show();
}

void ScanPage::scanApplicationCaches()
{
    m_acWidget->setSize(Utils::formatBytes(scan(Utils::getAppCaches())));
    m_acWidget->show();
}
