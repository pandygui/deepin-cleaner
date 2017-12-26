#include "utils.h"
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QStandardPaths>

quint64 Utils::getFileSize(const QString &filePath)
{
    QFileInfo info(filePath);
    quint64 totalSize = 0;

    if (info.exists()) {
        if (info.isFile()) {
            totalSize += info.size();
        } else if (info.isDir()) {
            QDir dir(filePath);
            for (const QFileInfo &i : dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs)) {
                totalSize += getFileSize(i.absoluteFilePath());
            }
        }
    }

    return totalSize;
}

QFileInfoList Utils::getDpkgPackages()
{
    QDir reports("/var/cache/apt/archives");

    return reports.entryInfoList(QDir::Files);
}

QFileInfoList Utils::getCrashReports()
{
    QDir reports("/var/crash");

    return reports.entryInfoList(QDir::Files);
}

QFileInfoList Utils::getAppLogs()
{
    QDir logs("/var/log");

    return logs.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
}

QFileInfoList Utils::getAppCaches()
{
    const QString homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QDir caches(homePath + "/.cache");

    return caches.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
}
