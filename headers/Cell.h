#ifndef CELL_H
#define CELL_H

#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include <QLabel>

#include "SaverLoader.h"

class Cell: public QLabel
{
friend std::vector<Cell*> SaverLoader::loadMap(std::string file_name);

public:
    typedef enum{ORDINARY, TREASURE, INITIAL, DECISION, TRANSPORT} CellType;
    Cell(CellType cellType, QWidget *parent = nullptr);
    const std::vector<Cell *> &getAdjacentList();
    const CellType &getCellType();
    const int &getCellID();
    const double &getXPos();
    const double &getYPos();
    
private:
    typedef enum{GREEN, ORANGE, BLUE, RED, VIOLET} CellColor;
    static std::map <CellType, CellColor> colorTranslator;
    static std::map <CellType, std::string> iconTranslator;
    
    unsigned long long int cellID;
    double xPosition, yPosition;
    CellType cellType;
    CellColor cellColor;
    std::vector<Cell *> adjacentList;
    
    void setCellID(unsigned long long int cellID);
    void setColor();
    void loadImage();
    bool addAdjacent(Cell *newAdjacent);
    bool removeAdjacent(Cell *oldAdjacent);
    void setAdjacentList(const std::vector<Cell *> &adjacentList);
    void setPos(const double &xPos, const double &yPos);
    
    
};

#endif // CELL_H
