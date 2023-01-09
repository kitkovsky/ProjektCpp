#ifndef DIALOG_KAFELKA_H
#define DIALOG_KAFELKA_H

#include <QDialog>

namespace Ui {
class Dialog_kafelka;
}

class Dialog_kafelka : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_kafelka(QWidget *parent = nullptr);
    ~Dialog_kafelka();

private slots:
    void on_Save_clicked();

    void on_Cancel_clicked();

private:
    Ui::Dialog_kafelka *ui;
};

#endif // DIALOG_KAFELKA_H
