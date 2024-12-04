//
// Created by Bibesh Pyakurel on 12/1/24.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>  // For date handling

class Transaction {
private:
    std::string type;         // Type of transaction (Deposit, Withdrawal, etc.)
    double amount;            // Amount of money involved in the transaction
    std::string date;         // Date of the transaction

public:
    // Constructor to initialize a transaction with type, amount, and current date
    Transaction(const std::string& type, double amount);

    // Getter for the transaction type (Deposit, Withdrawal)
    std::string getType() const;

    // Getter for the transaction amount
    double getAmount() const;

    // Getter for the transaction date
    std::string getDate() const;

    // Helper function to get the current date as a string (in the format YYYY-MM-DD)
    static std::string getCurrentDate();
};

#endif // TRANSACTION_H

