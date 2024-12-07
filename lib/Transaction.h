//
// Created by Bibesh Pyakurel on 12/1/24.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
private:
    std::string type; // "Deposit" or "Withdrawal"
    double amount;
    std::time_t timestamp; // Time of transaction

public:
    // Constructor
    Transaction(const std::string& type, double amount);

    // Getters
    std::string getType() const;
    double getAmount() const;
    std::string getTimestamp() const; // Format the timestamp as a string
};

#endif // TRANSACTION_H


