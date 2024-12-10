//
// Created by Bibesh Pyakurel on 12/06/24.
//

#include "Manager.h"

#include <Bank.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

// Constructor: Initializes manager data
Manager::Manager(std::string name, std::string password): User(name, password) {
}

Manager::~Manager() = default;

User::Type Manager::getAccountType() const {
    return User::Type::MANAGER;
}

// View all user data
void Manager::viewAllUserData() const {
    Bank &instance = Bank::getInstance();
    std::vector<User *> users = instance.getUsers();

    if (users.size() == 0) {
        std::cout << "No users found" << std::endl;
        return;
    }

    std::cout << "All User Accounts:" << std::endl;
    std::setfill("-");
    std::cout << std::setw(20) << std::endl;
    std::cout << "---------------------------------------------\n";
    std::cout << " | Username | Balance | Account Type\n";
    std::cout << "---------------------------------------------\n";
}
