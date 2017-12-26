#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    ItemWidget(QWidget *parent = nullptr);

    void setTitle(const QString &text);
    void setSize(const QString &text);

private:
    QHBoxLayout *m_layout;
    QLabel *m_titleLabel;
    QLabel *m_sizeLabel;
};

#endif // ITEMWIDGET_H
