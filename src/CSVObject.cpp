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
    this->data = std::vector(1, std::vector<std::string>());

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
 * Method to deallocate the heap-allocated data. Since at the time of writing, the class was not allocating any
 * heap-allocated data, a default destructor is fine. Otherwise, the default keyword can be replaced with an
 * implementation of the destructor as needed.
 */
CSVObject::~CSVObject() = default;

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
            std::vector<int> commaIndices;
            int currentIndex = 0;

            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ',') {
                    commaIndices.push_back(i);
                }
            }

            int previousIndex;
            for (int i = 0; i <= commaIndices.size(); i++) {
                if (i == 0) {
                    previousIndex = 0;
                    currentIndex = commaIndices[i];
                } else if (i == commaIndices.size()) {
                    previousIndex = currentIndex + 1;
                    currentIndex = commaIndices.size() - 1;
                } else {
                    previousIndex = currentIndex + 1;
                    currentIndex = commaIndices[i];
                }
                this->data[lineNumber].push_back(line.substr(previousIndex, currentIndex - previousIndex));
            }

            lineNumber++;
        }
        inputFile.close();
    }
}

/**
 * Method to write (or persist) the changes in the CSVObject to the filesystem.
 */
void CSVObject::writeFile() const {
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
    return this->getRowCount() > 0 ? this->data[0].size() : 0;
}

/**
 * Function to query the index at the first sighting of a specified value in a given column, starting at a specific
 * index.
 *
 * @param colKey The key corresponding to the column to be queried.
 * @param colValue The value that is expected for the column to have.
 * @param startingRowIndex Since multiple rows may have the same value for the given column, this startingRowIndex
 *                         specifies where the querying should begin row-wise.
 * @return An integer corresponding to the index in the data vector where the value for the row was found (starting on
 *         the startingRowIndex.
 */
int CSVObject::queryRowNumber(std::string colKey, std::string colValue, int startingRowIndex) const {

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
    for(int i = startingRowIndex; i < this->data.size(); i++) {
        if(this->data[i][colIndex] == colValue) {
            rowIndex = i;
            break;
        }
    }

    // If the requested data was not found, the function will return -1. Otherwise, it will return the corresponding row index.
    return rowIndex;

}

/**
 * Method to add a row to the file.
 *
 * @param rowContents A vector containing the row contents (each column entry contained in a string).
 */
void CSVObject::createRow(std::vector<std::string> rowContents) {
    this->data.push_back(rowContents);
    writeFile();

}

/**
 * Method to read data from a row in the CSV file given a line number.
 *
 * @param lineNumber The line number containing the data to be read.
 * @return A vector of strings corresponding to the data that was read by the function.
 */
std::vector<std::string> CSVObject::readRow(int lineNumber) const {
    return this->data[lineNumber];
}

/**
 * Function to update the row in the CSV file given a line number and a vector containing the new column entry data
 * to be overwritten.
 *
 * @param lineNumber An integer corresponding to the line number on which the data appears.
 * @param newRowContents The new row contents that will replace the old ones.
 */
void CSVObject::updateRow(int lineNumber, std::vector<std::string> newRowContents) {
    // We can use the std::move operator, which works with the standard template library for the vector class
    // to allow for the efficient transfer of resources.
    this->data[lineNumber] = std::move(newRowContents);
    writeFile();
}

/**
 * Method to delete the row given a corresponding line number.
 *
 * @param lineNumber An integer corresponding to the line number to be deleted.
 */
void CSVObject::deleteRow(int lineNumber) {
    this->data.erase(this->data.begin() + lineNumber);
    writeFile();
}

/**
 * Method to print out the CSVObject as comma-separated entries using std::cout.
 */
void CSVObject::print() const {

    for(int i = 0; i < this->getRowCount(); i++) {
        for(int j = 0; j < this->getColCount(); j++) {
            std::cout << this->data[j][i] << ", ";
        }
        std::cout << std::endl;
    }

}
