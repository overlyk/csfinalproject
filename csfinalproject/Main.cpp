#include <iostream>
#include "User.h"
#include "Manager.h"

using namespace std;

int main()
{

    Account* ptr;
    User user;
    Manager manager;
    int choice;
    string username;
    string password;
    //map of user objects
    
    //for each loop to grab all user/manager objects needed
    //grabs data from users.txt and managers.txt

    cout << "Choose login option 1 (user) or 3 (manager)" << endl;
    cin >> choice;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    //if they chose 1, we know we are looking for a user address
    if (choice == 1 || choice == 3)
    {
        if (login(username, password))
        {
            cout << "Valid Login" << endl;
        }
        else
        {
            cout << "Invalid Login" << endl;
        }
    }
}


bool login(string username, string password)
{
    //if username exists in our table of users
    //authenticate it against he password
    //return true if valid, false if not
}