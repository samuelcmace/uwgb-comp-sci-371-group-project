//
// Created by Samuel Mace on 2024/11/26.
//

#include "CSVObject.h"

#include <string>
#include <vector>

class TestCSVObject : public CSVObject {
    public:
        TestCSVObject(std::string p_filepath, std::vector<std::string> p_columnNames) : CSVObject(p_filepath, p_columnNames) {}
        void testPrint() const {
            print();
        }
};

int main(int argc, char **argv) {

    std::vector<std::string> columnNames = {"username", "password", "accountID"};
    const TestCSVObject test("assets/test_data/accounts.csv", columnNames);
    test.testPrint();

    return 0;

}
