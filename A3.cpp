//************************************
// AccountTestMain.cpp
// The purpose of this code is to create a program which imitates an ATM. 
//************************************

// README: The only place you will need to make changes to this
// code file is within the switch statement provided below

#include <iostream>
#include <iomanip> // for 'fixed' and 'setprecision'

// A function to print the user account balances. Do not change
// the code in this function
void PrintAccountBalances(int & transaction, double account1, double account2);

// function main begins program execution
int main()
{
	// a variable to track the number of transactions
	// Do not mess with these variables
	int transaction = 0;
	double savings = 100.50; // this value should stay 100.50
	double checking = 100.50; // this value should stay 100.50

							  // display initial balance of each account
	std::cout << "Welcome to People's Second Bank ATM" << "\n";
	PrintAccountBalances(transaction, savings, checking);

	// a variable to hold their choice
	int selection = 0;
	// a variable to hold the dollar amount for the transactions
	double amount = 0; // you can reuse this variable every time - make sure to update account values
	while (selection != 7)
	{
		// Display a menu to the user
		// You MUST use the integer values (1-7) for the auto evaluator to work
		std::cout << "(1) to deposit to savings account" << std::endl;
		std::cout << "(2) to deposit to checking account" << std::endl;
		std::cout << "(3) to withdraw from savings account" << std::endl;
		std::cout << "(4) to withdraw from checking account" << std::endl;
		std::cout << "(5) to transfer from savings to checking" << std::endl;
		std::cout << "(6) to transfer from checking to savings" << std::endl;
		std::cout << "(7) to exit" << std::endl; // sentinel value

												 // Ask the user for their choice
		std::cout << "What would you like to do? ";
		std::cin >> selection;

		///////////////////////////////////////////////////////////////////////////////////
		// Inside of this switch statement is the only place you need to write code!///////
		// If you modified any other code, start over./////////////////////////////////////
		// Use a switch statement to detect their option///////////////////////////////////
		// Use the variables provided to hold the dollar amount of their transaction///////
		// Also use the provided variables to track the account balances///////////////////
		///////////////////////////////////////////////////////////////////////////////////
		switch (selection)
		{
			case 1:
				std::cout << "How much do you want to deposit into savings?";
				std::cin >> amount;
				savings += amount;
				break;
			case 2:
				std::cout << "How much do you want to deposit into checking?";
				std::cin >> amount;
				checking += amount;
				break;
			case 3:
				std::cout << "How much do you want withdraw from savings?";
				std::cin >> amount;
				if (amount>savings){
					std::cout << "Balance exceeded!\n";
				}
				else {
					savings -= amount;
				}
				break;
			case 4:
				std::cout << "How much do you want to withdraw from checking?";
				if (amount>checking) {
					std::cout << "Balance exceeded!\n";
				}
				else {
					checking -= amount;
				}
				break;
			case 5:
				std::cout << "How much do you want to transfer from savings to checking?";
				std::cin >> amount;
				if (amount>savings) {
					std::cout << "Balance exceeded!\n";
				}
				else {
					checking += amount;
					savings -= amount;
				}
				break; 
			case 6:
				std::cout << "How much do you want to transfer from checking to savings?";
				if (amount>checking) {
					std::cout << "Balance exceeded!\n";
				}
				else {
					checking -= amount;
					savings += amount;
				}
				break;
			case 7:
				std::cout << "Goodbye!\n";
				break;
			default:
				std::cout << "Invalid Selection\n";
				break;

		}
		///////////////////////////////////////////////////////////////////////////////////
		// You don't need to modify any code anywhere else in this file.///////////////////
		///////////////////////////////////////////////////////////////////////////////////

		// display new balances after each transaction
		// DO NOT change or move this statement
		//////////////////////////////////////////////////////////////////////
		PrintAccountBalances(transaction, savings, checking);
		///////////////////////////////////////////////////////////////////////
	}

	// Pause the program before exit
	std::cout << "Press ENTER to continue";
	std::cin.ignore(); // ignores the next return key in the buffer
	std::cin.get(); // waits for a new return key on the buffer
	return 0;
} // end main

  // Do not change any of the code in this function
void PrintAccountBalances(int & transaction, double savings, double checking)
{
	transaction += 1;
	std::cout << "[" << transaction << "] Savings balance: $";
	std::cout << std::setprecision(2) << std::fixed << savings << "\n";
	std::cout << "[" << transaction << "] Checking balance: $";
	std::cout << std::setprecision(2) << std::fixed << checking << "\n";
	std::cout << std::endl; // std::endl inserts a return and flushes the buffer
}