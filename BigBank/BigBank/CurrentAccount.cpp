#include "pch.h"
#include "CurrentAccount.h"


CurrentAccount::CurrentAccount(String^ holder, double limit)
	:BankAccount(holder), overdraftLimit(limit)
{

}

void CurrentAccount::ChangeOverdraftLimit(double newLimit)
{
	overdraftLimit = newLimit;
}

double CurrentAccount::GetOverdraftLimit()
{
	return overdraftLimit;
}

String^ CurrentAccount::ToString() 
{
	String^ result = BankAccount::ToString();
	result = String::Concat(result, ", Overdraft Limit: ");
	result = String::Concat(result, overdraftLimit.ToString());
	return result;
}

bool CurrentAccount::CanDebit(double amount) 
{
	String^ details = RoutingInstructions(amount);
	return (amount <= GetBalance() + overdraftLimit);
}