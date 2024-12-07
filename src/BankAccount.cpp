//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(unsigned long username, double initialBalance)
    : username(username), balance(initialBalance) {}

// Deposit method
bool BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        return true;
    }
    return false;
}

// Withdraw method
bool BankAccount::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        return true;
    }
    std::cout << "Insufficient funds!" << std::endl;
    return false;
}

// Print account summary
void BankAccount::printAccountSummary() const {
    std::cout << "Account ID: " << username << "\nBalance: $" << balance << std::endl;
    for (const auto& txn : transactions) {
        std::cout << txn.getDate() << " | " << txn.getType() << ": $" << txn.getAmount() << std::endl;
    }
}

// Getter for account ID
unsigned long BankAccount::getAccountID() const {
    return username;
}

// Getter for balance
double BankAccount::getBalance() const {
    return balance;
}

// Getter for transactions
const std::vector<Transaction>& BankAccount::getTransactions() const {
    return transactions;
}

// Fetch account by username
BankAccount* BankAccount::getAccountByUsername(
    unsigned long username, 
    const std::vector<BankAccount>& accounts) {
    for (auto& account : accounts) {
        if (account.getAccountID() == username) {
            return &account;
        }
    }
    return nullptr;  // this will return nullptr if not found
}


