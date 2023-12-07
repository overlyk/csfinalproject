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
	cout << accountMap["manager2"]->getPassword() << endl;

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