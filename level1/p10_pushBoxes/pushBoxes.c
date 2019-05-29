#include <stdio.h>
#include <Windows.h>
/*
	0: 空地
	1: 目的地   ☆
	2: 墙壁     ■
	4: 箱子     ▓
	8: 玩家     ♀
	16: 箱子到达目的地  ★
*/
#define Up 72
#define Down 80
#define Left 75
#define Right 77
int map[13][14] = {
	{0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0},
	{0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0},
	{0, 2, 2, 2, 2, 0, 0, 4, 4, 2, 2, 2, 2, 2},
	{0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2},
	{0, 2, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 2},
	{0, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2},
	{2, 2, 2, 2, 4, 2, 2, 0, 0, 0, 0, 0, 0, 2},
	{2, 0, 0, 0, 4, 0, 2, 0, 0, 0, 8, 0, 0, 2},
	{2, 0, 4, 0, 4, 0, 2, 0, 2, 2, 2, 2, 2, 2},
	{2, 2, 0, 0, 4, 0, 2, 0 ,2, 1, 1, 1, 2, 0},
	{0, 2, 0, 2, 0, 0, 0, 0, 0, 1, 1, 1, 2, 0},
	{0, 2, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 2, 0},
	{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0}
};
int tarPos[][2] = {
	{9, 9},
	{9, 10},
	{9, 11},
	{10, 9},
	{10, 10},
	{10, 11},
	{11, 8},
	{11, 9},
	{11, 10},
	{11, 11}
};
char key = 0;
int row = 0, column = 0;
int oldType = 0;
int oldBoxType = 0; 
void DrawMap() {
	for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++)
	{
		for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("☆");
				break;
			case 2:
				printf("■");
				break;
			case 4:
				printf("▓");
				break;
			case 8:
				printf("♀");
				row = i;
				column = j;
				break;
			case 16:
				printf("★");
				break;
			}
		}
		printf("\n");
	}
}
void Move(int r, int c)
{
	if (map[row + r][column + c] != 2)
	{
		if (map[row + r][column + c] == 4 || map[row + r][column + c] == 16)
		{
			if (map[row + 2 * r][column + 2 * c] != 2 && map[row + 2 * r][column + 2 * c] != 4 && map[row + 2 * r][column + 2 * c] != 16)
			{
				if (map[row + r][column + c] == 16)
				{
					oldBoxType = 1;
				}
				else if (map[row + r][column + c] == 4)
				{
					oldBoxType = 0;
				}
				map[row + r][column + c] = oldBoxType;
				if (map[row + 2 * r][column + 2 * c] == 1)
				{
					map[row + 2 * r][column + 2 * c] = 16;
				}
				else
				{
					map[row + 2 * r][column + 2 * c] = 4;
				}
			}
			else {
				return;
			}
		}
		map[row][column] = oldType;
		oldType = map[row + r][column + c];
		map[row + r][column + c] = 8;
	}
}
void resultCheck()
{
	int result = 1;
	for (int i = 0; i < sizeof(tarPos) / sizeof(tarPos[0]); i++)
	{
		if (map[tarPos[i][0]][tarPos[i][1]] != 16)
		{
			result = 0;
		}
	}
	if (result)
	{
		MessageBox(NULL, TEXT("你赢了!!"), TEXT("游戏结束"), MB_OK);
		exit(0);
	}
}
void hidden()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cci);
}
int main(void)
{
	hidden();
	DrawMap();
	for (;;)
	{
		key = getch();
		switch (key)
		{
		case Up:
			Move(-1, 0);
			break;
		case Down:
			Move(1, 0);
			break;
		case Left:
			Move(0, -1);
			break;
		case Right:
			Move(0, 1);
			break;
		}
		resultCheck(); 
		system("cls"); 
		DrawMap();
	}
	return 0;
}
