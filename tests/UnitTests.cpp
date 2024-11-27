//
// Created by Samuel Mace on 2024/11/26.
//

#include "CSVObject.h"

class TestCSVObject : public CSVObject {
    public:
        TestCSVObject() : CSVObject("assets/test_data/accounts.csv", std::vector<std::string>({"username", "password", "accountID"})) {}
        void testPrint() const {
            print();
        }
};

int main(int argc, char **argv) {

    const TestCSVObject test;
    test.testPrint();

    return 0;

}
