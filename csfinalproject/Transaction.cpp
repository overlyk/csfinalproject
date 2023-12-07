#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(string dateTime, string transactionName, double transactionAmount)
{
	this->dateTime = dateTime;
	this->transactionName = transactionName;
	this->transactionAmount = transactionAmount;
}
string Transaction::getDateTime() const
{
	return this->dateTime;
}
string Transaction::getTransactionName() const
{
	return this->transactionName;
}
double Transaction::getTransactionAmount() const
{
	return this->transactionAmount;
}