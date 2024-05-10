#pragma once
#include "LoyaltyScheme.h"

ref class CreditCardAccount
{
public:
	static CreditCardAccount();
	static int GetNumberOfAccounts();
	CreditCardAccount(long number, double limit);
	void SetCreditLimit(double amount);
	bool MakePurchase(double amount);
	void MakeRepayment(double amount);
	void PrintStatement();
	long GetAccountNumber();
	literal System::String^ name = "Super Platinum Card";
	void RedeemLoyaltyPoints();
private:
	static double interestRate;
	static int numberOfAccounts = 0;
	initonly long accountNumber;
	double currentBalance;
	double creditLimit;
	LoyaltyScheme^ scheme;// handle to a LoyaltyScheme object
};
