//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <string>

#include "CSVObject.h"
#include "User.h"

class UserManager : public CSVObject {
private:
    std::vector<User> users;

public: // UserManager-specified methods
    UserManager();

    void addUser(std::vector<std::string> userDetails) {
        users.push_back(userDetails);
        createRow(userDetails); //inheriting the method createRow from CSVObject
    }
    void deleteUser(int lineNumber) {
        deleteRow(lineNumber); //inheriting the method deleteRow from CSVObject
    }




};

#endif //USERMANAGER_H
