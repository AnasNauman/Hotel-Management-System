#include "Customer.h"
#include <iostream>
#include<cstring>
#include <string>
#include <ctime>
#include <fstream>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int main()
{
    initwindow(1300, 800);                     // Put the machine into graphics mode and get the maximum coordinates
    int  maxx = getmaxx(), maxy = getmaxy();  // Maximum x and y pixel coordinates And Store The Values
    int x, y;                                // Coordinates of the mouse click
    int gdriver = DETECT, gmode, i;         //Drivers Related To Mouse Operational Functions

    customerList = new Customer * [TotalCustomers];
    for (int i = 0; i < TotalCustomers; i++)
    {
        customerList[i] = NULL;
    }
    janitorList = new Janitor * [3];
    waiterList = new Waiter * [3];
    for (int i = 0; i < 3; i++)
    {
        janitorList[i] = NULL;
        waiterList[i] = NULL;
    }
    void wait_for_left_click();
    {
        do {
            const int DELAY = 100; // Milliseconds of delay between checks
          /*  while (!ismouseclick(WM_LBUTTONDOWN))
                   delay(DELAY);*/
            getmouseclick(WM_LBUTTONDOWN, x, y);
            cleardevice();
            MenuDisplay();
            cout << "Latest left click at: " << x << " " << y << endl;
            if ((x < 685 && x>545) && (y > 245 && y < 285))// ADMIN LOGIN PAGE
            {
                setbkcolor(0);
                adminLoginPage();
                continue;
            }
            if ((x < 685 && x>545) && (y > 345 && y < 385))//USER LOGIN PAGE
            {
                setbkcolor(0);
                userLoginPage();
                continue;
            }
            if ((x < 645 && x>585) && (y > 455 && y < 485))//EXIT PROGRAM
            {
                cleardevice();
                setcolor(0);
                settextstyle(9, 0, 9);
                outtextxy(250, 300, "THANK YOU\n\n\n\n\n");
                break;
            }
        } while (1);
    }
    remove("CustomerIDandPassword.txt");

   for (int i = 0; i < TotalCustomers; i++)
    {
        if (customerList[i] != NULL)
        {
            delete customerList[i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (janitorList[i] != NULL)
        {
            delete[] janitorList[i];
        }
        if (waiterList[i] != NULL)
        {
            delete[] waiterList[i];
        }
    }
    delete[] customerList;
    delete[] janitorList;
    delete[] waiterList;
    cout << "Customer List Destroyed"<<endl;
    cout << "Waiter List Destroyed" << endl;
    cout << "Janitor List Destroyed" << endl;
    system("pause");
}
