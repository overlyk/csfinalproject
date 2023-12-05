#pragma once
#include <string>
#include <iostream>
#include "Account.h"

using namespace std;


class User : public Account
{
private:
	//these two inherited from Account
	//string username;
	//string password;
	string accountNumber;

public:
	//inherited from Account
	bool login(Account account);


};
