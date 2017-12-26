#ifndef SCANPAGE_H
#define SCANPAGE_H

#include <QWidget>
#include <QVBoxLayout>

class ScanPage : public QWidget
{
    Q_OBJECT

public:
    ScanPage(QWidget *parent = nullptr);

private:
    QVBoxLayout *m_layout;
};

#endif // SCANPAGE_H
