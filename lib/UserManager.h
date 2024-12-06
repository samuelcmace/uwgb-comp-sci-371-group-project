//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include "User.h"
#include "CSVObject.h"  // For interaction with CSV files

class UserManager final : public CSVObject {
private:
    std::vector<User*> users;  // List of all users
    UserManager();

public:
    UserManager& getInstance() {
        static UserManager instance;
        return instance;
    }
    // Prevent the instance from being accidentally copied or assigned (using the assignment operator)
    // by explicitly setting these methods to delete.
    UserManager& operator=(const UserManager&) = delete;
    UserManager(const UserManager&) = delete;

    // Destructor to clean up dynamically allocated User objects
    ~UserManager();

    void addUser(User* user);

    bool authenticateUser(const std::string& username, const std::string& enteredPassword);

    User* getUserByUsername(const std::string& username);

    User* createUser(const std::string& createUser, const std::string& password, const std::string& user_type);

    // Load users from the CSV file
    void loadUsersFromCSV();
};

#endif // USERMANAGER_H