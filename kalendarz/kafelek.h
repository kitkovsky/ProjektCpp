#ifndef KAFELEK_H
#define KAFELEK_H

#include "wydarzenie.h"

#include <QWidget>
#include <QDate>

class Kafelek : public QWidget
{
    Q_OBJECT
public:
    Kafelek(QWidget *parent = nullptr);
    QDate get_date() const
    {
        return data;
    }
    void set_date(QDate d)
    {
        data = d;
    }
    void paintEvent(QPaintEvent *event);
    void set_displayed_month(int m)
    {
        displayed_month = m;
    }
    void mousePressEvent(QMouseEvent *event);
    void dodaj_wpis(const Wydarzenie &w);

    void set_wydarzenia(std::vector<Wydarzenie> wydarzenia);

signals:
    void wydarzenie_changed(Wydarzenie wydarzenie);

public slots:
    void wydarzenie_accepted(Wydarzenie wydarzenie);

private:
    QDate data = QDate(2022, 12, 9);
    int displayed_month;
    std::vector<Wydarzenie>wpisy_kafelka;
};

#endif // KAFELEK_H
