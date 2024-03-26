#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow tray;
//    tray.hide();

    MainWindow w;
    w.show();
    return a.exec();
}
