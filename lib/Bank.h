//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef BANK_H
#define BANK_H

#include <vector>
#include "CSVObject.h"
#include "User.h"

class Bank : public CSVObject {

private:
    static int activeAccounts;        // Tracks the number of active accounts
    std::vector<User*> users;         // In-memory storage for user data
    Bank();
    void loadUsersFromFile();
    static Bank* instance;

public:

    // Delete copy constructor and assignment operator
    Bank(const Bank& object) = delete;
    Bank& operator=(const Bank& object) = delete;

    // Static method to get the singleton instance of Bank.
    static Bank* getInstance() {
        if(instance == nullptr) {
            instance = new Bank();
        }
        return instance;
    }

    ~Bank() {
        delete instance;
    }

    // Methods to manage users
    void createUser(const std::string& username, const std::string& password, const User::Type userType);
    void deleteUser(const std::string& accountID);

    // Login functionality
    bool login(const std::string& username, const std::string& password);

    // Update balance
    void updateBalance(const std::string& accountID, double newBalance);

    // Static method to get the number of active accounts
    static int getActiveAccounts();

};

#endif // BANK_H
