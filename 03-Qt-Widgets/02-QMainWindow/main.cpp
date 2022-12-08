#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mw;
    mw.setWindowTitle("Kaan's Main Window");
    mw.show();

    return a.exec();
}
