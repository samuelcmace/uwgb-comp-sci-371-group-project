//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <vector>
#include "Transaction.h"
#include "User.h"

class BankAccount {
private:
    unsigned long username;  // User's unique ID
    double balance;          // Account balance
    std::vector<Transaction> transactions;  // List of transactions

public:
    // Constructor
    BankAccount(unsigned long username, double initialBalance);

    // Deposit and withdraw methods
    bool deposit(double amount);
    bool withdraw(double amount);

    // Print account summary
    void printAccountSummary() const;

    // Getters
    unsigned long getAccountID() const;
    double getBalance() const;
    const std::vector<Transaction>& getTransactions() const;

    // Static method to fetch a BankAccount by username
    static BankAccount* getAccountByUsername(
        unsigned long username, 
        const std::vector<BankAccount>& accounts);

    // Additional utility methods could be added here
};

#endif // BANKACCOUNT_H


