#include<iostream>
#include<regex>
#include<string>
#include "PasswordValidator.h"

using namespace std;

bool PasswordValidator::isPasswordValid(const string& password){
    const regex valid(
        "^(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$"
    );
    return regex_match(password, valid);
}


