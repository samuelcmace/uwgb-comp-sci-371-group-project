//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include <iostream>

#include "UserManager.h"
#include "Customer.h"
#include "User.h"
#include "Employee.h"

// Initialize static member
int UserManager::activeAccounts = 0;

// Constructor: Initializes the UserManager with the CSV file
UserManager::UserManager(const std::string& filePath)
    : usersCSV(filePath, {"AccountID", "Username", "Password", "Balance"}) {
    loadUsersFromFile();
}

// Create a new user
void UserManager::createUser(const std::string& username, const std::string& password, const std::string& accountID, double balance) {
    // Check for duplicate accountID
    for (const auto& user : users) {
        if (user.getAccountNumber() == accountID) {
            std::cout << "Error: Account ID already exists.\n";
            return;
        }
    }

    // Add user to memory and CSV
    User newUser(username, password, accountID, balance);
    users.push_back(newUser);
    usersCSV.createRow({accountID, username, password, std::to_string(balance)});

    // Increment active accounts
    activeAccounts++;
    std::cout << "User created successfully.\n";
}

// Delete a user
void UserManager::deleteUser(const std::string& accountID) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].getAccountNumber() == accountID) {
            users.erase(users.begin() + i); // Remove user from memory

            // Remove from CSV
            int userIndex = usersCSV.queryRowNumber("AccountID", accountID);
            if (userIndex != -1) {
                usersCSV.deleteRow(userIndex);
            }

            // Decrement active accounts
            activeAccounts--;
            std::cout << "User deleted successfully.\n";
            return;
        }
    }
    std::cout << "Error: Account not found.\n";
}

// Load users from the file into memory
void UserManager::loadUsersFromFile() {
    for (int i = 1; i < usersCSV.getRowCount(); ++i) { // Skip header row
        auto row = usersCSV.readRow(i);
        if (row.size() < 4) {
            std::cerr << "Warning: Malformed row in users.txt\n";
            continue;
        }

        User user(row[1], row[2], row[0], std::stod(row[3])); // Username, Password, AccountID, Balance
        users.push_back(user);
    }
    activeAccounts = users.size();
    std::cout << "Loaded " << activeAccounts << " users from file.\n";
}

// Handle user login
bool UserManager::login(const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            std::cout << "Login successful for user: " << username << "\n";
            return true;
        }
    }
    std::cout << "Error: Invalid username or password.\n";
    return false;
}

// Update user balance
void UserManager::updateBalance(const std::string& accountID, double newBalance) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].getAccountNumber() == accountID) {
            users[i].setBalance(newBalance);

            // Update the CSV file
            int userIndex = usersCSV.queryRowNumber("AccountID", accountID);
            if (userIndex != -1) {
                auto row = usersCSV.readRow(userIndex);
                row[3] = std::to_string(newBalance); // Update balance in CSV
                usersCSV.updateRow(userIndex, row);
            }

            std::cout << "Balance updated successfully for account " << accountID << ".\n";
            return;
        }
    }
    std::cout << "Error: Account not found.\n";
}

// Get the number of active accounts
int UserManager::getActiveAccounts() {
    return activeAccounts;
}
