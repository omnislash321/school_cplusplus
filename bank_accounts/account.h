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
	virtual void deposit(double);
	virtual void withdraw(double);
	virtual void monthlyProc();
};

#endif
