#include "mainwindow.h"
#include <DApplication>
#include <DWidgetUtil>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setTheme("light");
    a.loadTranslator();

    MainWindow w;
    w.setFixedSize(400, 550);
    w.setWindowIcon(QIcon(":/images/deepin-cleaner.svg"));
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
