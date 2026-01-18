#include <iostream>
#include "../InputValidators/EmailValidator.h"
#include "../InputValidators/PasswordValidator.h"

using std::cout;
using std::endl;

void testEmailValidator() {
    EmailValidator ev;

    cout << "\nRunning EmailValidator tests...\n";

    cout << (!ev.isEmailValid("test@200") 
            ? "PASS : test@200 (invalid)\n" 
            : "FAIL : test@200 should be invalid\n");

    cout << (ev.isEmailValid("test@gmail.com") 
            ? "PASS : test@gmail.com (valid)\n" 
            : "FAIL : test@gmail.com should be valid\n");

    cout << (!ev.isEmailValid("test200@.com") 
            ? "PASS : test200@.com (invalid)\n" 
            : "FAIL : test200@.com should be invalid\n");

    cout << (!ev.isEmailValid("Deep@") 
            ? "PASS : Deep@ (invalid)\n" 
            : "FAIL : Deep@ should be invalid\n");
}

void testPasswordValidator() {
    PasswordValidator pv;

    cout << "\nRunning PasswordValidator tests...\n";

    cout << (!pv.isPasswordValid("test@2000") 
            ? "PASS : test@2000 (no uppercase)\n" 
            : "FAIL : test@2000 should be invalid\n");

    cout << (pv.isPasswordValid("Test@2000") 
            ? "PASS : Test@2000 (valid)\n" 
            : "FAIL : Test@2000 should be valid\n");

    cout << (!pv.isPasswordValid("test200") 
            ? "PASS : test200 (too short)\n" 
            : "FAIL : test200 should be invalid\n");

    cout << (!pv.isPasswordValid("tes@200") 
            ? "PASS : tes@200 (too short)\n" 
            : "FAIL : tes@200 should be invalid\n");
}

int main() {
    testEmailValidator();
    testPasswordValidator();
    cout << endl;
    return 0;
}
