#ifndef RANDOMDIALOG_H
#define RANDOMDIALOG_H

#include <QDialog>
#include <random>

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
    void attackPressed();
    void defencePressed();

private:
    Ui::RandomDialog *ui;
    std::uniform_int_distribution<std::size_t> uid;

    void putMsg(QLineEdit *placeToPut, const QString &message);
};

#endif // RANDOMDIALOG_H
