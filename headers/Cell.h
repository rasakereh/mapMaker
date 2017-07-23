#ifndef CELL_H
#define CELL_H

#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include <QLabel>

class Cell: public QLabel
{
public:
    typedef enum{ORDINARY, TREASURE, INITIAL, DECISION, TRANSPORT} CellType;
    Cell(CellType cellType, QWidget *parent = nullptr);
    
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
    
};

#endif // CELL_H
