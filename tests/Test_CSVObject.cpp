//
// Created by Samuel Mace on 2024/11/26.
//

#include "lib/CSVObject.h"

#include <string>
#include <vector>

/**
 * Dummy class to help expose the protected methods in the CSVObject for testing purposes...
 */
class TestCSVObject : public CSVObject {
public:
    TestCSVObject(std::string p_filepath,
                  std::vector<std::string> p_columnNames) : CSVObject(p_filepath, p_columnNames) {
    }

    void testPrint() const {
        print();
    }

    std::vector<std::string> testReadRow(const int row) const {
        return this->readRow(row);
    }

    int testGetRowCount() const {
        return this->getRowCount();
    }

    void testUpdateRow(int rowIndex, std::vector<std::string> updatedRow) {
        this->updateRow(rowIndex, updatedRow);
    }

    void testCreateRow(std::vector<std::string> newRow) {
        this->createRow(newRow);
    }

    void testDeleteRow(int rowIndex) {
        this->deleteRow(rowIndex);
    }
};

/**
 * Unit test on the mock CSV file to determine whether the column row matches the expected values.
 */
void readRowTest() {

    std::cout << "Executing Row Read Test..." << std::endl;

    const std::vector<std::string> columnNames = {"username", "password", "accountID"};

    TestCSVObject test("assets/test_data/accounts.csv", columnNames);
    std::vector<std::string> firstRow = test.testReadRow(0);

    // The std::vector class provides an operator overload for the == and != operators that automatically
    // compare the elements in the vectors for us without us having to compare the values manually.
    if(firstRow != columnNames) {
        throw std::runtime_error("First Row Matching Test Failed!");
    } else {
        std::cout << "Row Read Test Passed!" << std::endl;
    }

}

/**
 *  
 */
void createRowTest() {

    std::cout << "Executing Row Creation Test..." << std::endl;

    const std::vector<std::string> columnNames = {"username", "password", "accountID"};

    TestCSVObject writeTest("assets/test_data/accounts.csv", columnNames);
    std::vector<std::string> expectedNewRow = {"asdfjkl", "123fdfgdsFD", "1234543"};
    writeTest.testCreateRow(expectedNewRow);

    TestCSVObject readTest("assets/test_data/accounts.csv", columnNames);
    std::vector<std::string> actualNewRow = readTest.testReadRow(readTest.testGetRowCount() - 1);

    if(expectedNewRow != actualNewRow) {
        throw std::runtime_error("Row Creation Test: FAIL");
    } else {
        std::cout << "Row Creation Test: PASS" << std::endl;
    }

}

void deleteRowTest() {

    std::cout << "Executing Row Deletion Test..." << std::endl;

    const std::vector<std::string> columnNames = {"username", "password", "accountID"};

    TestCSVObject deleteObject("assets/test_data/accounts.csv", columnNames);

    int deletedIndex = deleteObject.testGetRowCount() - 1;
    std::vector<std::string> deletedRow = deleteObject.testReadRow(deletedIndex);
    deleteObject.testDeleteRow(deletedIndex);

    TestCSVObject readTest("assets/test_data/accounts.csv", columnNames);

    int lastIndex = readTest.testGetRowCount() - 1;
    std::vector<std::string> lastRow = readTest.testReadRow(lastIndex);

    // In this case, there would be an error if the last row and the deleted row were equal.
    // In a theoretical case, the deletion could occur as expected and the exception thrown
    // if there are two rows of data that are exactly the same positioned towards the end
    // of the vector. However, in that case, the data would be quite useless and the
    // exception would be cause for investigation.
    if(lastRow == deletedRow) {
        throw std::runtime_error("Row Deletion Test: FAIL");
    } else {
        std::cout << "Row Deletion Test: PASS" << std::endl;
    }

}

void updateRowTest() {

    std::cout << "Executing Row Update Test..." << std::endl;

    const std::vector<std::string> columnNames = {"username", "password", "accountID"};

    TestCSVObject firstObject("assets/test_data/accounts.csv", columnNames);
    int lastIndex = firstObject.testGetRowCount() - 1;
    std::vector<std::string> lastRowOriginal = firstObject.testReadRow(lastIndex);

    // Use the copy constructor for the vector to create a duplicate row that can be modified.
    // Then, update the row by overwriting the index with the new data.
    std::vector<std::string> lastRowUpdated = lastRowOriginal;
    lastRowUpdated[0] = "Hello World";
    firstObject.testUpdateRow(lastIndex, lastRowUpdated);

    TestCSVObject secondObject("assets/test_data/accounts.csv", columnNames);
    int lastIndexCurrent = firstObject.testGetRowCount() - 1;
    std::vector<std::string> lastRowCurrent = firstObject.testReadRow(lastIndex);

    if(lastRowCurrent == lastRowOriginal) {
        throw std::runtime_error("Row Update Test: FAIL");
    } else {
        std::cout << "Row Update Test: PASS" << std::endl;
    }

}

int main(int argc, char **argv) {

    try {
        readRowTest();
        createRowTest();
        deleteRowTest();
        updateRowTest();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}
