#pragma once
#include <string>
#include <iostream>
#include "Account.h"

using namespace std;


class Transactions
{
private:
	string name;
	string datetime;
	double amount;

public:
	string getName();
	string getDateTime();
	double getAmount();


};