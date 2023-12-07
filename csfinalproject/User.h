#pragma once
#include <string>
#include<list>
#include <iostream>
#include "Account.h"
#include "Transaction.h"

using namespace std;


class User : public Account
{
private:
	//these two inherited from Account
	//string username;
	//string password;
	int accountNumber;
	double balance;
	list<Transaction> transactions;

public:
	//inherited from Account
	/*bool login(Account account);*/
	User(string username, string password, int accountNumber, double balance);
	~User();
	list<Transaction> getTransactionHistory();
	int getAccountNumber();
	double getBalance();
	void addTransaction(string dateTime, string transactionName, double transactionAmount);
	string toString();


};
