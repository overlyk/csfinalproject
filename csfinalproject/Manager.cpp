#pragma once
#include <string>
#include "Manager.h"

using namespace std;


	//inherited from Account
	//string username;
	//string password;

	//bool Manager::login(Account account)
	//{
	//	//check if password given is the same as whats in managers.txt
	//	cout << "Manager logging in" << endl;
	//	return true;
	//}
Manager::Manager(string username, string password) {
	this->username = username;
	this->password = password;

}