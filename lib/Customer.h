#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "BankAccount.h"
#include "User.h"

#include <sstream>

class Customer : public User {
private:
    BankAccount *customerAccount;

public:
    Customer(const std::string &username, const std::string &password);

    ~Customer();

    Type getAccountType() const;

    double getBalance() const;

    bool deposit(double amount);

    bool withdrawal(double amount);

    std::string printAccountSummary() const;
};

#endif // CUSTOMER_H
