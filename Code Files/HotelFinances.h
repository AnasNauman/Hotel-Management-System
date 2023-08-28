#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
class HotelWallet
{
private:
	float HotelBalance;
public:
	HotelWallet();
	void SetHotelBalance(float);
	float GetHotelBalance();
	void ViewHoteBalance();
	void operator+(float);
	void operator-(float);
};
class Expenditures :virtual public HotelWallet
{
private:
	float Totalexpenditures;
public:
	Expenditures();
	void SetExpenditures(float);
	void ViewTotalExpenditures();
	float GetTotalExpenditures();
	void operator+(float);
};
class Profits :virtual public HotelWallet
{
private:
	float Totalprofits;
public:
	Profits();
	void Setprofits(float);
	float GetTotalProfits();
	void ViewTotalProfits();
	void operator+(float);
};
class FinancialIndicator : public Expenditures, public Profits
{
private:
	float liquidityRatio;
	float priceEarningRatio;
	float profitability;
public:
	FinancialIndicator();
	float GetLiquidityRatio();
	float GetPriceEarningRatio();
	float GetProfitablity();
	void ViewFinancialIndicators();
	void operator+(float);
	void operator-(float);
};