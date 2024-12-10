//
// Created by Bibesh Pyakurel on 12/1/24.
//

#include "Transaction.h"
#include <iomanip>
#include <sstream>

#include <string>

// Constructor overloads for Transaction, one of which takes in a timestamp as a string
// and converts it to a time_t object automatically, while the other one just assigns the value
// to the instance variable directly.
Transaction::Transaction(const Type &type, double amount, std::string timestamp)
    : type(type), amount(amount) {
    this->timestamp = convertStringToTimestamp(timestamp);
}

Transaction::Transaction(const Type &type, double amount, std::time_t timestamp)
    : type(type), amount(amount), timestamp(timestamp) {
}

Transaction::Transaction(const Type &type, double amount) : type(type), amount(amount), timestamp(std::time(nullptr)) {
}

// Getters
Transaction::Type Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTimestamp() const {
    return convertTimestampToString(this->timestamp);
}

std::time_t Transaction::getTimestampRaw() const {
    return timestamp;
}

std::string Transaction::convertTimestampToString(const std::time_t &timestamp) {
    std::tm *localTime = std::localtime(&timestamp);
    std::ostringstream formattedTime;
    formattedTime << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return formattedTime.str();
}

std::time_t Transaction::convertStringToTimestamp(const std::string &timestamp) {
    struct std::tm time = {};
    std::istringstream ss(timestamp);
    ss >> std::get_time(&time, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        throw std::invalid_argument("Invalid timestamp format! Please try again!");
    }
    return std::mktime(&time);
}

Transaction::Type Transaction::getTypeEnum(const std::string &type) {
    if (type == "DEPOSIT") {
        return DEPOSIT;
    }
    if (type == "WITHDRAWAL") {
        return WITHDRAWAL;
    }
    throw std::invalid_argument("Unknown transaction type!");
}

std::string Transaction::getTypeString(const Type &type) {
    if (type == DEPOSIT) {
        return "DEPOSIT";
    }
    if (type == WITHDRAWAL) {
        return "WITHDRAWAL";
    }
    throw std::invalid_argument("Unknown transaction type!");
}
