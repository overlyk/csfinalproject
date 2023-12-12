#include <iostream>
#include "User.h"
#include "Manager.h"
#include "AccountManager.h"

using namespace std;

int main()
{
    //map of user objects
    //for each loop to grab all user/manager objects needed
    //grabs data from users.txt and managers.txt
    AccountManager accountManager("managerdata.txt", "userdata.txt");
    
    int option = 0;
    while (option != 4)
    {
        cout << "Welcome to the main menu" << endl;
        bool invalidInput = true;
        while (invalidInput)
        {
            cout << "1: Create Account\n2: User Login\n3: Manager Login\n4: Exit\nSelect an option: ";
            cin >> option;
            if (cin.fail())
            {
                cin.clear();
                cin.sync();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Please enter a valid option! " << endl;
            }
            else
            {
                invalidInput = false;
            }
        }
        cout << endl;
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

    }
    cout << "Thank you for using the program.  Goodbye.";
    return 0;
}
