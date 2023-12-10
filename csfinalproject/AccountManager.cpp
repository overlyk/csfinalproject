#include "AccountManager.h"
#include "Manager.h"
#include "User.h"
#include <fstream>
#include <iostream>
using namespace std;

AccountManager::AccountManager(string managerPath, string accountPath) 
{
	this->highestAccountNum = -1;
	setupManagers(managerPath);
	setupUsers(accountPath);
	loginAccount = NULL;
	accountMap["testUser"] = new User("testUser", "testPass",10101, 200);
}

AccountManager::~AccountManager()
{

}

//contains main loop for authenticating a login to be used for any class type
//3 attempts to login allowed
//if account is valid, set address to loginAccount pointer to address of account in map
bool AccountManager::authenticate()
{
	string username;
	string password;

	bool loginSuccess = false;
	int count = 3;
	cout << "Welcome to the login screen" << endl;

	while (count > 0)
	{
		cout << count << " login attempts remaining.\n" << endl;

		cout << "Username: ";
		cin >> username;

		if (accountMap.count(username) == 1) //if username is a valid key in the map
		{
			cout << "Password: ";
			cin >> password;

			if (accountMap[username]->getPassword() == password)
			{
				cout << "Welcome " << username << "!!" << endl;
				cout << "Logging in... \n" << endl;
				loginAccount = accountMap[username]; //update pointer to valid user memory address
				return true;
			}
			else
			{
				cout << "Incorrect password." << endl;
				count--;
			}
		}
		else
		{
			cout << "Invalid username. " << endl;
			count--;
		}
	}

	cout << "You have exceeded the maximum amount of attempts to login. \n" << endl;
	return false;
}

//first calls authenticate() to see if login is valid and get memory address of account
//if authenticated as a user, start user choice selection
void AccountManager::userLogin()
{
	User* user = NULL;

	//use authenticate() to check if login is true or false
	//if true, assign our pointer to the accounts memory address
	//if false, explicitly exit out of the login process back to main menu
	if (authenticate()) 
	{
		user = (User*)loginAccount; 
	}
	else
	{
		return;
	}

	//create these variables down here to save memory allocation/speed in case the login was invalid
	string transactionHistory = "";
	int option = 0;
	bool loggedIn = true;

	while (loggedIn)
	{
		cout << "Main User Menu" << endl;
		cout << "1: Print Balance\n2: Print History\n3: Withdraw\n4: Deposit\n5: Log out\nSelect an Option: ";
		cin >> option;
		cout << endl;
		switch (option)
		{
		case 1:
			cout << "Your balance is: $" << user->getBalance() << endl;
			break;
		case 2:
			//remove extra text?
			cout << "Your history is: \n" << user->getTransactionHistory() << endl;
			break;
		case 3:
			user->withdraw();
			break;
		case 4:
			user->deposit();
			break;
		case 5:
			cout << "Goodbye. \n" << endl;
			loggedIn = false;
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}
}

//first calls authenticate() to see if login is valid and get memory address of account
//if authenticated as a manager, start manager choice selection
void AccountManager::managerLogin()
{
	Manager* manager = NULL;

	//use authenticate() to check if login is true or false
	//if true, assign our manager pointer to the accounts memory address
	//if false, explicitly exit out of the login process back to main menu
	if (authenticate())
	{
		manager = (Manager*)loginAccount;
	}
	else
	{
		return;
	}

	//create these variables down here to save memory allocation/speed in case the login was invalid
	User* userChoice = NULL; //will eventually point to memory address of a user we want history of
	string userUsername = "";
	int option = 0;
	bool loggedIn = true;

	while (loggedIn)
	{
		cout << "Main Manager Menu" << endl;
		cout << "1: Print User Data\n2: Log out\nSelect an Option: ";
		cin >> option;
		cout << endl;
		switch (option)
		{
		case 1:
			cout << "User Information Portal" << endl;
			cout << "Username of account you want the information of: ";
			cin >> userUsername;

			if (accountMap.count(userUsername) == 1)
			{
				userChoice = (User*)accountMap[userUsername];
				cout << userChoice->toString() + "\n";
			}
			else
			{
				cout << "User does not exist " << endl;
			}
			break;
		case 2:
			cout << "Goodbye. \n" << endl;
			loggedIn = false;
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}



}

void AccountManager::setupManagers(string filePath)
{
	ifstream inputFile(filePath);
	if (inputFile.is_open())
	{
		string line;
		int linePosition = 0;
		string currentUsername;
		string currentPassword;
		while (getline(inputFile, line))
		{
			if (line == "#")
			{
				linePosition = 1;
			}
			else
			{
				if (linePosition == 1)
				{
					currentUsername = line;
				}
				else if (linePosition == 2)
				{
					currentPassword = line;
					accountMap[currentUsername] = new Manager(currentUsername, currentPassword);
				}
				linePosition++;

			}
		}
	}
	//probably need to close inputFile here
}

void AccountManager::setupUsers(string userPath)
{
	
	ifstream inputFile(userPath);
	if (inputFile.is_open())
	{
		string line;
		int linePosition = 0;
		bool isReadingTransactionHistory = false;
		string currentUsername;
		string currentPassword;
		int currentAccountNumber;
		double currentAccountBalance;
		bool isError;
		User* currentUser;
		
		while (getline(inputFile, line))
		{
			if (line == "#")
			{
				linePosition = 1;
				isReadingTransactionHistory = false;
				isError = false;
			}
			else if (line == "~")
			{
				linePosition = 1;
				isReadingTransactionHistory = true;
			}
			else if (!isReadingTransactionHistory)
			{
				switch (linePosition)
				{
				case 1:
					currentUsername = line;
					break;

				}
			}
		}
	}
}