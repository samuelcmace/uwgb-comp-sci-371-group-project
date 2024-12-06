//
// Created by Bibesh Pyakurel on 12/1/24.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "BankAccount.h"
#include <memory>  // For using smart pointers

class Customer : public User {
private:
    std::unique_ptr<BankAccount> bankAccount;  // Using uniqeu pointer for memory management

public:
    // Constructor to initialize Customer with username, password, and initial deposit for the bank account
    Customer(const std::string& username, const std::string& password);

    // Get the bank account associated with the customer
    BankAccount* getBankAccount();

    // Method to deposit money into the customer's bank account
    bool deposit(double amount);

    // Method to withdraw money from the customer's bank account
    bool withdraw(double amount);

    // Method to print the customer's account summary
    void printAccountSummary() const;
};

#endif // CUSTOMER_H

