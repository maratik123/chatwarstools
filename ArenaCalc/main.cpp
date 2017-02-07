#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QStringBuilder>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load(QStringLiteral("qt_") % QLocale::system().name(),
            QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    MainWindow w;
    w.show();

    return a.exec();
}
