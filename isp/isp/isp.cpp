//------------------------------------------------------------------------------
// Project Name : ISP
// Written By : Roberto Hong Xu Kuang
// Last Modified : 10/19/2014
//------------------------------------------------------------------------------
// A program that will calculate an internet bill based on the package of the 
// customer. Program will prompt for package and hours.
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Function protoypes
void dispMenu(); //Display the Menu
void processMenu(int); //Process the Menu choices
void printPrice(int, double); //Print the price

int main(){
	dispMenu();

	return 0;
}

//------------------------------------------------------------------------------
// Function dispMenu() - Will output the menu and filter any wrong menu choices.
// Then, it will call the next function to move on with the program.
void dispMenu(){
	int choice;
	cout << "Select a subscription package:\n";
	cout << "1. Package A\n" << "2. Package B\n" << "3. Package C\n";
	cout << "4. Quit\n\n";
	cin >> choice;
	
	//If choice is not an int, or choice isn't within 1 and 4,
	if(!cin || choice > 4 || choice < 1)
	{
		//This will be displayed and the program will end;
		cout << "The valid choices are 1 through 4. Run the program again and ";
		cout << "select one of those.";
	} else
		//Otherwise, it will call the next function.
		processMenu(choice);
}

//------------------------------------------------------------------------------
// Function processMenu(int) - Taking the menu choice and asking for hours, it
// will filter out any wrong hour choices not between 0 and 744. 
void processMenu(int choice){
	double hours;
	
	//Since 4 is the only unique menu choice, this won't ask for input.
	if(choice == 4)
		cout << "Program Ending";
	else{
		cout << "How many hours were used? ";
		cin >> hours;
	}
	//If cin isn't a double, or not within the correct range, program will end.
	if(!cin || hours > 744.00 || hours < 0){
		cout << "The hours used must be between 0.00 and 744.00.\n";
	} else if(choice != 4) //If the choice was not 4, then call next function. 
		printPrice(choice, hours);	
}

//------------------------------------------------------------------------------
// Function printPrice(int, double) - Will take the selected menu package and
// the hours from input, and then calculate the price.
void printPrice(int choice, double hours){
	double total;
	
	//Calculations for the total.
	// Package A - $9.95 for first 10 hours, $2.00 per hour.
	// Package B - $14.95 for first 20 hours, $1.00 per hour.
	// Package C - $19.95 for unlimited hours.
	switch(choice){
		case 1: total = 9.95;
			if(hours > 10.00)
			total += (hours-10)*2;
			break;
		case 2: total = 14.95;
			if(hours > 20)
				total += (hours-20)*1;
			break;
		case 3: total = 19.95;
			break;
	}
	//Set precision to 2 decimal places, and fix it so it will show .00	
	cout << "The total amount due is $" << fixed << setprecision(2) << total;
}
