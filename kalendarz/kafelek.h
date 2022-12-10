#ifndef KAFELEK_H
#define KAFELEK_H

#include <QWidget>
#include <QDate>

class Kafelek : public QWidget
{
    Q_OBJECT
public:
    explicit Kafelek(QWidget *parent = nullptr);
    QDate get_date() const
    {
     return data;
    }
    void set_date(QDate d)
    {
        data = d;
    }
    void paintEvent(QPaintEvent *event);
signals:

private:
    QDate data = QDate(2022, 12, 9);

};

#endif // KAFELEK_H
