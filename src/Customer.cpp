#include "Customer.h"

Customer::Customer() : User() {
    this->customerAccount = new Account();
}

Customer::~Customer() {
    delete this->customerAccount;
}

User::Type Customer::getAccountType() const {
    return User::Type::CUSTOMER;
}

double getBalance() const {
    return this->customerAccount->getBalance();
}

std::string printAccountSummary() const {
    std::ostringstream summary;
    summary << "Account Summary for: " << this->getUsername() << "\n";
    summary << "Current Balance: $" << std::fixed << std::setprecision(2) << this->account->getBalance() << "\n";
    summary << "Transaction History:\n";
    summary << this->account->printTransactionHistory();
    return summary.str();
}
