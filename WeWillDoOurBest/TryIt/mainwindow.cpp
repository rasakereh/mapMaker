#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Connector();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Connector()
{
    //QObject::connect(this -> ui -> ordinaryCell_button, &QPushButton::clicked, [&](){this->current_choice = "ordinaryCell_button";} );
    QObject::connect(this -> ui -> ordinaryCell_button, &QPushButton::clicked, this, &MainWindow::close );
}
