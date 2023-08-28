#ifndef Arcade.h
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
class Arcade
{
public:
virtual void Play() = 0;
virtual ~Arcade();
};
class Hangman:public Arcade
{
private:
     string card;
	 string hint;
	 string displ;
     int lives;
	 int score;
public:
	 Hangman();
	 ~Hangman();
	 void Play();
	 void IntializeWord(string&);
	 void CheckAnswer(char&, string&, int&);
};
class Game1024:public Arcade
{
private:
	int score;
	int rows;
	int columns;
	int **copygrid;
	int** grid;
public:
	Game1024();
	~Game1024();
	void CopyGrid();
	int Checkgrid();
	void  Random();
	void up();
	void down();
	void left();
	void right();
	void InterfaceIntialize();
	void GridDisplay();
	bool WinnerCheck();
	bool LoserCheck();
	void Play();
};
#endif 