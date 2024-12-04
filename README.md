# UWGB COMP SCI 371 Group Project

In partial fulfilment of the graduation requirements for UWGB's COMP SCI 371 (Advanced Object-Oriented Design) course, this project is a simple banking application written in C++ by a team of students in the course.

## Running the Application

Since this banking application utilizes only the standard template library, only a C++ compiler/build system as well as the CMake tool is needed to compile and run this application. The directions for building the application are listed in the `CMakeLists.txt` file of the repository's root directory.

## UML Diagram

```mermaid
---
title: Bank Account Application
---
classDiagram
    class User {
        <<Abstract>>
        -std::string username
        -std::string password

        +User(username, password)
        +void login()
        +std::string getUsername()
        +std::string getPassword()
    }
    class Transaction {
        -std::string type
        -std::string date
        -double amount
        +Transaction(type, amount)
        +std::string getType()
        +double getAmount()
        +std::string getDate()
        +static std::string getCurrentDate
    }
    class BankAccount {
        -unsigned long accountID
        -double balance
        -std::vector<Transaction*> transactions
        +BankAccount()
        +bool deposit()
        +bool withdraw()
        +void printAccountSummary()
        +usinged long getAccountID()
        +double getBalance()
        +std::vector<Transaction>& getTransactions()
    }
    Transaction "*" -- "1" BankAccount
    class Customer {
        -std::unique_ptr bankAccount
        +Customer(username, password, accountID, initialBalance)
        +bool login()
        +BankAccount* getBankAccount()
        +bool deposit()
        +bool withdraw()
        +void printAccountSummary()

    }
    Customer "1" -- "*" BankAccount
    class BankManager {
        -unsigned long managerID()
        
        +void viewAccount()
        +void deleteAccount()
    }
    class CSVObject {
        +CSVObject(std::string filePath)
    }
    User <|-- Customer
    User <|-- BankManager
    class UserManager {
        -std::vector<User> users
        +UserManager(CSVObject* csvObject)
        +void addUser()
        +bool authenticate User(username,enteredPassword)
        +User* getUserByUsername(username)
        +void loadUsersFromCSV()
    }
    CSVObject <|-- UserManager
```
