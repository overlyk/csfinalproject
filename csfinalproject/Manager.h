#pragma once
#include <string>
#include <iostream>
#include "Account.h"
#include "User.h"

using namespace std;


class Manager : public Account
{
private:

public:
	//inherited from Account
	Manager(string username, string password);
	void getHistory();
	
	

};