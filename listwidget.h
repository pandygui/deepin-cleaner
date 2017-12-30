#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "listitem.h"

class ListWidget : public QWidget
{
    Q_OBJECT

public:
    ListWidget(QWidget *parent = nullptr);

    void addChild(const QString &title);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private:
    QVBoxLayout *m_layout;
    ListItem *m_packageCachesWidget;
    ListItem *m_crashReportsWidget;
    ListItem *m_appLogsWidget;
    ListItem *m_appCachesWidget;
};

#endif // LISTWIDGET_H
