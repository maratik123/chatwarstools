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
    static void setGlobalTranslation(const QLocale &locale, bool sendSignal = true);
    ~MainWindow();

    static QTranslator qtTranslator;
    static QTranslator arenaCalcTranslator;


protected:
    void changeEvent(QEvent *event);

public slots:
    void showRandomDialog();
    void switchLanguage(QAction *action);

private:
    Ui::MainWindow *ui;
    QActionGroup *languageActionGroup;

    void createLanguageMenu();
};

#endif // MAINWINDOW_H
