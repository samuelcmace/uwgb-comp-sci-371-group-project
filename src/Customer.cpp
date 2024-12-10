#include "Customer.h"

Customer::Customer(const std::string &username, const std::string &password) : User(username, password) {
    this->customerAccount = new BankAccount(this->username);
}

Customer::~Customer() {
    delete this->customerAccount;
}

User::Type Customer::getAccountType() const {
    return CUSTOMER;
}

double Customer::getBalance() const {
    return this->customerAccount->getBalance();
}

bool Customer::deposit(double amount) {
    return this->customerAccount->deposit(amount);
}

bool Customer::withdrawal(double amount) {
    return this->customerAccount->withdraw(amount);
}

std::string Customer::printAccountSummary() const {
    std::ostringstream summary;
    summary << "Account Summary for: " << this->getUsername() << "\n";
    summary << "Current Balance: $" << std::fixed << std::setprecision(2) << this->customerAccount->getBalance() <<
            "\n";
    summary << "Transaction History:\n";
    summary << this->customerAccount->printTransactionHistory();
    return summary.str();
}
