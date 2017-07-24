#ifndef WORKSHEET_H
#define WORKSHEET_H

#include <vector>

#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>

#include "Cell.h"
#include "MapDraft.h"
#include "Toolbar.h"

class Worksheet: public QWidget
{
public:
    Worksheet(QWidget *parent = nullptr);
    void saveMap();
    void loadMap();
    
private:
    std::vector<Cell *> allCells;
    
    Toolbar *toolbar;
    MapDraft *mapDraft;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QVBoxLayout worksheetLayout;
    
    void clearMapDraft();
    void updateMapDraft();
    
};

#endif // WORKSHEET_H
