//
// Created by Bibesh Pyakurel on 12/1/24.
//

#include "Transaction.h"
#include <iomanip>
#include <sstream>

// Constructor overloads for Transaction, one of which takes in a timestamp as a string
// and converts it to a time_t object automatically, while the other one just assignes the value
// to the instance variable directly.
Transaction::Transaction(const Transaction::Type& type, double amount, std::string timestamp)
    : type(type), amount(amount) {
    this->timestamp = Transaction::convertStringToTimestamp(timestamp);
}

Transaction::Transaction(const Transaction::Type& type, double amount, std::time_t timestamp)
    : type(type), amount(amount), timestamp(timestamp) {

}

Transaction::Transaction(const Transaction::Type& type, double amount) : type(type), amount(amount), timestamp(std::time(nullptr)) {

}

// Getters
Transaction::Type Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTimestamp() const {
    return Transaction::convertTimestampToString(this->timestamp);
}

std::time_t Transaction::getTimestampRaw() const {
    return timestamp;
}

std::string Transaction::convertTimestampToString(const std::time_t& timestamp) {
    std::ostringstream formattedTime;
    std::tm* localTime = std::localtime(&timestamp);
    formattedTime << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return formattedTime.str();
}

std::time_t Transaction::convertStringToTimestamp(const std::string& timestamp) {
    std::istringstream formattedTime(timestamp);
    std::tm* time = {};
    formattedTime >> std::get_time(&time, "%Y-%m-%d %H:%M:%S");
    if(formattedTime.fail()) {
        throw std::invalid_argument("Invalid timestamp format! Please try again!");
    }
    return std::mktime(time);
}

Transaction::Type Transaction::getTypeEnum(const std::string& type) {
    if(type == "DEPOSIT") {
        return Transaction::Type::DEPOSIT;
    } else if(type == "WITHDRAWAL") {
        return Transaction::Type::WITHDRAWAL;
    }
}

std::string Transaction::getTypeString(const Transaction::Type& type) {
    if(type == Transaction::Type::DEPOSIT) {
        return "DEPOSIT";
    } else if(type == Transaction::Type::WITHDRAWAL) {
        return "WITHDRAWAL";
    }
}
