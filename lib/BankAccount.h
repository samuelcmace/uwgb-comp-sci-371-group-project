//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <vector>
#include "Transaction.h"  //from out Transaction class

class BankAccount {
private:
    std::string username;     // User's username
    double balance;           //account balance
    std::vector<Transaction> transactions;  //list of transactions

public:
    //constructor to initialize BankAccount with accountID and initial balance
    BankAccount(unsigned long username, double initialBalance);

    //
    //User* getUserByUsername(const std::string& username);

    // Method to deposit money into the account
    bool deposit(double amount);

    // Method to withdraw money from the account
    bool withdraw(double amount);

    // Method to print the account summary (balance and transactions)
    void printAccountSummary() const;

    // Getter for account ID
    unsigned long getAccountID() const;

    // Getter for current balance
    double getBalance() const;

    // Getter for the list of transactions
    const std::vector<Transaction>& getTransactions() const;
};

#endif // BANKACCOUNT_H

