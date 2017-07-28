#include "../headers/SaverLoader.h"
#include "../headers/Cell.h"
#include <vector>
#include <string>
#include <algorithm>

#include <QDebug>

SaverLoader::SaverLoader()
{

}

void SaverLoader::saveMap(std::string file_name, const std::vector<Cell *> &cells){
    const char* char_file_name = file_name.c_str(); //convert cpp string to a char*
    FILE* fptr = fopen(char_file_name,"w");   //Opens file for writing
    unsigned long long int size = cells.size();        // total number of cells
    unsigned long long int ID = 0;     // ID of a cell
    unsigned long long int tempAdjID = 0;
    int castCellType = 0;
    std::vector<Cell*> adjacent_list;   // list of adjacents to a cell
    int numAdj = 0;         // number of neighbours
    int xPos = 0 , yPos = 0;         // Coordinates
    Cell::CellType what_is_type = Cell::ORDINARY;   //type of a cell
    fwrite(&size, sizeof(unsigned long long int), 1, fptr);
    qDebug() << size;
    for(unsigned long long int i = 0 ; i < size ; i++){    //a loop for writing whole of cells

        //Here, there are a lot of functions to be built...
        //getters for: adjacentList, cellType, xPosition, yPosition.
        ID = cells[i] -> getCellID();
        adjacent_list = cells[i] -> getAdjacentList();
        numAdj = adjacent_list.size();
        what_is_type = cells[i] -> getCellType();
        castCellType = static_cast<int>(what_is_type);
        xPos = cells[i] -> getXPos();
        yPos = cells[i] -> getYPos();

        qDebug() << ID << ", " << numAdj << ", " << castCellType;
        fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
        fwrite(&numAdj, sizeof(int), 1, fptr);
        fwrite(&castCellType, sizeof(int), 1, fptr);
        fwrite(&xPos, sizeof(int), 1, fptr);
        fwrite(&yPos, sizeof(int), 1, fptr);

    } //End of loop  (for writing properties of a Cell)
    for(unsigned long long int i = 0 ; i < size ; i++){
        adjacent_list = cells[i]->getAdjacentList();
        for(int j = 0 ; j < numAdj ; j++){
            tempAdjID = adjacent_list[j]->getCellID();
            qDebug() << i << ", " << tempAdjID;
            fwrite( &tempAdjID, sizeof(unsigned long long int), 1, fptr );
        }
    }
    fclose(fptr);
} //End of saving function

std::vector<Cell*> SaverLoader::loadMap(std::string file_name){
    const char* char_file_name = file_name.c_str();
    FILE* fptr = fopen(char_file_name,"r");
    std::vector<Cell*> cells;

    //IMPORTANT
    //Cell temp_cell(Cell::ORDINARY, nullptr); // What the phase with this constructor?
    //IMPORTANT

    Cell* temp = nullptr;
    unsigned long long int size = 0;
    unsigned long long int ID = 0;
    unsigned long long int tempID = 0;
    std::vector<Cell*> adjacent_list;
    std::vector<int> numAdj;
    int temp_numAdj = 0;
    int xPos = 0 , yPos = 0;
    int castCellType = 0;
    Cell::CellType what_is_type = Cell::ORDINARY;
    fread(&size, sizeof(unsigned long long int), 1, fptr);
    qDebug() << size;
    for(unsigned long long int i = 0 ; i < size ; i++){

        fread(&ID, sizeof(unsigned long long int), 1, fptr);
        fread(&temp_numAdj, sizeof(int), 1, fptr);

        fread(&castCellType, sizeof(int), 1, fptr);
        what_is_type = static_cast<Cell::CellType>(castCellType);

        fread(&xPos, sizeof(int), 1, fptr);
        fread(&yPos, sizeof(int), 1, fptr);
        temp = new Cell(what_is_type);
        temp->setCellID(ID);
        temp->setPos(xPos, yPos);
        cells.push_back(temp);

        // I temprorily made this functin friend with Cell class. For escaping from compile errors. :)
        //You, HajReza, may want to set a new function for this action! :)

        //And here, there are a lot of functions to be built...
        //setters for: cellType, xPosition, yPosition
        numAdj.push_back(temp_numAdj);
        qDebug() << ID << ", " << temp_numAdj << ", " << castCellType;

        //cells.push_back(&temp_cell);//Are we only playing with addresses? This would not return a vector of Cell*.
        // There is no copy of information.
        //I think it is better to return a vector of Cell instead of Cell*. Isn't it? :)
        //Also I hope that a vector<Cell> can be passed to saveMap. And loadMap return a vector<Cell>.
    }
    for(unsigned long long int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < numAdj[i] ; j++){
            fread(&tempID, sizeof(unsigned long long int), 1, fptr);
            qDebug() << i << ", " << tempID;
            auto it = std::find_if(cells.begin(), cells.end(), [&tempID](Cell* goal) {return goal->getCellID() == tempID;});
            cells.at(i)->addAdjacent(*it);
        }
    }
    fclose(fptr);

    return cells;
}
