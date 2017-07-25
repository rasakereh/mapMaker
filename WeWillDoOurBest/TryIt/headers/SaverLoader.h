#ifndef SAVERLOADER_H
#define SAVERLOADER_H

#include <string>
#include <vector>

class Cell;

class SaverLoader
{
private:

public:
    SaverLoader();
    void saveMap(std::string file_name, std::vector<Cell*> cells);
    std::vector<Cell*> loadMap(std::string file_name);
};

#endif // SAVERLOADER_H
