#include "mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    p_central_wg = new QScrollArea;
    QLabel* wg = new QLabel("AAAAAAAAAAAAAATest");
    wg->setAlignment(Qt::AlignCenter);
    wg->setStyleSheet("background-color:rgb(255, 200, 200);");
    wg->resize(800, 500);
    p_central_wg->setWidget(wg);
    setCentralWidget(p_central_wg);
}

MainWindow::~MainWindow()
{
}

