#pragma once
#include <map>
#include "Account.h"
using namespace std;
class AccountManager()
{
private:
	int highestAccountNum;
	int getNextAccountNum();
	map<string, Account*> accountMap;
public:
	AccountManager(string managerPath, string accountPath);
	~AccountManager();
	void userLogin();
	void managerLogin();
	void createAccount();
}