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
	Account* loginAccount;

public:
	AccountManager(string managerPath, string accountPath);
	~AccountManager();
	bool authenticate();
	void userLogin();
	void managerLogin();
	//void createAccount();
};