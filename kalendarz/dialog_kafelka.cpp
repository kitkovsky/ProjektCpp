#include "dialog_kafelka.h"

#include "ui_dialog_kafelka.h"

Dialog_kafelka::Dialog_kafelka(Wydarzenie wyd, QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog_kafelka), wydarzenie(wyd) {
    ui->setupUi(this);
    ui->timeEdit->setTime(wyd.getTimeStart());
    ui->timeEdit_2->setTime(wyd.getTimeEnd());
    ui->lineEdit->setText(wyd.getText());
}

Dialog_kafelka::~Dialog_kafelka() { delete ui; }

void Dialog_kafelka::on_Save_clicked() {
    Wydarzenie w(wydarzenie.getDate(), ui->timeEdit->time(),
                 ui->timeEdit_2->time(), ui->lineEdit->text());
    emit wydarzenie_accepted(w);
    accept();
}

void Dialog_kafelka::on_Cancel_clicked() { accept(); }
