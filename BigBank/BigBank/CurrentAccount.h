#pragma once

#include "BankAccount.h"

ref class CurrentAccount : BankAccount
{
public:
	CurrentAccount(String^ holder, double limit);
	void ChangeOverdraftLimit(double newLimit);
	double GetOverdraftLimit();
	// Choose to override ToString
	virtual String^ ToString() override;
	// Have to override CanDebit
	virtual bool CanDebit(double amount) override;
private:
	double overdraftLimit;
};