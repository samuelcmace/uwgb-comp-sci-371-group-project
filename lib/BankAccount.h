//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>

#include "User.h"
#include "Transaction.h"
#include "CSVObject.h"

class BankAccount : public CSVObject {
private:
    std::vector<Transaction *> transactionHistory; // History of transactions
    void loadTransactionsFromCSV();

public:
    BankAccount(const std::string &accountName);

    ~BankAccount();

    bool deposit(double amount);

    bool withdraw(double amount);

    double getBalance() const;

    std::string printTransactionHistory() const;
};

#endif // BANKACCOUNT_H
