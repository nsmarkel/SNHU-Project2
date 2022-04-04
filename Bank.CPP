#include <iostream>
#include<iomanip>
#include<math.h>
#include "Bank.h"

using namespace std;
/// <summary>
/// Constructor
/// </summary>
Bank::Bank() {

	NumberofYears=0;
	Months=0;
	OpeningAmount=0;
	DepositedAmount=0;
	TotalAmount=0;
	InterestRate=0;
	ClosingAmount=0;
}

/// <summary>
/// Prints screen to show what you can enter.
/// </summary>
void Bank::MenuScreen() {
	cout << "****************************" << endl;
	cout << "********Data Input**********" << endl;
	cout << " Intial investment amount:  " << endl;
	cout << " Monthly Deposit:           " << endl;
	cout << " Annual interest:           " << endl;
	cout << " Number of years:           " << endl;
	cout << "****************************" << endl;
}

/// <summary>
/// Prints the amounts entered by the user
/// </summary>
void Bank::PrintInput() {
	cout << "****************************" << endl;
	cout << "********Data Input**********" << endl;
	cout << " Intial investment amount: " << OpeningAmount << endl;
	cout << " Monthly Deposit: \t   " << DepositedAmount << endl;
	cout << " Annual interest: \t   " << InterestRate << endl;
	cout << " Number of years: \t   " << NumberofYears << endl;
	cout << "****************************" << endl;
}

/// <summary>
/// Shows the amount of interest earned without making any deposits. 
/// </summary>
void Bank::BalanceScreenWithout() {

	double total = OpeningAmount;
	double interest = InterestRate * .01;

	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "========================================================" << endl;
	cout << "  Year     Year End Balance     Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;
	for (int i = 0; i < NumberofYears; ++i) {

		total = total + interest;
		
		cout << setprecision(2) << fixed << showpoint << "   " << (i+1) << "\t\t\t" << total 
			<< "\t\t\t" << interest << endl << endl;

		interest = total * interest;
	}
}

/// <summary>
/// Shows the Month end balance with the month end interest earned. Was not able to convert this into years like the first screen.
/// </summary>
void Bank::BalanceScreenWith() {;

	double rate = ((OpeningAmount + DepositedAmount) * (InterestRate / 100.00) / 12.00);
	double balance = OpeningAmount + DepositedAmount + rate;


	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "========================================================" << endl;
	cout << "  Month     Month End Balance     Month End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;

	for (int i = 0; i < (NumberofYears*12); ++i) {
		
		rate = ((OpeningAmount + DepositedAmount) * (InterestRate / 100.00) / 12.00);
		balance = OpeningAmount + DepositedAmount + rate;

		cout << setprecision(2) << fixed << showpoint << "   " << (i + 1) << "\t\t\t" << balance
			<< "\t\t\t" << rate << endl << endl;

		OpeningAmount += balance;
	}
}

/// <summary>
/// Gets input from user and assigns to private variables. Using input validation.
/// </summary>
void Bank::Input() {

	cout << "Intial investment amount : " << endl;
	cin >> OpeningAmount;	
	while (OpeningAmount < 0.0) {
		cout << "Invalid try again " << endl;
		cin >> OpeningAmount;
	}

	cout << "Monthly Deposit:" << endl;
	cin >> DepositedAmount;
	while (DepositedAmount < 0.0) {
		cout << "Invalid try again " << endl;
		cin >> DepositedAmount;
	}

	cout << "Annual interest:" << endl;
	cin >> InterestRate;
	while (InterestRate < 0.0) {
		cout << "Invalid try again " << endl;
		cin >> InterestRate;
	}

	cout << "Number of years:" << endl;
	cin >> NumberofYears;
	while (NumberofYears < 0.0) {
		cout << "Invalid try again " << endl;
		cin >> NumberofYears;
	}

}

/// <summary>
/// Gets monthly interest rate based off yearly interest rate and user entered variables.
/// </summary>
double Bank::Interest(){
	
	double rate;
	rate = ((OpeningAmount + DepositedAmount) * (InterestRate / 100.00) / 12.00);
	return rate;

}
