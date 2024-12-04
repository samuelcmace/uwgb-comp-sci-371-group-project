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
    int input = 0;
    while (input != 4)
    {
        input = 0;
        std::cout << "Make a selection\n1. User Login\n2. Create Account\n3. Manager Login\n4. Exit\n";
        std::cin >> input;
        if (input == 1)
        {
            std::string username, password;
            bool login = false;
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
                    //TODO
                    //verify availability of funds, deduct specified amount if funds are available
                }
                else if (userOptions == 2)
                {
                    //Deposit
                    //TODO
                    //add money to account
                }
                else if (userOptions == 3)
                {
                    //Print Account Summary
                    //TODO
                    //transaction history and current account balance
                }
                else
                {
                    std::cout << "Invalid Input\n";
                    continue;
                }
            }
            //delete user
        }
        else if (input == 2)
        {
            //Create Account
            //TODO
        }
        else if (input == 3)
        {
            //Manager Login
            //TODO
            //Authenticate Manager login, give access to creating/deleting/managing accounts.
        }
        else
        {
            std::cout << "Invalid Input";
            continue;
        }
    }
    std::cout << "\nExiting Program...";

    CSVObject csv;

    return 0;

}
