//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "User.h"

// Constructor
User::User(std::string username, std::string password, std::string accountNumber, std::string accountType, double balance)
    : username(username), password(password), accountNumber(accountNumber), accountType(accountType), balance(balance) {}

// Getters
std::string User::getUsername() const {
    return username;
}
std::string User::getPassword() const {
    return password;
}
std::string User::getAccountNumber() const {
    return accountNumber;
}
std::string User::getAccountType() const {
    return accountType;
}
double User::getBalance() const {
    return balance;
}

// Setters
void User::setAccountType(const std::string& newAccountType) {
    accountType = newAccountType;
}
void User::setBalance(double newBalance) {
    balance = newBalance;
}

