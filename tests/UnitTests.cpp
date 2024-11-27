//
// Created by Samuel Mace on 2024/11/26.
//

#include "CSVObject.h"

class Transaction {
    int id;
    double amount;
public:
    Transaction(int id, double amount) {
        this->id = id;
        this->amount = amount;
    }
    int getId() const {
        return id;
    }
    double getAmount() const {
        return amount;
    }
};

class Account {
    std::string name;
    std::string password;
    std::vector<Transaction> transactions;
public:
    Account(std::string name, std::string password) {
        this->name = name;
        this->password = password;
    }
    bool authenticate(std::string username, std::string password) {
        return this->name.compare(username) == 0 && this->password.compare(password) == 0;
    }
};

class AccountManager : public CSVObject {
  std::vector<Account> accounts;
public:
    AccountManager() : CSVObject("accounts.csv", std::vector<std::string>({"username", "password", "account_id"})) {

    }

};

int main(int argc, char **argv) {

    CSVLoadTest test("MOCK_DATA.csv"

    return 0;
}
