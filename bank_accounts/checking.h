#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"

class Checking : public Account
{
public:
	Checking() : Account()
		{}

	void withdraw(double);
	void deposit(double);
	void monthlyProc();
};

#endif
