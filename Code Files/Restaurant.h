#ifndef Restaurant.h
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <Windows.h>
#include <winnt.rh>
#include "graphics.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;
class Buffet
{
private:
    char** dish;
    float* price;
    int size;
public:
    Buffet(); 
    ~Buffet();
    Buffet& operator+(string);
    Buffet& operator-(int);
    float operator[](int);
    friend ostream& operator<<(ostream&, const Buffet&);

};
class Dessert
{
private:
    float* price;
    char** sweet;
    int size;
public:
    Dessert();
    ~Dessert();
    Dessert& operator+(string);
    Dessert& operator-(int);
    float operator[](int);
    friend ostream& operator<<(ostream&, const Dessert&);
};
class Bar
{
private:
    char** drinks;
    float* price;
    int size;
public:
    Bar();
    ~Bar();
    Bar& operator+(string);
    Bar& operator-(int);
    float  operator[](int);
    friend ostream& operator<<(ostream&, const Bar&);
};
class Restaurant
{
private:
    Buffet** buf;
    Dessert** des;
    Bar** bar;
public:
    Restaurant();
    ~Restaurant();
    Restaurant& operator+(string);
    Restaurant& operator-(string);
    bool BufStatus();
    bool BarStatus();
    bool DessertStatus();
    float operator[](int);
    friend ostream& operator<<(ostream&, Restaurant&);
};
#endif 