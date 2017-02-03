#ifndef RANDOMDIALOG_H
#define RANDOMDIALOG_H

#include <QDialog>

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
};

#endif // RANDOMDIALOG_H
