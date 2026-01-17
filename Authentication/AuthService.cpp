#include "AuthService.h"
#include <fstream>
#include "../inputValidators/EmailValidator.h"
#include "../inputValidators/PasswordValidator.h"
#include "../utils/PasswordHasher.h"
#include "../utils/Constants.h"

AuthResult AuthService::registerUser(
    const std::string& username,
    const std::string& fullname,
    const std::string& email,
    const std::string& password
) {
    EmailValidator emailValidator;
    PasswordValidator passwordValidator;

    // duplicate check
    std::ifstream checkFile(DATA_PATH + username + ".txt");
    if (checkFile.is_open()) {
        return AuthResult::USER_EXISTS;
    }

    std::ofstream fout(DATA_PATH + username + ".txt");
    if (!fout.is_open()) {
        return AuthResult::FILE_ERROR;
    }

    fout << fullname << '\n';
    fout << email << '\n';
    fout << username << '\n';
    fout << PasswordHasher::hashPassword(password) << '\n';
    fout.close();

    return AuthResult::SUCCESS;
}

bool AuthService::loginUser(
    const std::string& username,
    const std::string& password
) {
    std::ifstream fin(DATA_PATH + username + ".txt");
    if (!fin.is_open()) {
        return false;
    }

    std::string fullname, email, storedUsername, storedPassword;
    getline(fin, fullname);
    getline(fin, email);
    getline(fin, storedUsername);
    getline(fin, storedPassword);
    fin.close();

    return PasswordHasher::hashPassword(password) == storedPassword;
}
