//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "User.h"

User::User(std::string username, std::string password) {
    this->username = username;
    this->password = password;
}

std::string User::getUsername() const {
    return this->username;
}

std::string User::getPassword() const {
    return this->password;
}

bool User::authenticate(std::string username, std::string password) {
    return this->username == username && this->password == password;
}
