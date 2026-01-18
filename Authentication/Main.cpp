#include<iostream>
#include "Registration.h"
#include "Login.h"
#include "ChangePassword.h"
#include "../utils/Colors.h"

using namespace std;

int main(){

    UserRegistration registration;
    Userlogin login;
    ChangePassword ChangePassword;


    while (true){
        Cyan();
        cout <<"-------AUTHENTICATION_MENU------------" <<endl;
        ResetTextColor();

        Yellow();
        cout <<" 1. Registration " << endl;
        cout <<" 2. Login " << endl;
        cout <<" 3. Forget password " << endl;
        cout <<" 4. Exit " << endl;
        ResetTextColor();
        
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            registration.registration();
        } else if (choice == 2) {
            login.login();
        } else if (choice == 3) {
            Green();
            ChangePassword.changePassword();
            ResetTextColor();
        } else if(choice == 4){
            Green();
            cout << "Exiting program...\n";
            ResetTextColor();
            break;   // ✅ exits loop
        } else {
            Red();
            cout << "Invalid choice\n";
            ResetTextColor();
        }
    
    }

    return 0;
}            