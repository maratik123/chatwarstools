#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QActionGroup;
class QTranslator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static void setGlobalTranslation(const QString &strLocale, bool sendSignal = true);
    ~MainWindow();
    static QString savedLocale();

    static QTranslator qtTranslator;
    static QTranslator arenaCalcTranslator;

protected:
    void changeEvent(QEvent *event);
    void closeEvent(QCloseEvent *event);

public slots:
    void showRandomDialog();
    void switchLanguage(QAction *action);

private:
    Ui::MainWindow *ui;
    QActionGroup *languageActionGroup;

    void createLanguageMenu();
};

#endif // MAINWINDOW_H
