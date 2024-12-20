//
// Created by Bibesh Pyakurel on 12/1/24.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
public:
    enum Type {
        DEPOSIT,
        WITHDRAWAL
    };

private:
    Type type; // "Deposit" or "Withdrawal"
    double amount;
    std::time_t timestamp; // Time of transaction

public:
    // Constructor
    Transaction(const Type &type, double amount, std::time_t timestamp);

    Transaction(const Type &type, double amount, std::string timestamp);

    Transaction(const Type &type, double amount);

    // Getters
    Type getType() const;

    double getAmount() const;

    std::string getTimestamp() const;

    std::time_t getTimestampRaw() const;

    // Static methods that don't deal with class variables. They just change the representation
    static std::string convertTimestampToString(const std::time_t &timestamp);

    static std::time_t convertStringToTimestamp(const std::string &timestamp);

    static std::string getTypeString(const Transaction::Type &type);

    static Type getTypeEnum(const std::string &type);
};

#endif // TRANSACTION_H
