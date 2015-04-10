//------------------------------------------------------------------------------
// Project Name: Bank Accounts
// Written By : Roberto Hong Xu Kuang
// Last Modified : 12/04/2014
//------------------------------------------------------------------------------
// This is the header for checking account. This is a child of the Account 
// class. 
#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"

class Checking : public Account
{
public:
	Checking() : Account()
		{}
	Checking(double bal, double interest) : Account(bal, interest)
		{}
	int withdraw(double);
	void deposit(double);
	double monthlyProc();
};

#endif
