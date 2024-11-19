//
// Created by samue on 11/18/2024.
//

#ifndef CSVOBJECT_H
#define CSVOBJECT_H

#include <vector>
#include <string>
#include <fstream>

class CSVObject final {
private:
    std::string filePath;
    unsigned int columnCount;
    unsigned int rowCount;
    std::vector<std::vector<std::string>> data;
    void readFile();

public:
    CSVObject(std::vector<std::string> columnNames, std::string filePath);
    virtual ~CSVObject();
    void writeFile();

};

#endif // CSVOBJECT_H
