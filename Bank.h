#ifndef BANK_H
#define BANK_H

using namespace std;

class Bank {

public:
	Bank();
	void MenuScreen();
	void BalanceScreenWithout();
	void BalanceScreenWith();
	void Input();
	void PrintInput();
	double Interest();
	

private:
	double NumberofYears;
	double Months;
	double OpeningAmount;
	double DepositedAmount;
	double TotalAmount;
	double InterestRate;
	double ClosingAmount;

};

#endif
