//
// Created by Bibesh Pyakurel on 12/1/24.
//

#include "Customer.h"
#include <iostream>

// Constructor initializes the customer with a username, password, and an associated bank account
Customer::Customer(const std::string& username, const std::string& password, unsigned long accountID, double initialBalance)
    : User(username, password) {
    // Initialize the customer's bank account with an account ID and an initial balance
    bankAccount = std::make_unique<BankAccount>(accountID, initialBalance);
}

// Override the login method for the customer
bool Customer::login(const std::string& enteredPassword) {
    // Check if the entered password matches the stored password
    return enteredPassword == password;
}

// Get the bank account associated with the customer
BankAccount* Customer::getBankAccount() {
    return bankAccount.get();  // Return raw pointer to BankAccount
}

// Deposit money into the customer's bank account
bool Customer::deposit(double amount) {
    return bankAccount->deposit(amount);
}

// Withdraw money from the customer's bank account
bool Customer::withdraw(double amount) {
    return bankAccount->withdraw(amount);
}

// Print the customer's account summary (balance and transactions)
void Customer::printAccountSummary() const {
    bankAccount->printAccountSummary();  // Delegates to the BankAccount's print method
}

