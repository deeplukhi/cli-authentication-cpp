#include "AuthService.h"
#include <fstream>
#include <iostream>
#include <string>
#include "../inputValidators/EmailValidator.h"
#include "../inputValidators/PasswordValidator.h"
#include "../utils/PasswordHasher.h"
#include "../utils/Constants.h"

using namespace std;

AuthResult AuthService::registerUser(
    const std::string& username,
    const std::string& fullname,
    const std::string& email,
    const std::string& password
) {

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


bool AuthService::changePassword(
    std::string& username,
    std::string& oldPassword,
    std::string& newPassword
) {
    string filepath = DATA_PATH + username + ".txt";
    ifstream fin(filepath);

    if (!fin.is_open()) {
        cout << "❌ User not found\n";
        return false;
    }

    string fullname, email, storedUsername, storedPassword;
    getline(fin, fullname);
    getline(fin, email);
    getline(fin, storedUsername);
    getline(fin, storedPassword);
    fin.close();

    // Verify old password
    string oldHash = PasswordHasher::hashPassword(oldPassword);
    if (oldHash != storedPassword) {
        cout << "❌ Old password incorrect\n";
        return false;
    }

    // Rewrite file with new password
    ofstream fout(filepath);
    if (!fout.is_open()) {
        cout << "❌ Failed to update password\n";
        return false;
    }

    fout << fullname << endl;
    fout << email << endl;
    fout << storedUsername << endl;
    fout << PasswordHasher::hashPassword(newPassword) << endl;
    fout.close();

    cout << "✅ Password changed successfully\n";
    return true;
}