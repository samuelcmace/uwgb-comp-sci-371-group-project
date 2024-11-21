//
// Created by Samuel Mace <samuelcmace@gmail.com> on 11/18/2024.
//

#ifndef CSVOBJECT_H
#define CSVOBJECT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class CSVObject {
private:
    std::string filePath;
    std::vector<std::vector<std::string>> data;
    void readFile();
    void writeFile();

protected:
    int getRowCount() const;
    int getColCount() const;
    void print() const;
    int queryRowNumber(std::string colKey, std::string colValue, int startingRowIndex = 0);
    void createRow(std::vector<std::string> rowContents);
    std::vector<std::string> readRow(int lineNumber);
    void updateRow(int lineNumber, std::vector<std::string> newRowContents);
    void deleteRow(int lineNumber);

public:
    CSVObject(std::string filePath, std::string columnNames[]);
    virtual ~CSVObject();

};

#endif // CSVOBJECT_H
