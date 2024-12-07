#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer : public User {
private:
    BankAccount* customerAccount;
public:
    Customer();
    User::Type getAccountType() const;
    double getBalance() const;
    std::string printAccountSummary() const;
};

#endif // CUSTOMER_H
