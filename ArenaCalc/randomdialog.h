#ifndef RANDOMDIALOG_H
#define RANDOMDIALOG_H

#include <QDialog>
#include <random>

#include "commonstringholder.h"

class QLineEdit;

namespace Ui {
class RandomDialog;
}

enum class PrivateParts {
    UNKNOWN = enumToId(StringID::UNKNOWN),
    HEAD = enumToId(StringID::HEAD),
    CHEST = enumToId(StringID::CHEST),
    LEGS = enumToId(StringID::LEGS)
};

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

private:
    Ui::RandomDialog *ui;
    std::uniform_int_distribution<int> uid;
    PrivateParts curAttack;
    PrivateParts curDefence;

    void putMsg(PrivateParts& curPart, QLineEdit *placeToPut, bool distinct, const QString &message);
    void updateForm();
    void updateAttack();
    void updateDefence();
};

#endif // RANDOMDIALOG_H
