#include "randomdialog.h"
#include "ui_randomdialog.h"

#include "randomholder.h"
#include "commonstringholder.h"

namespace {
enum class PrivateParts {
    HEAD = enumToId(StringID::HEAD),
    CHEST = enumToId(StringID::CHEST),
    LEGS = enumToId(StringID::LEGS)
};
}

RandomDialog::RandomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomDialog),
    uid(enumToId(PrivateParts::HEAD), enumToId(PrivateParts::LEGS))
{
    ui->setupUi(this);
}

RandomDialog::~RandomDialog()
{
    delete ui;
}

void RandomDialog::attackPressed()
{
    putMsg(ui->attackLineEdit, commonStringHolder(StringID::ATTACK));
}

void RandomDialog::defencePressed()
{
    putMsg(ui->defenceLineEdit, commonStringHolder(StringID::DEFENCE));
}

void RandomDialog::putMsg(QLineEdit *placeToPut, const QString &message)
{
    auto value = uid(RandomHolder::getInstance().mainEngine());
    placeToPut->setText(message.arg(commonStringHolder(idToEnum<StringID>(value))));
}
