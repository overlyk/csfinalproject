#pragma once
#include <string>
#include <iostream>
#include "Transactions.h"

using namespace std;


double amount;
string username;
string datetime;

string Transactions::getName()
{
	return username;
}
string Transactions::getDateTime()
{
	return datetime;
}
double getAmount()
{
	return amount;
}


