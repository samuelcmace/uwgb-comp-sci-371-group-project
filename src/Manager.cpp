//
// Created by Bibesh Pyakurel on 12/06/24.
//

#include "Manager.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor: Initializes manager data
Manager::Manager(std::string name, std::string password)
    : name(name), password(password) {}

// Login validation
bool Manager::login(const std::string& inputName, const std::string& inputPassword, const std::string& managersFilePath) {
    std::ifstream file(managersFilePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open managers file: " << managersFilePath << "\n";
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string managerName, managerPassword;
        std::getline(lineStream, managerName, ',');
        std::getline(lineStream, managerPassword, ',');

        if (managerName == inputName && managerPassword == inputPassword) {
            return true;
        }
    }

    std::cerr << "Login failed: Invalid credentials.\n";
    return false;
}

// View all user data
void Manager::viewAllUserData(const CSVObject& usersCSV) const {
    if (usersCSV.getRowCount() == 0) {
        std::cout << "No user data available.\n";
        return;
    }

    std::cout << "All User Accounts:\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "Account Number | Username | Balance | Account Type\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 1; i < usersCSV.getRowCount(); ++i) { // Skip header row
        auto userRow = usersCSV.readRow(i);
        std::cout << userRow[0] << " | "
                  << userRow[1] << " | $"
                  << userRow[3] << " | "
                  << userRow[4] << "\n";
    }

    std::cout << "---------------------------------------------\n";
}
