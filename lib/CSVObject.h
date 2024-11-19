//
// Created by Samuel Mace <samuelcmace@gmail.com> on 11/18/2024.
//

#ifndef CSVOBJECT_H
#define CSVOBJECT_H

#include <vector>
#include <string>
#include <fstream>

class CSVObject {
private:
    std::string filePath;
    std::vector<std::vector<std::string>> data;

protected:
    int getRowCount() const;
    int getColCount() const;
    void readFile();
    void writeFile();

public:
    CSVObject(std::vector<std::string> columnNames, std::string filePath);
    virtual ~CSVObject();

};

#endif // CSVOBJECT_H
