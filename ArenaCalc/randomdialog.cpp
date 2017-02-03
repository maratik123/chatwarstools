#include "randomdialog.h"
#include "ui_randomdialog.h"

#include "randomholder.h"

RandomDialog::RandomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomDialog),
    uid(0, 2)
{
    ui->setupUi(this);
}

RandomDialog::~RandomDialog()
{
    delete ui;
}

void RandomDialog::attackPressed() {
    putMsg(ui->attackLineEdit, tr("Attack %1"));
}

void RandomDialog::defencePressed() {
    putMsg(ui->defenceLineEdit, tr("Defence %1"));
}

void RandomDialog::putMsg(QLineEdit *placeToPut, const QString &message) {
    int value = uid(RandomHolder::getInstance().mainEngine());
    placeToPut->setText(message.arg(value));
}
