//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "BankAccount.h"
#include <iostream>

// Constructor to initialize a BankAccount with an accountID and an initial balance
BankAccount::BankAccount(unsigned long accountID, double initialBalance)
    : accountID(accountID), balance(initialBalance) {}

// Deposit method: Adds the specified amount to the balance
bool BankAccount::deposit(double amount) {
    if (amount > 0) {  // Only deposit if the amount is positive
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));  // Log the deposit transaction
        return true;
    }
    return false;  // Return false if deposit amount is invalid
}

// Withdraw method: Deducts the specified amount from the balance
bool BankAccount::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {  // Ensure sufficient funds
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));  // Log the withdrawal transaction
        return true;
    }
    std::cout << "Insufficient funds!" << std::endl;  // Notify if funds are insufficient
    return false;  // Return false if withdrawal failed
}

// Print method: Displays the account balance and all transactions
void BankAccount::printAccountSummary() const {
    std::cout << "Account ID: " << accountID << "\nBalance: $" << balance << std::endl;
    std::cout << "Transactions:" << std::endl;
    for (const auto& txn : transactions) {
        std::cout << txn.getDate() << " - " << txn.getType() << ": $" << txn.getAmount() << std::endl;
    }
}

// Getter for account ID
unsigned long BankAccount::getAccountID() const {
    return accountID;
}

// Getter for balance
double BankAccount::getBalance() const {
    return balance;
}

// Getter for transactions list
const std::vector<Transaction>& BankAccount::getTransactions() const {
    return transactions;
}

