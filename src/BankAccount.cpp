//
// Created by Bibesh Pyakurel on 11/26/24.
//

#include "BankAccount.h"

#include <iostream>
#include <iomanip>
#include <sstream>

// Constructor: Links a User object to the account
BankAccount::BankAccount(const std::string &accountName) : CSVObject(accountName + ".csv", {"TYPE", "AMOUNT", "TIMESTAMP"}) {
    this->loadTransactionsFromCSV();
}

BankAccount::~BankAccount() {
    for (Transaction *transaction: transactionHistory) {
        delete transaction;
    }
}

void BankAccount::loadTransactionsFromCSV() {
    for (int i = 1; i < this->getRowCount(); i++) {
        std::vector<std::string> rowContents = this->readRow(i);

        Transaction::Type type = Transaction::getTypeEnum(rowContents[0]);
        double amount = std::stod(rowContents[1]);
        std::string timestamp = rowContents[2];

        Transaction *newTransaction = new Transaction(type, amount, timestamp);
        transactionHistory.emplace_back(newTransaction);
    }
}

// Deposit money
bool BankAccount::deposit(double amount) {
    if (amount <= 0) {
        std::cerr << "Deposit amount must be greater than zero.\n";
        return false;
    }

    Transaction *newTransaction = new Transaction(Transaction::Type::DEPOSIT, amount);
    transactionHistory.emplace_back(newTransaction);

    // Schema: "TYPE", "AMOUNT", "TIMESTAMP"
    this->createRow({
        Transaction::convertTimestampToString(Transaction::DEPOSIT),
        std::to_string(amount),
        newTransaction->getTimestamp()
    });
    std::cout << "Deposit successful! New balance: $" << this->getBalance() << std::endl;
    return true;
}

// Withdraw money
bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cerr << "Withdrawal amount must be greater than zero.\n";
        return false;
    }
    double currentBalance = this->getBalance();
    if (amount > currentBalance) {
        std::cerr << "Insufficient funds. Current balance: $" << currentBalance << "\n";
        return false;
    }

    // Log the transaction
    Transaction *newTransaction = new Transaction(Transaction::Type::WITHDRAWAL, amount);
    transactionHistory.emplace_back(newTransaction);

    // Schema: "TYPE", "AMOUNT", "TIMESTAMP"
    this->createRow({
        Transaction::convertTimestampToString(Transaction::WITHDRAWAL),
        std::to_string(amount),
        newTransaction->getTimestamp()
    });

    std::cout << "Withdrawal successful! New balance: $" << this->getBalance() << "\n";
    return true;
}

double BankAccount::getBalance() const {
    double balance = 0.0f;
    for (Transaction *transaction: transactionHistory) {
        if (transaction->getType() == Transaction::Type::DEPOSIT) {
            balance += transaction->getAmount();
        } else if (transaction->getType() == Transaction::Type::WITHDRAWAL) {
            balance -= transaction->getAmount();
        }
    }
    return balance;
}

std::string BankAccount::printTransactionHistory() const {
    std::ostringstream summary;
    for (Transaction *transaction: this->transactionHistory) {
        summary << "  - " << transaction->getType() << ": $"
                << std::fixed << std::setprecision(2) << transaction->getAmount()
                << " on " << transaction->getTimestamp() << "\n";
    }
    return summary.str();
}
