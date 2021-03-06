#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h> 
#define Height 30
#define Width 30
#define Wall 0
#define Road 1
#define Start 2
#define End 3
#define Up 72
#define Down 80
#define Left 75
#define Right 77
int map[Height + 2][Width + 2];
void move(int x, int y);
void create(int x, int y);
void paint(int x, int y);
void game();
void hidden();

int main()
{
	int i, j;
	srand((unsigned)time(NULL));
	hidden();
	for (i = 0; i <= Height + 1; i++)
	{
		for (j = 0; j <= Width + 1; j++)
		{
			if (i == 0 || i == Height + 1 || j == 0 || j == Width + 1)
				map[i][j] = Road;
		}
	}
	create(1 + rand() % (Height - 2), 1 + rand() % (Width - 2));
	for (i = 0; i <= Height + 1; i++)
	{
		map[i][0] = Wall;
		map[i][Width + 1] = Wall;
	}
	for (j = 0; j <= Width + 1; j++)
	{
		map[0][j] = Wall;
		map[Height + 1][j] = Wall;
	}
	map[2][1] = Start;
	map[Height - 1][Width] = End;
	for (i = 1; i <= Height; i++)
	{
		for (j = 1; j <= Width; j++)
		{
			paint(i, j);
		}
	}
	game();
	getch();
	return 0;
}

void hidden()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cci);
}

void game()
{
	int x = 2, y = 1;
	int c;
	while (1)
	{
		move(2 * y, x);
		printf("●");
		if (map[x][y] == End)
		{
			move(50, 26);
			printf("到达终点，按任意键结束");
			getch();
			break;
		}
		c = getch();
		switch (c)
		{
		case Up:
			if (map[x - 1][y] != Wall)
			{
				paint(x, y);
				x--;
			}
			break;
		case Down:
			if (map[x + 1][y] != Wall)
			{
				paint(x, y);
				x++;
			}
			break;
		case Left:
			if (map[x][y - 1] != Wall)
			{
				paint(x, y);
				y--;
			}
			break;
		case Right:
			if (map[x][y + 1] != Wall)
			{
				paint(x, y);
				y++;
			}
			break;
		}
	}
}

void create(int x, int y)
{
	int c[4][2] = { 0,1,1,0,0,-1,-1,0 };
	int i, j, t;
	for (i = 0; i < 4; i++) {
		j = rand() % 4;
		t = c[i][0]; c[i][0] = c[j][0]; c[j][0] = t;
		t = c[i][1]; c[i][1] = c[j][1]; c[j][1] = t;
	}
	map[x][y] = Road;
	for (i = 0; i < 4; i++) 
	{
		if (map[x + 2 * c[i][0]][y + 2 * c[i][1]] == Wall) 
		{
			if (x + c[i][0] < Height&&x + c[i][0]>1 && y + c[i][1] > 1 && y + c[i][1] < Width)
			{
				map[x + c[i][0]][y + c[i][1]] = Road;
			}
			if (x + 2 * c[i][0] < Height&&x + 2 * c[i][0]>1 && y + 2 * c[i][1] > 1 && y + 2 * c[i][1] < Width)
			{
				create(x + 2 * c[i][0], y + 2 * c[i][1]);
			}
		}
	}
}

void move(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void paint(int x, int y)
{
	move(2 * y, x);
	switch (map[x][y])
	{
	case Start:
		printf("入"); break;
	case End:
		printf("出"); break;
	case Wall:
		printf("▇"); break;
	case Road:
		printf(" "); break;
	}
}