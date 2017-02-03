#include "randomdialog.h"
#include "ui_randomdialog.h"

RandomDialog::RandomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomDialog)
{
    ui->setupUi(this);
}

RandomDialog::~RandomDialog()
{
    delete ui;
}

void RandomDialog::attackPressed() {

}

void RandomDialog::defencePressed() {

}
