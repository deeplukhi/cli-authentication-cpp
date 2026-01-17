#include <iostream>
#include <fstream>
#include "Login.h"
#include "AuthService.h"
#include "../utils/PasswordHasher.h"
#include "../utils/Constants.h"
#include "../utils/Colors.h"

using namespace std;

void Userlogin::login() {
    AuthService auth;
    Cyan();
    cout << "----------LOGIN------------" << endl;
    ResetTextColor();

    while(true){
        
        Yellow();
        cout << "Enter your user-name : ";
        ResetTextColor();
        getline(cin, username);
        
        Yellow();
        cout << "Enter your Password : ";
        ResetTextColor();
        getline(cin, password);

        bool success = auth.loginUser(username, password);

        if (success) {
            Green();
            cout << "✅ Login successful" << endl;
            ResetTextColor();
            break;
        } else {
            Red();
            cout << "❌ Invalid username or password. Try again.\n" << endl;
            ResetTextColor();
        }    
    }
}
