#include "wydarzenie.h"

Wydarzenie::Wydarzenie(QDate date, QTime timestart, QTime timeend, QString text)
    : date(date), time_start(timestart), time_end(timeend), text(text) {}

Wydarzenie::Wydarzenie() {}

const QDate &Wydarzenie::getDate() const { return date; }

void Wydarzenie::setDate(const QDate &newDate) { date = newDate; }

const QTime &Wydarzenie::getTimeStart() const { return time_start; }

void Wydarzenie::setTimeStart(const QTime &newTime) { time_start = newTime; }

const QTime &Wydarzenie::getTimeEnd() const { return time_end; }

void Wydarzenie::setTimeEnd(const QTime &newTime) { time_end = newTime; }

const QString &Wydarzenie::getText() const { return text; }

void Wydarzenie::setText(const QString &newText) { text = newText; }

QDataStream &operator<<(QDataStream &out, const Wydarzenie &dane) {
    out << dane.date;
    out << dane.time_start;
    out << dane.time_end;
    out << dane.text;
    return out;
}

QDataStream &operator>>(QDataStream &in, Wydarzenie &dane) {
    in >> dane.date;
    in >> dane.time_start;
    in >> dane.time_end;
    in >> dane.text;
    return in;
}
