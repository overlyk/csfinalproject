#include <iostream>
#include "User.h"
#include "Manager.h"
#include "AccountManager.h"

using namespace std;

int main()
{

    /*Account* ptr;
    User user;
    Manager manager;
    int choice;
    string username;
    string password;*/
    //map of user objects
    
    //for each loop to grab all user/manager objects needed
    //grabs data from users.txt and managers.txt
    cout << "hello world" << endl;
    AccountManager accountManager("managerdata.txt", "userdata.txt");
    /*
    int option = 0;
    while (option != 4)
    {
        cout << "Select an option:\n1: Create Account\n2: User Login\n3: Manager Login\n4: Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            accountManager.createAccount();
            break;
        case 2:
            accountManager.userLogin();
            break;
        case 3:
            accountManager.managerLogin();
            break;
        case 4:
            break;
        default:
            cout << "Invalid input" << endl;
        }

    }*/
    cout << "Thank you for using the program.  Goodbye.";
    return 0;
}
