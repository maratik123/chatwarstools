#include "randomdialog.h"
#include "ui_randomdialog.h"

#include "randomholder.h"

RandomDialog::RandomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomDialog),
    uid(enumToId(PrivateParts::HEAD), enumToId(PrivateParts::LEGS)),
    curAttack(PrivateParts::UNKNOWN),
    curDefence(PrivateParts::UNKNOWN)
{
    ui->setupUi(this);
    updateForm();
}

RandomDialog::~RandomDialog()
{
    delete ui;
}

void RandomDialog::updateAttack()
{
    putMsg(curAttack, ui->attackLineEdit, ui->attackDistinctCheckBox->isChecked(), commonStringHolder(StringID::ATTACK));
}

void RandomDialog::updateDefence()
{
    putMsg(curDefence, ui->defenceLineEdit, ui->defenceDistinctCheckBox->isChecked(), commonStringHolder(StringID::DEFENCE));
}

void RandomDialog::putMsg(PrivateParts &curPart, QLineEdit *placeToPut, bool distinct, const QString &message)
{
    PrivateParts oldValue = curPart;
    PrivateParts newValue;
    auto &engine = RandomHolder::getInstance().mainEngine();
    do {
        newValue = idToEnum<PrivateParts>(uid(engine));
    } while (distinct && newValue == oldValue);

    curPart = newValue;

    placeToPut->setText(message.arg(commonStringHolder(enumToEnum<StringID>(newValue))));
}

void RandomDialog::updateForm()
{
    updateAttack();
    updateDefence();
}

void RandomDialog::generatePressed()
{
    updateForm();
}
