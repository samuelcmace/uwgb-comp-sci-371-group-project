//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "UserManager.h"
#include <iostream>
#include <stdexcept>

// Constructor to initialize UserManager with a CSVObject (for file interaction)
UserManager::UserManager(CSVObject* csvObject) : csvObject(csvObject) {
    loadUsersFromCSV();  // Load users from the CSV file on initialization
}

// Destructor to clean up dynamically allocated users
UserManager::~UserManager() {
    for (auto user : users) {
        delete user;  // Deallocate memory for each user
    }
}

// Add a new user to the list and save to the CSV file
void UserManager::addUser(User* user) {
    users.push_back(user);  // Add the new user to the internal list
    csvObject->createRow({user->getUsername(), user->getPassword()});  // Save user data to CSV
}

// Authenticate a user by checking their username and password
bool UserManager::authenticateUser(const std::string& username, const std::string& enteredPassword) {
    for (auto user : users) {
        if (user->getUsername() == username && user->getPassword() == enteredPassword) {
            return true;  //Authentication successful
        }
    }
    return false;  //Authentication failed
}

// Get a user by their username
User* UserManager::getUserByUsername(const std::string& username) {
    for (auto user : users) {
        if (user->getUsername() == username) {
            return user;  // Return the user if found
        }
    }
    return nullptr;  // Return nullptr if user not found
}

// Load users from the CSV file
void UserManager::loadUsersFromCSV() {
    // This method should query the CSV file and create User objects
    // Example: users.push_back(new Customer(username, password));  // Assuming a Customer class exists
}
