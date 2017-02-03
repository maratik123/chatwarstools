#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "randomdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showRandomDialog() {
    RandomDialog *randomDialog = new RandomDialog(this);
    randomDialog->show();
}
