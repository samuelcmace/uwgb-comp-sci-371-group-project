//
// Created by Samuel Mace <samuelcmace@gmail.com> on 11/18/2024.
//

#include "CSVObject.h"

/**
 * Initializes a new CSVObject with the corresponding directory path and column names.
 * @param columnNames The names that define the schema of the CSV file.
 * @param filePath The directory on the filesystem where the CSV file will be located.
 */
CSVObject::CSVObject(std::string filePath, std::vector<std::string> columnNames) {

    this->filePath = filePath;

    // Use the C++17 std::filesystem namespace to check whether the file exists on the system first...
    bool fileAlreadyExists = std::filesystem::exists(filePath);

    std::cout << "Reading from file " << filePath << "..." << std::endl;
    this->readFile();

    // If the file already existed prior to reading from it, check if the column names align with what is specified
    // in the schema. If not, throw a runtime error...
    if (fileAlreadyExists) {
        std::cout << "Verifying schema of column names..." << std::endl;
        bool columnsMatch = true;
        for (int i = 0; i < this->data[0].size(); i++) {
            if (this->data[0][i] != columnNames[i]) {
                columnsMatch = false;
            }
        }
        if (!columnsMatch) {
            throw std::runtime_error("Error: The specified column names do not match! Aborting...");
        }
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
        int lineNumber = 0;
        while(std::getline(inputFile, line)) {

            // Store the indexes of the commas as a queue data structure so that we can easily pop them when we are
            // ready to read the line.
            std::queue<int> commaIndices;
            int currentIndex = 0;

            while(currentIndex < line.size()) {
                currentIndex = line.find(",", currentIndex);
                commaIndices.push(currentIndex);
            }

            do {
                const int nextIndex = commaIndices.front();
                commaIndices.pop();
                this->data[lineNumber].push_back(line.substr(currentIndex, nextIndex - currentIndex));
                currentIndex = nextIndex;
            } while (!commaIndices.empty());

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
                row += this->data[i][j];
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
 * Method to retrieve the number of rows in the CSV file. This data value is based on the number of entries
 * in the root data vector.
 */
int CSVObject::getRowCount() const {
    return this->data.size();
}

/**
 * Method to retrieve the number of columns in the CSV file. If the CSVObject has at-least one column (as it should),
 * then return the size of the first column. Otherwise, return 0 for an empty data vector.
 */
int CSVObject::getColCount() const {
    return this->getColCount() > 0 ? this->data[0].size() : 0;
}

int CSVObject::queryRowNumber(std::string colKey, std::string colValue, int startingRowIndex) {

    // Determine the column mapping using the provided column key colKey...
    int colIndex = -1;
    for(int i = 0; i < this->data[0].size(); i++) {
        if(this->data[0][i] == colKey) {
            colIndex = i;
            break;
        }
    }

    if(colIndex == -1) {
        throw std::runtime_error("Error: The requested column '" + colKey + "' was not found in the file '" + filePath + "'. Aborting!");
    }

    // Query the row index where the specified object is...
    int rowIndex = -1;
    for(int i = 0; i < this->data.size(); i++) {
        if(this->data[i][colIndex] == colValue) {
            rowIndex = i;
            break;
        }
    }

    // If the requested data was not found, the function will return -1. Otherwise, it will return the corresponding row index.
    return rowIndex;

}

void CSVObject::createRow(std::vector<std::string> rowContents) {



    // Call the writeFile() method to persist the changes.
    writeFile();
}

std::vector<std::string> CSVObject::readRow(int lineNumber) {

    std::vector<std::string> rowContents;

    return rowContents;

}

void CSVObject::updateRow(int lineNumber, std::vector<std::string> newRowContents) {



    // Call the writeFile() method to persist the changes.
    writeFile();
}

/**
 *
 * @param lineNumber
 */
void CSVObject::deleteRow(int lineNumber) {



    // Call the writeFile() method to persist the changes.
    writeFile();
}

void CSVObject::print() const {

    for(int i = 0; i < this->getRowCount(); i++) {
        for(int j = 0; j < this->getColCount(); j++) {
            std::cout << this->data[j][i] << ", ";
        }
        std::cout << std::endl;
    }

}
