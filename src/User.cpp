//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "User.h"

#include <Transaction.h>

// Constructor
User::User(const std::string &username, const std::string &password) : username(username), password(password) {
};

User::~User() = default;

// Getters
std::string User::getUsername() const {
    return this->username;
}

std::string User::getPassword() const {
    return this->password;
}

bool User::authenticate(const std::string &username, const std::string &password) const {
    return this->username == username && this->password == password;
}

User::Type User::getTypeEnum(const std::string &type) {
    if (type == "CUSTOMER") {
        return CUSTOMER;
    } else if (type == "MANAGER") {
        return MANAGER;
    }
}

std::string User::getTypeString(const Type &type) {
    if (type == CUSTOMER) {
        return "CUSTOMER";
    } else if (type == MANAGER) {
        return "MANAGER";
    }
}
