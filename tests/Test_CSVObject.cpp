//
// Created by Samuel Mace on 2024/11/26.
//

#include "CSVObject.h"

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

void firstRowMatchesTest() {
    std::vector<std::string> columnNames = {"username", "password", "accountID"};
    const TestCSVObject test("assets/test_data/accounts.csv", columnNames);

    // Test 1: Assert that the vector of columns columnNames is equal to the first row...
    std::vector<std::string> firstRow = test.testReadRow(0);

    for (int i = 0; i < firstRow.size(); i++) {
        if (firstRow[i] != columnNames[i]) {
            throw std::runtime_error("First Row Matching Test Failed!");
        }
    }
    std::cout << "Passed First Row Test!" << std::endl;
}

void lastRowMatchesTest() {
    std::vector<std::string> columnNames = {"username", "password", "accountID"};
    const TestCSVObject test("assets/test_data/accounts.csv", columnNames);

    std::vector<std::string> expectedLastRow = {"tpkqjhvi", "wgmhBZ7Q0z", "593136"};
    std::vector<std::string> actualLastRow = test.testReadRow(test.testGetRowCount() - 1);

    for (int i = 0; i < actualLastRow.size(); i++) {
        if (actualLastRow[i] != expectedLastRow[i]) {
            throw std::runtime_error("Last Row Matching Test Failed!");
        }
    }
    std::cout << "Passed Last Row Test!" << std::endl;
}

void createRowTest() {

    std::vector<std::string> columnNames = {"username", "password", "accountID"};
    TestCSVObject test("assets/test_data/accounts.csv", columnNames);

    std::vector<std::string> expectedLastRow = {"tpkqjhvi", "wgmhBZ7Q0z", "593136"};
    std::vector<std::string> actualLastRow = test.testReadRow(test.testGetRowCount() - 1);

    for (int i = 0; i < actualLastRow.size(); i++) {
        if (actualLastRow[i] != expectedLastRow[i]) {
            throw std::runtime_error("Last Row Matching Test Failed!");
        }
    }

    std::vector<std::string> newRow = {"asdfjkl", "123fdfgdsFD", "1234543"};
    test.testCreateRow(newRow);



}

void deleteRowTest() {

    std::vector<std::string> columnNames = {"username", "password", "accountID"};
    const TestCSVObject test("assets/test_data/accounts.csv", columnNames);
}

void updateRowTest() {

    std::vector<std::string> columnNames = {"username", "password", "accountID"};
    const TestCSVObject test("assets/test_data/accounts.csv", columnNames);
}

int main(int argc, char **argv) {

    try {
        std::cout << "Running First Row Test..." << std::endl;
        firstRowMatchesTest();

        std::cout << "Running Last Row Test..." << std::endl;
        lastRowMatchesTest();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;

}
