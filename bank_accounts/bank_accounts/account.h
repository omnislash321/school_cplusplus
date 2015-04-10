//------------------------------------------------------------------------------
// Project Name: Bank Accounts
// Written By : Roberto Hong Xu Kuang
// Last Modified : 12/04/2014
//------------------------------------------------------------------------------
// This is the header file for the base class Accounts
// Changes : Added a second constructor for arguments:
//   Changed withdraw and monthlyProc to int and double instead of void
//   Added 3 get methods for withdawals, deposits, and balance.
//   Check .cpp to see what they return.

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
	double balance;
	int deposits;
	int withdrawals;
	double interestRate;
	double serviceCharges;
	virtual void calcInt();
public:
	Account();
	Account(double, double);
	virtual void deposit(double);
	virtual int withdraw(double);
	virtual double monthlyProc();
	
	int getWithdrawals();
	int getDeposits();
	double getBalance();
};

#endif
