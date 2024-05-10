#include "pch.h"
#include "BankAccount.h"


BankAccount::BankAccount(String^ holder):accountHolder(holder), balance(0.0) {}

void BankAccount::Credit(double amount)
{
	balance += amount;
}

bool BankAccount::Debit(double amount) 
{
	if (CanDebit(amount)) 
	{
		balance += amount;
		return true;
	}
	else 
	{
		return false;
	}
}

double BankAccount::GetBalance()
{
	return balance;
}

String^ BankAccount::ToString() 
{
	String^ result = gcnew String("Account holder: ");
	result = String::Concat(result, accountHolder);
	result = String::Concat(result, ", Balance: ");
	result = String::Concat(result, balance.ToString());
	return result;
}

String^ BankAccount::RoutingInstructions(double amount)
{
	return "Some string...";
}