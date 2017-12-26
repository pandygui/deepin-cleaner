#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "listwidget.h"

class HomePage : public QWidget
{
    Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr);

signals:
    void scanBtnClicked();

private:
    QVBoxLayout *m_mainLayout;
    QLabel *m_tipsLabel;
    ListWidget *m_listWidget;
    QPushButton *m_scanButton;
};

#endif // HOMEPAGE_H
