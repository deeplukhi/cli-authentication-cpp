#include "EmailValidator.h"
#include <regex>
using namespace std;

bool EmailValidator::isEmailValid(const string& email){
    const regex valid(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    return regex_match(email, valid);
}

