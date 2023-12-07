#pragma once
#include <iostream>
using namespace std;

class Transaction
{
private:
	string dateTime;
	string transactionName;
	double transactionAmount;
public:
	Transaction(string dateTime, string transactionName, double transactionAmount);
	string getDateTime() const;
	string getTransactionName() const;
	double getTransactionAmount() const;
};