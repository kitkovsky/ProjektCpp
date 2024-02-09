#include "kafelek.h"

#include <QMessageBox>
#include <QPainter>
#include <string>

Kafelek::Kafelek(QWidget *parent) : QWidget{parent} {}

void Kafelek::paintEvent(QPaintEvent *event) {
    const int font_size = 15;
    QBrush background(QColor(hover ? "#4891b4" : "azure"));

    QPainter painter(this);
    painter.setFont(QFont("Arial", font_size));
    auto today = data.day();
    bool paint_today = data == QDate::currentDate();
    if (data.month() != displayed_month) {
        if (hover) {
            background.setColor("#4891b4");
        } else
            background.setColor("lightgrey");
    }
    if (paint_today) {
        background.setColor("goldenrod");
    }
    auto r = rect();
    painter.setBrush(background);
    painter.drawRect(r);
    painter.drawText(5, font_size + 10, std::to_string(today).c_str());

    painter.setFont(QFont("Arial", 9));
    int numer_wpisu = 0;

    for (const auto &wpis : wpisy_kafelka) {
        QString napis =
            wpis.getTimeStart().toString("h.mm") + " " + wpis.getText();
        painter.drawText(5, 38 + numer_wpisu * 11, napis);
        numer_wpisu++;
    }
}

void Kafelek::enterEvent(QEnterEvent *event) { hover = true; }

void Kafelek::leaveEvent(QEvent *event) { hover = false; }

void Kafelek::mousePressEvent(QMouseEvent *event) {
    for (auto wpis : wpisy_kafelka) {
        Dialog_kafelka dialog(wpis, this);
        connect(&dialog, &Dialog_kafelka::wydarzenie_accepted, this,
                &Kafelek::wydarzenie_accepted);
        dialog.exec();
    }
    Dialog_kafelka dialog(Wydarzenie(data, QTime(12, 0), QTime(12, 0), ""),
                          this);
    connect(&dialog, &Dialog_kafelka::wydarzenie_accepted, this,
            &Kafelek::wydarzenie_accepted);
    dialog.exec();
}

void Kafelek::dodaj_wpis(const Wydarzenie &w) {
    for (const auto &wpis : wpisy_kafelka) {
        if (wpis.getTimeStart() == w.getTimeStart() and
            wpis.getTimeEnd() == w.getTimeEnd() and
            wpis.getDate() == w.getDate() and wpis.getText() == w.getText())
            return;
    }
    wpisy_kafelka.push_back(w);
}

void Kafelek::set_wydarzenia(std::vector<Wydarzenie> wydarzenia) {
    wpisy_kafelka = wydarzenia;
    repaint();
}

void Kafelek::wydarzenie_accepted(Wydarzenie wydarzenie) {
    bool znalezniono = false;
    for (int i = 0; i < wpisy_kafelka.size(); i++) {
        auto &wpis = wpisy_kafelka[i];
        if (wpis.getDate() == wydarzenie.getDate() and
            wpis.getTimeStart() == wydarzenie.getTimeStart() and
            wpis.getTimeEnd() == wydarzenie.getTimeEnd()) {
            wpis = wydarzenie;
            if (wpis.getText().isEmpty()) {
                wpisy_kafelka.erase(wpisy_kafelka.begin() + 1);
            }
            znalezniono = true;
            break;
        }
    }
    if (!znalezniono) {
        wpisy_kafelka.push_back(wydarzenie);
    }
    emit wydarzenie_changed(wydarzenie);
    repaint();
}
