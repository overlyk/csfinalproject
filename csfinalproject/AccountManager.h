#pragma once

#include <map>
#include "Account.h"

using namespace std;

class AccountManager
{
private:
	int highestAccountNum;
	//int getNextAccountNum();
	map<string, Account*> accountMap;
	void setupManagers(string filePath);
	void setupUsers(string filePath);

public:
	AccountManager(string managerPath, string accountPath);
	~AccountManager();
	Account* authenticate();
	void userLogin();
	void managerLogin();
	//void createAccount();
};