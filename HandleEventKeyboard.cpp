#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int gety()
{
	HANDLE hConsoleOutput;
	CONSOLE_SCREEN_BUFFER_INFO info;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOutput, &info);
	return info.dwCursorPosition.Y;
}

void turnCursor(bool on)
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = on;
	cursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor;
	Cursor.X = x;
	Cursor.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor);
}

void textColor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}

int print(const char* s, int choose)
{
	char* yourChoose, * ntok = 0, * str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
	yourChoose = strtok_s(str, "\n", &ntok);
	int i = 1;
	while (yourChoose)
	{
		if (i == choose)
		{
			textColor(12);
			cout << yourChoose << endl;
		}
		else
		{
			textColor(15);
			cout << yourChoose << "   " << endl;
		}
		yourChoose = strtok_s(0, "\n", &ntok);
		i++;
	}
	delete[] str;
	return i - 1;
}

int menu(const char* s)
{
	turnCursor(0);
	int y = gety(), choose = 1;
	while (1)
	{
		gotoXY(0, y);
		int nChoose = print(s, choose);
		char input = _getch();
		if (input == -32)
		{
			input = _getch();
			switch (input)
			{
			case 72: choose = (choose > 1) ? choose - 1 : 1; break;
			case 80: choose = (choose < nChoose) ? choose + 1 : input; break;
			}
		}
		if ((input >= 48) && (input <= 57))
		{
			int x = input - 48;
			if ((x > 0) && (x <= nChoose)) choose = x;
		}
		if (input == '\r')
		{
			textColor(15);
			turnCursor(1);
			return choose;
		}
	}
}

int main()
{
	int yourChoose = menu("1\n2\n3");
	cout << "Your choose: " << yourChoose;
}