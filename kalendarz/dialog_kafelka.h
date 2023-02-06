#ifndef DIALOG_KAFELKA_H
#define DIALOG_KAFELKA_H

#include <QDialog>
#include "wydarzenie.h"

namespace Ui {
class Dialog_kafelka;
}

class Dialog_kafelka : public QDialog
{
    Q_OBJECT

public:
     Dialog_kafelka(Wydarzenie wyd, QWidget *parent = nullptr);
    ~Dialog_kafelka();

private slots:
    void on_Save_clicked();

    void on_Cancel_clicked();

signals:
    void wydarzenie_accepted(Wydarzenie wydarzenie);
private:
    Ui::Dialog_kafelka *ui;
    Wydarzenie wydarzenie;
};

#endif // DIALOG_KAFELKA_H
