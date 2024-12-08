//
// Created by Bibesh Pyakurel on 11/26/24.
//

#ifndef USER_H
#define USER_H

#include <string>
#include <Transaction.h>

class User {
public:
    // Enum to Represent the User Type (Manager or Customer)
    enum Type {
        CUSTOMER,
        MANAGER
    };

protected:
    std::string username;
    std::string password;

public:
    // Constructor
    User(const std::string &username, const std::string &password);

    virtual ~User();

    // Getters
    std::string getUsername() const;

    std::string getPassword() const;

    virtual Type getAccountType() const = 0;

    bool authenticate(const std::string &username, const std::string &password) const;

    static Type getTypeEnum(const std::string &type);

    static std::string getTypeString(const Type &type);
};

#endif // USER_H
