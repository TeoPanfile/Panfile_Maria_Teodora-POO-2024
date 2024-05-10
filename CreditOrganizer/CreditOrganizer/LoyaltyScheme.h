#pragma once

ref class LoyaltyScheme
{
public:
	LoyaltyScheme(); //constructor
	void EarnPointsOnAmount(double amountSpent); //Earn 1 point per 10$ spent
	void RedeemPoints(int points); //redeem points
	int GetPoints(); //return the value of totalPoints
private:
	static int totalPoints = 0; //total points earned so far
};
