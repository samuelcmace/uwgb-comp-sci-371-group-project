//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
#include "User.h"
#include "Transaction.h"

std::vector<Transaction> transactionHistory;


class BankAccount {
private:
    User* user; // Pointer to the associated User object
    std::vector<Transaction> transactionHistory;// History of transactions

public:
    // Constructor
    BankAccount(User* user);

    void deposit(double amount);
    void withdraw(double amount);

    std::string printAccountSummary() const;
};

#endif // BANKACCOUNT_H


