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
	bool virtual login(Account account);


};