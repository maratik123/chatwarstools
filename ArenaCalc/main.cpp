#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationDomain(QStringLiteral("chatwarstools.free"));
    QCoreApplication::setOrganizationName(QStringLiteral("ChatWarsTools"));
    QCoreApplication::setApplicationName(QStringLiteral("ArenaCalc"));
    QCoreApplication::setApplicationVersion(QStringLiteral("1.0.0.0"));

    MainWindow::setGlobalTranslation(MainWindow::savedLocale(), false);

    a.installTranslator(&MainWindow::qtTranslator);
    a.installTranslator(&MainWindow::arenaCalcTranslator);

    MainWindow w;
    w.show();

    return a.exec();
}
