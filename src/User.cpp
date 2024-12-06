//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "User.h"

// Constructor to initialize user with username and password
User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {}

//Getter function for username
std::string User::getUsername() const {
    return username;
}

//Getter function for password
std::string User::getPassword() const {
    return password;
}
