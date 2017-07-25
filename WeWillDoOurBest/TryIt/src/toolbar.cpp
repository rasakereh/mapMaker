#include "../headers/Toolbar.h"

Toolbar::Toolbar(QWidget *parent): QFrame(parent)
{
    this -> setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    
    this -> toolbarButtons["DecisionCell"] = new QPushButton();
    this -> toolbarButtons["InitialCell"] = new QPushButton();
    this -> toolbarButtons["OrdinaryCell"] = new QPushButton();
    this -> toolbarButtons["TransportCell"] = new QPushButton();
    this -> toolbarButtons["TreasureCell"] = new QPushButton();
    
    this -> toolbarLayout.setSpacing(10);
    
    for(auto it = this -> toolbarButtons.begin(); it != this -> toolbarButtons.end(); it++)
    {
        // fileName = :/icons/$CellType$.png
        QString fileName = QString(it -> first.c_str()).append(".png").prepend(":/icons/");
        it -> second -> setIcon(QIcon(fileName));
        it -> second -> setToolTip(it -> first.c_str());
        this -> toolbarLayout.addWidget(it -> second);
        it -> second -> show();
    }
}
