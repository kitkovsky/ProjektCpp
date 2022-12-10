#include "kafelek.h"
#include <QPainter>
#include <string>

Kafelek::Kafelek(QWidget *parent)
    : QWidget{parent}
{

}

void Kafelek::paintEvent(QPaintEvent *event)
{
    const int font_size = 15;

    QPainter painter(this);
    painter.setFont(QFont("Arial",font_size));
    auto today = data.day();
    painter.drawText(5,font_size+10,std::to_string(today).c_str());
}
