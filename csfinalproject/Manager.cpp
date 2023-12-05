#pragma once
#include <string>
#include "Manager.h"

using namespace std;


	//inherited from Account
	//string username;
	//string password;

	bool Manager::login(Account account)
	{
		cout << "Manager logging in" << endl;
		return true;
	}

