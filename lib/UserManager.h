//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "User.h"
#include "CSVObject.h"  // For interaction with CSV files

class UserManager {
private:
    std::vector<User*> users;  // List of all users
    CSVObject* csvObject;      // CSVObject to interact with CSV file for user data

public:
    // Constructor to initialize UserManager with a CSVObject for data persistence
    UserManager(CSVObject* csvObject);

    // Destructor to clean up dynamically allocated User objects
    ~UserManager();

    // Add a new user to the list and CSV file
    void addUser(User* user);

    // Authenticate a user based on username and password
    bool authenticateUser(const std::string& username, const std::string& enteredPassword);

    // Retrieve a user by their username
    User* getUserByUsername(const std::string& username);

    // Load users from the CSV file
    void loadUsersFromCSV();
};

#endif // USERMANAGER_H

