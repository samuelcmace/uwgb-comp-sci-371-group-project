//
// Created by Bibesh Pyakurel on 12/06/24.
//

#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>

#include "CSVObject.h"
#include "User.h"

class Manager : public User {
public:
    // Constructor
    Manager(std::string name, std::string password);

    // Login validation
    bool login(const std::string& inputName, const std::string& inputPassword);

    // View all user data
    void viewAllUserData() const;
    void setBalance(double newBalance);
    std::string getAccountType() const;

};

#endif // MANAGER_H
