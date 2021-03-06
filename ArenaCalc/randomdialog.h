#ifndef RANDOMDIALOG_H
#define RANDOMDIALOG_H

#include <QDialog>
#include <random>
#include <utility>

#include "enums.h"

class QLineEdit;

namespace Ui {
class RandomDialog;
}

class RandomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RandomDialog(QWidget *parent = 0);
    ~RandomDialog();

public slots:
    void generatePressed();

protected:
    void changeEvent(QEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    Ui::RandomDialog *ui;
    std::uniform_int_distribution<int> uid;
    PrivateParts curAttack;
    PrivateParts curDefence;

    PrivateParts calcNewValue(PrivateParts oldValue, bool distinct);
    void updateForm();
    void updateAttackValue();
    void updateAttackMsg();
    void updateDefenceValue();
    void updateDefenceMsg();
};

#endif // RANDOMDIALOG_H
