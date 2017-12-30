#ifndef LISTITEM_H
#define LISTITEM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>

class ListItem : public QWidget
{
    Q_OBJECT

public:
    ListItem(const QString &title, bool isVisible = true, QWidget *parent = nullptr);

    bool isChecked();
    void setChecked(bool isCheck);

protected:
    void paintEvent(QPaintEvent *);

private:
    QHBoxLayout *m_mainLayout;
    QLabel *m_titleLabel;
    QCheckBox *m_checkBox;
    bool m_isSeparatorVisible;
};

#endif // LISTITEM_H
