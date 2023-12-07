#pragma once
#include <string>


using namespace std;


class Account 
{
protected:
	string username;
	string password;

public:
	Account();
	string virtual getUsername();
	string virtual getPassword();
	//bool virtual login(Account account);


};