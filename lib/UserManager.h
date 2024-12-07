//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "CSVObject.h"
#include "User.h"

class UserManager {
private:
    static int activeAccounts;       // Tracks the number of active accounts
    CSVObject usersCSV;              // Handles operations on users.txt
    std::vector<User> users;         // In-memory storage for user data

public:
    // Constructor
    UserManager(const std::string& filePath);

    // Methods to manage users
    void createUser(const std::string& username, const std::string& password, const std::string& accountID, double balance);
    void deleteUser(const std::string& accountID);
    void loadUsersFromFile();

    // Login functionality
    bool login(const std::string& username, const std::string& password);

    // Update balance
    void updateBalance(const std::string& accountID, double newBalance);

    // Static method to get the number of active accounts
    static int getActiveAccounts();
};

#endif // USERMANAGER_H
