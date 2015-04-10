//------------------------------------------------------------------------------
// Project Name: Bank Accounts
// Written By : Roberto Hong Xu Kuang
// Last Modified : 12/04/2014
//------------------------------------------------------------------------------
// This is the cpp file for the checking account. The withdraw function is 
// special because it must check whether or not the withdrawal will cause the
// balance to drop below 0.
#include "checking.h"

//------------------------------------------------------------------------------
// withdraw(double) - First, if the amount to withdraw will cause the balance
// to drop below 0, the withdrawal will not go through. It will return -1 since
// it failed. Also, it will add a 15$ service charge. Otherwise, the withdrawal
// goes through, and withdraws gets incremented.
int Checking::withdraw(double amount)
{
	double newBal = balance - amount;

	//Must make sure it's a valid withdrawal.
	if(newBal < 0)
	{
		serviceCharges -= 15;
		return -1;
	}
	else
	{
		balance = newBal;
		withdrawals ++;
	}
	
	return 1;
}

//------------------------------------------------------------------------------
// deposit(double) - Technically not needed, but this was added since the header
// file contained this method. Simply calls the base method for deposit.
void Checking::deposit(double amount)
{
	Account::deposit(amount);
}

//------------------------------------------------------------------------------
// monthlyProc() - First, it will add a $5 charge, and then 10 cents per every
// withdrawal. After that, it will call the base class function. It will return
// the service charges before it gets reset.
double Checking::monthlyProc()
{
	serviceCharges += 5 + (0.1 * withdrawals);

	//The base class returns the total service charges.
	return Account::monthlyProc();
}
