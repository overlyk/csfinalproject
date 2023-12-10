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
	int accountNumber;
	double balance;
	list<Transaction> transactions;

public:
	User(string username, string password, int accountNumber, double balance);
	~User();
	string getTransactionHistory();
	int getAccountNumber();
	double getBalance();
	void addTransaction(string dateTime, string transactionName, double transactionAmount);
	string toString();
	void withdraw();
	void deposit();


};
