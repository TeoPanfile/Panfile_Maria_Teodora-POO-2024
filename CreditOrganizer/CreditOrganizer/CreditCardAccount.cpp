//#include "stdafx.h"
#include "pch.h"
#include "CreditCardAccount.h"
#using <mscorlib.dll>
using namespace System;
void CreditCardAccount::SetCreditLimit(double amount) 
{
	creditLimit = amount;
}
bool CreditCardAccount::MakePurchase(double amount)
{
	if (currentBalance + amount > creditLimit)
	{
		return false;
	}
	else
	{
		currentBalance += amount;

		// if current balance 50% or > of credit limit
		if (currentBalance >= creditLimit / 2)
		{
			//if LoyaltyScheme object doesn't exist yet
			if (scheme == nullptr)
				// create it
				scheme = gcnew LoyaltyScheme();
		}
		else
		{
			//LoyaltyScheme already exists
			//so we add bonus points
			scheme->EarnPointsOnAmount(amount);
		}
		return true;
	}
}
void CreditCardAccount::MakeRepayment(double amount)
{
	currentBalance -= amount;
}
void CreditCardAccount::PrintStatement()
{
	Console::Write("Current balance: ");
	Console::WriteLine(currentBalance);
}
long CreditCardAccount::GetAccountNumber()
{
	return accountNumber;
}
CreditCardAccount::CreditCardAccount(long number, double limit)
{
	scheme = nullptr;
	accountNumber = number;
	creditLimit = limit;
	currentBalance = 0.0;
	numberOfAccounts++;
	Console::Write("This is account number: ");
	Console::WriteLine(numberOfAccounts);
}
int CreditCardAccount::GetNumberOfAccounts()
{
	return numberOfAccounts;
}
static CreditCardAccount::CreditCardAccount()
{
	interestRate = 4.5;
	Console::WriteLine("Static constructor called");
}
void CreditCardAccount::RedeemLoyaltyPoints()
{
	// If LoyaltyScheme object doesn't exist yet
	if (scheme == nullptr)
	{
		//Display error message
		Console::WriteLine("Sorry, you do not have a loyalty scheme yet");
	}
	else
	{
		//Tell the user current no of points available
		Console::Write("Points available: ");
		Console::Write(scheme->GetPoints());
		Console::Write(". How many points do you want to redeem? \n");
		String^ input = Console::ReadLine();
		int points = Convert::ToInt32(input);
		//redeem points
		scheme->RedeemPoints(points);
		//Tell user how many points are left
		Console::Write("Points remaining: ");
		Console::WriteLine(scheme->GetPoints());
	}
}