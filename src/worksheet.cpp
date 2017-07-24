#include "../headers/Worksheet.h"

Worksheet::Worksheet(QWidget *parent): QWidget(parent), worksheetLayout(this)
{
    this -> mapDraft = new MapDraft(this);
    this -> saveButton = new QPushButton(this);
    this -> loadButton = new QPushButton(this);
    
    this -> mapDraft -> setMinimumSize(10, 10);
    this -> mapDraft -> setMaximumSize(640, 480);
    
    this -> worksheetLayout.addRow(this -> mapDraft);
    this -> worksheetLayout.addRow(this -> mapDraft);
    
    worksheetLayout.addRow(this -> saveButton);
    worksheetLayout.addRow(this -> loadButton);
}
