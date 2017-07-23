#include "../headers/SaverLoader.h"
#include "../headers/Cell.h"
#include <vector>
#include <string>

SaverLoader::SaverLoader()
{

}

SaverLoader::saveMap(std::string file_name, std::vector<Cell*> cells){
    char* char_file_name = file_name.c_str(); //convert cpp string to a char*
    FILE* fptr = fopen(char_file_name,w);   //Opens file for writing
    int size = cells.size();        // total number of cells
    unsigned long long int ID = -1;     // ID of a cell
    std::vector<Cell*> adjacent_list;   // list of adjacents to a cell
    int numAdj = 0;         // number of neighbours
    double xPos = 0 , yPos = 0;         // Coordinates
    Cell::CellType what_is_type = Cell::ORDINARY;   //type of a cell
    fwrite(&size, sizeof(int), 1, fptr);
    for(int i = 0 ; i < size ; i++){    //a loop for writing whole of cells
        ID = cells[i] -> getID();
        fwrite(&ID, sizeof(unsigned long long int), 1, fptr);
        adjacent_list = cells[i] -> getAdjacentList();
        numAdj = adjacent_list.size();
        fwrite(&numAdj, sizeof(int), 1, fptr);
        what_is_type = cells[i] -> getCellType();
        fwrite(&what_is_type, sizeof(Cell::CellType), 1, fptr);
        xPos = cells[i] -> getxPos();
        yPos = cells[i] -> getyPos();
        fwrite(&xPos, sizeof(double), 1, fptr);
        fwrite(&yPos, sizeof(double), 1, fptr);
        for(int j = 0 ; j < numAdj ; j++){
            fwrite( adjacent_list[j].getID(), sizeof(unsigned long long int), 1, fptr );
        }
    } //End of writing a Cell properties
} //End of saving function

SaverLoader::loadMap(std::string file_name){
    char* char_file_name = file_name.c_str();
}
