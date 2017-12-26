#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent)
    : QListWidget(parent)
{
    setSelectionMode(QAbstractItemView::NoSelection);
    setStyleSheet("QListView {"
                  "border: 1px solid #eee;"
                  "border-radius: 4px;"
                  "}");

    addChild(tr("Package Caches"));
    addChild(tr("Crash Reports"));
    addChild(tr("Application Logs"));
    addChild(tr("Application Caches"));

    connect(this, &ListWidget::itemClicked, this, &ListWidget::handleItemClicked);
}

void ListWidget::addChild(const QString &title)
{
    QListWidgetItem *item = new QListWidgetItem;
    ListItem *child = new ListItem(title);

    item->setSizeHint(QSize(100, 65));
    addItem(item);
    setItemWidget(item, child);
}

void ListWidget::handleItemClicked()
{
    ListItem *item = qobject_cast<ListItem *>(indexWidget(currentIndex()));

    if (item->isChecked()) {
        item->setChecked(false);
    } else {
        item->setChecked(true);
    }
}
