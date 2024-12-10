//
// Created by Samuel Mace <samuelcmace@gmail.com> on 11/18/2024.
//

#ifndef CSVOBJECT_H
#define CSVOBJECT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

class CSVObject {
private:
    std::string filePath;
    std::vector<std::vector<std::string> > data;

    void readFile();

    void writeFile() const;

protected:
    int getRowCount() const;

    int getColCount() const;

    void print() const;

    int queryRowNumber(std::string colKey, std::string colValue, int startingRowIndex = 0) const;

    void createRow(std::vector<std::string> rowContents);

    std::vector<std::string> readRow(int lineNumber) const;

    void updateRow(int lineNumber, std::vector<std::string> newRowContents);

    void deleteRow(int lineNumber);

public:
    CSVObject(std::string filePath, std::vector<std::string> columnNames);

    virtual ~CSVObject();
};

#endif // CSVOBJECT_H
