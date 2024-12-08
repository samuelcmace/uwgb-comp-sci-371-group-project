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
    ~Manager();

    // View all user data
    void viewAllUserData() const;

    void setBalance(double newBalance);

    Type getAccountType() const;

};

#endif // MANAGER_H
