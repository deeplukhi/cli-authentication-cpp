#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <string>

enum class AuthResult {
    SUCCESS,
    USER_EXISTS,
    FILE_ERROR
};

class AuthService {
public:
    AuthResult registerUser(
        const std::string& username,
        const std::string& fullname,
        const std::string& email,
        const std::string& password
    );

    bool loginUser(
        const std::string& username,
        const std::string& password
    );
};

#endif
