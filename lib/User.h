//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;
public:
    User(std::string username, std::string password);
    std::string getUsername() const;
    std::string getPassword() const;
    bool authenticate(std::string username, std::string password);
};

#endif //USER_H
