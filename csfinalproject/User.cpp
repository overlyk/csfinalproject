#pragma once
#include <string>
#include "User.h"

using namespace std;

	//inherited from Account
	//string username;
	//string password;
	
	bool User::login(Account account)
	{
		cout << "User logging in" << endl;;
		return true;
	}
