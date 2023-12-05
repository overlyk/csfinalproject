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

    cout << "Choose login option 1 (user) or 3 (manager)" << endl;
    cin >> choice;

    //if they chose 1, we know we are looking for a user address
    if (choice == 1)
    {
        ptr = &user;
        //polymorphically logging in an account object as it's subclass (user)
        if (ptr->login(user))
        {
            //user login was success - loop options to perform on user object here
        }
        else
        {
            //go back to main options again
        }

        
    }

    //if they chose 3, we know we are looking for a manager address
    if (choice == 3)
    {
        ptr = &manager;
        //polymorphically logging in an account object as it's subclass (manager)
        if (ptr->login(manager))
        {
            //manager login was success. 
            //list options manager object can perform on any user object (either in seperate function/class or here)
        }
        else
        {
            //login failed. try again
        }
    }

}