#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow::setGlobalTranslation(QLocale::system(), false);

    a.installTranslator(&MainWindow::qtTranslator);
    a.installTranslator(&MainWindow::arenaCalcTranslator);

    MainWindow w;
    w.show();

    return a.exec();
}
