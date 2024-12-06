//
// Created by Bibesh Pyakurel on 12/1/24.
//

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>  // For date handling

class Transaction {
private:
     // Type of withdraw which is either Deposit and Withdrawal
    double amount;          
    std::string date;         // Date of the transaction

public:
    // Constructor to initialize
    Transaction(const std::string& type, double amount);

    // Getter for Deposit and Withdrawal
    std::string getType() const;

    // Getter for the amount
    double getAmount() const;

    // Getter for the date
    std::string getDate() const;

    // Helper function to get the current date as a string
    static std::string getCurrentDate();

};

#endif // TRANSACTION_H

