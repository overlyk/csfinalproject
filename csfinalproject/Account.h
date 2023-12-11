#pragma once
#include <string>


using namespace std;


class Account 
{
protected:
	string username;
	string password;
	bool isAdmin;

public:
	Account();
	virtual string getUsername();
	virtual string getPassword();
	virtual string toString();
	virtual bool getIsAdmin();


};