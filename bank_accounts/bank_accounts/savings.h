//------------------------------------------------------------------------------
// Project Name: Bank Accounts
// Written By : Roberto Hong Xu Kuang
// Last Modified : 12/04/2014
//------------------------------------------------------------------------------
// The header file for the savings account. Child of the account class.
// Has an extra variable - bool status. If the status is false, then the user
// will not be able to make a withdrawal until the balance is over $25.
#ifndef SAVINGS_H
#define SAVINGS_H

#include "account.h"

class Savings : public Account
{
protected:
	bool status;
public:
	//Inline constructor.
	Savings() : Account()
	{
		//Set the status to false since it starts at 0.00 for balance.	
		status = false;
	}
	Savings(double bal, double interest) : Account(bal, interest)
		{}
	int withdraw(double);
	void deposit(double);
	double monthlyProc();
};

#endif
