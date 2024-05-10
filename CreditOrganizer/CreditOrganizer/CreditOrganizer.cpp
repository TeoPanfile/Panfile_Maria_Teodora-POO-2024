#include "pch.h"
#include "CreditCardAccount.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    int n = CreditCardAccount::GetNumberOfAccounts();
    Console::WriteLine("Number of accounts initially: ");
    Console::WriteLine(n);
    Console::Write("Card name is ");
    Console::WriteLine(CreditCardAccount::name);
    Console::WriteLine("\nCreating first object");
    CreditCardAccount ^account1;
    account1 = gcnew CreditCardAccount(12345, 2000);
    Console::WriteLine("\nMaking a purchase (300)");
    account1->MakePurchase(300);
    Console::WriteLine("\nMaking a purchase (700)");
    account1->MakePurchase(700);
    Console::WriteLine("\nMaking a purchase (500)");
    account1->MakePurchase(500);
    Console::WriteLine("\nRedeeming points");
    account1->RedeemLoyaltyPoints();
    /*account1->PrintStatement();
    Console::WriteLine("\nCreating second object");
    CreditCardAccount^ account2;
    account2 = gcnew CreditCardAccount(67890, 5000);
    account2->MakePurchase(750);
    account2->PrintStatement();
    n = CreditCardAccount::GetNumberOfAccounts();
    Console::Write("\nNumber of accounts now: ");
    Console::WriteLine(n);*/

}
