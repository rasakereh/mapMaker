#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/MapDraft.h"

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
    QObject::connect(this -> ui -> ordinaryCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = Cell::ORDINARY;} );

    QObject::connect(this -> ui -> treasureCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = Cell::TREASURE;} );

    QObject::connect(this -> ui -> initialCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = Cell::INITIAL;} );

    QObject::connect(this -> ui -> decisionCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = Cell::DECISION;} );

    QObject::connect(this -> ui -> transportCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = Cell::TRANSPORT;} );
}
