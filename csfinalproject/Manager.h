#pragma once
#include <string>
#include <iostream>
#include "Account.h"

using namespace std;


class Manager : public Account
{
private:
	//inherited from Account
	//string username;
	//string password;

public:
	//inherited from Account
	bool login(Account account);
	

};