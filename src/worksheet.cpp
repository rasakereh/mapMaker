#include "../headers/Worksheet.h"

Worksheet::Worksheet(QWidget *parent): QWidget(parent), worksheetLayout(this)
{
    this -> toolbar = new Toolbar(this);
    this -> mapDraft = new MapDraft(this);
    this -> saveButton = new QPushButton("&Save ...", this);
    this -> loadButton = new QPushButton("&Load ...", this);
    
    this -> mapDraft -> setMinimumSize(10, 10);
    this -> mapDraft -> setMaximumSize(640, 480);
    
    this -> worksheetLayout.addWidget(this -> toolbar);
    this -> worksheetLayout.addWidget(this -> mapDraft);
    this -> worksheetLayout.addWidget(this -> mapDraft);
    
    worksheetLayout.addWidget(this -> saveButton);
    worksheetLayout.addWidget(this -> loadButton);
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
