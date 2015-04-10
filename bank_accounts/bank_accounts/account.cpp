//------------------------------------------------------------------------------
// Project Name: Bank Accounts
// Written By : Roberto Hong Xu Kuang
// Last Modified : 12/04/2014
//------------------------------------------------------------------------------
// This is the cpp file for the account header.
#include "account.h"


//------------------------------------------------------------------------------
// Constructor (No arguments) - Sets everything to 0. Annual interest rate of 
//  5% is the given.
Account::Account()
{
	balance = 0.00;
	deposits = 0;
	withdrawals = 0;
	interestRate = 0.05;
	serviceCharges = 0.00;
}

//------------------------------------------------------------------------------
// Constructor (2 arguments) - This is the same as basic constructor, but
// allows the user to create an Account with specified balance and interest. 
Account::Account(double bal, double interest)
{
	balance = bal;
	deposits = 0;
	withdrawals = 0;
	interestRate = interest;
	serviceCharges = 0.00;	
}

//------------------------------------------------------------------------------
// calcInt() - Will calculate the monthly interest and then add it to the 
// balance. Monthly interest is annual interets / 12.
void Account::calcInt()
{
	balance += (interestRate/12) * balance;
}

//------------------------------------------------------------------------------
// deposit(double) - This will add the specified amount to the balance, and then
// increment the deposits count.
void Account::deposit(double amount)
{
	balance += amount;
	
	deposits ++;
}

//------------------------------------------------------------------------------
// withdraw(double) - This will subtract the specified amount from the balance,
// and then increment the withdrawals count. Will return 1 if successful.
int Account::withdraw(double amount)
{
	balance -= amount;

	withdrawals ++;

	//Since this is just the parent class, return 1.
	return 1;
}

//------------------------------------------------------------------------------
// monthlyProc() - This will calculate the interest and add it to the balance,
// and then it will take away any service charges. Then, reset everything back
// to zero. It will return the service charges before reset.
double Account::monthlyProc()
{
	calcInt();
	balance -= serviceCharges;
	withdrawals = 0;
	deposits = 0;

	double total = serviceCharges;

	serviceCharges = 0;

	return total;
}

//------------------------------------------------------------------------------
// getWithdrawals() - Getter method for withdrawals.
int Account::getWithdrawals()
{
	return withdrawals;
}


//------------------------------------------------------------------------------
// getDeposits() - Getter method for deposits.
int Account::getDeposits()
{
	return deposits;
}

//------------------------------------------------------------------------------
// getBalance() - Getter method for balance.
double Account::getBalance()
{
	return balance;
}
