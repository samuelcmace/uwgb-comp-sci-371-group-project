#include <Customer.h>
#include <iostream>
#include <string>
#include <memory>

#include "BankAccount.h"
#include "User.h"
#include "CSVObject.h"
#include "Transaction.h"
#include "Bank.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Bank is the instance of the singleton class.
    Bank *bankInstance = Bank::getInstance();
    //Main loop of the program
    double amount;
    bool isLoggedIn;
    int input;
    int managerInput;
    User *currentUser;
    while (input != 4) {
        input = 0;
        std::cout << "Make a selection\n1. User Login\n2. Create Account\n3. Manager Login\n4. Exit\n";
        std::cin >> input;
        if (input == 1) {
            std::string username, password;
            isLoggedIn = false;

            while (isLoggedIn == false) {
                //User Login Selected
                std::cout << "Enter Username: ";
                std::cin >> username;
                std::cout << "Enter Password: ";
                std::cin >> password;
                isLoggedIn = bankInstance->login(username, password);
                if (!isLoggedIn) {
                    std::cout << "Login failed." << std::endl;
                }
            }

            //Check if user is a manager
            if (currentUser->getAccountType() == User::Type::MANAGER) {
                std::cerr << "You are a manager. Login to the Manager page." << endl;
                continue;
            }
            Customer *currentUser = (Customer *) bankInstance->getUserByUsername(username);

            //User Options:
            int userOptions = 0;
            while (userOptions != 4) {
                userOptions = 0;
                std::cout << "Make a selection:/n1. Withdrawal\n2. Deposit/n3. Account Summary\n4. Log Out\n";
                std::cin >> userOptions;
                if (userOptions == 1) {
                    //Withdrawal Selected
                    amount = 0.0;
                    cout << "Amount for withdrawal: ";
                    cin >> amount;
                    currentUser->withdrawal(amount);
                } else if (userOptions == 2) {
                    //Deposit
                    amount = 0.0;
                    cout << "Amount for deposit: ";
                    cin >> amount;
                    currentUser->deposit(amount);
                } else if (userOptions == 3) {
                    //Print Account Summary
                    currentUser->printAccountSummary();
                } else {
                    std::cout << "Invalid Input\n";
                }
            }
        } else if (input == 2) {
            //Create Account
            string usernam, passwor;
            cout << "Creating new account.\nEnter Username: ";
            cin >> usernam;
            cout << "Enter Password: ";
            cin >> passwor;
            bankInstance->createUser(usernam, passwor, User::Type::CUSTOMER);
            cout << "Account successfully created." << endl;
        } else if (input == 3) {
            //Manager Login
            //TODO
            //Authenticate Manager login, give access to creating/deleting/managing accounts.
            string userN, passW;
            cout << "Manager Login\nEnter Username: ";
            cin >> userN;
            cout << "Enter Password: ";
            cin >> passW;
            if (bankInstance->login(userN, passW)) {
                User *manager = bankInstance->getUserByUsername(userN);
                if (manager->getAccountType() != User::Type::MANAGER) {
                    std::cerr << "You must be a manager to access this page." << std::endl;
                    continue;
                }
            } else {
                continue;
            }
            managerInput = 0;
            while (managerInput != 4) {
                managerInput = 0;
                cout << "Manager Options:\n1. Create Account\n2. Delete Account\n3. Edit Balance\n4. Logout\n";
                cin >> managerInput;
                if (managerInput == 1) {
                    //Create Account
                    string userna, passwo;
                    cout << "Creating new account.\nEnter Username: ";
                    cin >> userna;
                    cout << "Enter Password: ";
                    cin >> passwo;
                    if (bankInstance->createUser(userna, passwo, User::Type::CUSTOMER)) {
                        cout << "Account successfully created." << endl;
                    } else {
                        std::cerr << "Account could not be created." << std::endl;
                    }
                } else if (managerInput == 2) {
                    //Delete Account
                    string enteredUsername;
                    cout << "Enter username of account to be deleted:";
                    cin >> enteredUsername;
                    //TODO: delete method of bankInstance
                    if (bankInstance->deleteUser(enteredUsername)) {
                        std::cout << "Account successfully deleted." << std::endl;
                    } else {
                        std::cerr << "Account could not be deleted." << std::endl;
                    }
                } else if (managerInput == 3) {
                    //Edit Balance
                    amount = 0.0;
                    std::string usern;
                    std::cout << "Enter username of account to be modified: ";
                    std::cin >> usern;
                    std::cout << "Enter amount of new balance: ";
                    std::cin >> amount;
                    bankInstance->updateBalance(usern, amount);
                    std::cout << "Balance updated successfully." << endl;
                } else if (managerInput == 4) {
                    break;
                } else {
                    std::cout << "Invalid Input";
                }
            }
        } else {
            std::cout << "Invalid Input";
        }
    }
    std::cout << "\nExiting Program...";
    delete currentUser;

    return 0;
}
