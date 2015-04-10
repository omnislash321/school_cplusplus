//------------------------------------------------------------------------------
// Project Name: Bank Accounts
// Written By : Roberto Hong Xu Kuang
// Last Modified : 12/04/2014
//------------------------------------------------------------------------------
// Bank accounts will have two bank accounts, a savings and a checkings account,
// both of which are children classes of the account class. They have 2 main
// options, to withdraw and to deposit. 
#include "savings.h"
#include "checking.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

//Function prototypes.
int printMenu(fstream*, fstream*);
void sWithdraw(Savings*, double, fstream*);
void cWithdraw(Checking*, double, fstream*);
void dispTotal(Savings*, Checking*, fstream*);

//------------------------------------------------------------------------------
// main method - Command line arguments.
int main(int argc, char* argv[])
{
	// If there aren't two file arguments, then exit.
	if(argc < 3)
		exit(1);
	else
	{
		//Create the two file streams.
		fstream inFile, outFile;
		
		//Open the input file.
		inFile.open(argv[1], ios::in);
	
		if(!inFile)
		{
			cout << "InFile not found!";
			exit(1);
		}
		
		//Open the output file.
		outFile.open(argv[2], ios::out);
		
		if(!outFile)
		{
			cout << "OutFile not found!";
			exit(1);
		}


		//If both are opened successfully, then...
		if(inFile && outFile)
		{
			//Create the two accounts and set some variables.
			Checking cAccount;
			Savings sAccount;
			int choice = 0;
			double amount = 0;
			
			//A do-while for the menu.
			do
			{
				//Get the choice of the user input.
				choice = printMenu(&inFile, &outFile);
				
				//Switch statement for the choices.
				switch(choice)
				{
					//1 & 2 are similar, so I grouped it together.
					case 1:
					case 2:
						outFile << "Enter amount to deposit: ";
						inFile >> amount;
						//1 = Savings, 2 = Checking.
						if(choice == 1)
							//Deposit to the savings account.
							sAccount.deposit(amount);
						else
							//Deposit to the checking account.
							cAccount.deposit(amount);
						break;
					//Same reasoning as aove.
					case 3:
					case 4:
						outFile << "Enter amount to withdraw: ";
						inFile >> amount;
						//3 = savings, 2 = checking.
						if(choice == 3)
							//Withdraw from savings.
							sWithdraw(&sAccount, amount, &outFile);
						else
							//Withdraw from checking.
							cWithdraw(&cAccount, amount, &outFile);
						break;
					case 5:
						//Display the statistics.
						dispTotal(&sAccount, &cAccount, &outFile);
						break;
					case 6:
						break;
					default:
						break;
				}
			}
			while(choice != 6);

			//Close file streams.
			inFile.close();
			outFile.close();	
		}
	}
}


//------------------------------------------------------------------------------
// printMenu(fstream*, fstream*) - Will print out the menu. If not valid choices
// then it will loop until a valid choice is found.
int printMenu(fstream* inFile, fstream* outFile)
{
	*outFile << "\n\n";
	*outFile << "******** BANK ACCOUNT MENU ********\n\n";
	*outFile << "1.  Savings Account Deposit\n";
	*outFile << "2.  Checking Account Deposit\n";
	*outFile << "3.  Savings Account Withdrawal\n";
	*outFile << "4.  Checking Account Withdrawal\n";
	*outFile << "5.  Update and Display Account Statistics\n";
	*outFile << "6.  Exit\n\n";
	*outFile << "Your choice, please: (1-6)  ";

	int choice;
	*inFile >> choice;

	while(choice > 6 || choice < 1)
	{
		*outFile << "Enter a number from 1 through 6 please: ";
		*inFile >> choice;
	}	

	return choice;
}

//------------------------------------------------------------------------------
// sWithdraw(Savings*, double, fstream*) - This will withdraw from the savings
// account. Since there are 3 possibilities, each one needs a seperate output
// 1 - Withdraw successful. -1 - Inactive account. -2 - Withdraw went through,
// but caused the account to be deactivated.
void sWithdraw(Savings* acc, double amount, fstream* outFile)
{
	int result = acc->withdraw(amount);
	if(result == -1)
		*outFile << "Account is inactive.\n\n";
	else if(result == -2)
	{
		*outFile << "\nYour account has fallen below $25.00.";	
		*outFile << "\nIt will be deactivated.\n";
	}
}

//------------------------------------------------------------------------------
// cWithdraw(Checking*, double, fstream*) - Will withdraw money from the 
// checking account. If the result from it is -1, then that means it failed
// and a service fee of 15$ was added.
void cWithdraw(Checking* acc, double amount, fstream* outFile)
{
	int result = acc->withdraw(amount);
	if(result == -1)
	{
		*outFile << "You are attempting to withdraw more ";
		*outFile << "than the account balance.\n";
	}
}

//------------------------------------------------------------------------------
// dispTotal(Savings*, Checking*, fstream*) - Will display the statistics
// of both the accounts.
void dispTotal(Savings* sAcc, Checking* cAcc, fstream* outFile)
{
	//Fixed and setprecision for the decimals in balance and service charges.
	*outFile << fixed << setprecision(2) << "\n\n";
	*outFile << "SAVINGS ACCOUNT MONTHLY STATISTICS:\n";
	*outFile << "Withdrawals:		" << sAcc->getWithdrawals() << "\n";
	*outFile << "Deposits:		" << sAcc->getDeposits() << "\n";
	*outFile << "Service Charges:	" << sAcc->monthlyProc() << "\n";
	*outFile << "\nEnding Balance: 	" << sAcc->getBalance() << "\n";	
	*outFile << "\n\n\n";
	*outFile << "CHECKING ACCOUNT MONTHLY STATISTICS:\n";
	*outFile << "Withdrawals:		" << cAcc->getWithdrawals() << "\n";
	*outFile << "Deposits:		" << cAcc->getDeposits() << "\n";
	*outFile << "Service Charges:	" << cAcc->monthlyProc() << "\n";
	*outFile << "\nEnding Balance: 	" << cAcc->getBalance() << "\n";
	*outFile << "\n";
}
