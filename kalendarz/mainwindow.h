#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>
#include <vector>

#include "kafelek.h"
#include "wydarzenie.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read_events();
    void write_events();

  private slots:
    void on_action_strzalka_w_gore_triggered();

    void on_action_strzalka_w_dol_triggered();

    void wydarzenie_accepted(Wydarzenie wydarzenie);

    void on_actional_ma_kota_triggered();

  private:
    Ui::MainWindow *ui;

    int month = QDate::currentDate().month();
    int year = QDate::currentDate().year();

    std::array<std::array<Kafelek *, 7>, 5> kafelki;
    std::vector<Wydarzenie> wpisy;
    QString wydarzenie_filename = "wydarzenia.kjk";

    void inicjuj_kafelki();
    void update_toolbar();
    void update_board();
    std::vector<Wydarzenie> find_wpisy(QDate date);
};
#endif // MAINWINDOW_H
