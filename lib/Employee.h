#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "User.h"

class Employee : public User {
private:
public:
    Employee(const std::string& username, const std::string& password);
};

#endif // EMPLOYEE_H
