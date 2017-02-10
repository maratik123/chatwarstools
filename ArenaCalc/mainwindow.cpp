#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "randomdialog.h"
#include <QDir>
#include <QTranslator>
#include <QLibraryInfo>
#include <QSettings>

namespace {
const QString &translationsPath = QStringLiteral(":/translations");
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createLanguageMenu();

    QSettings settings;
    settings.beginGroup(objectName());
    restoreGeometry(settings.value(QStringLiteral("geometry")).toByteArray());
    restoreState(settings.value(QStringLiteral("windowState")).toByteArray());
    settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.beginGroup(objectName());
    settings.setValue(QStringLiteral("geometry"), saveGeometry());
    settings.setValue(QStringLiteral("windowState"), saveState());
    settings.endGroup();
    for(RandomDialog *rndDlg : findChildren<RandomDialog *>(QString(), Qt::FindDirectChildrenOnly)) {
        rndDlg->close();
    }
    QMainWindow::closeEvent(event);
}

QString MainWindow::savedLocale()
{
    QSettings settings;
    settings.beginGroup(QStringLiteral("translation"));
    return settings.value(QStringLiteral("locale"), QLocale::system().name().left(2)).toString();
}

void MainWindow::createLanguageMenu()
{
    languageActionGroup = new QActionGroup(this);

    QDir qmDir(translationsPath);
    const QStringList &fileNames = qmDir.entryList(QStringList(QStringLiteral("ArenaCalc_*.qm")));
    const QString &actionString = QStringLiteral("%1 %2");
    const QString &preferredLocale = savedLocale();
    const QLatin1String defaultLocale("en");
    QAction *defaultAction = nullptr;
    bool actionChecked = false;
    int i = 1;
    for (const QString &fileName : fileNames) {
        QString locale(fileName);
        locale.remove(0, locale.indexOf(QLatin1Char('_')) + 1).chop(3);
        QTranslator translator;
        translator.load(fileName, qmDir.absolutePath());
        const QString &language = translator.translate("MainWindow", "English");

        QAction *action = new QAction(actionString.arg(i).arg(language), this);
        ++i;
        action->setCheckable(true);
        action->setData(locale);

        ui->menuLanguage->addAction(action);
        languageActionGroup->addAction(action);

        if (locale == preferredLocale) {
            action->setChecked(true);
            actionChecked = true;
        } else if (!actionChecked && defaultAction == nullptr && locale == defaultLocale) {
            defaultAction = action;
        }
    }

    connect(languageActionGroup, &QActionGroup::triggered, this, &MainWindow::switchLanguage);

    if (!actionChecked) {
        if (defaultAction != nullptr) {
            defaultAction->setChecked(true);
        } else {
            languageActionGroup->actions().constFirst()->setChecked(true);
        }
    }
}

QTranslator MainWindow::qtTranslator;
QTranslator MainWindow::arenaCalcTranslator;

void MainWindow::setGlobalTranslation(const QString &strLocale, bool sendSignal)
{
    const QString &underscore = QStringLiteral("_");
    QLocale locale(strLocale);
    qtTranslator.load(locale, QStringLiteral("qt"),  underscore, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    arenaCalcTranslator.load(locale, QStringLiteral("ArenaCalc"), underscore, translationsPath);

    if (sendSignal) {
        QCoreApplication::postEvent(QCoreApplication::instance(), new QEvent(QEvent::LanguageChange));
    }
}

void MainWindow::switchLanguage(QAction *action)
{
    const QString &strLocale = action->data().toString();
    setGlobalTranslation(strLocale);
    QSettings settings;
    settings.beginGroup(QStringLiteral("translation"));
    settings.setValue(QStringLiteral("locale"), strLocale);
    settings.endGroup();
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
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
    QMainWindow::changeEvent(event);
}
