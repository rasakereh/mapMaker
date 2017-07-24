#include "../headers/Toolbar.h"

Toolbar::Toolbar(QWidget *parent): QFrame(parent)
{
    this -> toolbarButtons["DecisionCell"] = new QPushButton;
    this -> toolbarButtons["InitialCell"] = new QPushButton;
    this -> toolbarButtons["OrdinaryCell"] = new QPushButton;
    this -> toolbarButtons["TransportCell"] = new QPushButton;
    this -> toolbarButtons["TreasureCell"] = new QPushButton;
    
    for(auto it = this -> toolbarButtons.begin(); it != this -> toolbarButtons.end(); it++)
    {
        // fileName = :/icons/$CellType$.png
        QString fileName = QString(this -> first.c_str()).append(".png").prepend(":/icons/");
        it -> second -> setIcon(QIcon(fileName));
        this -> toolbarLayout.addWidget(it -> second);
    }
}
