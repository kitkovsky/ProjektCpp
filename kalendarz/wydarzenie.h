#ifndef WYDARZEINE_H
#define WYDARZEINE_H

#include <QDate>
#include <QTime>
#include <QString>
#include <QDataStream>

class Wydarzenie
{
public:
    Wydarzenie(QDate date,QTime time,QString text);
    Wydarzenie();
    friend QDataStream& operator<<( QDataStream &out, const Wydarzenie& dane );

    friend QDataStream& operator>>( QDataStream &in, Wydarzenie& dane );

    const QDate &getDate() const;
    void setDate(const QDate &newDate);

    const QTime &getTime() const;
    void setTime(const QTime &newTime);

    const QString &getText() const;
    void setText(const QString &newText);

private:
    QDate date;
    QTime time;
    QString text;

};

QDataStream& operator<<( QDataStream &out, const Wydarzenie& dane );

QDataStream& operator>>( QDataStream &in, Wydarzenie& dane );
#endif // WYDARZEINE_H
