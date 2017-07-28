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
    QObject::connect(this -> ui -> selectionTool_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = MapDraft::NOTYPE;} );
    
    QObject::connect(this -> ui -> ordinaryCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = MapDraft::ORDINARY;} );

    QObject::connect(this -> ui -> treasureCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = MapDraft::TREASURE;} );

    QObject::connect(this -> ui -> initialCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = MapDraft::INITIAL;} );

    QObject::connect(this -> ui -> decisionCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = MapDraft::DECISION;} );

    QObject::connect(this -> ui -> transportCell_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = MapDraft::TRANSPORT;} );
    
    QObject::connect(this -> ui -> delete_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->current_choice = MapDraft::DELETE_CELL;} );

    QObject::connect(this -> ui -> save_button, &QPushButton::clicked,
                     [&](){this->Save();});

    QObject::connect(this -> ui -> load_button, &QPushButton::clicked,
                     [&](){this -> ui -> mapDraft_frm ->setAllCell( this -> Load() ) ;});
}

void MainWindow::Save()
{
    SaverLoader sl;
    QString name = QFileDialog::getSaveFileName();
    sl.saveMap(name.toStdString(), this -> ui -> mapDraft_frm -> getAllCell());
}

std::vector<Cell *> MainWindow::Load()
{
    SaverLoader sl;
    QString name = QFileDialog::getOpenFileName();
    std::vector<Cell *> result = sl.loadMap(name.toStdString());
    for(auto it = result.begin() ; it != result.end() ; it++ ){
        this -> ui -> mapDraft_frm -> addCell((*it)->getXPos(), (*it)->getYPos(), (*it)->getCellType());
    }
    return result;
}
