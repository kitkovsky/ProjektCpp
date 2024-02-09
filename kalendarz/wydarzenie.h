#ifndef WYDARZEINE_H
#define WYDARZEINE_H

#include <QDataStream>
#include <QDate>
#include <QString>
#include <QTime>

class Wydarzenie {
  public:
    Wydarzenie(QDate date, QTime timestart, QTime timeend, QString text);
    Wydarzenie();
    friend QDataStream &operator<<(QDataStream &out, const Wydarzenie &dane);

    friend QDataStream &operator>>(QDataStream &in, Wydarzenie &dane);

    const QDate &getDate() const;
    void setDate(const QDate &newDate);

    const QTime &getTimeStart() const;
    void setTimeStart(const QTime &newTime);

    const QTime &getTimeEnd() const;
    void setTimeEnd(const QTime &newTime);

    const QString &getText() const;
    void setText(const QString &newText);

  private:
    QDate date;
    QTime time_start;
    QTime time_end;
    QString text;
};

QDataStream &operator<<(QDataStream &out, const Wydarzenie &dane);

QDataStream &operator>>(QDataStream &in, Wydarzenie &dane);
#endif // WYDARZEINE_H
