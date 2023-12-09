#pragma once
#include <string>
#include <iostream>
#include "Account.h"

using namespace std;

Account::Account()
{

}

//bool Account::login(Account account)
//{
//	return true;
//}

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