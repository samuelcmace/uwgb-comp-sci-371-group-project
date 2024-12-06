//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;  // User's username
    std::string password;  // User's password

public:
    // Constructor to initialize username and password
    User(const std::string& username, const std::string& password);

    virtual ~User() = default;  // Virtual destructor for proper cleanup

    // Getter functions for username and password
    std::string getUsername() const;
    std::string getPassword() const;

    enum Type {
        CUSTOMER,
        EMPLOYEE
    };

};

#endif // USER_H

