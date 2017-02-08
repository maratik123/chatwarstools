#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "randomdialog.h"
#include <QDir>
#include <QTranslator>
#include <QLibraryInfo>

namespace {
const QString &translationsPath = QStringLiteral(":/translations");
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createLanguageMenu();
}

void MainWindow::createLanguageMenu()
{
    languageActionGroup = new QActionGroup(this);

    QDir qmDir(translationsPath);
    const QStringList &fileNames = qmDir.entryList(QStringList(QStringLiteral("ArenaCalc_*.qm")));
    const QString &actionString = QStringLiteral("%1 %2");
    const QString &systemLanguage = QLocale::system().name().left(2);
    const QLatin1String defaultLocale("en");
    QAction *defaultAction = nullptr;
    bool actionChecked = false;
    for (int i = 0; i < fileNames.size(); ++i) {
        QString locale(fileNames[i]);
        locale.remove(0, locale.indexOf(QLatin1Char('_')) + 1).chop(3);
        QTranslator translator;
        translator.load(fileNames[i], qmDir.absolutePath());
        const QString &language = translator.translate("MainWindow", "English");

        QAction *action = new QAction(actionString.arg(i + 1).arg(language), this);
        action->setCheckable(true);
        action->setData(locale);

        ui->menuLanguage->addAction(action);
        languageActionGroup->addAction(action);

        if (locale == systemLanguage) {
            action->setChecked(true);
            actionChecked = true;
        } else if (!actionChecked && locale == defaultLocale) {
            defaultAction = action;
        }
    }

    if (!actionChecked && defaultAction != nullptr) {
        defaultAction->setChecked(true);
    }

    connect(languageActionGroup, &QActionGroup::triggered, this, &MainWindow::switchLanguage);
}

QTranslator MainWindow::qtTranslator;
QTranslator MainWindow::arenaCalcTranslator;

void MainWindow::setGlobalTranslation(const QLocale &locale, bool sendSignal)
{
    const QString &underscore = QStringLiteral("_");
    qtTranslator.load(locale, QStringLiteral("qt"),  underscore, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    arenaCalcTranslator.load(locale, QStringLiteral("ArenaCalc"), underscore, translationsPath);

    if (sendSignal) {
        QCoreApplication::postEvent(QCoreApplication::instance(), new QEvent(QEvent::LanguageChange));
    }
}

void MainWindow::switchLanguage(QAction *action)
{
    setGlobalTranslation(QLocale(action->data().toString()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRandomDialog()
{
    RandomDialog *randomDialog = new RandomDialog(this);
    randomDialog->show();
}

void MainWindow::changeEvent(QEvent *event)
{
    switch(event->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        QMainWindow::changeEvent(event);
        break;
    }
}
