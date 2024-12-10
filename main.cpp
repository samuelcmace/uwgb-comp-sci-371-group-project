#include <Customer.h>
#include <iostream>
#include <Manager.h>
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
    Bank &bankInstance = Bank::getInstance();
    //Main loop of the program
    double amount;
    bool isLoggedIn;
    int input;
    int managerInput;
    User *currentUser = nullptr;
    Customer *currentCustomer = nullptr;
    Manager *currentManager = nullptr;
    while (input != 4) {
        input = 0;
        std::cout << "Make a selection:" << std::endl
                << "1. User Login" << std::endl
                << "2. Create Account" << std::endl
                << "3. Manager Login" << std::endl
                << "4. Exit" << std::endl
                << "=> ";
        std::cin >> input;
        if (input == 1) {
            std::string username, password;
            isLoggedIn = false;
            int count = 0;

            while (isLoggedIn == false) {
                //User Login Selected
                std::cout << "Enter Username: ";
                std::cin >> username;
                std::cout << "Enter Password: ";
                std::cin >> password;
                isLoggedIn = bankInstance.login(username, password);
                if (!isLoggedIn) {
                    std::cout << "Login failed." << std::endl;
                    count++;
                }
                if (count >= 3) {
                    break;
                }
            }
            if (isLoggedIn) {
                //Check if user is a manager
                currentUser = bankInstance.getUserByUsername(username);
                if (currentUser->getAccountType() == User::Type::MANAGER) {
                    std::cerr << "You are a manager. Login to the Manager page." << endl;
                    continue;
                }
                //Customer* currentCustomer = (Customer*) bankInstance.getUserByUsername(username);
                currentCustomer = (Customer *) bankInstance.getUserByUsername(username);

                //User Options:
                int userOptions = 0;
                while (userOptions != 4) {
                    userOptions = 0;
                    std::cout << "Make a selection:" << std::endl
                            << "1. Withdrawal" << std::endl
                            << "2. Deposit" << std::endl
                            << "3. Account Summary" << std::endl
                            << "4. Log Out" << std::endl;
                    std::cin >> userOptions;
                    if (userOptions == 1) {
                        //Withdrawal Selected
                        amount = 0.0;
                        cout << "Amount for withdrawal: ";
                        cin >> amount;
                        currentCustomer->withdrawal(amount);
                    } else if (userOptions == 2) {
                        //Deposit
                        amount = 0.0;
                        cout << "Amount for deposit: ";
                        cin >> amount;
                        currentCustomer->deposit(amount);
                    } else if (userOptions == 3) {
                        //Print Account Summary
                        cout << currentCustomer->printAccountSummary();
                    } else {
                        std::cout << "Invalid Input" << std::endl;
                    }
                }
            }
        } else if (input == 2) {
            //Create Account
            string usernam, passwor;
            cout << "Creating new account." << std::endl << "Enter Username: ";
            cin >> usernam;
            cout << "Enter Password: ";
            cin >> passwor;
            bankInstance.createUser(usernam, passwor, User::Type::CUSTOMER);
            //cout << "Account successfully created." << endl;
        } else if (input == 3) {
            //Manager Login
            string userN, passW;
            cout << "Manager Login" << std::endl << "Enter Username: ";
            cin >> userN;
            cout << "Enter Password: ";
            cin >> passW;
            if (bankInstance.login(userN, passW)) {
                //User *manager = bankInstance.getUserByUsername(userN);
                currentManager = (Manager *) bankInstance.getUserByUsername(userN);
                if (currentManager->getAccountType() != User::Type::MANAGER) {
                    std::cerr << "You must be a manager to access this page." << std::endl;
                    continue;
                }
            } else {
                continue;
            }
            managerInput = 0;
            while (managerInput != 4) {
                managerInput = 0;
                cout << "Manager Options:" << std::endl
                        << "1. Create Account" << std::endl
                        << "2. Delete Account" << std::endl
                        << "3. Edit Balance" << std::endl
                        << "4. Logout" << std::endl
                        << "=> ";
                cin >> managerInput;
                if (managerInput == 1) {
                    //Create Account
                    string userna, passwo;
                    cout << "Creating new account." << std::endl << "Enter Username: ";
                    cin >> userna;
                    cout << "Enter Password: ";
                    cin >> passwo;
                    if (bankInstance.createUser(userna, passwo, User::Type::CUSTOMER)) {
                        cout << "Account successfully created." << endl;
                    } else {
                        std::cerr << "Account could not be created." << std::endl;
                    }
                } else if (managerInput == 2) {
                    //Delete Account
                    string enteredUsername;
                    cout << "Enter username of account to be deleted:";
                    cin >> enteredUsername;
                    if (bankInstance.deleteUser(enteredUsername)) {
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
                    bankInstance.updateBalance(usern, amount);
                    //std::cout << "Balance updated successfully." << endl;
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
    std::cout << std::endl << "Exiting Program...";
    return 0;
}
