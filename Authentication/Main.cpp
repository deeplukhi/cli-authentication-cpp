#include<iostream>
#include "Registration.h"
#include "Login.h"
#include "../utils/Colors.h"

using namespace std;

int main(){

    UserRegistration registration;
    Userlogin login;

    while (true){
        Cyan();
        cout <<"-------AUTHENTICATION_MENU------------" <<endl;
        ResetTextColor();

        Yellow();
        cout <<" 1. Registration " << endl;
        cout <<" 2. Login " << endl;
        cout <<" 3. Exit " << endl;
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