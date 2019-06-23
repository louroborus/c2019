#include"yuan.h"

void choice(int who)
{
	int x = 7, y = 7;
	int c;
	for (;;)
	{
		move(2 * y, x);
		printf("¡î");
		c = getch();
		if (c == HC && mp[x][y] == Blank)
		{
			if (who == 2)
			{
				mp[x][y] = Gamer;
			}
			else
			{
				mp[x][y] = AI;
			}
			move(2 * y, x);
			paint(x, y);
			break;
		}
		switch (c)
		{
		case Up:
			if (mp[x - 1][y] != Wall)
			{
				paint(x, y);
				--x;
			}
			break;
		case Down:
			if (mp[x + 1][y] != Wall)
			{
				paint(x, y);
				++x;
			}
			break;
		case Left:
			if (mp[x][y - 1] != Wall)
			{
				paint(x, y);
				--y;
			}
			break;
		case Right:
			if (mp[x][y + 1] != Wall)
			{
				paint(x, y);
				++y;
			}
			break;
		}
	}
}
void game()
{
	system("cls");
	for (int i = 0; i <= 16; ++i)
	{
		for (int j = 0; j <= 16; ++j)
		{
			paint(i, j);
		}
	}
	while (ISEND())
	{
		choice(1);
		if (!ISEND())
			break;
		choice(2);
	}
	OVER(1);
}

void AIgame()
{
	system("cls");
	mp[8][8] = AI;
	for (int i = 0; i <= 16; ++i)
	{
		for (int j = 0; j <= 16; ++j)
		{
			paint(i, j);
		}
	}
	while (ISEND())
	{
		choice(2);
		if (!ISEND())
			break;
		Aichoice();
	}
	OVER(2);
}