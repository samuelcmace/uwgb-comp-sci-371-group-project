//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string username;
    std::string password;

public:
    // Constructor
    User(std::string username, std::string password);
    virtual ~User() {}

    // Getters
    std::string getUsername() const;
    std::string getPassword() const;
    virtual std::string getAccountType() const = 0;

    // Enum to Represent the User Type (Manager or Customer)
    enum Type {
        CUSTOMER,
        MANAGER
    };
    static User::Type getTypeEnum(const std::string& type);
    static std::string getTypeString(const User::Type& type);

};

#endif // USER_H
