#pragma once
#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

Account::Account()
{

}

string Account::getPassword()
{
	return this->password;
}
string Account::getUsername()
{
	return this->username;
}
string Account::toString()
{
	string returnString = "#\n" + this->username + "\n" + this->password + "\n";
	return returnString;
}

bool Account::getIsAdmin()
{
	return this->isAdmin;
}