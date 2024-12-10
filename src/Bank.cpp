//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include <iostream>

#include "Bank.h"
#include "Customer.h"
#include "Manager.h"
#include "User.h"

// Initialize static member
int Bank::activeAccounts = 0;

// Constructor: Initializes the Bank with the CSV file
Bank::Bank()
    : CSVObject("users.csv", {"USERNAME", "PASSWORD", "TYPE"}) {
    loadUsersFromFile();
}

/**
 * Manually delete all the heap-allocated User objects.
 */
Bank::~Bank() {
    for (User *user: this->users) {
        delete user;
    }
}

void Bank::createUserInMemory(const std::string &username, const std::string &password, const User::Type type) {
    User *newUser;
    if (type == User::Type::CUSTOMER) {
        newUser = new Customer(username, password);
    } else if (type == User::Type::MANAGER) {
        newUser = new Manager(username, password);
    }
    users.push_back(newUser);
}

// Create a new user
bool Bank::createUser(const std::string &username, const std::string &password, const User::Type& userType) {
    // Check for duplicate accountID
    for (const auto &user: users) {
        if (user->getUsername() == username) {
            std::cout << "Error: Username already exists.\n";
            return false;
        }
    }

    // Add user to memory and CSV
    createUserInMemory(username, password, userType);
    this->createRow({username, password, User::getTypeString(userType)});

    // Increment active accounts
    activeAccounts++;
    std::cout << "User created successfully.\n";
    return true;
}

// Delete a user
bool Bank::deleteUser(const std::string &username) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->getUsername() == username) {
            users.erase(users.begin() + i);

            int userIndex = this->queryRowNumber("USERNAME", username);
            if (userIndex != -1) {
                this->deleteRow(userIndex);
            }

            // Decrement active accounts
            activeAccounts--;
            return true;
        }
    }

    std::cerr << "User does not exist." << std::endl;
    return false;
}

std::vector<User *> Bank::getUsers() {
    return this->users;
}

User *Bank::getUserByUsername(const std::string &username) const {
    User *userToReturn = nullptr;
    for (User *user: this->users) {
        if (user->getUsername() == username) {
            userToReturn = user;
            break;
        }
    }
    return userToReturn;
}

// Load users from the file into memory
void Bank::loadUsersFromFile() {
    for (int i = 1; i < this->getRowCount(); ++i) {
        // Skip header row
        std::vector<std::string> row = this->readRow(i);
        if (row.size() != 3) {
            std::cerr << "Warning: Malformed row in users.csv\n";
            continue;
        }

        // Schema: "USERNAME","PASSWORD","TYPE"
        std::string username = row[0];
        std::string password = row[1];
        User::Type type = User::getTypeEnum(row[2]);

        createUserInMemory(username, password, type);
    }
    activeAccounts = users.size();
    std::cout << "Loaded " << activeAccounts << " users from file.\n";
}

// Handle user login
bool Bank::login(const std::string &username, const std::string &password) {
    for (User *user: users) {
        if (user->authenticate(username, password)) {
            std::cout << "Login successful for user: " << username << "\n";
            return true;
        }
    }
    std::cout << "Error: Invalid username or password.\n";
    return false;
}

// Update user balance
void Bank::updateBalance(const std::string &username, double newBalance) {
    for (size_t i = 0; i < users.size(); ++i) {
        User *currentUser = users[i];
        if (users[i]->getUsername() == username) {
            if (currentUser->getAccountType() != User::Type::CUSTOMER) {
                std::cerr << "User is not a customer! Aborting!" << std::endl;
                return;
            }

            Customer *customer = dynamic_cast<Customer *>(currentUser);

            double currentBalance = customer->getBalance();
            Transaction::Type newTransactionType = newBalance > currentBalance
                                                       ? Transaction::Type::DEPOSIT
                                                       : Transaction::Type::WITHDRAWAL;
            double transactionAmount = std::max(newBalance, currentBalance) - std::min(newBalance, currentBalance);

            if (newTransactionType == Transaction::DEPOSIT) {
                customer->deposit(transactionAmount);
            } else {
                customer->deposit(transactionAmount);
            }

            std::cout << "Balance updated successfully for account " << username << ".\n";
            return;
        }
    }
    std::cout << "Error: Account not found.\n";
}

// Get the number of active accounts
int Bank::getActiveAccounts() {
    return activeAccounts;
}
