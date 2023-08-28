#include "Customer.h"
#include "Employee.h"
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
Janitor** janitorList;
Waiter** waiterList;
int JanitorIndex = 0, Waiterindex = 0;
EmployeeCharacteristics::EmployeeCharacteristics()
{
    ID = "-";
    Age = 0;
}
EmployeeCharacteristics::EmployeeCharacteristics(string fname, string lname, string gender, int age, string id) :PersonType(fname, lname, gender)
{
    Age = age;
    ID = id;
}
EmployeeCharacteristics::~EmployeeCharacteristics()
{
    cout << "EmployeeCharacteristics Destructor Called" << endl;
}
Janitor::Janitor()
{
    salary = 70.0;
}
Janitor::Janitor(string fname, string lname, string gender, int age, string id) :EmployeeCharacteristics(fname, lname, gender, age, id)
{
    salary = 70.0;
}
void  Janitor::SetSalary(float newSalary)
{
    if (newSalary > 20)
    {
        salary = newSalary;
    }
}
float Janitor::GetTotalPay(int noOfJanitors)
{
    return (salary * noOfJanitors);
}
Janitor::~Janitor()
{
    cout << "Janitor Destructor Called" << endl;
}
Waiter::Waiter()
{
    salary = 100.0;
}
Waiter::Waiter(string fname, string lname, string gender, int age, string id) :EmployeeCharacteristics(fname, lname, gender, age, id)
{
    salary = 100;
}
void  Waiter::SetSalary(float newSalary)
{
    if (newSalary > 20)
    {
        salary = newSalary;
    }
}
float Waiter::GetTotalPay(int noOfJanitors)
{
    return (salary * noOfJanitors);
}
Waiter::~Waiter()
{
    cout << "Waiter Destructor Called" << endl;
}