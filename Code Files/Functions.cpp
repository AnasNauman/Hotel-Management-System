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
extern FinancialIndicator HotelBankAccount;
extern Restaurant restaurant;
extern Customer** customerList;
extern int TotalCustomers, CustomerIndex;
extern Janitor** janitorList;
extern Waiter** waiterList;
extern int  JanitorIndex, Waiterindex;

void CheckOutCustomer()
{
    string fname = "", lname = "", fnameC, lnameC;
    int index = 0, pass, indexC;
    int x, y;
    bool found = false;
    char ch, ch2;
    {
        setbkcolor(0);
        setcolor(14);
        settextstyle(9, 0, 9);
        outtextxy(360, 100, "CHECK OUT");
        settextstyle(3, 0, 3);
        setcolor(15);
        outtextxy(1150, 50, "Back");
        outtextxy(380, 350, "First Name:");
        outtextxy(385, 445, "Last Name:");
        rectangle(490, 345, 930, 380);
        rectangle(490, 440, 930, 475);
        setcolor(WHITE);
        rectangle(670, 570, 770, 600);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(680, 580, WHITE);
        setcolor(RED);
        setbkcolor(15);
        outtextxy(670, 572, "Check Out");
        setbkcolor(0); }
    do
    {
        const int DELAY = 100; 
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << x << "  " << y << endl;
        if ((x < 935 && x >490) && (y < 385 && y>345))
        {
            void flush_input();
            {
                while (kbhit())
                    getch();
            }
            ch = getch();
            while (ch != 13)
            {
                if (ch != 8 && ch != 27)
                {
                    fname.push_back(ch);
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    bgiout << fname;
                    outstreamxy(500, 350);
                }
                if (ch == 8 && ch != 27)
                {
                    if (fname != "")
                        fname.pop_back();
                    cleardevice();
                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 9);
                    outtextxy(360, 100, "CHECK OUT");
                    settextstyle(3, 0, 3);
                    setcolor(15);
                    outtextxy(1150, 50, "Back");
                    outtextxy(380, 350, "First Name:");
                    outtextxy(385, 445, "Last Name:");
                    rectangle(490, 345, 930, 380);
                    rectangle(490, 440, 930, 475);
                    bgiout << fname;
                    outstreamxy(500, 350);
                    setcolor(WHITE);
                    rectangle(670, 570, 770, 600);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(680, 580, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(670, 572, "Check Out");
                    setbkcolor(0);
                }
                ch = getch();
            }
        }
        if ((x < 935 && x >490) && (y < 475 && y>440))
        {
            void flush_input();
            {
                while (kbhit())
                    getch();
            }
            ch2 = getch();
            while (ch2 != 13) 
            {
                if (ch2 != 8 && ch2 != 27)
                {
                    lname.push_back(ch2);
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    bgiout << lname;
                    outstreamxy(500, 445);
                }
                if (ch2 == 8 && ch2 != 27)
                {
                    if (lname != "")
                        lname.pop_back();
                    cleardevice();
                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 9);
                    outtextxy(360, 100, "CHECK OUT");
                    settextstyle(3, 0, 3);
                    setcolor(15);
                    outtextxy(1150, 50, "Back");
                    outtextxy(380, 350, "First Name:");
                    outtextxy(385, 445, "Last Name:");
                    rectangle(490, 345, 930, 380);
                    rectangle(490, 440, 930, 475);
                    bgiout << lname;
                    outstreamxy(500, 445);
                    bgiout << fname;
                    outstreamxy(500, 350);
                    setcolor(WHITE);
                    rectangle(670, 570, 770, 600);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(680, 580, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(670, 572, "Check Out");
                    setbkcolor(0);
                }
                ch2 = getch();
            }
        }
        if ((x < 773 && x>670) && (y > 570 && y < 600) && fname != "" && lname != "")
        {
            ifstream fin("CustomerIDandPassword.txt", ios::app);
            ofstream foutnew("new.txt");
            while (fin >> indexC, fin >> fnameC, fin >> lnameC, fin >> pass)
            {
                bool f1 = true, f2 = true;
                for (int i = 0; fnameC[i] != '\0' || fname[i] != '\0'; i++)
                {
                    if (fnameC[i] != fname[i])
                    {
                        f1 = false;
                        break;
                    }
                }
                for (int i = 0; lnameC[i] != '\0' || lname[i] != '\0'; i++)
                {
                    if (lnameC[i] != lname[i])
                    {
                        f2 = false;
                        break;
                    }
                }
                if (f1 && f2)
                {
                    index = indexC;
                    float a, b;
                    a = (0.9 * customerList[index][0].GetTotalBillAtCheckOut());
                    b = (0.1 * customerList[index][0].GetTotalBillAtCheckOut());
                    HotelBankAccount + a;
                    HotelBankAccount - b;
                    delete  customerList[index];
                    customerList[index] = NULL;
                    CustomerIndex--;
                    found = true;
                    continue;
                }
                foutnew << indexC << " " << fnameC << " " << lnameC << " " << pass << endl;
            }
            if (found)
            {
                setcolor(YELLOW);
                bgiout << "Checked Out Successfully";
                outstreamxy(610, 680);
                setcolor(WHITE);
            }
            else
            {
                setcolor(RED);
                bgiout << "Customer not Found";
                outstreamxy(610, 680);
                setcolor(WHITE);
            }
            foutnew.close();                                     //FIRST CLOSE THEN REMOVE AND RENAME POSSIBLE
            fin.close();                                         //FIRST CLOSE THEN REMOVE AND RENAME POSSIBLE
            remove("CustomerIDandPassword.txt");                 //FIRST CLOSE THEN REMOVE AND RENAME POSSIBLE
            rename("new.txt", "CustomerIDandPassword.txt");
            delay(3000);//FIRST CLOSE THEN REMOVE AND RENAME POSSIBLE
            break;
        }
        if ((x < 1245 && x>1135) && (y > 45 && y < 75))
        {
            cleardevice();
            return;
        }
    } while (1);
}
void customerdetails()
{
    int x = 0, y = 0;
    char ch, ch2;
    string fname = "", lname = "";
    {cleardevice();
    setbkcolor(0);
    cleardevice();
    setcolor(14);
    settextstyle(9, 0, 6);
    outtextxy(330, 100, "CUSTOMER DETAILS");
    setcolor(15);
    settextstyle(3, 0, 3);
    setcolor(WHITE);
    rectangle(660, 420, 770, 455);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(670, 430, WHITE);
    setcolor(RED);
    setbkcolor(15);
    outtextxy(669, 424, "Get Details");
    setbkcolor(0);
    settextstyle(3, 0, 3);
    setcolor(15);
    outtextxy(1150, 50, "Back");
    outtextxy(360, 250, "First Name:");
    outtextxy(360, 345, "Last Name:");
    rectangle(490, 245, 930, 280);
    rectangle(490, 340, 930, 375); }
    do
    {
        const int DELAY = 100; 
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << x << "  " << y << endl;

        if ((x < 935 && x >495) && (y < 285 && y>255))// USER ID 
        {
            void flush_input();
            {
                while (kbhit())
                    getch();
            }
            ch = getch();
            while (ch != 13)
            {
                if (ch != 8 && ch != 27)
                {
                    fname.push_back(ch);
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    bgiout << fname;
                    outstreamxy(500, 250);
                }
                if (ch == 8 && ch != 27)
                {
                    if (fname != "")
                        fname.pop_back();
                    cleardevice();
                    setcolor(WHITE);
                    rectangle(660, 420, 770, 455);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(670, 430, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(669, 424, "Get Details");
                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 6);
                    outtextxy(330, 100, "CUSTOMER DETAILS");
                    settextstyle(3, 0, 3);
                    setcolor(15);
                    outtextxy(1150, 50, "Back");
                    outtextxy(360, 250, "First Name:");
                    outtextxy(360, 345, "Last Name:");
                    rectangle(490, 245, 930, 280);
                    rectangle(490, 340, 930, 375);
                    bgiout << fname;
                    outstreamxy(500, 250);
                    bgiout << lname;
                    outstreamxy(500, 346);
                }
                ch = getch();
            }
        }
        if ((x < 935 && x >495) && (y < 375 && y>345))
        {
            void flush_input();
            {
                while (kbhit())
                    getch();
            }
            ch2 = getch();
            while (ch2 != 13)
            {
                if (ch2 != 8)
                {
                    lname.push_back(ch2);
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    bgiout << lname;
                    outstreamxy(500, 346);
                }
                if (ch2 == 8)
                {
                    if (lname != "")
                        lname.pop_back();
                    cleardevice();
                    setcolor(WHITE);
                    rectangle(660, 420, 770, 455);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(670, 430, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(669, 424, "Get Details");
                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 6);
                    outtextxy(330, 100, "CUSTOMER DETAILS");
                    settextstyle(3, 0, 3);
                    setcolor(15);
                    outtextxy(1150, 50, "Back");
                    outtextxy(360, 250, "First Name:");
                    outtextxy(360, 345, "Last Name:");
                    rectangle(490, 245, 930, 280);
                    rectangle(490, 340, 930, 375);
                    bgiout << fname;
                    outstreamxy(500, 250);
                    bgiout << lname;
                    outstreamxy(500, 346);
                }
                ch2 = getch();
            }
        }
        if ((x < 1245 && x>1135) && (y > 45 && y < 75))//back
        {
            cleardevice();
            return;
        }//back
        if ((x < 770 && x>660) && (y > 420 && y < 455))
        {
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
                    break;
                }
            }
            fin.close();

            if (login)
            {
                cleardevice();
                setcolor(YELLOW);
                settextstyle(9, 0, 6);
                outtextxy(140, 25, "CUSTOMER INFORMATION");
                setcolor(15);
                settextstyle(3, 0, 3);
                setcolor(WHITE);
                rectangle(120, 125, 560, 760);
                rectangle(740, 125, 1180, 760);
                setcolor(YELLOW);
                outtextxy(263, 140, "Customer Details");
                outtextxy(896, 140, "Customer Invoice");
                setcolor(15);
                outtextxy(1150, 50, "Back");
                outtextxy(150, 220, "First Name:");
                outtextxy(150, 280, "Last Name:");
                outtextxy(150, 340, "Gender:");
                outtextxy(150, 400, "Arrival Date:");
                outtextxy(150, 460, "Depature Date:");
                outtextxy(150, 520, "Account Name:");
                outtextxy(150, 580, "Account Pin:");
                outtextxy(150, 640, "Room Number:");
                outtextxy(150, 700, "Room Type:");
                customerList[rn]->ViewPersonalDetails(1);
                bgiout << pw;
                outstreamxy(310, 580);
                bgiout << customerList[rn]->GetRoomNumber();
                outstreamxy(310, 640);
                char m = customerList[rn]->GetRoomType();
                if (m == 'L')
                {
                    bgiout << "Luxury";
                    outstreamxy(310, 700);
                }
                if (m == 'D')
                {
                    bgiout << "Delux";
                    outstreamxy(310, 700);
                }
                if (m == 'M')
                {
                    bgiout << "Moderate";
                    outstreamxy(310, 700);
                }
                time_t t = time(NULL);
                tm* tPtr = localtime(&t);
                bgiout << "Bill To:";
                outstreamxy(770, 190);
                bgiout << "Invoice No:";
                outstreamxy(970, 230);
                bgiout << "Due Date:";
                outstreamxy(970, 270);
                bgiout << "Time:";
                outstreamxy(970, 310);
                bgiout << fname << " " << lname;
                outstreamxy(840, 190);
                bgiout << customerList[rn]->getinvoice();
                outstreamxy(1080, 230);
                bgiout << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900;
                outstreamxy(1080, 270);
                bgiout << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << ":" << (tPtr->tm_sec);
                outstreamxy(1080, 310);
                bgiout << "Description";
                outstreamxy(780, 360);
                bgiout << "Amount";
                outstreamxy(1075, 360);
                bgiout << "Room Charges";
                outstreamxy(780, 420);
                bgiout << "$";
                outstreamxy(1080, 420);
                bgiout << "Food Charges";
                outstreamxy(780, 460);
                bgiout << "$";
                outstreamxy(1080, 460);
                bgiout << "Acrade Charges";
                outstreamxy(780, 500);
                bgiout << "$";
                outstreamxy(1080, 500);
                bgiout << "Service Charges";
                outstreamxy(910, 530);
                bgiout << "$150";
                outstreamxy(1080, 530);
                bgiout << "Total";
                outstreamxy(910, 605);
                bgiout << "$";
                outstreamxy(1080, 605);
                customerList[rn]->CheckCurrentExpenditure(2);
                setcolor(YELLOW);
                bgiout << "Thanks for visiting CandleWood Suites";
                outstreamxy(790, 690);
                setcolor(RED);
                line(740, 580, 1180, 580);
                line(740, 650, 1180, 650);
                setcolor(15);
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
            else if (fname == "" || lname == "")
            {
                setcolor(RED);
                bgiout << "Empty";
                outstreamxy(675, 600);
                setcolor(15);
            }
            else
            {
                setcolor(RED);
                bgiout << "Incorrect!";
                outstreamxy(675, 600);
                setcolor(15);
            }
        }
    } while (1);
}
//////////////////////////////////////////////////////////////////////
void CheckInCustomer()
{
    int x, y;
    string fname = "";
    string lname = "";
    string gender = "";
    string DOA = "";
    string DOD = "";
    int count = 0, count2 = 0;
    int mm, yyyy, dd, mmd, yyyyd, ddd;
    string date, month, year;
    char ch, ch2;
    bool found = true, found2 = true, found3 = true, founddate = false, founddate2 = false;
    srand(time(0));
    if (CustomerIndex >= TotalCustomers)
    {
        setcolor(RED);
        settextstyle(9, 0, 7);
        outtextxy(90, 245, "HOTEL IS FULLY BOOKED");
        setcolor(WHITE);
        settextstyle(3, 0, 3);
        outtextxy(523, 355, "CANNOT CREATE THE ACCOUNT");
        setcolor(WHITE);
        delay(4000);
    }
    else
    {
        int findEmptyIndex = 0, pass = 0;
        for (int i = 0; i < TotalCustomers; i++)
        {
            if (customerList[i] == NULL)
            {
                customerList[i] = new Customer;
                findEmptyIndex = i;
                break;
            }
        }
        {setbkcolor(0);
        setcolor(14);
        settextstyle(9, 0, 9);
        outtextxy(360, 100, "CHECK IN");
        settextstyle(3, 0, 3);
        setcolor(15);
        outtextxy(1150, 50, "Back");
        outtextxy(58, 245, "First Name:");
        outtextxy(58, 345, "Last Name:");
        outtextxy(90, 445, "Gender:");
        outtextxy(55, 545, "Arrival Date:");
        outtextxy(28, 645, "Depature Date:");
        outtextxy(650, 245, "Room Type:");
        outtextxy(790, 245, "Luxury:");
        outtextxy(950, 245, "Moderate:");
        outtextxy(1140, 245, "Delux:");
        rectangle(170, 240, 540, 280);
        rectangle(170, 340, 540, 380);
        rectangle(170, 440, 540, 480);
        rectangle(170, 540, 540, 580);
        rectangle(170, 640, 540, 680);
        rectangle(863, 245, 895, 269);
        rectangle(1047, 245, 1077, 269);
        rectangle(1202, 245, 1233, 269);
        setcolor(WHITE);
        rectangle(630, 715, 720, 745);
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(640, 720, WHITE);
        setcolor(RED);
        setbkcolor(15);
        outtextxy(643, 718, "Create");
        setbkcolor(0); }
        do
        {
            const int DELAY = 100; // Milliseconds of delay between checks
            while (!ismouseclick(WM_LBUTTONDOWN))
                delay(DELAY);
            getmouseclick(WM_LBUTTONDOWN, x, y);
            cout << x << "  " << y << endl;
            if ((x < 540 && x >170) && (y > 250 && y < 280))
            {
                void flush_input();
                {
                    while (kbhit())
                        getch();
                }
                ch = getch();
                while (ch != 13) 
                {
                    if (ch != 8 && ch != 27)
                    {
                        fname.push_back(ch);
                        setcolor(15);
                        settextstyle(3, 0, 3);
                        bgiout << fname;
                        outstreamxy(180, 248);
                    }
                    if (ch == 8 && ch != 27)
                    {
                        if (fname != "")
                            fname.pop_back();
                        cleardevice();
                        setbkcolor(0);
                        setcolor(14);
                        settextstyle(9, 0, 9);
                        outtextxy(360, 100, "CHECK IN");
                        settextstyle(3, 0, 3);
                        setcolor(15);
                        outtextxy(1150, 50, "Back");
                        outtextxy(58, 245, "First Name:");
                        outtextxy(58, 345, "Last Name:");
                        outtextxy(90, 445, "Gender:");
                        outtextxy(55, 545, "Arrival Date:");
                        outtextxy(28, 645, "Depature Date:");
                        outtextxy(650, 245, "Room Type:");
                        outtextxy(790, 245, "Luxury:");
                        outtextxy(950, 245, "Moderate:");
                        outtextxy(1140, 245, "Delux:");
                        rectangle(170, 240, 540, 280);
                        rectangle(170, 340, 540, 380);
                        rectangle(170, 440, 540, 480);
                        rectangle(170, 540, 540, 580);
                        rectangle(170, 640, 540, 680);
                        rectangle(863, 245, 895, 269);
                        rectangle(1047, 245, 1077, 269);
                        rectangle(1202, 245, 1233, 269);
                        if (found == 1 && found2 == 0 && found3 == 0)
                        {
                            setcolor(RED);
                            rectangle(863, 245, 895, 269);
                            setfillstyle(SOLID_FILL, RED);
                            floodfill(869, 250, RED);
                        }
                        else if (found == 0 && found2 == 1 && found3 == 0)
                        {
                            setcolor(YELLOW);
                            rectangle(1047, 245, 1077, 269);
                            setfillstyle(SOLID_FILL, YELLOW);
                            floodfill(1063, 250, YELLOW);
                        }
                        else if (found == 0 && found2 == 0 && found3 == 1)
                        {
                            setcolor(GREEN);
                            rectangle(1202, 245, 1233, 269);
                            setfillstyle(SOLID_FILL, GREEN);
                            floodfill(1218, 250, GREEN);
                        }
                        {
                            if (DOD == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 702);
                            }
                            else if ((count2 < 8 || count2 > 10) || !founddate2)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 702);
                            }
                            if (DOA == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 602);
                            }

                            else if ((count < 8 || count > 10) || !founddate)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 602);
                            }
                            if (fname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 302);
                            }
                            if (lname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 402);
                            }
                            if (gender == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 502);
                            }
                            if (found == 1 && found2 == 1 && found3 == 1)
                            {
                                setcolor(RED);
                                bgiout << "Option not Selected";
                                outstreamxy(946, 302);
                            }
                        }
                        setcolor(WHITE);
                        rectangle(630, 715, 720, 745);
                        setfillstyle(SOLID_FILL, WHITE);
                        floodfill(640, 720, WHITE);
                        setcolor(RED);
                        setbkcolor(15);
                        outtextxy(643, 718, "Create");
                        setbkcolor(0);
                        setcolor(15);
                        bgiout << fname;
                        outstreamxy(180, 248);
                        bgiout << lname;
                        outstreamxy(180, 348);
                        bgiout << gender;
                        outstreamxy(180, 448);
                        bgiout << DOA;
                        outstreamxy(180, 548);
                        bgiout << DOD;
                        outstreamxy(180, 648);
                        outtextxy(650, 245, "Room Type:");
                        outtextxy(790, 245, "Luxury:");
                        outtextxy(950, 245, "Moderate:");
                        outtextxy(1140, 245, "Delux:");
                        rectangle(863, 245, 895, 269);
                        rectangle(1047, 245, 1077, 269);
                        rectangle(1202, 245, 1233, 269);
                    }
                    ch = getch();
                }
            }
            if ((x < 540 && x >170) && (y > 350 && y < 380))
            {
                void flush_input();
                {
                    while (kbhit())
                        getch();
                }
                ch2 = getch();
                while (ch2 != 13) 
                {
                    if (ch2 != 8 && ch2 != 27)
                    {
                        lname.push_back(ch2);
                        setcolor(15);
                        settextstyle(3, 0, 3);
                        bgiout << lname;
                        outstreamxy(180, 348);
                    }
                    if (ch2 == 8 && ch2 != 27)
                    {
                        if (lname != "")
                            lname.pop_back();
                        cleardevice();
                        setbkcolor(0);
                        setcolor(14);
                        settextstyle(9, 0, 9);
                        outtextxy(360, 100, "CHECK IN");
                        settextstyle(3, 0, 3);
                        setcolor(15);
                        outtextxy(1150, 50, "Back");
                        outtextxy(58, 245, "First Name:");
                        outtextxy(58, 345, "Last Name:");
                        outtextxy(90, 445, "Gender:");
                        outtextxy(55, 545, "Arrival Date:");
                        outtextxy(28, 645, "Depature Date:");
                        rectangle(863, 245, 895, 269);
                        rectangle(1047, 245, 1077, 269);
                        rectangle(1202, 245, 1233, 269);
                        outtextxy(650, 245, "Room Type:");
                        outtextxy(790, 245, "Luxury:");
                        outtextxy(950, 245, "Moderate:");
                        outtextxy(1140, 245, "Delux:");
                        rectangle(170, 240, 540, 280);
                        rectangle(170, 340, 540, 380);
                        rectangle(170, 440, 540, 480);
                        rectangle(170, 540, 540, 580);
                        rectangle(170, 640, 540, 680);
                        if (found == 1 && found2 == 0 && found3 == 0)
                        {
                            setcolor(RED);
                            rectangle(863, 245, 895, 269);
                            setfillstyle(SOLID_FILL, RED);
                            floodfill(869, 250, RED);
                        }
                        else if (found == 0 && found2 == 1 && found3 == 0)
                        {
                            setcolor(YELLOW);
                            rectangle(1047, 245, 1077, 269);
                            setfillstyle(SOLID_FILL, YELLOW);
                            floodfill(1063, 250, YELLOW);
                        }
                        else if (found == 0 && found2 == 0 && found3 == 1)
                        {
                            setcolor(GREEN);
                            rectangle(1202, 245, 1233, 269);
                            setfillstyle(SOLID_FILL, GREEN);
                            floodfill(1218, 250, GREEN);
                        }
                        {
                            if (DOD == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 702);
                            }
                            else if ((count2 < 8 || count2 > 10) || !founddate2)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 702);
                            }
                            if (DOA == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 602);
                            }

                            else if ((count < 8 || count > 10) || !founddate)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 602);
                            }
                            if (fname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 302);
                            }
                            if (lname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 402);
                            }
                            if (gender == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 502);
                            }
                            if (found == 1 && found2 == 1 && found3 == 1)
                            {
                                setcolor(RED);
                                bgiout << "Option not Selected";
                                outstreamxy(946, 302);
                            }
                        }
                        setcolor(WHITE);
                        rectangle(630, 715, 720, 745);
                        setfillstyle(SOLID_FILL, WHITE);
                        floodfill(640, 720, WHITE);
                        setcolor(RED);
                        setbkcolor(15);
                        outtextxy(643, 718, "Create");
                        setbkcolor(0);
                        setcolor(15);
                        bgiout << fname;
                        outstreamxy(180, 248);
                        bgiout << lname;
                        outstreamxy(180, 348);
                        bgiout << gender;
                        outstreamxy(180, 448);
                        bgiout << DOA;
                        outstreamxy(180, 548);
                        bgiout << DOD;
                        outstreamxy(180, 648);
                    }
                    ch2 = getch();
                }
            }
            if ((x < 540 && x >170) && (y > 450 && y < 480))
            {
                void flush_input();
                {
                    while (kbhit())
                        getch();
                }
                ch = getch();
                while (ch != 13) 
                {
                    if (ch != 8 && ch != 27)
                    {
                        gender.push_back(ch);
                        setcolor(15);
                        settextstyle(3, 0, 3);
                        bgiout << gender;
                        outstreamxy(180, 448);
                    }
                    if (ch == 8 && ch != 27)
                    {
                        if (gender != "")
                            gender.pop_back();
                        cleardevice();
                        setbkcolor(0);
                        setcolor(14);
                        settextstyle(9, 0, 9);
                        outtextxy(360, 100, "CHECK IN");
                        settextstyle(3, 0, 3);
                        setcolor(15);
                        outtextxy(1150, 50, "Back");
                        outtextxy(58, 245, "First Name:");
                        outtextxy(58, 345, "Last Name:");
                        outtextxy(90, 445, "Gender:");
                        outtextxy(55, 545, "Arrival Date:");
                        outtextxy(28, 645, "Depature Date:");
                        rectangle(863, 245, 895, 269);
                        rectangle(1047, 245, 1077, 269);
                        rectangle(1202, 245, 1233, 269);
                        outtextxy(650, 245, "Room Type:");
                        outtextxy(790, 245, "Luxury:");
                        outtextxy(950, 245, "Moderate:");
                        outtextxy(1140, 245, "Delux:");
                        rectangle(170, 240, 540, 280);
                        rectangle(170, 340, 540, 380);
                        rectangle(170, 440, 540, 480);
                        rectangle(170, 540, 540, 580);
                        rectangle(170, 640, 540, 680);
                        if (found == 1 && found2 == 0 && found3 == 0)
                        {
                            setcolor(RED);
                            rectangle(863, 245, 895, 269);
                            setfillstyle(SOLID_FILL, RED);
                            floodfill(869, 250, RED);
                        }
                        else if (found == 0 && found2 == 1 && found3 == 0)
                        {
                            setcolor(YELLOW);
                            rectangle(1047, 245, 1077, 269);
                            setfillstyle(SOLID_FILL, YELLOW);
                            floodfill(1063, 250, YELLOW);
                        }
                        else if (found == 0 && found2 == 0 && found3 == 1)
                        {
                            setcolor(GREEN);
                            rectangle(1202, 245, 1233, 269);
                            setfillstyle(SOLID_FILL, GREEN);
                            floodfill(1218, 250, GREEN);
                        }
                        {
                            if (DOD == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 702);
                            }
                            else if ((count2 < 8 || count2 > 10) || !founddate2)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 702);
                            }
                            if (DOA == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 602);
                            }
                            else if ((count < 8 || count > 10) || !founddate)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 602);
                            }
                            if (fname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 302);
                            }
                            if (lname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 402);
                            }
                            if (gender == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 502);
                            }
                            if (found == 1 && found2 == 1 && found3 == 1)
                            {
                                setcolor(RED);
                                bgiout << "Option not Selected";
                                outstreamxy(946, 302);
                            }
                        }
                        setcolor(WHITE);
                        rectangle(630, 715, 720, 745);
                        setfillstyle(SOLID_FILL, WHITE);
                        floodfill(640, 720, WHITE);
                        setcolor(RED);
                        setbkcolor(15);
                        outtextxy(643, 718, "Create");
                        setbkcolor(0);
                        setcolor(15);
                        bgiout << fname;
                        outstreamxy(180, 248);
                        bgiout << lname;
                        outstreamxy(180, 348);
                        bgiout << gender;
                        outstreamxy(180, 448);
                        bgiout << DOA;
                        outstreamxy(180, 548);
                        bgiout << DOD;
                        outstreamxy(180, 648);
                    }
                    ch = getch();
                }
            }
            if ((x < 540 && x >170) && (y > 550 && y < 580))
            {
                void flush_input();
                {
                    while (kbhit())
                        getch();
                }
                ch = getch();
                while (ch != 13) 
                {
                    if (ch != 8 && ch != 27)
                    {
                        DOA.push_back(ch);
                        setcolor(15);
                        settextstyle(3, 0, 3);
                        bgiout << DOA;
                        outstreamxy(180, 548);
                    }
                    if (ch == 8 && ch != 27)
                    {
                        if (DOA != "")
                            DOA.pop_back();
                        cleardevice();
                        setbkcolor(0);
                        setcolor(14);
                        settextstyle(9, 0, 9);
                        outtextxy(360, 100, "CHECK IN");
                        settextstyle(3, 0, 3);
                        setcolor(15);
                        outtextxy(1150, 50, "Back");
                        outtextxy(58, 245, "First Name:");
                        outtextxy(58, 345, "Last Name:");
                        outtextxy(90, 445, "Gender:");
                        outtextxy(55, 545, "Arrival Date:");
                        outtextxy(28, 645, "Depature Date:");
                        rectangle(863, 245, 895, 269);
                        rectangle(1047, 245, 1077, 269);
                        rectangle(1202, 245, 1233, 269);
                        outtextxy(650, 245, "Room Type:");
                        outtextxy(790, 245, "Luxury:");
                        outtextxy(950, 245, "Moderate:");
                        outtextxy(1140, 245, "Delux:");
                        rectangle(170, 240, 540, 280);
                        rectangle(170, 340, 540, 380);
                        rectangle(170, 440, 540, 480);
                        rectangle(170, 540, 540, 580);
                        rectangle(170, 640, 540, 680);
                        if (found == 1 && found2 == 0 && found3 == 0)
                        {
                            setcolor(RED);
                            rectangle(863, 245, 895, 269);//luxury added
                            setfillstyle(SOLID_FILL, RED);
                            floodfill(869, 250, RED);
                        }
                        else if (found == 0 && found2 == 1 && found3 == 0)
                        {
                            setcolor(YELLOW);
                            rectangle(1047, 245, 1077, 269);
                            setfillstyle(SOLID_FILL, YELLOW);
                            floodfill(1063, 250, YELLOW);
                        }
                        else if (found == 0 && found2 == 0 && found3 == 1)
                        {
                            setcolor(GREEN);
                            rectangle(1202, 245, 1233, 269);
                            setfillstyle(SOLID_FILL, GREEN);
                            floodfill(1218, 250, GREEN);
                        }
                        {
                            if (DOD == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 702);
                            }
                            else if ((count2 < 8 || count2 > 10) || !founddate2)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 702);
                            }
                            if (DOA == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 602);
                            }

                            else if ((count < 8 || count > 10) || !founddate)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 602);
                            }
                            if (fname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 302);
                            }
                            if (lname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 402);
                            }
                            if (gender == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 502);
                            }
                            if (found == 1 && found2 == 1 && found3 == 1)
                            {
                                setcolor(RED);
                                bgiout << "Option not Selected";
                                outstreamxy(946, 302);
                            }
                        }
                        setcolor(WHITE);
                        rectangle(630, 715, 720, 745);
                        setfillstyle(SOLID_FILL, WHITE);
                        floodfill(640, 720, WHITE);
                        setcolor(RED);
                        setbkcolor(15);
                        outtextxy(643, 718, "Create");
                        setbkcolor(0);
                        setcolor(15);
                        bgiout << fname;
                        outstreamxy(180, 248);
                        bgiout << lname;
                        outstreamxy(180, 348);
                        bgiout << gender;
                        outstreamxy(180, 448);
                        bgiout << DOA;
                        outstreamxy(180, 548);
                        bgiout << DOD;
                        outstreamxy(180, 648);
                    }

                    ch = getch();
                }
            }
            if ((x < 540 && x >170) && (y > 650 && y < 680))
            {
                void flush_input();
                {
                    while (kbhit())
                        getch();
                }
                ch = getch();
                while (ch != 13)
                {
                    if (ch != 8 && ch != 27)
                    {
                        DOD.push_back(ch);
                        setcolor(15);
                        settextstyle(3, 0, 3);
                        bgiout << DOD;
                        outstreamxy(180, 648);
                    }
                    if (ch == 8 && ch != 27)
                    {
                        if (DOD != "")
                            DOD.pop_back();
                        cleardevice();
                        setbkcolor(0);
                        setcolor(14);
                        settextstyle(9, 0, 9);
                        outtextxy(360, 100, "CHECK IN");
                        settextstyle(3, 0, 3);
                        setcolor(15);
                        outtextxy(1150, 50, "Back");
                        outtextxy(58, 245, "First Name:");
                        outtextxy(58, 345, "Last Name:");
                        outtextxy(90, 445, "Gender:");
                        outtextxy(55, 545, "Arrival Date:");
                        outtextxy(28, 645, "Depature Date:");
                        rectangle(863, 245, 895, 269);
                        rectangle(1047, 245, 1077, 269);
                        rectangle(1202, 245, 1233, 269);
                        outtextxy(650, 245, "Room Type:");
                        outtextxy(790, 245, "Luxury:");
                        outtextxy(950, 245, "Moderate:");
                        outtextxy(1140, 245, "Delux:");
                        rectangle(170, 240, 540, 280);
                        rectangle(170, 340, 540, 380);
                        rectangle(170, 440, 540, 480);
                        rectangle(170, 540, 540, 580);
                        rectangle(170, 640, 540, 680);
                        if (found == 1 && found2 == 0 && found3 == 0)
                        {
                            setcolor(RED);
                            rectangle(863, 245, 895, 269);
                            setfillstyle(SOLID_FILL, RED);
                            floodfill(869, 250, RED);
                        }
                        else if (found == 0 && found2 == 1 && found3 == 0)
                        {
                            setcolor(YELLOW);
                            rectangle(1047, 245, 1077, 269);
                            setfillstyle(SOLID_FILL, YELLOW);
                            floodfill(1063, 250, YELLOW);
                        }
                        else if (found == 0 && found2 == 0 && found3 == 1)
                        {
                            setcolor(GREEN);
                            rectangle(1202, 245, 1233, 269);
                            setfillstyle(SOLID_FILL, GREEN);
                            floodfill(1218, 250, GREEN);
                        }
                        {
                            if (DOD == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 702);
                            }
                            else if ((count2 < 8 || count2 > 10) || !founddate2)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 702);
                            }
                            if (DOA == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 602);
                            }

                            else if ((count < 8 || count > 10) || !founddate)
                            {
                                setcolor(RED);
                                bgiout << "Incorrect";
                                outstreamxy(447, 602);
                            }
                            if (fname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 302);
                            }
                            if (lname == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 402);
                            }
                            if (gender == "")
                            {
                                setcolor(RED);
                                bgiout << "Empty";
                                outstreamxy(447, 502);
                            }
                            if (found == 1 && found2 == 1 && found3 == 1)
                            {
                                setcolor(RED);
                                bgiout << "Option not Selected";
                                outstreamxy(946, 302);
                            }
                        }
                        setcolor(WHITE);
                        rectangle(630, 715, 720, 745);
                        setfillstyle(SOLID_FILL, WHITE);
                        floodfill(640, 720, WHITE);
                        setcolor(RED);
                        setbkcolor(15);
                        outtextxy(643, 718, "Create");
                        setbkcolor(0);
                        setcolor(15);
                        bgiout << fname;
                        outstreamxy(180, 248);
                        bgiout << lname;
                        outstreamxy(180, 348);
                        bgiout << gender;
                        outstreamxy(180, 448);
                        bgiout << DOA;
                        outstreamxy(180, 548);
                        bgiout << DOD;
                        outstreamxy(180, 648);
                    }
                    ch = getch();
                }
            }
            if ((x < 720 && x >630) && (y > 715 && y < 745))
            {
                cleardevice();
                {
                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 9);
                    outtextxy(360, 100, "CHECK IN");
                    settextstyle(3, 0, 3);
                    setcolor(15);
                    outtextxy(1150, 50, "Back");
                    outtextxy(58, 245, "First Name:");
                    outtextxy(58, 345, "Last Name:");
                    outtextxy(90, 445, "Gender:");
                    outtextxy(55, 545, "Arrival Date:");
                    outtextxy(28, 645, "Depature Date:");
                    rectangle(863, 245, 895, 269);
                    rectangle(1047, 245, 1077, 269);
                    rectangle(1202, 245, 1233, 269);
                    outtextxy(650, 245, "Room Type:");
                    outtextxy(790, 245, "Luxury:");
                    outtextxy(950, 245, "Moderate:");
                    rectangle(170, 240, 540, 280);
                    rectangle(170, 340, 540, 380);
                    rectangle(170, 440, 540, 480);
                    rectangle(170, 540, 540, 580);
                    rectangle(170, 640, 540, 680);
                    if (found == 1 && found2 == 0 && found3 == 0)
                    {
                        setcolor(RED);
                        rectangle(863, 245, 895, 269);
                        setfillstyle(SOLID_FILL, RED);
                        floodfill(869, 250, RED);
                    }
                    else if (found == 0 && found2 == 1 && found3 == 0)
                    {
                        setcolor(YELLOW);
                        rectangle(1047, 245, 1077, 269);
                        setfillstyle(SOLID_FILL, YELLOW);
                        floodfill(1063, 250, YELLOW);
                    }
                    else if (found == 0 && found2 == 0 && found3 == 1)
                    {
                        setcolor(GREEN);
                        rectangle(1202, 245, 1233, 269);
                        setfillstyle(SOLID_FILL, GREEN);
                        floodfill(1218, 250, GREEN);
                    }
                    setcolor(WHITE);
                    rectangle(630, 715, 720, 745);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(640, 720, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(643, 718, "Create");
                    setbkcolor(0);
                    setcolor(15);
                    bgiout << fname;
                    outstreamxy(180, 248);
                    bgiout << lname;
                    outstreamxy(180, 348);
                    bgiout << gender;
                    outstreamxy(180, 448);
                    bgiout << DOA;
                    outstreamxy(180, 548);
                    bgiout << DOD;
                    outstreamxy(180, 648);
                }
                count = 0, founddate = false, founddate2 = false, count2 = 0;
                for (int i = 0; DOA[i] != '\0'; i++)
                    count++;
                if (count == 10 || count == 8 || count == 9)
                {
                    char m[3], d[3], y[5];
                    int i, j;
                    for (i = 0; DOA[i] != '/'; i++)
                        m[i] = DOA[i];
                    i++;
                    for (j = 0; DOA[i] != '/'; i++, j++) {
                        d[j] = DOA[i];
                    }
                    i++;
                    for (j = 0; DOA[i] != '\0'; i++, j++)
                        y[j] = DOA[i];
                    mm = atoi(m);
                    dd = atoi(d);
                    yyyy = atoi(y);
                    cout << mm << "/" << dd << "/" << yyyy;
                    founddate = CheckDate(mm, dd, yyyy);
                    cout << founddate;
                }
                for (int i = 0; DOD[i] != '\0'; i++)
                    count2++;
                if (count2 == 10 || count2 == 8 || count2 == 9)
                {
                    char m[3], d[3], y[5];
                    int i, j;
                    for (i = 0; DOD[i] != '/'; i++)
                        m[i] = DOD[i];
                    i++;
                    for (i = 3, j = 0; DOD[i] != '/'; i++, j++) {
                        d[j] = DOD[i];
                    }
                    i++;
                    for (i = 6, j = 0; DOD[i] != '\0'; i++, j++)
                        y[j] = DOD[i];

                    mmd = atoi(m);
                    ddd = atoi(d);
                    yyyyd = atoi(y);
                    founddate2 = CheckDate(mmd, ddd, yyyyd);
                }
                if (DOD == "")
                {
                    setcolor(RED);
                    bgiout << "Empty";
                    outstreamxy(447, 702);
                }
                else if ((count2 < 8 || count2 > 10) || !founddate2)
                {
                    setcolor(RED);
                    bgiout << "Incorrect";
                    outstreamxy(447, 702);
                }
                if (DOA == "")
                {
                    setcolor(RED);
                    bgiout << "Empty";
                    outstreamxy(447, 602);
                }
                else if ((count < 8 || count > 10) || !founddate)
                {
                    setcolor(RED);
                    bgiout << "Incorrect";
                    outstreamxy(447, 602);
                }
                if (fname == "")
                {
                    setcolor(RED);
                    bgiout << "Empty";
                    outstreamxy(447, 302);
                }
                if (lname == "")
                {
                    setcolor(RED);
                    bgiout << "Empty";
                    outstreamxy(447, 402);
                }
                if (gender == "")
                {
                    setcolor(RED);
                    bgiout << "Empty";
                    outstreamxy(447, 502);
                }
                if (found == 1 && found2 == 1 && found3 == 1)
                {
                    setcolor(RED);
                    bgiout << "Option not Selected";
                    outstreamxy(946, 302);
                }
                if ((founddate && founddate2) && ((found && !found2 && !found3) || (!found && found2 && !found3) || (!found && !found2 && found3)) && fname != "" && lname != "" && gender != "")
                {
                    cleardevice();
                    customerList[findEmptyIndex]->SetDoA(mm, dd, yyyy);
                    customerList[findEmptyIndex]->SetDoD(mmd, ddd, yyyyd);
                    customerList[findEmptyIndex]->SetName(fname, lname, gender);
                    customerList[findEmptyIndex]->SetRoomNumber(findEmptyIndex + 1);
                    customerList[findEmptyIndex]->SetRoomCharges();
                    int invoice = (rand() % 99999) + 999;//added
                    customerList[findEmptyIndex]->setinvoice(invoice);//added
                    pass = (rand() % 99999) + 999;
                    setcolor(RED);
                    settextstyle(9, 0, 7);
                    outtextxy(90, 245, "Account Created Successfully");
                    setcolor(WHITE);
                    settextstyle(3, 0, 3);
                    outtextxy(500, 400, "Account Password:");
                    setcolor(WHITE);
                    outtextxy(540, 500, "Room Number:");
                    setcolor(YELLOW);
                    bgiout << pass;
                    outstreamxy(700, 400);
                    bgiout << findEmptyIndex + 1;
                    outstreamxy(700, 500);
                    delay(3000);
                    setcolor(15);
                    cleardevice();
                    break;
                }
            }
            if ((x < 1245 && x>1135) && (y > 45 && y < 75))
            {
                return;
            }
            if ((x < 895 && x>863) && (y > 246 && y < 269) && found)
            {
                setcolor(RED);
                rectangle(863, 245, 895, 269);
                setfillstyle(SOLID_FILL, RED);
                floodfill(869, 250, RED);
                found2 = false, found3 = false;
                customerList[findEmptyIndex]->SetRoomType('L');
            }
            if ((x < 1078 && x>1048) && (y > 244 && y < 269) && found2)
            {
                setcolor(YELLOW);
                rectangle(1047, 245, 1077, 269);
                setfillstyle(SOLID_FILL, YELLOW);
                floodfill(1063, 250, YELLOW);
                found = false, found3 = false;
                customerList[findEmptyIndex]->SetRoomType('M');
            }
            if ((x < 1234 && x>1202) && (y > 244 && y < 269) && found3)
            {
                setcolor(GREEN);
                rectangle(1202, 245, 1233, 269);
                setfillstyle(SOLID_FILL, GREEN);
                floodfill(1218, 250, GREEN);
                found = false, found2 = false;
                customerList[findEmptyIndex]->SetRoomType('D');
            }
        } while (1);
        ofstream fout("CustomerIDandPassword.txt", ios::app);
        fout << endl;
        fout << findEmptyIndex << " " << fname << " " << lname << " " << pass;
        cout << fname << " " << lname << endl << "Your Password Is: " << pass;
        fout.close();
        CustomerIndex++;
    }
}
void RoomAvailability()
{
    int x = 0, y = 0;
    cleardevice();
    do
    {
        setcolor(YELLOW);
        settextstyle(9, 0, 9);
        outtextxy(30, 45, "MAP");
        settextstyle(3, 0, 3);
        setcolor(15);
        outtextxy(1150, 50, "Back");
        setcolor(WHITE);
        rectangle(280, 300, 440, 610);
        setcolor(2);
        rectangle(30, 197, 60, 228);
        setfillstyle(SOLID_FILL, 2);
        floodfill(40, 202, 2);
        setcolor(4);
        rectangle(30, 261, 60, 290);
        setfillstyle(SOLID_FILL, 4);
        floodfill(40, 269, 4);
        setcolor(1);
        rectangle(30, 325, 60, 352);
        setfillstyle(SOLID_FILL, 1);
        floodfill(40, 329, 1);
        setcolor(8);
        rectangle(30, 389, 60, 417);
        setfillstyle(SOLID_FILL, 8);
        floodfill(40, 395, 8);
        setcolor(15);
        outtextxy(82, 202, "Available");
        outtextxy(82, 266, "Not Available");
        outtextxy(82, 330, "Pool");
        outtextxy(82, 394, "Sports");
        outtextxy(312, 262, "Restaurant");
        outtextxy(312, 318, "Bar");
        outtextxy(312, 402, "Buffet");
        outtextxy(312, 492, "Deserts");
        outtextxy(652, 110, "Rooms");
        outtextxy(500, 192, "R1");
        outtextxy(500, 263, "R2");
        outtextxy(500, 329, "R3");
        outtextxy(500, 404, "R4");
        outtextxy(500, 473, "R5");
        outtextxy(720, 192, "R6");
        outtextxy(720, 263, "R7");
        outtextxy(720, 329, "R8");
        outtextxy(720, 404, "R9");
        outtextxy(710, 473, "R10");
        outtextxy(950, 266, "Sports Yard");
        outtextxy(652, 575, "Pool");
        setcolor(8);
        rectangle(909, 299, 1074, 560);
        setfillstyle(SOLID_FILL, 8);
        floodfill(915, 320, 8);
        setcolor(1);
        rectangle(510, 610, 850, 740);
        setfillstyle(SOLID_FILL, 1);
        floodfill(520, 620, 1);
        setcolor(2);
        rectangle(312, 343, 406, 398);
        setfillstyle(SOLID_FILL, 2);
        floodfill(320, 353, 2);
        setcolor(2);
        rectangle(312, 427, 406, 482);
        setfillstyle(SOLID_FILL, 2);
        floodfill(320, 435, 2);
        setcolor(2);
        rectangle(312, 518, 406, 570);
        setfillstyle(SOLID_FILL, 2);
        floodfill(320, 525, 2);
        if (customerList[0] == NULL)
        {
            setcolor(2);
            rectangle(530, 165, 616, 235);
            setfillstyle(SOLID_FILL, 2);
            floodfill(540, 175, 2);
        }
        else
        {
            setcolor(4);
            rectangle(530, 165, 616, 235);
            setfillstyle(SOLID_FILL, 4);
            floodfill(540, 175, 4);
        }
        if (customerList[1] == NULL)
        {
            setcolor(2);
            rectangle(530, 238, 616, 305);
            setfillstyle(SOLID_FILL, 2);
            floodfill(540, 245, 2);
        }
        else
        {
            setcolor(4);
            rectangle(530, 238, 616, 305);
            setfillstyle(SOLID_FILL, 4);
            floodfill(540, 245, 4);
        }
        if (customerList[2] == NULL)
        {
            setcolor(2);
            rectangle(530, 309, 616, 375);
            setfillstyle(SOLID_FILL, 2);
            floodfill(540, 315, 2);
        }
        else
        {
            setcolor(4);
            rectangle(530, 309, 616, 375);
            setfillstyle(SOLID_FILL, 4);
            floodfill(540, 315, 4);
        }

        if (customerList[3] == NULL)
        {
            setcolor(2);
            rectangle(530, 379, 616, 445);//r4
            setfillstyle(SOLID_FILL, 2);
            floodfill(540, 382, 2);
        }
        else
        {
            setcolor(4);
            rectangle(530, 379, 616, 445);//r4
            setfillstyle(SOLID_FILL, 4);
            floodfill(540, 382, 4);
        }
        if (customerList[4] == NULL)
        {
            setcolor(2);
            rectangle(530, 448, 616, 515);//r5
            setfillstyle(SOLID_FILL, 2);
            floodfill(540, 454, 2);
        }
        else
        {
            setcolor(4);
            rectangle(530, 448, 616, 515);//r5
            setfillstyle(SOLID_FILL, 4);
            floodfill(540, 454, 4);
        }

        if (customerList[5] == NULL)
        {
            setcolor(2);
            rectangle(750, 165, 836, 235);//r6
            setfillstyle(SOLID_FILL, 2);
            floodfill(760, 170, 2);
        }
        else
        {
            setcolor(4);
            rectangle(750, 165, 836, 235);//r6
            setfillstyle(SOLID_FILL, 4);
            floodfill(760, 170, 4);
        }
        if (customerList[6] == NULL)
        {
            setcolor(2);
            rectangle(750, 238, 836, 305);//r7
            setfillstyle(SOLID_FILL, 2);
            floodfill(760, 245, 2);
        }
        else
        {
            setcolor(4);
            rectangle(750, 238, 836, 305);//r7
            setfillstyle(SOLID_FILL, 4);
            floodfill(760, 245, 4);
        }

        if (customerList[7] == NULL)
        {
            setcolor(2);
            rectangle(750, 309, 836, 375);//r8
            setfillstyle(SOLID_FILL, 2);
            floodfill(760, 315, 2);
        }
        else
        {
            setcolor(4);
            rectangle(750, 309, 836, 375);//r8
            setfillstyle(SOLID_FILL, 4);
            floodfill(760, 315, 4);
        }
        if (customerList[8] == NULL)
        {
            setcolor(2);
            rectangle(750, 379, 836, 445);//r9
            setfillstyle(SOLID_FILL, 2);
            floodfill(760, 385, 2);
        }
        else
        {
            setcolor(4);
            rectangle(750, 379, 836, 445);//r9
            setfillstyle(SOLID_FILL, 4);
            floodfill(760, 385, 4);
        }
        if (customerList[9] == NULL)
        {
            setcolor(2);
            rectangle(750, 448, 836, 515);//r10
            setfillstyle(SOLID_FILL, 2);
            floodfill(760, 455, 2);
        }
        else
        {
            setcolor(4);
            rectangle(750, 448, 836, 515);//r10
            setfillstyle(SOLID_FILL, 4);
            floodfill(760, 455, 4);
        }


        if (restaurant.BufStatus())
        {
            setcolor(2);
            rectangle(312, 427, 406, 482);//buffy
            setfillstyle(SOLID_FILL, 2);
            floodfill(320, 435, 2);
        }
        else
        {
            setcolor(4);
            rectangle(312, 427, 406, 482);//buffy
            setfillstyle(SOLID_FILL, 4);
            floodfill(320, 435, 4);
        }

        if (restaurant.DessertStatus())
        {
            setcolor(2);
            rectangle(312, 518, 406, 570);//deserts
            setfillstyle(SOLID_FILL, 2);
            floodfill(320, 525, 2);
        }
        else
        {
            setcolor(4);
            rectangle(312, 518, 406, 570);//deserts
            setfillstyle(SOLID_FILL, 4);
            floodfill(320, 525, 4);
        }

        if (restaurant.BarStatus())
        {
            setcolor(2);
            rectangle(312, 343, 406, 398);//bar
            setfillstyle(SOLID_FILL, 2);
            floodfill(320, 353, 2);
        }
        else
        {
            setcolor(4);
            rectangle(312, 343, 406, 398);//bar
            setfillstyle(SOLID_FILL, 4);
            floodfill(320, 353, 4);
        }
        if ((x < 1245 && x>1135) && (y > 45 && y < 75))//back
        {
            cleardevice();
            return;
        }
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << x << "  " << y << endl;
    } while (1);
}
void RestaurantManagement()
{
    int x, y;
    do
    {
        {setcolor(14);
        settextstyle(9, 0, 5);
        outtextxy(260, 80, "RESTAURANT MANAGEMENT");
        settextstyle(3, 0, 3);
        bgiout << "BUFFET";
        outstreamxy(80, 200);
        bgiout << "DESSERT";
        outstreamxy(520, 200);
        bgiout << "BAR";
        outstreamxy(1000, 200);
        setcolor(15);
        bgiout << "ADD Halloumi Fries";
        outstreamxy(50, 250);
        bgiout << "DELETE Halloumi Fries";
        outstreamxy(50, 300);
        bgiout << "CLOSE BUFFET";
        outstreamxy(50, 400);
        bgiout << "OPEN BUFFET";
        outstreamxy(50, 450);
        bgiout << "ADD Turkish Delight";
        outstreamxy(500, 250);
        bgiout << "DELETE Turkish Delight";
        outstreamxy(500, 300);
        bgiout << "CLOSE DESSERT";
        outstreamxy(500, 400);
        bgiout << "OPEN DESSERT";
        outstreamxy(500, 450);
        bgiout << "ADD Bourgogne Wine";
        outstreamxy(950, 250);
        bgiout << "DELETE Bourgogne Wine";
        outstreamxy(950, 300);
        bgiout << "CLOSE BAR";
        outstreamxy(950, 400);
        bgiout << "OPEN BAR";
        outstreamxy(950, 450);
        outtextxy(1150, 50, "Back"); }
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << x << "  " << y << endl;
        if ((x < 220 && x>50) && (y > 250 && y < 270))
        {
            restaurant + "Halloumi Fries";
            cleardevice();
        }
        if ((x < 260 && x>50) && (y > 300 && y < 320))
        {
            restaurant - "Halloumi Fries";
            cleardevice();
        }
        if ((x < 685 && x>500) && (y > 250 && y < 270))
        {
            restaurant + "Turkish Delight";
            cleardevice();
        }
        if ((x < 720 && x>500) && (y > 300 && y < 320))
        {
            restaurant - "Turkish Delight";
            cleardevice();
        }
        if ((x < 1150 && x>950) && (y > 250 && y < 270))
        {
            restaurant + "Bourgogne Wine";
            cleardevice();
        }
        if ((x < 1180 && x>950) && (y > 300 && y < 320))
        {
            restaurant - "Bourgogne Wine";
            cleardevice();
        }

        if ((x < 205 && x>50) && (y > 400 && y < 420))
        {
            restaurant - "Buffet";
            cleardevice();
        }
        if ((x < 190 && x>50) && (y > 450 && y < 470))
        {
            restaurant + "Buffet";
            cleardevice();
        }
        if ((x < 675 && x>500) && (y > 400 && y < 420))
        {
            restaurant - "Dessert";
            cleardevice();
        }
        if ((x < 660 && x>500) && (y > 450 && y < 470))
        {
            restaurant + "Dessert";
            cleardevice();
        }
        if ((x < 1070 && x>950) && (y > 400 && y < 420))
        {
            restaurant - "Bar";
            cleardevice();
        }
        if ((x < 1055 && x>950) && (y > 450 && y < 470))
        {
            restaurant + "Bar";
            cleardevice();
        }
        if ((x < 1245 && x>1140) && (y > 45 && y < 75))// BACK
        {
            return;
        }
    } while (1);
}
void HotelFinances()
{
    int x, y;
    do
    {
        { setcolor(14);
        settextstyle(9, 0, 9);
        outtextxy(290, 60, "Hotel Finances");
        settextstyle(3, 0, 3);
        setcolor(15);
        bgiout << "Hotel Balance";
        outstreamxy(560, 200);
        bgiout << "Total Expenditures";
        outstreamxy(545, 300);
        bgiout << "Total Profits";
        outstreamxy(560, 400);
        bgiout << "Financial Indicator";
        outstreamxy(545, 500);
        outtextxy(1150, 50, "Back"); }
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << x << "  " << y << endl;
        if ((x < 680 && x>555) && (y > 200 && y < 220))// Hotel Balance
        {
            cleardevice();
            HotelBankAccount.ViewHoteBalance();
            cleardevice();
        }
        if ((x < 710 && x>535) && (y > 295 && y < 320))// Total Expenditures
        {
            cleardevice();
            HotelBankAccount.ViewTotalExpenditures();
            cleardevice();

        }
        if ((x < 660 && x>545) && (y > 395 && y < 420))// Total Profits
        {
            cleardevice();
            HotelBankAccount.ViewTotalProfits();
            cleardevice();
        }
        if ((x < 705 && x>535) && (y > 495 && y < 520))// Financial Indicator
        {
            cleardevice();
            HotelBankAccount.ViewFinancialIndicators();
            cleardevice();
        }
        if ((x < 1245 && x>1140) && (y > 45 && y < 75))// Back
        {
            return;
        }
    } while (1);
}
void EmployeeManagement()
{
    int xx, yy;
    cleardevice();
    do {
        {setcolor(14);
        settextstyle(9, 0, 5);
        outtextxy(395, 60, "Employee Management");
        settextstyle(3, 0, 3);
        setcolor(15);
        outstreamxy(530, 700);
        outtextxy(1150, 50, "Back");
        bgiout << "HIRE Janitor ";
        outstreamxy(350, 200);
        bgiout << "FIRE Janitor";
        outstreamxy(350, 300);
        bgiout << "PAY Janitor Salary";
        outstreamxy(320, 400);
        bgiout << "HIRE Waiter";
        outstreamxy(800, 200);
        bgiout << "FIRE Waiter";
        outstreamxy(800, 300);
        bgiout << "PAY Waiter Salary";
        outstreamxy(780, 400); }
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, xx, yy);
        cout << xx << "  " << yy << endl;
        if ((xx < 465 && xx>350) && (yy > 200 && yy < 220))//HIRE JANITOR
        {
            if (JanitorIndex >= 3)
            {
                settextstyle(3, 0, 3);
                setcolor(2);
                outtextxy(550, 630, "All Janitors Hired");
                delay(500);
                cleardevice();
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    if (janitorList[i] == NULL && i == 0)
                    {
                        janitorList[JanitorIndex] = new  Janitor("Alexander", "Anderson", "Male", 23, "101-102-103");
                        JanitorIndex++;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Janitor Hired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                    else if (janitorList[i] == NULL && i == 1)
                    {
                        janitorList[JanitorIndex] = new Janitor("Matthew", "Smith", "Male", 25, "104-105-106");
                        JanitorIndex++;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Janitor Hired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                    else if (janitorList[i] == NULL && i == 2)
                    {
                        janitorList[JanitorIndex] = new  Janitor("Christine", "Bell", "Female", 26, "107-108-109");
                        JanitorIndex++;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Janitor Hired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                }
            }
        }
        if ((xx < 465 && xx>350) && (yy > 300 && yy < 320))//FIRE JANITOR
        {
            if (JanitorIndex == 0)
            {
                settextstyle(3, 0, 3);
                setcolor(2);
                outtextxy(550, 630, "All Janitors Fired");
                delay(500);
                cleardevice();
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    if (janitorList[i] != NULL && i == 0)
                    {
                        delete janitorList[i];
                        janitorList[i] = NULL;
                        JanitorIndex--;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Janitor Fired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                    else if (janitorList[i] != NULL && i == 1)
                    {
                        delete janitorList[i];
                        janitorList[i] = NULL;
                        JanitorIndex--;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Janitor Fired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                    else if (janitorList[i] != NULL && i == 2)
                    {
                        delete janitorList[i];
                        janitorList[i] = NULL;
                        JanitorIndex--;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Janitor Fired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                }
            }
        }
        if ((xx < 910 && xx>800) && (yy > 200 && yy < 220))//HIRE WAITER
        {
            if (Waiterindex >= 3)
            {
                settextstyle(3, 0, 3);
                setcolor(2);
                outtextxy(550, 630, "All Waiters Hired");
                delay(500);
                cleardevice();
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    if (waiterList[i] == NULL && i == 0)
                    {
                        waiterList[Waiterindex] = new  Waiter("Marcus", "Jason", "Male", 23, "110-111-112");
                        Waiterindex++;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Waitor Hired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                    else if (waiterList[i] == NULL && i == 1)
                    {
                        waiterList[Waiterindex] = new Waiter("Ollie", "Parkinson", "Male", 23, "113-114-115");
                        Waiterindex++;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Waiter Hired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                    else if (waiterList[i] == NULL && i == 2)
                    {
                        waiterList[Waiterindex] = new  Waiter("Anabelle", "Palmer", "Female", 23, "116-117-118");
                        Waiterindex++;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Waiter Hired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                }
            }
        }
        if ((xx < 910 && xx>800) && (yy > 300 && yy < 320))//FIRE WAITER
        {
            if (Waiterindex == 0)
            {
                settextstyle(3, 0, 3);
                setcolor(2);
                outtextxy(550, 630, "All Waiters Fired");
                delay(500);
                cleardevice();
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    if (waiterList[i] != NULL && i == 0)
                    {
                        delete waiterList[i];
                        waiterList[i] = NULL;
                        Waiterindex--;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Waiter Fired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                    else if (waiterList[i] != NULL && i == 1)
                    {
                        delete waiterList[i];
                        waiterList[i] = NULL;
                        Waiterindex--;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Waiter Fired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                    else if (waiterList[i] != NULL && i == 2)
                    {
                        delete waiterList[i];
                        waiterList[i] = NULL;
                        Waiterindex--;
                        settextstyle(3, 0, 3);
                        setcolor(2);
                        outtextxy(570, 630, "Waiter Fired");
                        delay(500);
                        cleardevice();
                        break;
                    }
                }
            }
        }
        if ((xx < 490 && xx>320) && (yy > 400 && yy < 420))// PAY JANITOR
        {
            if (JanitorIndex != 0)
            {
                float payjanitor = janitorList[0]->GetTotalPay(JanitorIndex);
                HotelBankAccount - payjanitor;
                settextstyle(3, 0, 3);
                setcolor(2);
                outtextxy(590, 630, "Paid Janitors");
                delay(500);
                cleardevice();
            }
            else
            {
                settextstyle(3, 0, 3);
                setcolor(2);
                outtextxy(560, 630, "No Janitors To Pay");
                delay(500);
                cleardevice();
            }
        }
        if ((xx < 945 && xx>780) && (yy > 400 && yy < 420))// PAY WAITER
        {
            if (Waiterindex != 0)
            {
                float paywaiter = waiterList[0]->GetTotalPay(Waiterindex);
                HotelBankAccount - paywaiter;
                settextstyle(3, 0, 3);
                setcolor(2);
                outtextxy(590, 630, "Paid Waiters");
                delay(500);
                cleardevice();
            }
            else
            {
                settextstyle(3, 0, 3);
                setcolor(2);
                outtextxy(560, 630, "No Waiters To Pay");
                delay(500);
                cleardevice();
            }
        }
        if ((xx < 725 && xx>560) && (yy > 603 && yy < 626))
        {
            int xxx, yyy;
            cleardevice();
            outstreamxy(530, 700);
            outtextxy(1150, 50, "Back");
            do {
                while (!ismouseclick(WM_LBUTTONDOWN))
                    delay(DELAY);
                getmouseclick(WM_LBUTTONDOWN, xxx, yyy);
                cout << xxx << "  " << yyy << endl;
                if ((xxx < 1245 && xxx>1140) && (yyy > 45 && yyy < 75))// Back
                {
                    cleardevice();
                    break;
                }
            } while (1);
        }
        if ((xx < 720 && xx>560) && (yy > 704 && yy < 725))
        {
            int xxx, yyy;
            cleardevice();
            outstreamxy(530, 700);
            outtextxy(1150, 50, "Back");
            do {
                while (!ismouseclick(WM_LBUTTONDOWN))
                    delay(DELAY);
                getmouseclick(WM_LBUTTONDOWN, xxx, yyy);
                cout << xxx << "  " << yyy << endl;
                if ((xxx < 1245 && xxx>1140) && (yyy > 45 && yyy < 75))// Back
                {
                    cleardevice();
                    break;
                }
            } while (1);
        }
        if ((xx < 1245 && xx>1140) && (yy > 45 && yy < 75))// Back
        {
            cleardevice();
            break;
        }
    } while (1);
}
void adminmenu()
{
    int x, y;
    do
    {
        { setcolor(14);
        settextstyle(9, 0, 9);
        outtextxy(500, 60, "Menu");
        settextstyle(3, 0, 3);
        setcolor(15);
        bgiout << "CHECKIN CUSTOMER";
        outstreamxy(160, 200);
        bgiout << "CHECKOUT CUSTOMER";
        outstreamxy(148, 300);
        bgiout << "CUSTOMER DETAILS";
        outstreamxy(160, 400);
        bgiout << "ROOM AVAILABLITY";
        outstreamxy(165, 500);
        bgiout << "RESTAURANT MANAGEMENT";
        outstreamxy(750, 200);
        bgiout << "HOTEL FINANCES";
        outstreamxy(800, 300);
        bgiout << "EMPLOYEE MANAGEMENT";
        outstreamxy(765, 400);
        outtextxy(1150, 50, "LOGOUT"); }
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << x << "  " << y << endl;
        if ((x < 380 && x>165) && (y > 200 && y < 220))// CHECKIN CUSTOMER
        {
            cleardevice();
            CheckInCustomer();
            cleardevice();
        }
        if ((x < 390 && x>140) && (y > 295 && y < 320))// CHECKOUT CUSTOMER
        {
            cleardevice();
            CheckOutCustomer();
            cleardevice();
        }
        if ((x < 370 && x>160) && (y > 395 && y < 420))// CUSTOMER DETAILS
        {
            cleardevice();
            customerdetails();
            cleardevice();
        }
        if ((x < 365 && x>165) && (y > 495 && y < 520))// ROOM AVAILABILITY
        {
            cleardevice();
            RoomAvailability();
            cleardevice();
        }
        if ((x < 1040 && x>750) && (y > 200 && y < 220))// Restaurant Management
        {
            cleardevice();
            RestaurantManagement();
            cleardevice();
        }
        if ((x < 970 && x>800) && (y > 295 && y < 320))// Hotel Finances
        {
            cleardevice();
            HotelFinances();
            cleardevice();
        }
        if ((x < 1025 && x>760) && (y > 395 && y < 420))// Employee Management
        {
            cleardevice();
            EmployeeManagement();
            cleardevice();
        }
        if ((x < 1245 && x>1140) && (y > 45 && y < 75))// LOGOUT
        {
            return;
        }
    } while (1);
}
//////////////////////////////////////////////////////////////////////
void adminLoginPage()
{
    int x, y, yt = 500, count = 0;
    string id = "", pass = "";
    char ch, ch2;
    { setbkcolor(0);
    cleardevice();
    setcolor(14);
    settextstyle(9, 0, 9);
    outtextxy(200, 100, "ADMIN PORTAL");
    setcolor(15);
    settextstyle(3, 0, 3);
    outtextxy(1150, 50, "Back");
    outtextxy(400, 250, "Admin Id: ");
    outtextxy(390, 345, "Password: ");
    rectangle(490, 245, 930, 280);
    rectangle(490, 340, 930, 375);
    setcolor(WHITE);
    rectangle(660, 420, 740, 450);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(670, 430, WHITE);
    setcolor(RED);
    setbkcolor(15);
    outtextxy(675, 420, "Login");
    setbkcolor(0);
    }
    do
    {
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << "In ADMIN Latest left click at: " << x << " " << y << endl;
        if ((x < 935 && x >495) && (y < 285 && y>255))// ADMIN ID 
        {
            void flush_input();
            {
                while (kbhit())
                    getch();
            }
            ch = getch();
            while (ch != 13)
            {//character 13 is enter
                if (ch != 8 && ch != 27)
                {
                    id.push_back(ch);
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    bgiout << id;
                    outstreamxy(500, 250);
                }
                if (ch == 8 && ch != 27)
                {
                    if (id != "")
                        id.pop_back();
                    cleardevice();
                    setcolor(WHITE);
                    rectangle(660, 420, 740, 450);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(670, 430, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(675, 420, "Login");
                    setbkcolor(0);
                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 9);
                    outtextxy(200, 100, "ADMIN PORTAL");
                    settextstyle(3, 0, 3);
                    setcolor(15);
                    outtextxy(1150, 50, "Back");
                    outtextxy(400, 250, "Admin Id:");
                    outtextxy(390, 345, "Password:");
                    rectangle(490, 245, 930, 280);
                    rectangle(490, 340, 930, 375);
                    bgiout << id;
                    outstreamxy(500, 250);
                    yt = 500;
                    for (int i = 0; i < count; i++)
                    {
                        bgiout << "* ";
                        outstreamxy(yt, 350);
                        yt += 10;
                    }
                }
                ch = getch();
            }
        }
        if ((x < 935 && x >495) && (y < 375 && y>345))//ADMIN PASSWORD
        {
            void flush_input();
            {
                while (kbhit())
                    getch();
            }
            ch2 = getch();
            while (ch2 != 13)
            {//character 13 is enter
                if (ch2 != 8)
                {
                    pass.push_back(ch2);
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    bgiout << "* ";
                    count++;
                    outstreamxy(yt, 350);
                    yt += 10;
                }
                if (ch2 == 8)
                {
                    if (pass != "")
                        pass.pop_back();
                    cleardevice();
                    setcolor(WHITE);
                    rectangle(660, 420, 740, 450);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(670, 430, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(675, 420, "Login");
                    setbkcolor(0);
                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 9);
                    outtextxy(200, 100, "ADMIN PORTAL");
                    settextstyle(3, 0, 3);
                    setcolor(15);
                    outtextxy(1150, 50, "Back");
                    outtextxy(400, 250, "Admin Id:");
                    outtextxy(390, 345, "Password:");
                    rectangle(490, 245, 930, 280);
                    rectangle(490, 340, 930, 375);
                    bgiout << id;
                    outstreamxy(500, 250);
                    yt = 500;
                    count--;
                    for (int i = 0; i < count; i++)
                    {
                        bgiout << "* ";
                        outstreamxy(yt, 350);
                        yt += 10;
                    }
                }
                ch2 = getch();
            }
        }
        if ((x < 740 && x>660) && (y > 420 && y < 450))
        {
            if (pass == "admin" && id == "admin")
            {
                cleardevice();
                adminmenu();
                cleardevice();
                return;
            }
            else if (pass == "" && id == "")
            {
                setcolor(RED);
                bgiout << "Empty";
                outstreamxy(675, 600);
                setcolor(15);
            }
            else
            {
                setcolor(RED);
                bgiout << "Incorrect!";
                outstreamxy(675, 600);
                setcolor(15);
            }
        }
        if ((x < 1245 && x>1135) && (y > 45 && y < 75))
        {
            return;
        }
    } while (1);
}
//////////////////////////////////////////////////////////////////////
void userMenu(int customerRoomNumber)
{
    int x, y;
    do
    {
        {
            cleardevice();
            setbkcolor(0);
            setcolor(14);
            settextstyle(9, 0, 9);
            outtextxy(500, 60, "Menu");
            settextstyle(3, 0, 3);
            setcolor(15);
            bgiout << "ORDER FOOD";
            outstreamxy(570, 200);
            bgiout << "VIEW EXPENDITURES";
            outstreamxy(535, 300);
            bgiout << "VIEW PERSONAL DETAILS";
            outstreamxy(510, 400);
            bgiout << "ARCADE";
            outstreamxy(600, 500);
            outtextxy(1150, 50, "LOGOUT");
        }
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << x << "  " << y << endl;
        if ((x < 780 && x>555) && (y > 200 && y < 220))// Order Food
        {
            cleardevice();
            customerList[customerRoomNumber][0].OrderFood();
            cleardevice();

        }
        if ((x < 780 && x>535) && (y > 295 && y < 320))// Check Current Expenditure
        {
            cleardevice();
            customerList[customerRoomNumber][0].CheckCurrentExpenditure(1);
            cleardevice();

        }
        if ((x < 770 && x>555) && (y > 395 && y < 420))// Personal Details
        {
            cleardevice();
            customerList[customerRoomNumber][0].ViewPersonalDetails(2);
            cleardevice();
        }
        if ((x < 695 && x>595) && (y > 495 && y < 525))// ARCADE
        {
            cleardevice();
            customerList[customerRoomNumber][0].ArcadeScreen();
            cleardevice();
        }
        if ((x < 1245 && x>1140) && (y > 45 && y < 75))// LOGOUT
        {
            return;
        }

    } while (1);
}
void userLoginPage()
{
    int x, y, yt = 500, count = 0;
    string id = "", pass = "";
    char ch, ch2;
    {setbkcolor(0);
    cleardevice();
    setcolor(14);
    settextstyle(9, 0, 9);
    outtextxy(200, 100, "USER PORTAL");
    setcolor(15);
    settextstyle(3, 0, 3);
    outtextxy(1150, 50, "Back");
    outtextxy(400, 250, "User Id: ");
    outtextxy(390, 345, "Password: ");
    rectangle(490, 245, 930, 280);
    rectangle(490, 340, 930, 375);
    setcolor(WHITE);
    rectangle(660, 420, 740, 450);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(670, 430, WHITE);
    setcolor(RED);
    setbkcolor(15);
    outtextxy(675, 420, "Login");
    setbkcolor(0);
    }
    do
    {
        const int DELAY = 100; // Milliseconds of delay between checks
        while (!ismouseclick(WM_LBUTTONDOWN))
            delay(DELAY);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        cout << "In USER LOGIN left click at: " << x << " " << y << endl;
        if ((x < 935 && x >495) && (y < 285 && y>255))// USER ID 
        {
            void flush_input();
            {
                while (kbhit())
                    getch();
            }
            ch = getch();
            while (ch != 13)
            {
                if (ch != 8 && ch != 27)
                {
                    id.push_back(ch);
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    bgiout << id;
                    outstreamxy(500, 250);
                }
                if (ch == 8 && ch != 27)
                {
                    if (id != "")
                        id.pop_back();
                    cleardevice();
                    setcolor(WHITE);
                    rectangle(660, 420, 740, 450);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(670, 430, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(675, 420, "Login");
                    setbkcolor(0);

                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 9);
                    outtextxy(200, 100, "USER PORTAL");
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    outtextxy(1150, 50, "Back");
                    outtextxy(400, 250, "User Id: ");
                    outtextxy(390, 345, "Password: ");
                    rectangle(490, 245, 930, 280);
                    rectangle(490, 340, 930, 375);
                    bgiout << id;
                    outstreamxy(500, 250);
                    yt = 500;
                    for (int i = 0; i < count; i++)
                    {
                        bgiout << "* ";
                        outstreamxy(yt, 350);
                        yt += 10;
                    }
                }
                ch = getch();
            }
        }
        if ((x < 935 && x >495) && (y < 375 && y>345))//USER PASSWORD
        {
            void flush_input();
            {
                while (kbhit())
                    getch();
            }
            ch2 = getch();
            while (ch2 != 13)
            {
                if (ch2 != 8)
                {
                    pass.push_back(ch2);
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    bgiout << "* ";
                    count++;
                    outstreamxy(yt, 350);
                    yt += 10;
                }
                if (ch2 == 8)
                {
                    if (pass != "")
                        pass.pop_back();
                    cleardevice();
                    setcolor(WHITE);
                    rectangle(660, 420, 740, 450);
                    setfillstyle(SOLID_FILL, WHITE);
                    floodfill(670, 430, WHITE);
                    setcolor(RED);
                    setbkcolor(15);
                    outtextxy(675, 420, "Login");
                    setbkcolor(0);
                    setbkcolor(0);
                    setcolor(14);
                    settextstyle(9, 0, 9);
                    outtextxy(200, 100, "USER PORTAL");
                    setcolor(15);
                    settextstyle(3, 0, 3);
                    outtextxy(1150, 50, "Back");
                    outtextxy(400, 250, "User Id: ");
                    outtextxy(390, 345, "Password: ");
                    rectangle(490, 245, 930, 280);
                    rectangle(490, 340, 930, 375);
                    bgiout << id;
                    outstreamxy(500, 250);
                    yt = 500;
                    count--;
                    for (int i = 0; i < count; i++)
                    {
                        bgiout << "* ";
                        outstreamxy(yt, 350);
                        yt += 10;
                    }
                }
                ch2 = getch();
            }
        }
        if ((x < 740 && x>660) && (y > 420 && y < 450))
        {
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
                fn = fn + " ";
                fn.append(ln);
                if (fn == id && pass == pw)
                {
                    login = true;
                    break;
                }
            }
            fin.close();
            if (login)
            {
                cleardevice();
                userMenu(rn);
                cleardevice();
                return;
            }
            else if (pass == "" && id == "")
            {
                setcolor(RED);
                bgiout << "Empty";
                outstreamxy(675, 600);
                setcolor(15);
            }
            else
            {
                setcolor(RED);
                bgiout << "Incorrect!";
                outstreamxy(675, 600);
                setcolor(15);
            }
        }
        if ((x < 1245 && x>1135) && (y > 45 && y < 75))
        {
            return;
        }
    } while (1);

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
        fn = fn + " ";
        fn.append(ln);
        if (fn == id && pass == pw)
        {
            login = true;
            break;
        }
    }
    fin.close();
    if (login)
    {
        cout << "Login Succesful";
        cout << endl << "fn: " << fn << endl << "id: " << id << endl << "pass: " << endl << "pw: " << pw;
        userMenu(rn);
        return;
    }
    else
    {
        cout << "Incorrect login";
        return;
    }
}
//////////////////////////////////////////////////////////////////////
void MenuDisplay()
{
    setbkcolor(15);
    settextstyle(1, 0, 8);
    setcolor(5);
    outtextxy(130, 100, "CandleWood Suites");
    setcolor(4);
    settextstyle(3, 0, 3);
    outtextxy(550, 250, "ADMIN LOGIN");
    outtextxy(550, 350, "USER LOGIN");
    outtextxy(590, 460, "EXIT");
    delay(500);
}