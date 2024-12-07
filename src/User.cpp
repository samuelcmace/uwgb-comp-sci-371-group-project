//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "User.h"

// Constructor
User::User(std::string username, std::string password) : username(username), password(password) {}

// Getters
std::string User::getUsername() const {
    return this->username;
}

std::string User::getPassword() const {
    return this->password;
}

User::Type User::getTypeEnum(const std::string& type) {
    if(type == "CUSTOMER") {
        return User::Type::CUSTOMER;
    } else if(type == "MANAGER") {
        return User::Type::MANAGER;
    }
}

std::string User::getTypeString(const User::Type& type) {
    if(type == User::Type::CUSTOMER) {
        return "CUSTOMER";
    } else if(type == User::Type::MANAGER) {
        return "MANAGER";
    }
}
