//
// Created by Bibesh Pyakurel on 12/1/24.
//

#include "Transaction.h"
#include <iomanip>
#include <sstream>

// Constructor
Transaction::Transaction(const std::string& type, double amount)
    : type(type), amount(amount), timestamp(std::time(nullptr)) {}

// Getters
std::string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTimestamp() const {
    std::ostringstream formattedTime;
    std::tm* localTime = std::localtime(&timestamp);
    formattedTime << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return formattedTime.str();
}

