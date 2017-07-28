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
    QObject::connect(this -> ui -> selectionTool_button, &QPushButton::clicked,[&]()
    {
        this -> ui -> mapDraft_frm ->current_choice = MapDraft::NOTYPE;
        if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
            this -> ui -> mapDraft_frm -> last_choice -> normalize();
        this -> ui -> mapDraft_frm -> last_choice = nullptr;
    } );
    
    QObject::connect(this -> ui -> ordinaryCell_button, &QPushButton::clicked,[&]()
    {
        this -> ui -> mapDraft_frm ->current_choice = MapDraft::ORDINARY;
        if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
            this -> ui -> mapDraft_frm -> last_choice -> normalize();
        this -> ui -> mapDraft_frm -> last_choice = nullptr;
    } );

    QObject::connect(this -> ui -> treasureCell_button, &QPushButton::clicked,[&]()
    {
        this -> ui -> mapDraft_frm ->current_choice = MapDraft::TREASURE;
        if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
            this -> ui -> mapDraft_frm -> last_choice -> normalize();
        this -> ui -> mapDraft_frm -> last_choice = nullptr;
    } );

    QObject::connect(this -> ui -> initialCell_button, &QPushButton::clicked,[&]()
    {
        this -> ui -> mapDraft_frm ->current_choice = MapDraft::INITIAL;
        if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
            this -> ui -> mapDraft_frm -> last_choice -> normalize();
        this -> ui -> mapDraft_frm -> last_choice = nullptr;
    } );

    QObject::connect(this -> ui -> decisionCell_button, &QPushButton::clicked,[&]()
    {
        this -> ui -> mapDraft_frm ->current_choice = MapDraft::DECISION;
        if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
            this -> ui -> mapDraft_frm -> last_choice -> normalize();
        this -> ui -> mapDraft_frm -> last_choice = nullptr;
    } );

    QObject::connect(this -> ui -> transportCell_button, &QPushButton::clicked,[&]()
    {
        this -> ui -> mapDraft_frm ->current_choice = MapDraft::TRANSPORT;
        if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
            this -> ui -> mapDraft_frm -> last_choice -> normalize();
        this -> ui -> mapDraft_frm -> last_choice = nullptr;
    } );
    
    QObject::connect(this -> ui -> delete_button, &QPushButton::clicked,[&]()
        {
            this -> ui -> mapDraft_frm ->current_choice = MapDraft::DELETE_CELL;
            if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
                this -> ui -> mapDraft_frm -> last_choice -> normalize();
            this -> ui -> mapDraft_frm -> last_choice = nullptr;
        } );

    QObject::connect(this -> ui -> connect_button, &QPushButton::clicked,[&]()
        {
            this -> ui -> mapDraft_frm ->current_choice = MapDraft::CONNECT_CELL;
            if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
                this -> ui -> mapDraft_frm -> last_choice -> normalize();
            this -> ui -> mapDraft_frm -> last_choice = nullptr;
        } );

    QObject::connect(this -> ui -> disconnect_button, &QPushButton::clicked,[&]()
        {
            this -> ui -> mapDraft_frm ->current_choice = MapDraft::DISCONNECT_CELL;
            if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
                this -> ui -> mapDraft_frm -> last_choice -> normalize();
            this -> ui -> mapDraft_frm -> last_choice = nullptr;
        } );

    QObject::connect(this -> ui -> save_button, &QPushButton::clicked,[&]()
    {
        this->Save();
        if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
            this -> ui -> mapDraft_frm -> last_choice -> normalize();
        this -> ui -> mapDraft_frm -> last_choice = nullptr;});

    QObject::connect(this -> ui -> load_button, &QPushButton::clicked,[&]()
    {
        this -> Load();
        if (this -> ui -> mapDraft_frm -> last_choice != nullptr)
            this -> ui -> mapDraft_frm -> last_choice -> normalize();
        this -> ui -> mapDraft_frm -> last_choice = nullptr;
    });
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
    std::vector<Cell *> tempList;
    Cell *cur_cell = nullptr;
    unsigned long long int tempID = 10000000000;
    for(auto it = this->ui->mapDraft_frm->cells.end() - 1 ; it != this->ui->mapDraft_frm->cells.begin() - 1 ; it--){
        this -> ui -> mapDraft_frm -> deleteCell(*it);
    }
    for(auto it = result.begin() ; it != result.end() ; it++ ){
        this -> ui -> mapDraft_frm -> addCell((*it)->getXPos() + WIDTHCELL/2, (*it)->getYPos() + HEIGHTCELL/2, (*it)->getCellType());
        cur_cell = (*(this ->ui->mapDraft_frm->cells.end() - 1));
        cur_cell -> setCellID( (*it) -> getCellID() );
        //std::for_each(tempList.begin(), tempList.end(),cur_cell->addAdjacent);
    }
    for(auto ott = this -> ui -> mapDraft_frm -> cells.begin() ; ott != this -> ui -> mapDraft_frm -> cells.end() ; ott++){
        for(auto it = result.begin() ; it != result.end() ; it++ ){
            tempList = (*it)->getAdjacentList();
            for(auto op = tempList.begin() ; op != tempList.end() ; op++)
            {
                tempID = (*op) -> getCellID();

                auto new_it = std::find_if(this ->ui->mapDraft_frm->cells.begin(),
                                           this ->ui->mapDraft_frm->cells.end(),
                                           [&tempID](Cell* goal)
                                            {return goal->getCellID() == tempID;});

                (*ott) -> addAdjacent(*new_it);
            }
        }
    }
    /*
       MAST MALI SHADID
    */
    return result;
}
