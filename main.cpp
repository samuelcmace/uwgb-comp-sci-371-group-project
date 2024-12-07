#include <iostream>
#include <string>

#include "BankAccount.h"
#include "User.h"
#include "CSVObject.h"
#include "Customer.h"
#include "Employee.h"
#include "Transaction.h"
#include "UserManager.h"

using namespace std;

int main(int argc, char* argv[])
{
    UserManager userManager = UserManager::getInstance();
    //Main loop of the program
    //Initial input:
    double amount;
    bool login;
    int input;
    int managerInput;
    User user1;
    while (input != 4)
    {
        input = 0;
        std::cout << "Make a selection\n1. User Login\n2. Create Account\n3. Manager Login\n4. Exit\n";
        std::cin >> input;
        if (input == 1)
        {
            std::string username, password;
            login = false;
            while (login == false)
            {
                //User Login Selected
                std::cout << "Enter Username: ";
                std::cin >> username;
                std::cout << "Enter Password: ";
                std::cin >> password;
                login = userManager.authenticateUser(username, password);
                if (!login)
                {
                    std::cout << "Login failed." << std::endl;
                }
            }
            User user1 = userManager.getUserByUsername(username);
            //check if manager/customer
            if (type(user1) == EMPLOYEE)
            {

            }
            user1 = userManager.getUserByUsername(username);
            //TODO: check if user is a manager/customer
            //if (user1 is manager/employee) {
            // cout << "You are a manager. Login to the manager login.";
            // continue;
            //}
            
            //User Options:
            int userOptions = 0;
            while (userOptions != 4)
            {
                userOptions = 0;
                std::cout << "Make a selection:/n1. Withdrawal\n2. Deposit/n3. Account Summary\n4. Log Out\n";
                std::cin >> userOptions;
                if (userOptions == 1)
                {
                    //Withdrawal Selected
                    amount = 0.0;
                    cout << "Amount for withdrawal: ";
                    cin >> amount;
                    if (user1.withdraw(amount))
                    {
                        cout << "Withdrawal Successful." << endl;
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (userOptions == 2)
                {
                    //Deposit
                    amount = 0.0;
                    cout << "Amount for deposit: ";
                    cin >> amount;
                    if (user1.deposit(amount))
                    {
                        cout << "Deposit Successful." << endl;
                    }
                }
                else if (userOptions == 3)
                {
                    //Print Account Summary
                    user1.printAccountSummary();
                }
                else
                {
                    std::cout << "Invalid Input\n";
                    continue;
                }
            }
        }
        else if (input == 2)
        {
            //Create Account
            string usernam, passwor;
            cout << "Creating new account.\nEnter Username: ";
            cin >> usernam;
            cout << "Enter Password: ";
            cin >> passwor;
            userManager.createUser(usernam, passwor, CUSTOMER);
            cout << "Account successfully created." << endl;
        }
        else if (input == 3)
        {
            //Manager Login
            //TODO
            //Authenticate Manager login, give access to creating/deleting/managing accounts.
            string userN, passW;
            cout << "Manager Login\nEnter Username: ";
            cin >> userN;
            cout << "Enter Password: ";
            cin >> passW;
            if (userManager.authenticateUser(userN, passW))
            {
                user1 = userManager.getUserByUsername(userN);
            }
            else
            {
                continue;
            }
            managerInput = 0;
            while (managerInput != 4)
            {
                managerInput = 0;
                cout << "Manager Options:\n1. Create Account\n2. Delete Account\n3. Edit Balance\n4. Logout\n";
                cin >> managerInput;
                if (managerInput == 1)
                {
                    //Create Account
                    string userna, passwo;
                    cout << "Creating new account.\nEnter Username: ";
                    cin >> userna;
                    cout << "Enter Password: ";
                    cin >> passwo;
                    userManager.createUser(userna, passwo, CUSTOMER);
                    cout << "Account successfully created." << endl;
                }
                else if (managerInput == 2)
                {
                    //Delete Account
                    string enteredUsername;
                    cout << "Enter username of account to be deleted:";
                    cin >> enteredUsername;
                    //TODO: delete method of UserManager
                }
                else if (managerInput == 3)
                {
                    //Edit Balance
                    //TODO: function in class Customer to edit balance.
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            std::cout << "Invalid Input";
            continue;
        }
    }
    std::cout << "\nExiting Program...";

    return 0;

}
