#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "User.h"
#include <time.h> 

using namespace std;

	string username;
	string password;
	

User::User(string username, string password, int accountNumber, double balance)
{
	this->username = username;
	this->password = password;
	this->accountNumber = accountNumber;
	this->balance = balance;
}
string User::getTransactionHistory()
{
	string returnString = "\n";
	for (const Transaction transaction : transactions)
	{
		returnString += "~\n" + transaction.getTransactionName() + "\n";
		returnString += to_string(transaction.getTransactionAmount()) + "\n";
		returnString += transaction.getDateTime() + "\n";
	}
	return returnString;
}
int User::getAccountNumber()
{
	return this->accountNumber;
}
double User::getBalance()
{
	return this->balance;
}
void User::addTransaction(string dateTime, string transactionName, double transactionAmount)
{
	this->transactions.push_back(Transaction(dateTime, transactionName, transactionAmount));
}
string User::toString()
{
	string returnString = "#\n" + this->username + "\n" + this->password + "\n" + to_string(this->accountNumber) + "\n" + to_string(this->balance) + "\n";
	for (const Transaction transaction : transactions)
	{
		returnString += "~\n" + transaction.getTransactionName() + "\n";
		returnString += to_string(transaction.getTransactionAmount()) + "\n";
		returnString += transaction.getDateTime() + "\n";
	}
	return returnString;
}

void User::withdraw()
{
	cout << "Withdraw Cash" << endl;
	bool isValidWithdraw = false;

	int withdrawAmount;
	string withdrawName;

	while (!isValidWithdraw)
	{
		
		cout << "How much do you want to withdraw? Type -1 to Exit";
		cin >> withdrawAmount;
		if (withdrawAmount == -1)
		{
			return;
		}
		else if (withdrawAmount > this->balance)
		{
			cout << "Invalid withdrawal. Not enough cash in account" << endl;
		}
		else if (withdrawAmount < 0)
		{
			cout << "Please enter a positive number " << endl;
		}
		else
		{
			cout << "Enter name/reason for withdrawal: ";
			cin >> withdrawName;

			balance = balance - withdrawAmount;


			time_t my_time = time(NULL);

			addTransaction(ctime(&my_time), withdrawName, withdrawAmount);
			cout << "Your balance is now: " << this->balance;
			isValidWithdraw = true;
		}
	}

}

void User::deposit()
{
	cout << "Deposit Cash" << endl;
	bool isValidDeposit = false;

	int depositAmount;
	string depositName;

	while (!isValidDeposit)
	{

		cout << "How much do you want to deposit? Type -1 to Exit";
		cin >> depositAmount;

		if (depositAmount == -1)
		{
			return;
		}
		else if (depositAmount < 0)
		{
			cout << "Please enter a positive number " << endl;
		}
		else
		{
			cout << "Enter name/reason for deposit: ";
			cin >> depositAmount;

			balance = balance + depositAmount;


			time_t my_time = time(NULL);

			addTransaction(ctime(&my_time), depositName, depositAmount);

			cout << "Your balance is now: " << this->balance;
			isValidDeposit = true;
		}
	}
}