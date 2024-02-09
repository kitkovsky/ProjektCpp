#ifndef KAFELEK_H
#define KAFELEK_H

#include <QDate>
#include <QWidget>

#include "wydarzenie.h"

class Kafelek : public QWidget {
    Q_OBJECT
  public:
    Kafelek(QWidget *parent = nullptr);
    QDate get_date() const { return data; }
    void set_date(QDate d) { data = d; }
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

    void set_displayed_month(int m) { displayed_month = m; }
    void dodaj_wpis(const Wydarzenie &w);

    void set_wydarzenia(std::vector<Wydarzenie> wydarzenia);

  signals:
    void wydarzenie_changed(Wydarzenie wydarzenie);

  public slots:
    void wydarzenie_accepted(Wydarzenie wydarzenie);

  private:
    QDate data = QDate(2022, 12, 9);
    int displayed_month;
    std::vector<Wydarzenie> wpisy_kafelka;
    bool hover = false;
};

#endif // KAFELEK_H
