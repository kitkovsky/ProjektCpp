#include <QApplication>
#include <QFile>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QFile styleSheetFile("./Diffnes.qss");
    bool opened = styleSheetFile.open(QFile::ReadOnly);
    if (!opened) {
        styleSheetFile.setFileName("../kalendarz/Diffnes.qss");
        opened = styleSheetFile.open(QFile::ReadOnly);
    }
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    QFile file("./ratunku.txt");
    file.open(QFile::WriteOnly);
    file.write("ratunku!\n");

    MainWindow w;
    w.show();
    return a.exec();
}
