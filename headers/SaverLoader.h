#ifndef SAVERLOADER_H
#define SAVERLOADER_H

#include <string>
#include <vector>
#include "Cell.h"

class Cell;

class SaverLoader
{
private:

public:
    SaverLoader();
    saveMap(std::string file_name, std::vector<Cell*> cells);
    loadMap(std::string file_name);
};

#endif // SAVERLOADER_H
