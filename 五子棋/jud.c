#include"yuan.h"
int lens = 0, past = -1, f = 0, ff = 0;
inline void ju(int i, int j)
{
	if (mp[i][j] == Gamer)
	{
		if (past == Gamer || lens == 0)
		{
			++lens;
		}
		else
		{
			lens = 0;
		}
		past = Gamer;
	}
	else if (mp[i][j] == AI)
	{
		if (past == AI || lens == 0)
		{
			++lens;
		}
		else
		{
			lens = 0;
		}
		past = AI;
	}
	else
	{
		f = 1;
		past = Blank;
		lens = 0;
	}
	if (lens == 5)
	{
		whowin = mp[i][j];
		ff = 1;
	}
}

int ISEND()
{
	lens = 0, past = -1, f = 0, ff = 0;
	for (int i = 1; i <= 15; ++i)
	{
		lens = 0, past = -1;
		for (int j = 1; j <= 15; ++j)
		{
			ju(i, j);
		}
	}
	for (int j = 1; j <= 15; ++j)
	{
		lens = 0, past = -1;
		for (int i = 1; i <= 15; ++i)
		{
			ju(i, j);
		}
	}
	for (int i = 1; i <= 15; ++i)
	{
		int x = 1, y = i;
		lens = 0, past = -1;
		while (x <= 15 && y <= 15)
		{
			ju(x, y);
			++x; ++y;
		}
		x = 1; y = i, lens = 0, past = -1;
		while (x <= 15 && y >= 1)
		{
			ju(x, y);
			++x; --y;
		}
		x = 15; y = i, lens = 0, past = -1;
		while (x >= 1 && y >= 1)
		{
			ju(x, y);
			--x; --y;
		}
		x = 15; y = i, lens = 0, past = -1;;
		while (x >= 1 && y <= 15)
		{
			ju(x, y);
			--x; ++y;
		}
		if (ff == 1)
		{
			return 0;
		}
	}
	if (f == 0)
	{
		whowin = -1;
		return 0;
	}
	return 1;
}

void OVER(int mod)
{
	system("cls");
	move(12, 6);
	if (mod == 1)
	{
		if (whowin == AI)
		{
			printf("ִ����Ӯ�ˣ�\n");
		}
		else if (whowin == Gamer)
		{
			printf("ִ����Ӯ�ˣ�\n");
		}
		else
		{
			printf("ƽ�֣�\n");
		}
	}
	else
	{
		if (whowin == AI)
		{
			printf("����Ӯ�ˣ�\n");
		}
		else if (whowin == Gamer)
		{
			printf("��Ӯ�ˣ�\n");
		}
		else
		{
			printf("ƽ�֣�\n");
		}
	}
	printf("���س���������\n");
	char c = getchar();
	while ((c = getchar()) != '\n') {}
	system("cls");
	menu();
}