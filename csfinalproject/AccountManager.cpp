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
}

AccountManager::~AccountManager()
{

}

Account* AccountManager::authenticate()
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

		if (accountMap.count(username) == 1)
		{
			cout << "Password: ";
			cin >> password;

			if (accountMap[username]->getPassword() == password)
			{
				cout << "Logging in... \n" << endl;
				cout << "Welcome " << username << "!!" << endl;
				return accountMap[username];
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
	return NULL;

	}


void AccountManager::userLogin()
{
	User* user = NULL;
	Account* account = authenticate();
	bool loginSuccess;

	if (account != NULL)
	{
		loginSuccess = true;
		user = (User*)account;
	}
	else
	{
		loginSuccess = false;
	}

	int option = 0;
	while (loginSuccess)
	{
		cout << "1: Print Balance\n2: Print History\n3: Withdraw\n4: Deposit\n5: Log out\nSelect an Option: ";
		cin >> option;
		cout << endl;
		switch (option)
		{
		case 1:
			
			//print balance
			break;
		case 2:
			//print history
			break;
		case 3:
			//withdraw
			break;
		case 4:
			//deposit
			break;
		case 5:
			cout << "Goodbye. \n" << endl;
			loginSuccess = false;
			break;
		default:
			cout << "Invalid input" << endl;
		}
	}
}

void AccountManager::managerLogin()
{
	Manager* manager = NULL;
	Account* account = authenticate();
	bool loginSuccess;


	if (account != NULL)
	{
		loginSuccess = true;
		 manager = (Manager*)account;
	}
	else
	{
		loginSuccess = false;
	}


	int option = 0;
	while (loginSuccess)
	{
		cout << "1: Print Balance\n2: Log out\nSelect an Option: ";
		cin >> option;
		cout << endl;
		switch (option)
		{
		case 1:
			manager->getHistory();
			break;
		case 2:
			cout << "Goodbye. \n" << endl;
			loginSuccess = false;
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
	//
	//ifstream inputFile(userPath);
	//if (inputFile.is_open())
	//{
	//	string line;
	//	int linePosition = 0;
	//	bool isReadingTransactionHistory = false;
	//	string currentUsername;
	//	string currentPassword;
	//	int currentAccountNumber;
	//	double currentAccountBalance;
	//	bool isError;
	//	User* currentUser;
	//	
	//	while (getline(inputFile, line))
	//	{
	//		if (line == "#")
	//		{
	//			linePosition = 1;
	//			isReadingTransactionHistory = false;
	//			isError = false;
	//		}
	//		else if (line == "~")
	//		{
	//			linePosition = 1;
	//			isReadingTransactionHistory = true;
	//		}
	//		else if (!isReadingTransactionHistory)
	//		{
	//			switch (linePosition)
	//			{
	//			case 1:
	//				currentUsername = line;
	//				break;

	//			}
	//		}
	//	}
	//}
}