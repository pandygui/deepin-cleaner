#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QFileInfoList>

namespace Utils
{
    quint64 getFileSize(const QString &filePath);
    QFileInfoList getDpkgPackages();
    QFileInfoList getCrashReports();
    QFileInfoList getAppLogs();
    QFileInfoList getAppCaches();
    QString getHomePath();
}

#endif // UTILS_H
