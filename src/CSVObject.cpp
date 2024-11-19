//
// Created by samue on 11/18/2024.
//

#include "CSVObject.h"

/**
 * Initializes a new CSVObject with the corresponding directory path and column names.
 * @param columnNames The names that define the schema of the CSV file.
 * @param filePath The directory on the filesystem where the CSV file will be located.
 */
CSVObject::CSVObject(std::vector<std::string> columnNames, std::string filePath) {
    this->filePath = filePath;
    this->columnCount = columnNames.size();
    for(int i = 0; i < columnCount; i++) {
        this->data[i].assign(i, columnNames.at(i));
    }
    this->rowCount = 1;
}

/**
 * Method to deallocate the heap-allocated data.
 */
CSVObject::~CSVObject() {

}

/**
 * Method to read the CSV file and populate the CSVObject accordingly. Called only once during the CSVObject
 * initialization (which is why the method is marked as private).
 */
void CSVObject::readFile() {
    std::ifstream inputFile(filePath);

    if(inputFile.is_open()) {
        std::string line;
        while(std::getline(inputFile, line)) {

        }

        inputFile.close();
    }
}

/**
 * Method to write (or persist) the changes in the CSVObject to the filesystem.
 */
void CSVObject::writeFile() {
    // Create a new output file with the truncation mode for overwriting the file as it currently exists.
    std::ofstream outputFile(filePath, std::ofstream::trunc);

    if(outputFile.is_open()) {

        for (int i = 0; i < this->rowCount; i++) {
            std::string row;
            for(int j = 0; j < this->columnCount; j++) {
                row += "\"" + this->data[i][j] + "\"";
                if(j < this->columnCount - 1) {
                    row += ",";
                }
            }
            outputFile << row << std::endl;
        }

        outputFile.close();

    }
}
