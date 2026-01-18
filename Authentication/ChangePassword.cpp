#include<iostream>
#include<fstream>
#include <string>
#include "ChangePassword.h"
#include "AuthService.h"
#include "../inputValidators/PasswordValidator.h"
#include "../utils/Constants.h"
#include "../utils/PasswordHasher.h"
#include "../utils/Colors.h"

using namespace std;

void ChangePassword::changePassword(){
    AuthService auth;
    PasswordValidator passwordValidator;
    
    Cyan();
    cout << "------------ ChangePassword ----------\n";
    ResetTextColor();

    Yellow();
    cout<<"Enter your user-name : ";
    ResetTextColor();
    getline(cin, username);

    while (true) {
        Yellow();
        cout << "Enter your oldPassword : ";
        ResetTextColor();
        getline(cin, oldPassword);

        if (passwordValidator.isPasswordValid(oldPassword)) {
            break;
        } else {
            Red();
            cout << "❌ Invalid password format. Try again.\n";
            cout << "   (Min 8 chars, 1 uppercase, 1 digit, 1 special char)\n";
            ResetTextColor();
        }
    }

    while (true) {
        Yellow();
        cout << "Enter your Password : ";
        ResetTextColor();
        getline(cin, newPassword);

        if (passwordValidator.isPasswordValid(newPassword)) {
            break;
        } else {
            Red();
            cout << "❌ Invalid password format. Try again.\n";
            cout << "   (Min 8 chars, 1 uppercase, 1 digit, 1 special char)\n";
            ResetTextColor();
        }
    }

    bool success = auth.changePassword(username, oldPassword, newPassword);

    if(success){
        Green();
        cout << " Password has been changed !" << endl;
        ResetTextColor();
    }else{
        Red();
        cout << "Try again!" << endl;
        ResetTextColor();
    }
}