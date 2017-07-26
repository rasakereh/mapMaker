#include "../headers/Worksheet.h"

Worksheet::Worksheet(QWidget *parent): QWidget(parent), worksheetLayout(this)
{
    this -> toolbar = new Toolbar(this);
    this -> mapDraft = new MapDraft(this);
    this -> saveButton = new QPushButton("&Save ...", this);
    this -> loadButton = new QPushButton("&Load ...", this);
    
    this -> toolbar -> setMinimumSize(100, 30);
    this -> toolbar -> setMaximumSize(450, 30);
    
    this -> mapDraft -> setMinimumSize(100, 100);
    this -> mapDraft -> setMaximumSize(450, 450);
    
    this -> worksheetLayout.addWidget(this -> toolbar);
    this -> worksheetLayout.addWidget(this -> mapDraft);
    
    this -> worksheetLayout.addWidget(this -> saveButton);
    this -> worksheetLayout.addWidget(this -> loadButton);
}

void Worksheet::loadMap()
{
    
}

void Worksheet::saveMap()
{
    
}

void Worksheet::clearMapDraft()
{
    
}

void Worksheet::updateMapDraft()
{
    
}
