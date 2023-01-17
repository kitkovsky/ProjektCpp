#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <string>
#include "wydarzenie.h"
#include <QFile>
#include <QMessageBox>

std::array<QString, 12> month_tab

{
    "styczeń", "luty", "marzec", "kwiecień", "maj", "czerwiec", "lipiec", "sierpień", "wrześień", "pażdziernik", "listopad", "grudzień"
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    inicjuj_kafelki();
    update_toolbar();
    read_events();
}

MainWindow::~MainWindow()
{
    write_events();
    delete ui;
}

void MainWindow::read_events()
{
    QFile file(wydarzenie_filename);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    Wydarzenie w;
    while(true)
    {
        if(in.atEnd()) break;
        in >> w;
        wpisy.push_back(w);
    }
}

void MainWindow::write_events()
{
    QFile file(wydarzenie_filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"),
                                 file.errorString());
        return;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);

    for(const auto& w : wpisy)
    {
        out << w;
    }
}

void MainWindow::inicjuj_kafelki()
{
    kafelki[0][0] = ui->kafelek_00;
    kafelki[0][1] = ui->kafelek_01;
    kafelki[0][2] = ui->kafelek_02;
    kafelki[0][3] = ui->kafelek_03;
    kafelki[0][4] = ui->kafelek_04;
    kafelki[0][5] = ui->kafelek_05;
    kafelki[0][6] = ui->kafelek_06;
    kafelki[1][0] = ui->kafelek_10;
    kafelki[1][1] = ui->kafelek_11;
    kafelki[1][2] = ui->kafelek_12;
    kafelki[1][3] = ui->kafelek_13;
    kafelki[1][4] = ui->kafelek_14;
    kafelki[1][5] = ui->kafelek_15;
    kafelki[1][6] = ui->kafelek_16;
    kafelki[2][0] = ui->kafelek_20;
    kafelki[2][1] = ui->kafelek_21;
    kafelki[2][2] = ui->kafelek_22;
    kafelki[2][3] = ui->kafelek_23;
    kafelki[2][4] = ui->kafelek_24;
    kafelki[2][5] = ui->kafelek_25;
    kafelki[2][6] = ui->kafelek_26;
    kafelki[3][0] = ui->kafelek_30;
    kafelki[3][1] = ui->kafelek_31;
    kafelki[3][2] = ui->kafelek_32;
    kafelki[3][3] = ui->kafelek_33;
    kafelki[3][4] = ui->kafelek_34;
    kafelki[3][5] = ui->kafelek_35;
    kafelki[3][6] = ui->kafelek_36;
    kafelki[4][0] = ui->kafelek_40;
    kafelki[4][1] = ui->kafelek_41;
    kafelki[4][2] = ui->kafelek_42;
    kafelki[4][3] = ui->kafelek_43;
    kafelki[4][4] = ui->kafelek_44;
    kafelki[4][5] = ui->kafelek_45;
    kafelki[4][6] = ui->kafelek_46;


update_board();


}

void MainWindow::update_toolbar()
{
    ui->action_miesiac->setText(month_tab[month-1]);
    ui->action_rok->setText(std::to_string(year).c_str());
    update_board();
    update();
}

void MainWindow::update_board()
{

    QDate first_of_month(year, month, 1);
    QDate first_displayed = first_of_month.addDays(-(first_of_month.dayOfWeek() -1));


    for(int wiersz = 0; wiersz < (int)kafelki.size();++wiersz)
    {
        for(int kolumna = 0; kolumna < (int)kafelki[0].size();++kolumna)
        {
            kafelki[wiersz][kolumna]->set_date(first_displayed);
            kafelki[wiersz][kolumna]->set_displayed_month(first_of_month.month());
            first_displayed = first_displayed.addDays(1);
        }
    }
    kafelki[0][0]->dodaj_wpis(Wydarzenie(first_of_month, QTime(10,10), "ala ma kota"));
}



void MainWindow::on_action_strzalka_w_gore_triggered()
{
    if(month == 12)
    {
        month = 0;
        year ++;
    }
    month ++;
    update_toolbar();
}


void MainWindow::on_action_strzalka_w_dol_triggered()
{
    month --;
    if(month == 0)
    {
        month = 12;
        year --;
    }
    update_toolbar();
}

