#include "pch.h"
#include "LoyaltyScheme.h"

#using <mscorlib.dll>
using namespace System;

LoyaltyScheme::LoyaltyScheme()
{
	Console::WriteLine("Congratulations, you now qualify for bonus points");
}
int LoyaltyScheme::GetPoints()
{
	return totalPoints;
}
void LoyaltyScheme::EarnPointsOnAmount(double amountSpent)
{
	int points = (amountSpent / 10);
	totalPoints += points;
	Console::WriteLine("New bonus points earned: ");
	Console::WriteLine(points);
}

void LoyaltyScheme::RedeemPoints(int points)
{
	if (points <= totalPoints)
	{
		totalPoints -= points;
	}
	else
	{
		totalPoints = 0;
	}
}

