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
        -unsigned long userID
        -std::string password

        +User(username, password)
        +void login()
        +unsigned long getUserID()
        +std::string getPassword()
        +void setPassword(unsigned long )
    }
    class Transaction {
        -int transactionID
        -std::string date
        -double amount
    }
    class BankAccount {
        -unsigned long accountID
        -std::vector<Transaction*> transactions
        +BankAccount()
    }
    Transaction "*" -- "1" BankAccount
    class Customer {

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
```
