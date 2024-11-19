//
// Created by Samuel Mace <samuelcmace@gmail.com> on 11/18/2024.
//

#include "CSVObject.h"

/**
 * Initializes a new CSVObject with the corresponding directory path and column names.
 * @param columnNames The names that define the schema of the CSV file.
 * @param filePath The directory on the filesystem where the CSV file will be located.
 */
CSVObject::CSVObject(std::vector<std::string> columnNames, std::string filePath) {
    this->filePath = filePath;
    for(int i = 0; i < columnNames.size(); i++) {
        this->data[i].assign(0, columnNames.at(i));
    }
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
        int lineNumber = 1;
        while(std::getline(inputFile, line)) {
            // Create vectors to store the indices where the quotation marks and commas are located in the
            std::vector<int> quotationMarkPositions;
            std::vector<int> commasPositions;

            // Go through the line character by character and locate the indices where either a quotation mark or a
            // comma appear. Note these in corresponding vectors that we will use later in the algorithm.
            for(int i = 0; i < line.size(); i++) {
                if(line[i] == ',') {
                    commasPositions.push_back(i);
                } else if(line[i] == '"') {
                    quotationMarkPositions.push_back(i);
                }
            }

            // After going through the line completely, if the number of quotation mark characters in a given line
            // is not divisible by 2, throw an exception.
            if(quotationMarkPositions.size() % 2 == 1) {
                throw std::runtime_error("Error: Invalid CSV Syntax on Line " + std::to_string(lineNumber) + " in '" + filePath + "'. The number of quotation marks in any given line should be divisible by 2!");
            }

            int currentCommaIndex = 0;
            // Go through the quotation mark indices list to group the line into substrings.
            for(int i = 1; i < quotationMarkPositions.size(); i = i + 2) {
                // Perform an additional check to see if there are any commas hiding in between the quotation marks...
                int leftIndex = quotationMarkPositions[i - 1];
                int rightIndex = quotationMarkPositions[i];
                while(commasPositions[currentCommaIndex] < rightIndex &&
                    commasPositions[currentCommaIndex] > leftIndex &&
                    currentCommaIndex < commasPositions.size()) {
                    currentCommaIndex++;
                }
                this->data[floor(i / 2)].push_back(line.substr(leftIndex, rightIndex));
            }
            lineNumber++;
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

        for (int i = 0; i < this->getRowCount(); i++) {
            std::string row;
            for(int j = 0; j < this->getColCount(); j++) {
                row += "\"" + this->data[i][j] + "\"";
                if(j < this->getColCount() - 1) {
                    row += ",";
                }
            }
            outputFile << row << std::endl;
        }

        outputFile.close();

    }
}

/**
 * Method to retrieve the number of columns in the CSV file. This data value is based on the number of entries
 * in the root data vector.
 */
int CSVObject::getColCount() const {
    return this->data.size();
}

/**
 * Method to retrieve the number of rows in the CSV file. If the CSVObject has at-least one column (as it should),
 * then return the size of the first column. Otherwise, return 0 for an empty data vector.
 */
int CSVObject::getRowCount() const {
    return this->getColCount() > 0 ? this->data[0].size() : 0;
}
