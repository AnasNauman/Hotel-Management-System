#include "Customer.h"
#include "Employee.h"
#include "Arcade.h"
#include "Restaurant.h"
#include "HotelFinances.h"
#include <iostream>
#include<cstring>
#include <string>
#include <ctime>
#include <fstream>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
FinancialIndicator HotelBankAccount;
 Restaurant restaurant;
 Customer** customerList;
 int TotalCustomers = 10, CustomerIndex = 0;


//////////////////////////////////////////////////////////////////////
PersonType::PersonType()
{
    Fname = '-';
    Lname = '-';
    Gender = "N/A";
}
PersonType::PersonType(string c1, string c2, string c3)
{
    Fname = c1;
    Lname = c2;
    Gender = c3;

}
void PersonType::SetName(string c1, string c2, string c3)
{
    Fname = c1;
    Lname = c2;
    Gender = c3;
}
string PersonType::GetFname()
{
    return Fname;
}
string PersonType::GetLname()
{
    return Lname;
}
string PersonType::GetGender()
{
    return Gender;
}
Bill::Bill()
{
    RoomCharge = 0.0;
    MedicineFee = 0.0;
    FoodBill = 0.0;
    ServiceCharges = 150.0;
    Arcade = 0.0;
    invoice = 0;
    Total = 0.0;
}
float Bill::GetRoomCharge()
{
    return RoomCharge;
}
float Bill::GetMedicineFee()
{
    return MedicineFee;
}
float Bill::GetFoodBill()
{
    return FoodBill;
}
float Bill::GetServiceCharges()
{
    return ServiceCharges;
}
float Bill::GetArcade()
{
return Arcade;
}
void Bill::AddArcade(int a)
{
	Arcade += a;
}
void Bill::setinvoice(int x)
{
    invoice = x;
}
int Bill::getinvoice()
{
    return invoice;
}
float Bill::GetTotal()
{
    Total = RoomCharge + MedicineFee + FoodBill + ServiceCharges+Arcade;
    return Total;
}
void Bill::operator+(float pr)
{
    FoodBill = FoodBill + pr;
}
void Bill::SetRoomCharge(int z)
{
    RoomCharge = z;
}
Bill::~Bill()
{
    cout << "Bill Destructor Called" << endl;
}
/////////////////////////////////////////////////////////////
////////////////DATE TYPE CLASS//////////////////////////////
/////////////////////////////////////////////////////////////
DateType::DateType()
{
    day = 0;
    month = 0;
    year = 0;
}
void DateType::SetDate(int m, int d, int y)//added
{
    day = d;
    month = m;
    year = y;
}
int DateType::GetDay()
{
    return day;
}
int DateType::GetMonth()
{
    return month;
}
int DateType::GetYear()
{
    return year;
}
DateType::~DateType()
{
    cout << "DateType Destructor Called" << endl;
}
bool CheckDate(int m, int d, int y)//friend function
{
    if (1000 <= y <= 3000)
    {
        if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 0 && d <= 31)
            return true;
        else
            if (m == 4 || m == 6 || m == 9 || m == 11 && d > 0 && d <= 30)
                return true;
            else
                if (m == 2)
                {
                    if ((y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) && d > 0 && d <= 29)
                        return true;
                    else if (d > 0 && d <= 28)
                        return true;
                    else
                        return false;
                }
                else
                    return false;
    }
    else
        return false;
}
void  Customer::SetDoA(int a, int b, int c)
{
    DoA.SetDate(a, b, c);
}
void  Customer::SetDoD(int a, int b, int c)
{
    DoD.SetDate(a, b, c);
}
      Customer::Customer()
{
    RoomNumber = 0;
    RoomType = '-';//added
}
void  Customer::SetRoomType(char z)
{
    RoomType = z;
}//new added
char  Customer::GetRoomType()
{
    return RoomType;
}//new added
void  Customer::OrderFood()
{
    int x = 0, y = 0;
    float cost;
    do
    {
        { cleardevice();
        setbkcolor(0);
        setcolor(14);
        settextstyle(9, 0, 9);
        outtextxy(175, 60, "RESTAURANT");
        settextstyle(3, 0, 3);
        setcolor(15);
        outtextxy(1150, 50, "Back");
        cout << restaurant;
        }
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << "\nIN ORDER FOOD: " << x << "  " << y << endl;
        ///////////////////////
        if (restaurant.BufStatus())
        {

            if ((x < 305 && x >45) && (y < 275 && y>245))
            {
                cost = restaurant[0];
                CustomerBill + cost;
            }
            if ((x < 305 && x >45) && (y < 325 && y>295))
            {
                cost = restaurant[1];
                CustomerBill + cost;
            }
            if ((x < 305 && x >45) && (y < 375 && y>345))
            {
                cost = restaurant[2];
                CustomerBill + cost;
            }
            if ((x < 305 && x >45) && (y < 425 && y>395))
            {
                cost = restaurant[3];
                CustomerBill + cost;
            }
            if ((x < 305 && x >45) && (y < 475 && y>445))
            {
                cost = restaurant[4];
                CustomerBill + cost;
            }
        }
        ///////////////////////
        if (restaurant.DessertStatus())
        {
            if ((x < 745 && x >495) && (y < 275 && y>245))
            {
                cost = restaurant[5];
                CustomerBill + cost;
            }
            if ((x < 745 && x >495) && (y < 325 && y>295))
            {
                cost = restaurant[6];
                CustomerBill + cost;
            }
            if ((x < 745 && x >495) && (y < 375 && y>345))
            {
                cost = restaurant[7];
                CustomerBill + cost;
            }
            if ((x < 745 && x >495) && (y < 425 && y>395))
            {
                cost = restaurant[8];
                CustomerBill + cost;
            }
            if ((x < 745 && x >495) && (y < 475 && y>445))
            {
                cost = restaurant[9];
                CustomerBill + cost;
            }
        }
        ////////////////////////
        if (restaurant.BarStatus())
        {
            if ((x < 1185 && x >945) && (y < 275 && y>245))
            {
                cost = restaurant[10];
                CustomerBill + cost;
            }
            if ((x < 1185 && x >945) && (y < 325 && y>295))
            {
                cost = restaurant[11];
                CustomerBill + cost;
            }
            if ((x < 1185 && x >945) && (y < 375 && y>345))
            {
                cost = restaurant[12];
                CustomerBill + cost;
            }
            if ((x < 1185 && x >945) && (y < 425 && y>395))
            {
                cost = restaurant[13];
                CustomerBill + cost;
            }
            if ((x < 1185 && x >945) && (y < 475 && y>445))
            {
                cost = restaurant[14];
                CustomerBill + cost;
            }
        }
        //////////////////////////////
        if ((x < 1245 && x>1140) && (y > 45 && y < 75))// Back
        {
            cout << "\nYOUR TOTAL BILL: " << CustomerBill.GetFoodBill() << "\n";
            return;
        }
    } while (1);
}
void  Customer::CheckCurrentExpenditure(int z)
{
    if (z == 1)
    {
        int x = 0, y = 0;
        do
        {
            { cleardevice();
            setbkcolor(0);
            setcolor(14);
            settextstyle(9, 0, 7);
            outtextxy(285, 60, "EXPENDITURES");
            settextstyle(3, 0, 3);
            setcolor(15);
            outtextxy(1150, 50, "Back");
            setcolor(15);
            outtextxy(500, 250, "Room Charges ");
            bgiout << "$" << CustomerBill.GetRoomCharge();
            outstreamxy(750, 250);
            outtextxy(500, 300, "Food Bill ");
            bgiout << "$" << CustomerBill.GetFoodBill();
            outstreamxy(750, 300);
            outtextxy(500, 350, "Arcade");
            bgiout << "$" << CustomerBill.GetArcade();
            outstreamxy(750, 350);
            outtextxy(500, 400, "Service Charges ");
            bgiout << "$" << CustomerBill.GetServiceCharges();
            outstreamxy(750, 400);
            outtextxy(500, 450, "Total");
            bgiout << "$" << CustomerBill.GetTotal();
            outstreamxy(750, 450);
            }
            const int DELAY = 100; // Milliseconds of delay between checks
            while (!ismouseclick(WM_LBUTTONDOWN))
                delay(DELAY);
            getmouseclick(WM_LBUTTONDOWN, x, y);
            cout << "\nIN EXPENDITURES: " << x << "  " << y << endl;
            if ((x < 1245 && x>1140) && (y > 45 && y < 75))// Back
            {
                return;
            }
        } while (1);
    }
    if (z == 2)
    {

        bgiout << "$" << CustomerBill.GetRoomCharge();
        outstreamxy(1080, 420);

        bgiout << "$" << CustomerBill.GetFoodBill();
        outstreamxy(1080, 460);


        bgiout << "$" << CustomerBill.GetTotal();
        outstreamxy(1080, 605);

        bgiout << "$" << CustomerBill.GetArcade();
        outstreamxy(1080, 500);
    }
}
void  Customer::ViewPersonalDetails(int q)
{
    if (q == 1)
    {
        bgiout << GetFname();
        outstreamxy(310, 220);
        bgiout << GetLname();
        outstreamxy(310, 280);
        bgiout << GetGender();
        outstreamxy(310, 340);
        bgiout << DoA.GetDay() << "/" << DoA.GetMonth() << "/" << DoA.GetYear();
        outstreamxy(310, 400);
        bgiout << DoD.GetDay() << "/" << DoD.GetMonth() << "/" << DoD.GetYear();
        outstreamxy(310, 460);
        bgiout << GetFname() << " " << GetLname();
        outstreamxy(310, 520);
    }
    if (q == 2)
    {
        string fname = GetFname();
        string lname = GetLname();
        int x, y;
        ifstream fin("CustomerIDandPassword.txt", ios::app);
        string fn, ln, pw;
        int rn;
        bool login = false;
        while (!fin.eof())
        {
            fin >> rn;
            fin >> fn;
            fin >> ln;
            fin >> pw;


            if (fn == fname && ln == lname)
            {
                login = true;

            }
        }
        fin.close();
        setcolor(YELLOW);
        settextstyle(9, 0, 6);
        outtextxy(280, 96, "USER INFORMATION");
        setcolor(15);
        settextstyle(3, 0, 3);
        setcolor(WHITE);

        outtextxy(1150, 50, "Back");
        outtextxy(490, 220, "Name:");

        outtextxy(490, 280, "Gender:");
        outtextxy(490, 340, "Arrival Date:");
        outtextxy(490, 400, "Account Pin:");
        outtextxy(490, 460, "Room Number:");
        outtextxy(490, 520, "Room Type:");


        bgiout << pw;
        outstreamxy(650, 400);
        bgiout << GetRoomNumber();
        outstreamxy(650, 460);
        char m = GetRoomType();
        if (m == 'L')
        {
            bgiout << "Luxury";
            outstreamxy(650, 520);
        }
        if (m == 'D')
        {
            bgiout << "Delux";
            outstreamxy(650, 520);
        }

        if (m == 'M')
        {
            bgiout << "Moderate";
            outstreamxy(650, 520);
        }

        bgiout << GetFname() << " " << GetLname();
        outstreamxy(650, 220);

        bgiout << GetGender();
        outstreamxy(650, 280);
        bgiout << DoA.GetDay() << "/" << DoA.GetMonth() << "/" << DoA.GetYear();
        outstreamxy(650, 340);

        outtextxy(490, 580, "Total Bill:");
        bgiout << "$" << CustomerBill.GetTotal();
        outstreamxy(650, 580);

        do {
            const int DELAY = 100; // Milliseconds of delay between checks
            while (!ismouseclick(WM_LBUTTONDOWN))
                delay(DELAY);
            getmouseclick(WM_LBUTTONDOWN, x, y);
            cout << x << "  " << y << endl;
            if ((x < 1197 && x>1150) && (y > 54 && y < 70))//back
            {
                cleardevice();
                return;
            }//back

        } while (1);

    }
}
int   Customer::GetRoomNumber()
{
    return RoomNumber;
}
void  Customer::ArcadeScreen()
{
    Arcade * ptr[2];
    ptr[0] = new Hangman;
    ptr[1] = new Game1024;
 
    int x, y;
    do
    {
        { cleardevice();
            setbkcolor(0);
            setcolor(14);
            settextstyle(9, 0, 9);
            outtextxy(475, 60, "Arcade");
            settextstyle(3, 0, 4);
            setcolor(15);
            bgiout << "HangMan";
            outstreamxy(560, 300);
            bgiout << "$5";
            outstreamxy(800, 300);
            bgiout << "1024";
            outstreamxy(600, 500);
            bgiout << "$8";
            outstreamxy(800, 500);
            settextstyle(3, 0, 3);
            outtextxy(1150, 50, "Back"); }

        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << x << "  " << y << endl;
        if ((x < 735 && x>555) && (y > 300 && y < 330))// Hangman
        {
            cleardevice();
            ptr[0]->Play();
            CustomerBill.AddArcade(5);
            delay(4000);
            cleardevice();
            delete ptr[0];
            delete ptr[1];
            setlinestyle(0, 0, 1);
            return;
        }
        if ((x < 690 && x>570) && (y > 500 && y < 525))// 1024
        {
            cleardevice();
            
            ptr[1]->Play();
            CustomerBill.AddArcade(8);
            delay(4000);
            settextjustify(0, 2);
            setlinestyle(0, 2, 1);
            cleardevice();
            delete ptr[0];
            delete ptr[1];
            setlinestyle(0, 0, 1);
            return;
        }
        if ((x < 1245 && x>1140) && (y > 45 && y < 75))// Back
        {
            delete ptr[0];
            delete ptr[1];
            setlinestyle(0, 0, 1);
            return;
        }
    } while (1);
}
void  Customer::SetRoomNumber(int i)
{
    RoomNumber = i;
}
int   Customer::getinvoice()//added
{
    return (CustomerBill.getinvoice());
}
void  Customer::setinvoice(int x)//added
{
    CustomerBill.setinvoice(x);
}
void  Customer::SetRoomCharges()
{
    if(RoomType=='L')
    CustomerBill.SetRoomCharge(4000);
    else if (RoomType == 'M')
    {
        CustomerBill.SetRoomCharge(3000);
    }
    else if (RoomType == 'D')
    {
        CustomerBill.SetRoomCharge(2000);
    }
}
float Customer::GetTotalBillAtCheckOut()
{
    return CustomerBill.GetTotal();
}
Customer::~Customer()
{
    cout << "Customer Destructor Called" << endl;
}