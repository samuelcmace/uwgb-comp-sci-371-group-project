//
// Created by Bibesh Pyakurel on 12/1/24.
//

#include "Transaction.h"
#include <sstream>
#include <iomanip>

// Constructor to initialize the transaction with a type, amount, and current date
Transaction::Transaction(const std::string& type, double amount)
    : type(type), amount(amount), date(getCurrentDate()) {}

// Getter for the transaction type (Deposit, Withdrawal, etc.)
std::string Transaction::getType() const {
    return type;
}

// Getter for the transaction amount
double Transaction::getAmount() const {
    return amount;
}

// Getter for the transaction date
std::string Transaction::getDate() const {
    return date;
}

// Helper function to get the current date in YYYY-MM-DD format
std::string Transaction::getCurrentDate() {
    // Get the current date and time
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);

    // Format the date as YYYY-MM-DD
    std::ostringstream dateStream;
    dateStream << std::put_time(localTime, "%Y-%m-%d");
    return dateStream.str();
}

