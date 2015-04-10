//------------------------------------------------------------------------------
// Project Name: Bank Accounts
// Written By : Roberto Hong Xu Kuang
// Last Modified : 12/04/2014
//------------------------------------------------------------------------------
// The cpp file for the savings account.

#include "savings.h"

//------------------------------------------------------------------------------
// withdraw(double) - This method will return 1, -1, or -2. It will return 1
// if the withdraw goes through. It will return -1 if the account is inactive.
// Lastly, it will return -2 if the withdraw goes through, but now the account is
// inactive.
int Savings::withdraw(double amount)
{
	//First check if it's active to be withdraw first.
	if(status) //If it is, withdraw the amount.
		Account::withdraw(amount);
	else //Else return -1
		return -1;

	//Now, check it again.
	status = balance >= 25;

	//If the status is now inactive, return -2;
	if(!status)
		return -2;

	return 1;
}

//------------------------------------------------------------------------------
// deposit(double) - This will first check if the account is active or not. Then
// it will check if the new balance, of the amount included, will cause the 
// account to be active again.

void Savings::deposit(double amount)
{
	//If it's already active, then it won't bother checking.
	if(!status && (balance + amount) >= 25)
		status = true;

	//Deposit the amount.
	Account::deposit(amount);
}

//------------------------------------------------------------------------------
// monthlyProc() - After 4 withdrawals, a charge of $1 per withdrawal is added.
double Savings::monthlyProc()
{
	if(withdrawals > 4)
		serviceCharges += withdrawals;

	//Get the total from the base class method.
	double total = Account::monthlyProc();
	
	//Change the status if it is inactive now.
	status = balance >= 25;	

	//Return the total service chargse.
	return total;
}
