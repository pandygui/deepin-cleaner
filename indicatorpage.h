#ifndef INDICATORPAGE_H
#define INDICATORPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "dspinner.h"

DWIDGET_USE_NAMESPACE

class IndicatorPage : public QWidget
{
    Q_OBJECT

public:
    explicit IndicatorPage(QWidget *parent = nullptr);

private:
    QVBoxLayout *m_layout;
    QLabel *m_tipsLabel;
    DSpinner *m_spinner;
};

#endif // INDICATORPAGE_H
