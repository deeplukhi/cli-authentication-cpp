#ifndef PASSWORDHASHER_H
#define PASSWORDHASHER_H

#include <string>

class PasswordHasher {
public:
    static std::string hashPassword(const std::string& password);
};

#endif
