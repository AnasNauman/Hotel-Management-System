#ifndef Customer.h
#include <iostream>
#include<cstring>
#include <string>
#include <ctime>
#include <fstream>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
class Restaurant;
class PersonType;
class Bill;
class Datetype;
class Bar;
class Dessert;
class Buffet;
class Customer;
class EmployeeCharacteristics;
class Janitor;
class Waiter;
extern Restaurant restaurant;
extern Customer** customerList;
extern int TotalCustomers, CustomerIndex;
extern Janitor** janitorList;
extern Waiter** waiterList;
extern int  JanitorIndex, Waiterindex;

extern void CheckOutCustomer();
extern void customerdetails();
extern void CheckInCustomer();
extern void RoomAvailability();
extern void RestaurantManagement();
extern void adminmenu();
extern void adminLoginPage();
extern void userMenu(int customerRoomNumber);
extern void userLoginPage();
extern void MenuDisplay();
using namespace std;
/////////////////////////////////////////////////////////////
////////////////PERSON TYPE CLASS////////////////////////////
/////////////////////////////////////////////////////////////
class PersonType
{
private:
    string Fname;
    string Lname;
    string Gender;
public:
    PersonType();
    PersonType(string, string, string);
    void SetName(string, string, string);
    string GetFname();
    string GetLname();
    string GetGender();
};
/////////////////////////////////////////////////////////////
////////////////BILL CLASS///////////////////////////////////
/////////////////////////////////////////////////////////////
class Bill
{
private:
    float RoomCharge;
    float MedicineFee;
    float FoodBill;
    float ServiceCharges;
    int   invoice;
    float Arcade;
    float Total;
public:
    Bill();
    ~Bill();
    float GetRoomCharge();
    float GetMedicineFee();
    float GetFoodBill();
    float GetServiceCharges();
    float GetArcade();
    void setinvoice(int);
    void AddArcade(int);
    int getinvoice();
    float GetTotal();
    void operator+(float);
    void SetRoomCharge(int z);
};
/////////////////////////////////////////////////////////////
////////////////DATE&CUSTOMER CLASS//////////////////////////
/////////////////////////////////////////////////////////////
class DateType
{
private:
    int day;
    int month;
    int year;
public:
    DateType();
    ~DateType();
    void SetDate(int, int, int);
    int GetDay();
    int GetMonth();
    int GetYear();
    friend  bool CheckDate(int, int, int);
};
/////////////////////////////////////////////////////////////
////////////////CUSTOMER CLASS///////////////////////////////
/////////////////////////////////////////////////////////////
class Customer :public PersonType
{
private:
    Bill CustomerBill;
    DateType DoA;
    DateType DoD;
    int RoomNumber;
    char RoomType;
public:
    Customer();
    ~Customer();
    void OrderFood();
    void CheckCurrentExpenditure(int);
    void ViewPersonalDetails(int);
    int GetRoomNumber();
    void SetRoomNumber(int);
    void SetDoA(int, int, int);
    void SetDoD(int, int, int);
    void SetRoomType(char);
    char GetRoomType();
    int getinvoice();
    void setinvoice(int);
    void ArcadeScreen();
    void SetRoomCharges();
    float GetTotalBillAtCheckOut();
};
#endif