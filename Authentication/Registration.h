#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>

class UserRegistration{
private:
    std::string username;
    std::string password;
    std::string fullname;
    std::string email;

public:
    void registration();
};

#endif
