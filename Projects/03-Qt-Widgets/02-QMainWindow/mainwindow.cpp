#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    QPushButton *button= new QPushButton("Hello",this);
    setCentralWidget(button);

    quit_action= new QAction("Quit");

    connect(quit_action,&QAction::triggered,
            [=](){
        QApplication::quit();
    });

    QMenu *file_menu=menuBar()->addMenu("File");
    file_menu->addAction(quit_action);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("View");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    statusBar()->showMessage("Ready...");
    //statusBar()->clearMessage();
}


QSize MainWindow::sizeHint() const
{
    return QSize(600,400);
}
