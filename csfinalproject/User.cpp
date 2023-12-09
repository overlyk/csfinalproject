//#pragma once
//#include <string>
//#include "User.h"
//
//using namespace std;
//
//	string username;
//	string password;
//	
//
//User::User(string username, string password, int accountNumber, double balance)
//{
//	this->username = username;
//	this->password = password;
//	this->accountNumber = accountNumber;
//	this->balance = balance;
//}
//list<Transaction> User::getTransactionHistory()
//{
//	return this->transactions;
//}
//int User::getAccountNumber()
//{
//	return this->accountNumber;
//}
//double User::getBalance()
//{
//	return this->balance;
//}
//void User::addTransaction(string dateTime, string transactionName, double transactionAmount)
//{
//	this->transactions.push_back(Transaction(dateTime, transactionName, transactionAmount));
//}
//string User::toString()
//{
//	string returnString = "#\n" + this->username + "\n" + this->password + "\n" + to_string(this->accountNumber) + "\n" + to_string(this->balance) + "\n";
//	for (const Transaction transaction : transactions)
//	{
//		returnString += "~\n" + transaction.getTransactionName() + "\n";
//		returnString += to_string(transaction.getTransactionAmount()) + "\n";
//		returnString += transaction.getDateTime() + "\n";
//	}
//	return returnString;
//}