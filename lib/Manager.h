//
// Created by Bibesh Pyakurel on 12/06/24.
//

#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include "CSVObject.h"

class Manager {
private:
    std::string name;
    std::string password;

public:
    // Constructor
    Manager(std::string name, std::string password);

    // Login validation
    static bool login(const std::string& inputName, const std::string& inputPassword, const std::string& managersFilePath);

    // View all user data
    void viewAllUserData(const CSVObject& usersCSV) const;
};

#endif // MANAGER_H
