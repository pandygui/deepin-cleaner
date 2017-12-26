#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QListWidget>
#include <QListWidgetItem>
#include "listitem.h"

class ListWidget : public QListWidget
{
    Q_OBJECT

public:
    ListWidget(QWidget *parent = nullptr);

    void addChild(const QString &title);

private slots:
    void handleItemClicked();
};

#endif // LISTWIDGET_H
