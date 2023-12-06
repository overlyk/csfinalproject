#pragma once
#include <string>


using namespace std;


class Account 
{
private:
	string username;
	string password;

public:
	Account();
	~Account();
	string virtual getUsername();
	string virtual getPassword();
	//bool virtual login(Account account);


};