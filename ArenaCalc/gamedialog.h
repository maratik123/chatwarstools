#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>

namespace Ui {
class GameDialog;
}

class GameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameDialog(QWidget *parent = 0);
    ~GameDialog();

private:
    Ui::GameDialog *ui;
};

#endif // GAMEDIALOG_H
