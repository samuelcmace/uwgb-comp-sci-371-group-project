//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <sstream>

// Constructor: Links a User object to the account
BankAccount::BankAccount(User* user) : user(user) {}

// Deposit money
void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cout << "Deposit amount must be greater than zero.\n";
        return;
    }

    double newBalance = user->getBalance() + amount;
    user->setBalance(newBalance);

    // Log the transaction as an object
    transactionHistory.emplace_back("Deposit", amount);

    std::cout << "Deposit successful! New balance: $" << newBalance << "\n";
}

// Withdraw money
void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Withdrawal amount must be greater than zero.\n";
        return;
    }

    double currentBalance = user->getBalance();
    if (amount > currentBalance) {
        std::cout << "Insufficient funds. Current balance: $" << currentBalance << "\n";
        return;
    }

    // Update the user's balance
    double newBalance = currentBalance - amount;
    user->setBalance(newBalance);

    // Log the transaction
    std::ostringstream transaction;
    transaction << "Withdrawal: $" << std::fixed << std::setprecision(2) << amount;
    transactionHistory.push_back(transaction.str());

    std::cout << "Withdrawal successful! New balance: $" << newBalance << "\n";
}

std::string BankAccount::printAccountSummary() const {
    std::ostringstream summary;
    summary << "Account Summary for: " << user->getUsername() << "\n";
    summary << "Account Number: " << user->getAccountNumber() << "\n";
    summary << "Current Balance: $" << std::fixed << std::setprecision(2) << user->getBalance() << "\n";
    summary << "Transaction History:\n";

    for (const auto& transaction : transactionHistory) {
        summary << "  - " << transaction.getType() << ": $"
                << std::fixed << std::setprecision(2) << transaction.getAmount()
                << " on " << transaction.getTimestamp() << "\n";
    }
    return summary.str();
}



