#include "Restaurant.h"
#include "Customer.h"
#include "Arcade.h"
#include <iostream>
#include<cstring>
#include <string>
#include <ctime>
#include <fstream>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
Buffet::~Buffet()
{
    cout << size;
    for (int i = 0; i < size; i++)
    {
        delete[] dish[i];
    }
    delete[]dish;
    delete[]price;
    dish = NULL;
    price = NULL;
    cout << "Heelo zain ";
}
float  Buffet::operator[](int val)
{
    if (dish[val] != NULL)
    {
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "ORDER PLACED");
        delay(500);
        return price[val];
    }
}
Buffet::Buffet()
{
    size = 5;
    dish = new char* [size];
    for (int i = 0; i < size; i++)
    {
        dish[i] = new char[50];
    }
    char d0[] = "Barbeque Drumstick";
    int s0 = strlen(d0);
    char d1[] = "Mutton Karahi";
    int s1 = strlen(d1);
    char d2[] = "Mexican Pasta";
    int s2 = strlen(d2);
    char d3[] = "Beef Teppanyaki";
    int s3 = strlen(d3);
    for (int j = 0; j < s0; j++)
    {
        dish[0][j] = d0[j];
    }
    dish[0][s0] = '\0';

    for (int j = 0; j < s1; j++)
    {
        dish[1][j] = d1[j];
    }
    dish[1][s1] = '\0';

    for (int j = 0; j < s2; j++)
    {
        dish[2][j] = d2[j];
    }
    dish[2][s2] = '\0';

    for (int j = 0; j < s3; j++)
    {
        dish[3][j] = d3[j];
    }
    dish[3][s3] = '\0';
    dish[4] = 0;
    price = new float[size];
    float rs = 100.0;
    for (int i = 0; i < size; i++)
    {
        price[i] = rs;
        rs += 100.0;
    }
}
Buffet& Buffet::operator+(string newdish)
{
    if (dish[4] == NULL)
    {
        int s = 0;
        for (s = 0; newdish[s] != '\0'; s++)
        {
        }
        dish[4] = new char[s + 1];
        for (int j = 0; j < s; j++)
        {
            dish[4][j] = newdish[j];
        }
        dish[4][s] = '\0';
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "BUFFET ADDED");
        delay(500);
    }
    else
    {
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "BUFFET ALREADY EXISTS");
        delay(500);
    }

    return *this;
}
Buffet& Buffet::operator-(int index)
{
    settextstyle(3, 0, 3);
    setcolor(2);
    if (dish[index] == NULL)
    {
        outtextxy(520, 630, "No Buffet Exists");
        delay(500);
        return *this;
    }
    if (dish[index] != NULL)
    {
        delete[] dish[index];
        dish[index] = NULL;
        outtextxy(520, 630, "BUFFET Deleted");
        delay(500);
        return *this;
    }
    return *this;
}
ostream& operator<<(ostream& COUT, const Buffet& obj)
{
    cout << "\n.In BUFFET << Overloading";
    settextstyle(4, 0, 4);
    setcolor(14);
    outtextxy(90, 200, "BUFFET");
    settextstyle(3, 0, 3);
    setcolor(15);
    if (obj.dish[0] != NULL)
    {
        outtextxy(50, 250, obj.dish[0]);
        bgiout << "$" << obj.price[0];
        outstreamxy(250, 250);
    }
    if (obj.dish[1] != NULL)
    {
        outtextxy(50, 300, obj.dish[1]);
        bgiout << "$" << obj.price[1];
        outstreamxy(250, 300);
    }
    if (obj.dish[2] != NULL)
    {
        outtextxy(50, 350, obj.dish[2]);
        bgiout << "$" << obj.price[2];
        outstreamxy(250, 350);
    }
    if (obj.dish[3] != NULL)
    {
        outtextxy(50, 400, obj.dish[3]);
        bgiout << "$" << obj.price[3];
        outstreamxy(250, 400);
    }
    if (obj.dish[4] != NULL)
    {
        outtextxy(50, 450, obj.dish[4]);
        bgiout << "$" << obj.price[4];
        outstreamxy(250, 450);
    }
    return COUT;
}
Dessert::~Dessert()
{
    for (int i = 0; i < size; i++)
    {
        delete[]sweet[i];
    }
    delete[]sweet;
    sweet = NULL;
    delete[]price;
    price = NULL;
}
Dessert::Dessert()
{
    size = 5;
    sweet = new char* [size];
    for (int i = 0; i < size - 1; i++)
    {
        sweet[i] = new char[50];
    }
    char d0[] = "Lava Cake";
    int s0 = strlen(d0);
    char d1[] = "Muffins";
    int s1 = strlen(d1);
    char d2[] = "Brownie";
    int s2 = strlen(d2);
    char d3[] = "Coffee Truffle";
    int s3 = strlen(d3);
    for (int j = 0; j < s0; j++)
    {
        sweet[0][j] = d0[j];
    }
    sweet[0][s0] = '\0';

    for (int j = 0; j < s1; j++)
    {
        sweet[1][j] = d1[j];
    }
    sweet[1][s1] = '\0';

    for (int j = 0; j < s2; j++)
    {
        sweet[2][j] = d2[j];
    }
    sweet[2][s2] = '\0';

    for (int j = 0; j < s3; j++)
    {
        sweet[3][j] = d3[j];
    }
    sweet[3][s3] = '\0';
    sweet[4] = NULL;

    price = new float[size];
    float rs = 50.0;
    for (int i = 0; i < size; i++)
    {
        price[i] = rs;
        rs += 10;
    }
}
Dessert& Dessert::operator+(string newsweet)
{
    if (sweet[4] == NULL)
    {
        int s = 0;
        for (s = 0; newsweet[s] != '\0'; s++)
        {
        }
        sweet[4] = new char[s + 1];
        for (int j = 0; j < s; j++)
        {
            sweet[4][j] = newsweet[j];
        }
        sweet[4][s] = '\0';
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "SWEET ADDED");
        delay(500);
        return *this;
    }
    else
    {
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "SWEET ALREADY EXISTS");
        delay(500);
        return *this;
    }
}
Dessert& Dessert::operator-(int index)
{
    settextstyle(3, 0, 3);
    setcolor(2);
    if (sweet[index] == NULL)
    {
        outtextxy(520, 630, "No Sweet Exists");
        delay(500);
        return *this;
    }
    if (sweet[index] != NULL)
    {
        // delete[]sweet[index];
        sweet[index] = NULL;
        outtextxy(520, 630, "Sweet Deleted");
        delay(500);
        return *this;
    }
}
float  Dessert::operator[](int val)
{
    if (sweet[val] != NULL)
    {
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "ORDER PLACED");
        delay(500);
        return price[val];
    }
}
ostream& operator<<(ostream& COUT, const Dessert& obj)
{
    cout << "\n.In DESSERT << Overloading";
    settextstyle(4, 0, 4);
    setcolor(14);
    outtextxy(505, 200, "DESSERT");
    settextstyle(3, 0, 3);
    setcolor(15);
    if (obj.sweet[0] != NULL)
    {
        outtextxy(500, 250, obj.sweet[0]);
        bgiout << "$" << obj.price[0];
        outstreamxy(700, 250);
    }
    if (obj.sweet[1] != NULL)
    {
        outtextxy(500, 300, obj.sweet[1]);
        bgiout << "$" << obj.price[1];
        outstreamxy(700, 300);
    }
    if (obj.sweet[2] != NULL)
    {
        outtextxy(500, 350, obj.sweet[2]);
        bgiout << "$" << obj.price[2];
        outstreamxy(700, 350);
    }
    if (obj.sweet[3] != NULL)
    {
        outtextxy(500, 400, obj.sweet[3]);
        bgiout << "$" << obj.price[3];
        outstreamxy(700, 400);
    }
    if (obj.sweet[4] != NULL)
    {
        outtextxy(500, 450, obj.sweet[4]);
        bgiout << "$" << obj.price[4];
        outstreamxy(700, 450);
    }
    return COUT;
}
Bar::Bar()
{
    size = 5;
    drinks = new char* [size];
    for (int i = 0; i < size - 1; i++)
    {
        drinks[i] = new char[50];
    }
    char d0[] = "Mint Margarita";
    int s0 = strlen(d0);
    char d1[] = "Bigg Apple";
    int s1 = strlen(d1);
    char d2[] = "Fresh Lime";
    int s2 = strlen(d2);
    char d3[] = "Coca-Cola";
    int s3 = strlen(d3);
    for (int j = 0; j < s0; j++)
    {
        drinks[0][j] = d0[j];
    }
    drinks[0][s0] = '\0';

    for (int j = 0; j < s1; j++)
    {
        drinks[1][j] = d1[j];
    }
    drinks[1][s1] = '\0';

    for (int j = 0; j < s2; j++)
    {
        drinks[2][j] = d2[j];
    }
    drinks[2][s2] = '\0';

    for (int j = 0; j < s3; j++)
    {
        drinks[3][j] = d3[j];
    }
    drinks[3][s3] = '\0';
    drinks[4] = NULL;

    price = new float[size];
    float rs = 15.0;
    for (int i = 0; i < size; i++)
    {
        price[i] = rs;
        rs += 5;
    }
}
Bar::~Bar()
{
    for (int i = 0; i < size; i++)
    {
        delete[]drinks[i];
    }
    delete[]drinks;
    delete[]price;
    drinks = NULL;
    price = NULL;
}
Bar& Bar::operator+(string newdrink)
{
    if (drinks[4] == NULL)
    {
        int s = 0;
        for (s = 0; newdrink[s] != '\0'; s++)
        {
        }
        drinks[4] = new char[s + 1];
        for (int j = 0; j < s; j++)
        {
            drinks[4][j] = newdrink[j];
        }
        drinks[4][s] = '\0';
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "DRINK ADDED");
        delay(500);
        return *this;
    }
    else
    {
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "DRINK ALREADY EXISTS");
        delay(500);
        return *this;
    }
}
Bar& Bar::operator-(int index)
{
    settextstyle(3, 0, 3);
    setcolor(2);
    if (drinks[index] == NULL)
    {
        outtextxy(520, 630, "No Drink Exists");
        delay(500);
        return *this;
    }
    if (drinks[index] != NULL)
    {
        delete[] drinks[index];
        drinks[index] = NULL;
        outtextxy(520, 630, "Drink Deleted");
        delay(500);
        return *this;
    }
}
float  Bar::operator[](int val)
{
    if (drinks[val] != NULL)
    {
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "ORDER PLACED");
        delay(500);
        return price[val];
    }
}
ostream& operator<<(ostream& COUT, const Bar& obj)
{
    cout << "\n.In BAR << Overloading";
    settextstyle(4, 0, 4);
    setcolor(14);
    outtextxy(1000, 200, "BAR");
    settextstyle(3, 0, 3);
    setcolor(15);
    if (obj.drinks[0] != NULL)
    {
        outtextxy(950, 250, obj.drinks[0]);
        bgiout << "$" << obj.price[0];
        outstreamxy(1150, 250);
    }
    if (obj.drinks[1] != NULL)
    {
        outtextxy(950, 300, obj.drinks[1]);
        bgiout << "$" << obj.price[1];
        outstreamxy(1150, 300);
    }
    if (obj.drinks[2] != NULL)
    {
        outtextxy(950, 350, obj.drinks[2]);
        bgiout << "$" << obj.price[2];
        outstreamxy(1150, 350);
    }
    if (obj.drinks[3] != NULL)
    {
        outtextxy(950, 400, obj.drinks[3]);
        bgiout << "$" << obj.price[3];
        outstreamxy(1150, 400);
    }
    if (obj.drinks[4] != NULL)
    {
        outtextxy(950, 450, obj.drinks[4]);
        bgiout << "$" << obj.price[4];
        outstreamxy(1150, 450);
    }
    return COUT;
}
////////////////////////////////////////////////////////////////////
float Restaurant::operator[](int val)
{
    float p;
    if (val >= 0 && val < 5)
    {
        p = buf[0][0][val];
        cout << "Price Added To customer bill: " << p << endl;
        return p;
    }
    if (val >= 5 && val < 10)
    {
        p = des[0][0][val - 5];
        cout << "Price Added To customer bill: " << p << endl;
        return p;
    }
    if (val >= 10 && val < 14)
    {
        p = bar[0][0][val - 10];
        cout << "Price Added To customer bill: " << p << endl;
        return p;
    }
    return 0.0;
}
Restaurant::Restaurant()
{
    buf = new Buffet * [1];

    buf[0] = new Buffet[1];

    des = new Dessert * [1];

    des[0] = new Dessert[1];

    bar = new Bar * [1];

    bar[0] = new Bar[1];

}
Restaurant::~Restaurant()
{
    for (int i = 0; i < 1; i++)
    {
        delete[]buf[i];
        delete[]des[i];
        delete[]bar[i];
    }
    delete[]buf;
    delete[]des;
    delete[]bar;
    buf = NULL;
    des = NULL;
    bar = NULL;
}
Restaurant& Restaurant::operator + (string check)
{
    if ((check == "Halloumi Fries")&&buf[0]!=NULL)
    {
        buf[0]->operator+("Halloumi Fries");
        return *this;
    }
    else if ((check == "Turkish Delight") && des[0] != NULL)
    {
        des[0]->operator+("Turkish Delight");
        return *this;
    }
    else if ((check == "Bourgogne Wine") && bar[0] != NULL)
    {
        bar[0]->operator+("Bourgogne Wine");
        return *this;
    }

    if (check == "Buffet" && buf[0] == NULL)
    {
        buf[0] = new Buffet[1];
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "Buffet Is Now Functional");
        delay(600);
        return *this;
    }
    else if (check == "Dessert" && des[0] == NULL)
    {
        des[0] = new Dessert[1];
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "Dessert Is Now Functional");
        delay(600);
        return *this;
    }
    if (check == "Bar" && bar[0] == NULL)
    {
        bar[0] = new Bar[1];
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "Bar Is Now Functional");
        delay(600);
        return *this;
    }
    return *this;
}
Restaurant& Restaurant::operator-(string check)
{
    if ((check == "Halloumi Fries") && buf[0] != NULL)
    {
        buf[0]->operator-(4);
        return *this;
    }
    else if ((check == "Turkish Delight")&&des[0] != NULL)
    {
        des[0]->operator-(4);
        return *this;
    }
    else if ((check == "Bourgogne Wine")&&bar[0] != NULL)
    {
        bar[0]->operator-(4);
        return *this;
    }

    if (check == "Buffet" && buf[0] != NULL)
    {
        delete[] buf[0];
        buf[0] = NULL;
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "Buffet Is Non Functional");
        delay(600);
        return *this;
    }
    else if (check == "Dessert" && des[0] != NULL)
    {
        delete[] des[0];
        des[0] = NULL;
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "Dessert Is Non Functional");
        delay(600);
        return *this;
    }
    if (check == "Bar" && bar[0] != NULL)
    {
        delete[] bar[0];
        bar[0] = NULL;
        settextstyle(3, 0, 3);
        setcolor(2);
        outtextxy(520, 630, "Bar Is Non Functional");
        delay(600);
        return *this;
    }
    return *this;
}
ostream& operator<<(ostream& COUT, Restaurant& obj)
{
    if (obj.BufStatus())
    {
        //cout << endl << "BUFFET IS FUNCTIONAL";
        cout << obj.buf[0][0];
    }
    if (obj.DessertStatus())
    {
        //cout << endl << "DESSERT IS FUNCTIONAL";
        cout << obj.des[0][0];
    }
    if (obj.BarStatus())
    {
        //cout << endl << "BAR IS FUNCTIONAL";
        cout << obj.bar[0][0];
    }
    return COUT;
}
bool Restaurant::BufStatus()
{
    if (buf[0] != NULL)
    {
        return true;
    }
    return false;
}
bool Restaurant::BarStatus()
{
    if (bar[0] != NULL)
    {
        return true;
    }
    return false;
}
bool Restaurant::DessertStatus()
{
    if (des[0] != NULL)
    {
        return true;
    }
    return false;
}