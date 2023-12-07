#include "AccountManager.h"
#include "Manager.h"
#include "User.h"
#include <fstream>
#include <iostream>
using namespace std;

AccountManager::AccountManager(string managerPath, string accountPath) 
{
	setupManagers(managerPath);
	//setupUsers(accountPath);
	cout << accountMap["manager2"]->getPassword() << endl;

}

void AccountManager::setupManagers(string filePath)
{
	ifstream inputFile(filePath);
	if (inputFile.is_open())
	{
		string line;
		int linePosition = 0;
		bool hasError;
		string currentUsername;
		string currentPassword;
		while (getline(inputFile, line))
		{
			if (line == "#")
			{
				linePosition = 1;
				hasError = false;
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
}