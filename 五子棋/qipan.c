#include"yuan.h"
void hidden()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cci);
}
void paint(int x, int y)
{
	move(2 * y, x);
	switch (mp[x][y])
	{
	case AI:
		printf("○"); break;
	case Gamer:
		printf("●"); break;
	case Blank:
		printf("┼"); break;
	}
}
void move(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}