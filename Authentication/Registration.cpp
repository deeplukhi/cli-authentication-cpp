#include<iostream>
#include<fstream>
#include "Registration.h"
#include "AuthService.h"
#include "../inputValidators/EmailValidator.h"
#include "../inputValidators/PasswordValidator.h"
#include "../utils/PasswordHasher.h"
#include "../utils/Constants.h"
#include "../utils/Colors.h"

using namespace std;

void UserRegistration::registration(){
    AuthService auth;
    EmailValidator emailValidator;
    PasswordValidator passwordValidator;

    Cyan();
    cout << "---------- REGISTRATION ----------\n";
    ResetTextColor();

    Yellow();
    cout<<"Enter your user-name : ";
    ResetTextColor();
    getline(cin, username);

    Yellow();
    cout<<"Enter your Full-name : ";
    ResetTextColor();
    getline(cin, fullname);

    // 🔁 PASSWORD LOOP
    while (true) {
        Yellow();
        cout << "Enter your Password : ";
        ResetTextColor();
        getline(cin, password);

        if (passwordValidator.isPasswordValid(password)) {
            break;
        } else {
            Red();
            cout << "❌ Invalid password format. Try again.\n";
            cout << "   (Min 8 chars, 1 uppercase, 1 digit, 1 special char)\n";
            ResetTextColor();
        }
    }

    // 🔁 EMAIL LOOP
    while (true) {
        Yellow();
        cout << "Enter your Email id : ";
        ResetTextColor();
        getline(cin, email);

        if (emailValidator.isEmailValid(email)) {
            break;
        } else {
            Red();
            cout << "❌ Invalid email format. Try again.\n";
            ResetTextColor();
        }
    }

    AuthResult success = auth.registerUser(username, fullname, email, password);

    switch (success) {
        case AuthResult::SUCCESS:
            Green();
            cout << "✅ Registration successful\n";
            break;
            ResetTextColor();
        case AuthResult::USER_EXISTS:
            Red();
            cout << "❌ Username already exists\n";
            ResetTextColor();
            break;
        default:
            Red();
            cout << "❌ Registration failed\n";
            ResetTextColor();
    }
}