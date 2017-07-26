#include "../headers/SaverLoader.h"
#include "../headers/Cell.h"
#include <vector>
#include <string>
#include <algorithm>

SaverLoader::SaverLoader()
{

}

void SaverLoader::saveMap(std::string file_name, const std::vector<Cell *> &cells){
    const char* char_file_name = file_name.c_str(); //convert cpp string to a char*
    FILE* fptr = fopen(char_file_name,"w");   //Opens file for writing
    unsigned long long int size = cells.size();        // total number of cells
    unsigned long long int ID = 0;     // ID of a cell
    unsigned long long int tempAdjID = 0;
    std::vector<Cell*> adjacent_list;   // list of adjacents to a cell
    int numAdj = 0;         // number of neighbours
    double xPos = 0 , yPos = 0;         // Coordinates
    Cell::CellType what_is_type = Cell::ORDINARY;   //type of a cell
    fwrite(&size, sizeof(unsigned long long int), 1, fptr);
    for(unsigned long long int i = 0 ; i < size ; i++){    //a loop for writing whole of cells

        //Here, there are a lot of functions to be built...
        //getters for: adjacentList, cellType, xPosition, yPosition.
        ID = cells[i] -> getCellID();
        adjacent_list = cells[i] -> getAdjacentList();
        numAdj = adjacent_list.size();
        what_is_type = cells[i] -> getCellType();
        xPos = cells[i] -> getXPos();
        yPos = cells[i] -> getYPos();

        fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
        fwrite(&numAdj, sizeof(int), 1, fptr);
        fwrite(&what_is_type, sizeof(Cell::CellType), 1, fptr);
        fwrite(&xPos, sizeof(double), 1, fptr);
        fwrite(&yPos, sizeof(double), 1, fptr);

    } //End of loop  (for writing properties of a Cell)
    for(unsigned long long int i = 0 ; i < size ; i++){
        adjacent_list = cells[i]->getAdjacentList();
        for(int j = 0 ; j < numAdj ; j++){
            tempAdjID = adjacent_list[j]->getCellID();
            fwrite( &tempAdjID, sizeof(unsigned long long int), 1, fptr );
        }
    }
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
    double xPos = 0 , yPos = 0;
    Cell::CellType what_is_type = Cell::ORDINARY;
    fread(&size, sizeof(unsigned long long int), 1, fptr);
    for(unsigned long long int i = 0 ; i < size ; i++){

        fread(&ID, sizeof(unsigned long long int), 1, fptr);
        fread(&temp_numAdj, sizeof(int), 1, fptr);
        fread(&what_is_type, sizeof(Cell::CellType), 1, fptr);
        fread(&xPos, sizeof(double), 1, fptr);
        fread(&yPos, sizeof(double), 1, fptr);
        temp = new Cell(what_is_type);
        cells.push_back(temp);
        temp->setCellID(ID);
        // I temprorily made this functin friend with Cell class. For escaping from compile errors. :)
        //You, HajReza, may want to set a new function for this action! :)

        //And here, there are a lot of functions to be built...
        //setters for: cellType, xPosition, yPosition
        numAdj.push_back(temp_numAdj);
        temp->setPos(xPos, yPos);

        //cells.push_back(&temp_cell);//Are we only playing with addresses? This would not return a vector of Cell*.
        // There is no copy of information.
        //I think it is better to return a vector of Cell instead of Cell*. Isn't it? :)
        //Also I hope that a vector<Cell> can be passed to saveMap. And loadMap return a vector<Cell>.
    }
    for(unsigned long long int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < numAdj.at(i) ; j++){
            fread(&tempID, sizeof(unsigned long long int), 1, fptr);
            auto it = std::find_if(cells.begin(), cells.end(), [&tempID](Cell* goal) {return goal->getCellID() == tempID;});
            cells.at(i)->addAdjacent(*it);
        }
    }
    return cells;
}
