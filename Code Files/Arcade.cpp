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
Arcade::~Arcade()
{
	cout << "\nVirtual ARCADE Destructor Called\n";
}
Game1024::Game1024()
{
	score = 0;
	rows = 4;
	columns = 4;
	copygrid = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		copygrid[i] = new int[columns];
	}
	grid = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		grid[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			grid[i][j] = 0;
			copygrid[i][j] = 0;
		}
	}
}
Game1024::~Game1024()
{
	for (int i = 0; i < rows; i++)
	{
		delete[]  copygrid[i];
		delete[]  grid[i];
	}
	delete[]  copygrid;
	delete[]  grid;
	score = 0;
	rows = 0;
	columns = 0;
	cout << "\nGAME1024 Destructor Called\n";
}
void Game1024::CopyGrid()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			copygrid[i][j] = grid[i][j];
		}
	}
}
int Game1024::Checkgrid()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (copygrid[i][j] != grid[i][j])
			{
				return 1;
			}
		}
	}
	return 0;
}
void  Game1024::Random()
{
	srand(time(0));
	int num3, num4, num;
	while (1)
	{
		num3 = rand() % 4;
		num4 = rand() % 4;
		if (grid[num3][num4] == 0)
			break;
	}
	while (1)
	{
		num = rand() % 3;
		if (num == 1 || num == 2)
			break;
	}
	grid[num3][num4] = num;
}
void Game1024::up()
{
	int result;
	for (int j = 0; j < columns; j++) //column
	{
		int i2 = 0, j2 = j;
		for (int i = 1; i < rows; i++) //rows

		{
			if (grid[i][j] != 0)
			{
				if (grid[i][j] == grid[i - 1][j] || grid[i - 1][j] == 0)
				{
					if (grid[i2][j2] == grid[i][j])
					{
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						i2++;
					}
					else
						if (grid[i2][j2] == 0)
						{
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else
						{
							grid[++i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
				}
				else
					i2++;
			}
		}
	}
	result = Checkgrid();//to check if their was a movement in the grid or not 
	if (result == 1)//if there was a movement that random number will be generated
	{
		Random();
	}
}
void Game1024::down()
{
	int result;
	for (int j = 0; j < columns; j++)//columns
	{
		int i2 = rows - 1, j2 = j;
		for (int i = i2 - 1; i >= 0; i--)//rows
		{
			if (grid[i][j] != 0)
			{
				if (grid[i][j] == grid[i + 1][j] || grid[i + 1][j] == 0)
				{
					if (grid[i2][j2] == grid[i][j])
					{
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						i2--;
					}
					else
						if (grid[i2][j2] == 0)
						{
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else
						{
							grid[--i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
				}
				else
					i2--;
			}
		}
	}
	result = Checkgrid();
	if (result == 1)
	{
		Random();
	}
}
void Game1024::left()
{
	int result;
	for (int i = 0; i < rows; i++)//row
	{
		int i2 = i, j2 = 0;
		for (int j = 1; j < columns; j++)//column
		{
			if (grid[i][j] != 0)
			{
				if (grid[i][j] == grid[i][j - 1] || grid[i][j - 1] == 0)
				{
					if (grid[i2][j2] == grid[i][j])
					{
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						j2++;
					}
					else
					{
						if (grid[i2][j2] == 0)
						{
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else
						{
							grid[i2][++j2] = grid[i][j];
							grid[i][j] = 0;
						}
					}
				}
				else
					j2++;
			}
		}
	}
	result = Checkgrid();
	if (result == 1)
	{
		Random();
	}
}
void Game1024::right()
{
	int result;
	for (int i = 0; i < 4; i++)//rows
	{
		int i2 = i, j2 = columns - 1;
		for (int j = j2 - 1; j >= 0; j--)//columns
		{
			if (grid[i][j] != 0)
			{
				if (grid[i][j] == grid[i][j + 1] || grid[i][j + 1] == 0)
				{
					if (grid[i2][j2] == grid[i][j])
					{
						grid[i2][j2] = grid[i][j] + grid[i][j];
						grid[i][j] = 0;
						j2--;
					}
					else
						if (grid[i2][j2] == 0)
						{
							grid[i2][j2] = grid[i][j];
							grid[i][j] = 0;
						}
						else
						{
							grid[i2][--j2] = grid[i][j];
							grid[i][j] = 0;
						}
				}
				else
					j2--;
			}
		}
	}
	result = Checkgrid();
	if (result == 1)
	{
		Random();
	}
}
void Game1024::InterfaceIntialize()//this function is used for intializing two random numbers at random positions in the start of the game 
{
	srand(time(0));
	int num1, num2, num3, num4, num;
	num1 = rand() % 4;
	num2 = rand() % 4;
	while (1)
	{
		num = rand() % 3;
		if (num == 1)
			break;
	}
	grid[num1][num2] = num;
	while (1)
	{
		num3 = rand() % 4;
		num4 = rand() % 4;
		if (num1 != num3 && num4 != num2)
			break;
	}
	while (1)
	{
		num = rand() % 3;
		if (num == 1 || num == 2)
			break;
	}
	grid[num3][num4] = num;
}
void Game1024::GridDisplay()//this function is used for displaying grid
{
	int x, y;
	int p, q;
	{
		setcolor(YELLOW);
		settextstyle(3,0,3);
		bgiout << "Score: " << score;
		outstreamxy(105, 120);
		setlinestyle(DASHED_LINE, 2, 3);
		setcolor(RED);
		rectangle(342, 130, 1000, 740);
		line(342, 294, 1000, 294);
		line(342, 447, 1000, 447);
		line(342, 603, 1000, 603);
		line(499, 128, 499, 740);
		line(670, 130, 670, 740);
		line(830, 130, 830, 740);

		setcolor(15);
		settextstyle(BOLD_FONT, HORIZ_DIR, 4);

		setcolor(YELLOW);
		settextstyle(9, 0, 5);
		settextjustify(1, 3);

	}
	q = 190;
	for (int i = 0; i < rows; i++)
	{
		p = 410;
		for (int j = 0; j < columns; j++)
		{
			if (grid[i][j] != 0)
				bgiout << grid[i][j];
			outstreamxy(p, q);
			p = p + 170;
		}
		q = q + 160;
	}



}
bool Game1024::WinnerCheck()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (grid[i][j] == 1024)
			{
				return true;
			}
		}
	}
	return false;
}
bool Game1024::LoserCheck()
{
	for (int a = 0; a < rows; a++)
	{
		for (int b = 0; b < columns; b++)
		{
			if (grid[a][b] == 0)
			{
				return false;
			}
		}
	}
	int k = 0;
	for (int c = 0; c < rows; c++)
	{
		k++;
		if (k == 4)
		{
			break;
		}
		for (int d = 0; d < columns; d++)
		{
			if (d == 3)
			{
				break;
			}
			if (grid[c][d] == grid[c][d + 1] || grid[c][d] == grid[k][d])
			{
				return false;
			}
		}
	}
	if (grid[0][3] == grid[1][3] || grid[1][3] == grid[2][3] || grid[2][3] == grid[3][3] || grid[3][0] == grid[3][1] || grid[3][1] == grid[3][2] || grid[3][2] == grid[3][3])
	{
		return false;
	}
	else if (grid[0][3] != grid[1][3] && grid[1][3] != grid[2][3] && grid[2][3] != grid[3][3] && grid[3][0] != grid[3][1] && grid[3][1] != grid[3][2] && grid[3][2] != grid[3][3])
	{
		return true;
	}
	return false;
}
void Game1024::Play()
{
	int x, y, z;
	{
		setcolor(15);
		settextstyle(9, 0, 3);
		bgiout << "Welcome to 1024";
		outstreamxy(215, 65);
	}
	for (x = 200, y = 500; x < 800; x += 10)
	{
		bar(150, 400, x, y - 50);
		delay(100);
		settextstyle(9, 0, 5);
		outtextxy(255, 350, "Loading...");
		settextstyle(3, 0, 3);
		outtextxy(450, 460, "Rules");
		outtextxy(255, 500, "1. Press UP To Move Up");
		outtextxy(255, 550, "2. Press DOWN To Move Down");
		outtextxy(255, 600, "3. Press LEFT To Move Left");
		outtextxy(255, 650, "4. Press RIGHT To Move Right");
		outtextxy(255, 700, "5. Press ESC To Quit");


	}
	cleardevice();
	InterfaceIntialize();
	GridDisplay();
	cout << endl;
	bool found1 = false, found2 = false;
	int show = 0;
	// Just to keep the console open after program execution  
   //up 072 down 080 left 075 right 077 277 quit

	while (show != 277)
	{
		score += 5;
		int show = getch();
		cout << show;
		if (show == 277)
		{
			cout << "You have Quit The Game";
			break;
		}
		else if (show == 72)
		{
			up();
			cleardevice();
			CopyGrid();
			GridDisplay();
		}
		else if (show == 80)
		{
			down();
			cleardevice();
			CopyGrid();
			GridDisplay();
		}
		else if (show == 75)
		{
			left();
			cleardevice();
			CopyGrid();
			GridDisplay();
		}
		else if (show == 77)
		{
			right();
			cleardevice();
			CopyGrid();
			GridDisplay();
		}
		else if (show == 27)
			return;
		found1 = WinnerCheck();
		if (found1 == true)
		{
			cleardevice();
			setcolor(YELLOW);
			settextstyle(3, 0, 3);
			bgiout << "Your Score Was: " << score;
			outstreamxy(105, 120);
			settextstyle(9, 0, 8);
			setcolor(RED);
			bgiout << "YOU WON";
			outstreamxy(600, 250);
			delay(3000);
			break;
		}
		found2 = LoserCheck();
		if (found2 == true)
		{
			cleardevice();
			setcolor(YELLOW);
			settextstyle(3, 0, 3);
			bgiout << "Your Score Was: " << score;
			outstreamxy(105, 120);
			settextstyle(9, 0, 8);
			setcolor(RED);
			bgiout << "YOU LOSE";
			outstreamxy(600, 350);
			delay(3000);
			break;
		}
	}

}
Hangman::Hangman()
{
	score = 0;
	ifstream fin("Hangman.txt");
	srand(time(0));
	int count = rand() % 21, counter = 0;
	while (counter < count)
	{
		fin >> card;
		getline(fin, hint);
		counter++;
	}
	fin.close();
	lives = 5;
	displ = card;
	IntializeWord(displ);
}
Hangman::~Hangman()
{
	cout << "\nHANGMAN Destructor Called\n";
}
void Hangman::IntializeWord(string& displ)
{
	int len = 0;
	for (; displ[len] != '\0'; len++)
	{
	}
	int val = rand() % (len - 2) + 1, count = 0;
	while (count < val)
	{
		if (count == val)
		{
			return;
			break;
		}
		int index = rand() % (len - 2);
		if (displ[index] != '_')
		{
			displ[index] = '_';
			count++;
		}
	}
}
void Hangman::CheckAnswer(char& opt, string& displ, int& lives)
{
	bool found = false;
	for (int i = 0; card[i] != '\0'; i++)
	{
		if (opt == card[i] || (opt - 32) == (card[i]) || (opt + 32) == card[i])
		{
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Invalid Input. Lives Deducted";
		--lives;
		score -= 5;
	}
	if (found)
	{
		score += 20;
		for (int i = 0; card[i] != '\0'; i++)
		{
			if (opt == card[i] || (opt - 32) == (card[i]) || (opt + 32) == card[i])
			{
				displ[i] = card[i];
			}
		}
	}
}
void Hangman::Play()
{
	char opt;
	int x, y, z;
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	outtextxy(105, 60, "Welcome to Hangman");
	setlinestyle(DASHED_LINE, 2, 3);
	rectangle(100, 105, 480, 55);
	settextstyle(3, 0, 2);
	for (x = 200, y = 500; x < 800; x += 10)
	{
		bar(150, 400, x, y - 50);
		delay(100);
		settextstyle(9, 0, 5);
		outtextxy(255, 350, "Loading...");
		settextstyle(3, 0, 3);
		outtextxy(450, 460, "Rules");
		outtextxy(255, 500, "1. Score Incremented By 10 At End Of Each Turn");
		outtextxy(255, 550, "2. Score Decremented By 5 If Wrong Answer");
		outtextxy(255, 600, "3. Score Incremented By 20 If Correct Answer");
		outtextxy(255, 650, "4. Press ESC To Quit");
	}
	delay(100);
	PlaySound(TEXT("retro.wav"), NULL, SND_LOOP | SND_ASYNC);
	while (1)
	{
		score += 10;
		cleardevice();
		if (lives == 0)
		{
			cleardevice();
			setlinestyle(DASHED_LINE, 5, 10);
			line(200, 700, 850, 700);
			setcolor(DARKGRAY);
			setlinestyle(DASHED_LINE, 2, 8);
			line(200, 710, 850, 710);
			setcolor(RED);
			line(250, 690, 250, 450); //Main Line
			setcolor(RED);
			//Pillars
				setcolor(RED);
			line(250, 490, 350, 490);//Step 2
			line(255, 540, 300, 495);//Step 3
			setcolor(BROWN);
			line(349, 488, 350, 580);//Step 4
			setcolor(DARKGRAY);
			circle(360, 583, 10);//Step 5
			line(350, 600, 350, 635);//Step 6
			line(350, 600, 370, 625);//Step 7
			line(350, 600, 330, 625);//Step 8
			line(350, 630, 360, 660);//Step 9
			line(350, 630, 330, 660);//Step 10
			/////////////////////////////////////
			settextstyle(9, 0, 8);
			setcolor(RED);
			bgiout << "Game Lost";
			outstreamxy(400, 250);
			setcolor(YELLOW);
			settextstyle(9, 0, 3);
			bgiout << " The Word Was:  " << card;
			outstreamxy(470, 400);
			settextstyle(3, 0, 2);
			bgiout << "Your Score Was: " << score;
			outstreamxy(105, 120);
			PlaySound(TEXT("Game over.wav"), NULL, SND_ASYNC);
			return;
		}
		{setcolor(YELLOW);
		bgiout << "Score: " << score;
		outstreamxy(105, 120);
		settextstyle(9, 0, 8);
		bgiout << displ;
		outstreamxy(400, 350);
		setcolor(YELLOW);
		settextstyle(4, 0, 4);
		bgiout << "LIVES: " << lives;
		outstreamxy(1000, 50);
		settextstyle(3, 0, 3);
		setcolor(15);
		bgiout << "HINT: { " << hint << "  }";
		outstreamxy(600, 150);
		bgiout << "Enter Choice: ";
		outstreamxy(200, 550);
		void flush_input();
		{
			while (kbhit())
				getch();
		}
		opt = getch();
		if (opt == 27)
			return;
		else if (opt == 8)
			continue;
		setcolor(RED);
		bgiout << opt;
		outstreamxy(350, 550);
		delay(500);
		setcolor(15); }
		CheckAnswer(opt, displ, lives);
		int count = 0;
		for (int i = 0; displ[i] != '\0'; i++)
		{

			if (displ[i] == '_')
			{
				count++;
			}
		}
		if (count == 0)
		{
			cleardevice();
			////////////////////game win./////////////
			setlinestyle(DASHED_LINE, 5, 10);
			line(200, 700, 850, 700);
			setcolor(DARKGRAY);
			setlinestyle(DASHED_LINE, 2, 8);
			line(200, 710, 850, 710);
			setcolor(RED);
			line(250, 690, 250, 450); //Main Line
			setcolor(RED);
			//Pillars
				setcolor(RED);
			line(250, 490, 350, 490);//Step 2
			line(255, 540, 300, 495);//Step 3
			setcolor(BROWN);
			line(349, 488, 350, 580);//Step 4
			setcolor(DARKGRAY);
			circle(450, 610, 10);//Step 5
			line(450, 625, 450, 660);//Step 6
			line(450, 625, 470, 650);//Step 7
			line(450, 625, 430, 650);//Step 8
			line(450, 655, 460, 685);//Step 9
			line(450, 655, 430, 685);//Step 10
			settextstyle(9, 0, 8);
			setcolor(RED);
			bgiout << "Game Won";
			outstreamxy(400, 250);
			setcolor(YELLOW);
			settextstyle(9, 0, 3);
			bgiout << " The Word Was:  " << card;
			outstreamxy(470, 400);
			settextstyle(3, 0, 2);
			bgiout << "Your Score Was: " << score;
			outstreamxy(105, 120);
			PlaySound(TEXT("win sound.wav"), NULL, SND_ASYNC);
			return;
		}
	}
}