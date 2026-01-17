#include "PasswordHasher.h"
#include <functional>
using namespace std;

string PasswordHasher::hashPassword(const string& password) {
    return to_string(std::hash<string>{}(password));
}

