//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;
    std::string accountNumber;
    std::string accountType;
    double balance;

public:
    // Constructor
    User(std::string username, std::string password, std::string accountNumber, std::string accountType, double balance);

    // Getters
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getAccountNumber() const;
    std::string getAccountType() const;
    double getBalance() const;

    // Setters
    void setAccountType(const std::string& newAccountType);
    void setBalance(double newBalance);
};

#endif // USER_H

