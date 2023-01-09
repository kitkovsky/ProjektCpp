#include "kafelek.h"
#include <QPainter>
#include <string>
#include <QMessageBox>

Kafelek::Kafelek(QWidget *parent)
    : QWidget{parent}
{

}

void Kafelek::paintEvent(QPaintEvent *event)
{
    const int font_size = 15;
    QBrush background(QColor("azure"));

    QPainter painter(this);
    painter.setFont(QFont("Arial",font_size));
    auto today = data.day();
    bool paint_today = data == QDate::currentDate();
    if(data.month() != displayed_month)
    {
        background.setColor("lightgrey");
    }
    if(paint_today)
    {
        background.setColor("goldenrod");
    }
    auto r = rect();
    painter.setBrush(background);
    painter.drawRect(r);
    painter.drawText(5,font_size+10,std::to_string(today).c_str());

}

void Kafelek::mousePressEvent(QMouseEvent *event)
{
    Dialog_kafelka *kafelek = new Dialog_kafelka(this);
    kafelek->show();
}
