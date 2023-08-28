#include "HotelFinances.h"
#include "Customer.h"
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;


HotelWallet::HotelWallet()
{
	HotelBalance = 1000;
}
void HotelWallet::SetHotelBalance(float hb)
{
	HotelBalance = hb;
}
float HotelWallet::GetHotelBalance()
{
	return HotelBalance;
}
void HotelWallet::operator+(float sum)
{
	HotelBalance += sum;
}
void HotelWallet::operator-(float sum)
{
	if (HotelBalance - sum > 0)
	{
		HotelBalance -= sum;
	}
	else
	{
		cout << "\nINSUFFICIENT FUNDS\n";
		settextstyle(3, 0, 3);
		setcolor(2);
		outtextxy(550, 630, "INSUFFICIENT FUNDS");
		delay(500);
		cleardevice();
	}
}
void HotelWallet::ViewHoteBalance()
{
	int x, y;
	do
	{
		{ setcolor(14);
		settextstyle(9, 0, 9);
		outtextxy(290, 60, "Hotel Finances");
		settextstyle(4, 0, 3);
		setcolor(15);
		outtextxy(340, 360, "Hotel Balance");
		bgiout << "$" << HotelBalance;
		outstreamxy(800, 360);
		outtextxy(1150, 50, "Back"); }
		const int DELAY = 100; // Milliseconds of delay between checks
		while (!ismouseclick(WM_LBUTTONDOWN))
			delay(DELAY);
		getmouseclick(WM_LBUTTONDOWN, x, y);
		cout << x << "  " << y << endl;
		if ((x < 1245 && x>1140) && (y > 45 && y < 75))// Back
		{
			return;
		}
	} while (1);
}

Expenditures::Expenditures()
{
	Totalexpenditures = 250;
}
void Expenditures::SetExpenditures(float exp)
{
	if (exp > 100)
	{
		Totalexpenditures = exp;
	}
	else
	{
		Totalexpenditures = 250;
	}
}
float Expenditures::GetTotalExpenditures()
{
	return Totalexpenditures;
}
void Expenditures::ViewTotalExpenditures()
{
	int x, y;
	do
	{
		{ setcolor(14);
		settextstyle(9, 0, 9);
		outtextxy(290, 60, "Hotel Finances");
		settextstyle(4, 0, 3);
		setcolor(15);
		outtextxy(340, 360, "Total Expenditures");
		bgiout << "$" << Totalexpenditures;
		outstreamxy(800, 360);
		outtextxy(1150, 50, "Back"); }
		const int DELAY = 100; // Milliseconds of delay between checks
		while (!ismouseclick(WM_LBUTTONDOWN))
			delay(DELAY);
		getmouseclick(WM_LBUTTONDOWN, x, y);
		cout << x << "  " << y << endl;
		if ((x < 1245 && x>1140) && (y > 45 && y < 75))// Back
		{
			return;
		}
	} while (1);
}
void  Expenditures::operator+(float sum)
{
	HotelWallet::operator-(sum);
	Totalexpenditures += sum;
}

Profits::Profits()
{
	Totalprofits = 150;
}
void Profits::Setprofits(float prof)
{
	if (prof > 100)
	{
		Totalprofits = prof;
	}
	else
	{
		Totalprofits = 150;
	}
}
float Profits::GetTotalProfits()
{
	return Totalprofits;
}
void Profits::operator+(float sum)
{
	HotelWallet::operator+(sum);
	Totalprofits += sum;
}
void Profits::ViewTotalProfits()
{
	int x, y;
	do
	{
		{ setcolor(14);
		settextstyle(9, 0, 9);
		outtextxy(290, 60, "Hotel Finances");
		settextstyle(4, 0, 3);
		setcolor(15);
		outtextxy(340, 360, "Total Profits");
		bgiout << "$" << Totalprofits;
		outstreamxy(800, 360);
		outtextxy(1150, 50, "Back"); }
		const int DELAY = 100; // Milliseconds of delay between checks
		while (!ismouseclick(WM_LBUTTONDOWN))
			delay(DELAY);
		getmouseclick(WM_LBUTTONDOWN, x, y);
		cout << x << "  " << y << endl;
		if ((x < 1245 && x>1140) && (y > 45 && y < 75))// Back
		{
			return;
		}
	} while (1);
}

FinancialIndicator::FinancialIndicator()
{
	liquidityRatio = 25;
	priceEarningRatio = 60;
	profitability = 80;
}
float FinancialIndicator::GetLiquidityRatio()
{
	liquidityRatio = (GetTotalProfits() / GetTotalExpenditures()) * 100;
	if (liquidityRatio > 100)
	{
		srand(time(0));
		liquidityRatio = rand() % 100 + 1;
	}
	return liquidityRatio;
}
float FinancialIndicator::GetPriceEarningRatio()
{
	priceEarningRatio = rand() % 100 + 1;
	return priceEarningRatio;
}
float FinancialIndicator::GetProfitablity()
{
	profitability = (GetTotalProfits() / GetHotelBalance()) * 100;
	if (profitability > 100)
	{
		srand(time(0));
		profitability = rand() % 100 + 1;
	}
	return profitability;
}
void FinancialIndicator::operator+(float sum)
{
	Profits::operator+(sum);
}
void FinancialIndicator::operator-(float sum)
{
	Expenditures::operator+(sum);
}
void FinancialIndicator::ViewFinancialIndicators()
{
	{cleardevice();
	setcolor(14);
	settextstyle(9, 0, 9);
	outtextxy(290, 60, "Hotel Finances");
	settextstyle(3, 0, 3);
	setcolor(15);
	outtextxy(1150, 50, "Back"); }


	int percent, pp, count;
	int x, y, z, i, j, k;

	percent = GetLiquidityRatio();
	for (i = 4, pp = 200, count = 0; count <= percent; i += 4)
	{
		pp += 4;
		count++;
	}
	cout << pp;
	for (x = 200, y = 250; x < pp; x += 10)
	{
		setcolor(15);
		bgiout << "Liquidity Ratio";
		outstreamxy(50, 215);
		if (x <= 320)
		{
			setfillstyle(1, RED);
		}
		if (x > 320 && x <= 4400)
		{
			setfillstyle(1, YELLOW);
		}
		if (x > 440)
		{
			setfillstyle(1, GREEN);
		}
		settextstyle(3, 0, 3);
		bar(200, 250, x, y - 50);
		delay(100);
	}
	setcolor(15);
	bgiout << percent << " % ";
	outstreamxy(620, 215);




	percent = CustomerIndex * 10;
	for (i = 4, pp = 200, count = 0; count <= percent; i += 4)
	{
		pp += 4;
		count++;
	}
	cout << pp;
	for (x = 200, y = 350; x < pp; x += 10)
	{
		setcolor(15);
		bgiout << "Customer";
		outstreamxy(50, 315);
		if (x <= 320)
		{
			setfillstyle(1, RED);
		}
		if (x > 320 && x <= 4400)
		{
			setfillstyle(1, YELLOW);
		}
		if (x > 440)
		{
			setfillstyle(1, GREEN);
		}
		settextstyle(3, 0, 3);
		bar(200, 350, x, y - 50);
		delay(100);
	}
	setcolor(15);
	bgiout << percent << " % ";
	outstreamxy(620, 315);


	percent = GetPriceEarningRatio();
	for (i = 4, pp = 200, count = 0; count <= percent; i += 4)
	{
		pp += 4;
		count++;
	}
	cout << pp;
	for (x = 200, y = 450; x < pp; x += 10)
	{
		setcolor(15);
		bgiout << "Price-Earn Ratio";
		outstreamxy(50, 415);
		if (x <= 320)
		{
			setfillstyle(1, RED);
		}
		if (x > 320 && x <= 4400)
		{
			setfillstyle(1, YELLOW);
		}
		if (x > 440)
		{
			setfillstyle(1, GREEN);
		}
		settextstyle(3, 0, 3);
		bar(200, 450, x, y - 50);
		delay(100);
	}
	setcolor(15);
	bgiout << percent << " % ";
	outstreamxy(620, 415);

	percent = GetProfitablity();
	for (i = 4, pp = 200, count = 0; count <= percent; i += 4)
	{
		pp += 4;
		count++;
	}
	cout << pp;
	for (x = 200, y = 550; x < pp; x += 10)
	{
		setcolor(15);
		bgiout << "Profitability";
		outstreamxy(50, 515);
		if (x <= 320)
		{
			setfillstyle(1, RED);
		}
		if (x > 320 && x <= 4400)
		{
			setfillstyle(1, YELLOW);
		}
		if (x > 440)
		{
			setfillstyle(1, GREEN);
		}
		settextstyle(3, 0, 3);
		bar(200, 550, x, y - 50);
		delay(100);
	}
	setcolor(15);
	bgiout << percent << " % ";
	outstreamxy(620, 515);


	do
	{
		//const int DELAY = 100; // Milliseconds of delay between checks
		//while (!ismouseclick(WM_LBUTTONDOWN))
			 //delay(DELAY);
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if ((x < 1245 && x>1140) && (y > 45 && y < 75))// Back
		{
			return;
		}
	} while (1);
}