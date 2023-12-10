#pragma once
#include <string>
#include <iostream>
#include "Account.h"
#include "User.h"

using namespace std;

string username;
string password;

class Manager : public Account
{
private:

public:

	Manager(string username, string password);
	
	

};