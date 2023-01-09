#include "dialog_kafelka.h"
#include "ui_dialog_kafelka.h"

Dialog_kafelka::Dialog_kafelka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_kafelka)
{
    ui->setupUi(this);
}

Dialog_kafelka::~Dialog_kafelka()
{
    delete ui;
}

void Dialog_kafelka::on_Save_clicked()
{
    accept();
}


void Dialog_kafelka::on_Cancel_clicked()
{
    accept();
}

