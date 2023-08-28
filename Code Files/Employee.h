#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
class PersonType;
class EmployeeCharacteristics :public PersonType
{

private:
    string ID;
    int Age;
public:
    EmployeeCharacteristics();
    EmployeeCharacteristics(string, string, string, int, string);
    ~EmployeeCharacteristics();
};
class Janitor : public EmployeeCharacteristics
{
private:
    float salary;
public:
    Janitor();
    Janitor(string, string, string, int, string);
    void  SetSalary(float);
    float GetTotalPay(int);
    ~Janitor();
};
class Waiter : public EmployeeCharacteristics
{
private:
    float salary;
public:
    Waiter();
    Waiter(string, string, string, int, string);
    void  SetSalary(float);
    float GetTotalPay(int);
    ~Waiter();
};


