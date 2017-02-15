#include "randomdialog.h"
#include "ui_randomdialog.h"

#include "randomholder.h"
#include "enums.h"
#include "enumclassutil.h"
#include <array>
#include <QSettings>

namespace {
const char* attackScope = "RandomDialogAttack";
const char* defenceScope = "RandomDialogDefence";

const std::array<const char*, 3> attackPart({
    QT_TRANSLATE_NOOP(attackScope, "head"),
    QT_TRANSLATE_NOOP(attackScope, "chest"),
    QT_TRANSLATE_NOOP(attackScope, "legs"),
});

const std::array<const char*, 3> defencePart({
    QT_TRANSLATE_NOOP(defenceScope, "head"),
    QT_TRANSLATE_NOOP(defenceScope, "chest"),
    QT_TRANSLATE_NOOP(defenceScope, "legs"),
});
}

RandomDialog::RandomDialog(QWidget *parent) :
    QDialog(parent,
            Qt::WindowTitleHint |
            Qt::WindowSystemMenuHint |
            Qt::WindowMinMaxButtonsHint |
            Qt::WindowCloseButtonHint),
    ui(new Ui::RandomDialog),
    uid(enumToId(PrivateParts::HEAD), enumToId(PrivateParts::LEGS)),
    curAttack(PrivateParts::UNKNOWN),
    curDefence(PrivateParts::UNKNOWN)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    QSettings settings;
    settings.beginGroup(objectName());
    restoreGeometry(settings.value(QStringLiteral("geometry")).toByteArray());
    settings.endGroup();

    updateForm();
}

void RandomDialog::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.beginGroup(objectName());
    settings.setValue(QStringLiteral("geometry"), saveGeometry());
    settings.endGroup();
    QDialog::closeEvent(event);
}

RandomDialog::~RandomDialog()
{
    delete ui;
}

void RandomDialog::updateAttackValue()
{
    curAttack = calcNewValue(curAttack, ui->attackDistinctCheckBox->isChecked());
}

void RandomDialog::updateDefenceValue()
{
    curDefence = calcNewValue(curDefence, ui->defenceDistinctCheckBox->isChecked());
}

void RandomDialog::updateAttackMsg()
{
    ui->attackLineEdit->setText(tr("Attack %1").arg(QCoreApplication::translate(attackScope, attackPart[enumToId(curAttack)])));
}

void RandomDialog::updateDefenceMsg()
{
    ui->defenceLineEdit->setText(tr("Defence %1").arg(QCoreApplication::translate(defenceScope, defencePart[enumToId(curDefence)])));
}

PrivateParts RandomDialog::calcNewValue(PrivateParts oldValue, bool distinct)
{
    PrivateParts newValue;
    auto &engine = RandomHolder::getInstance().mainEngine();
    do {
        newValue = idToEnum<PrivateParts>(uid(engine));
    } while (distinct && newValue == oldValue);

    return newValue;
}

void RandomDialog::updateForm()
{
    updateAttackValue();
    updateDefenceValue();
    updateAttackMsg();
    updateDefenceMsg();
}

void RandomDialog::generatePressed()
{
    updateForm();
}

void RandomDialog::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
        updateAttackMsg();
        updateDefenceMsg();
    }
    QDialog::changeEvent(event);
}
