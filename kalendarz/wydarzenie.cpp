#include "wydarzenie.h"

Wydarzenie::Wydarzenie(QDate date,QTime time,QString text)
    :date(date), time(time), text(text)
{

}

Wydarzenie::Wydarzenie()
{

}

const QDate &Wydarzenie::getDate() const
{
    return date;
}

void Wydarzenie::setDate(const QDate &newDate)
{
    date = newDate;
}

const QTime &Wydarzenie::getTime() const
{
    return time;
}

void Wydarzenie::setTime(const QTime &newTime)
{
    time = newTime;
}

const QString &Wydarzenie::getText() const
{
    return text;
}

void Wydarzenie::setText(const QString &newText)
{
    text = newText;
}

QDataStream &operator<<(QDataStream &out, const Wydarzenie &dane)
{
    out << dane.date;
    out << dane.time;
    out << dane.text;
    return out;
}

QDataStream &operator>>(QDataStream &in, Wydarzenie &dane)
{
    in >> dane.date;
    in >> dane.time;
    in >> dane.text;
    return in;
}
