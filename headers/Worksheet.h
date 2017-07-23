#ifndef WORKSHEET_H
#define WORKSHEET_H

#include <vector>

#include <QPushButton>
#include <QFormLayout>

#include "Cell.h"
#include "MapDraft.h"

class Worksheet: public QWidget
{
public:
    Worksheet(QWidget *parent = nullptr);
    void saveMap();
    void loadMap();
    
private:
    std::vector<Cell *> allCells;
    
    MapDraft *mapDraft;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QFormLayout worksheetLayout;
    
    void clearMapDraft();
    void updateMapDraft();
    
};

#endif // WORKSHEET_H
