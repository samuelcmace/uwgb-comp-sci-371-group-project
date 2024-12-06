//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include <iostream>

#include "UserManager.h"
#include "Customer.h"
#include "User.h"
#include "Employee.h"

// Constructor to initialize UserManager with a CSVObject (for file interaction)
UserManager::UserManager() : CSVObject("user.csv",std::vector<std::string>{"username","password"}) {
    loadUsersFromCSV();  // Load users from the CSV file on initialization
}

//destructor to clean up dynamically allocated users
UserManager::~UserManager() {
    for (auto user : users) {
        delete user;  //deallocate memory for each user
    }
}

// Add a new user to the list and save to the CSV file
void UserManager::addUser(User* user) {
    users.push_back(user);  // Add the new user to the internal list
    this->createRow({user->getUsername(), user->getPassword()});  // Save user data to CSV
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

User* UserManager::createUser(const std::string& username, const std::string& password, const User::Type& user_type){
    User* newUser = nullptr;
    if(user_type == User::Type::CUSTOMER) {
        newUser = new Customer(username, password);
    } else if(user_type == User::Type::EMPLOYEE) {
        newUser = new Employee(username, password);
    }
    return newUser;
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
<<<<<<< Updated upstream
    //this method should query the CSV file and create User objects
    for (int i = 1; i < this->getRowCount(); ++i) {  //     Skip header row
        auto row = this->readRow(i);
=======
    // This method should query the CSV file and create User objects
    // Example: users.push_back(new Customer(username, password));  // Assuming a Customer class exists
    for (int i = 1; i < csvObject->getRowCount(); ++i) {  // Skip header row
        auto row = csvObject->readRow(i);
>>>>>>> Stashed changes
        if (row.size() < 3) {  // Assuming the third column is userType
            std::cerr << "Warning: Skipping malformed row in CSV file.\n";
            continue;
        }
        const std::string& username = row[0];
        const std::string& password = row[1];
<<<<<<< Updated upstream
        const User::Type& userType;
        if(row[2] == "0") {
            userType = User::Type::CUSTOMER;
        } else if(row[2] == "1") {
            userType = User::Type::EMPLOYEE;
        }
=======
        const std::string& userType = row[2];
>>>>>>> Stashed changes
        users.push_back(createUser(username, password, userType));
    }
}
