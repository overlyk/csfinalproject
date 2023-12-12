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
	this->isAdmin = false;
}
//returns our history as a string so we can isolate our transaction data when requesting it as a user
string User::getTransactionHistory()
{
	string returnString = "";
	if (transactions.empty())
	{
		returnString += "No transactions recorded yet!";
	}
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


	returnString += getTransactionHistory(); //since getTransactionHistory is already getting our transactions, just add the string it returns to our toString here
	return returnString;
}

void User::withdraw()
{
	cout << "Withdraw Cash -  Type -1 to Exit" << endl;
	bool isValidWithdraw = false;

	double withdrawAmount;
	string withdrawName;

	while (!isValidWithdraw)
	{
		
		cout << "Withdrawal amount: ";
		cin >> withdrawAmount;

		if (withdrawAmount == -1)
		{
			return;
		}
		else if (withdrawAmount > this->balance)
		{
			cout << "Invalid withdrawal. Not enough cash in account" << endl;
		}
		else if (withdrawAmount <= 0)
		{
			cout << "Please enter a positive number " << endl;
		}
		else
		{

			cout << "Enter name/reason for withdrawal: ";
			//getline instead of cin used so that a reason for withdraw/deposit can have a space
			cin.ignore();	//clears the input buffer of an leftover "\n" character from using cin
			getline(cin, withdrawName); //grabs entire input buffer up until we hit a "\n" character
			balance = balance - withdrawAmount;

			//my_time is used to store pointer to address that stores current system clock time (automatic when initialized as NULL)
			//ctime() translates the DateTime at that memory address into a string
			//suppress compiler warning by defining _CRT_SECURE_NO_WARNINGS by include statements
			time_t my_time = time(NULL); 
			addTransaction(ctime(&my_time), withdrawName, -withdrawAmount);

			cout << "Your balance is now: $" << this->balance << "\n" << endl;
			isValidWithdraw = true;
		}
	}

}
void User::deposit()
{
	cout << "Deposit Cash -  Type -1 to Exit" << endl;
	bool isValidDeposit = false;

	double depositAmount;
	string depositName;

	while (!isValidDeposit)
	{

		cout << "Deposit amount: ";
		cin >> depositAmount;

		if (depositAmount == -1)
		{
			return;
		}
		else if (depositAmount <= 0)
		{
			cout << "Please enter a positive number " << endl;
		}
		else
		{
			cout << "Enter name/reason for deposit: ";

			//getline instead of cin used so that a reason for withdraw/deposit can have a space
			cin.ignore(); //clears the input buffer of any "\n" character left from cin that causes getline() to fail
			getline(cin, depositName); //reads input buffer up until it hits a "\n" character

			this->balance = this->balance + depositAmount;

			//my_time is used to store pointer to address that stores current system clock time (automatic when initialized as NULL)
			//ctime() translates the DateTime at that memory address into a string
			//suppress compiler warning by defining _CRT_SECURE_NO_WARNINGS by include statements
			time_t my_time = time(NULL);
			addTransaction(ctime(&my_time), depositName, depositAmount);

			cout << "Your balance is now: $" << this->balance << "\n" << endl;
			isValidDeposit = true;
		}
	}
}