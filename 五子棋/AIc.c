#include"yuan.h"

int winmods[6] = { Blank,AI,AI,AI,AI,Blank };
int sco1 = 4320, winsco = 50000;
int mods[8][5] = {
{ AI,AI,AI,AI,AI },
{Blank,AI,AI,AI,AI},
{AI,AI,AI,Blank,AI},
{AI,AI,Blank,AI,AI} ,
{Blank,AI,AI,AI,Blank},
{Blank,AI,AI,Blank,Blank},
{Blank,AI,Blank,AI,Blank},
{AI,Blank,Blank,Blank,Blank},
};
int sco[8] = { 50000,720,720,720,720,120,120,20 };
struct Pos
{
	int mpp[17][17], score[17][17];
	int b[17][17];
}state[400];
int top;

void score1(int m[17][17], int nw)//判断每个位置的值
{
	for (int i = 1; i <= 15; ++i)
	{
		for (int j = 1; j <= 15; ++j)
		{
			state[nw].mpp[i][j] = m[i][j];
			state[nw].score[i][j] = 0;
			state[nw].b[i][j] = 0;
		}
	}
	for (int i = 1; i <= 15; ++i)
	{
		for (int j = 1; j <= 15; ++j)
		{
			if (state[nw].mpp[i][j] == Blank)
			{
				state[nw].b[i][j] = 1;
				score2(i, j, state[nw].mpp, nw);
			}
		}
	}
}
void score2(int x, int y, int m[17][17],int nw)//以给定位置为中心存入棋子串并传入函数进行匹配
{
	int sta[11], tp = 0, sum = 0;
	int x1 = x, x2 = x;
	while (x1 > 1 && x - x1 < 4)--x1;
	while (x2 < 15 && x2 - x < 4)++x2;
	for (int i = x1; i <= x2; ++i)
	{
		sta[tp++] = m[i][y];
		if (i == x)
		{
			sta[tp - 1] = AI;
		}
	}
	sum += score3(tp, sta);
	tp = 0;
	int y1 = y, y2 = y;
	while (y1 > 1 && y - y1 < 4)--y1;
	while (y2 < 15 && y2 - y < 4)++y2;
	for (int i = y1; i <= y2; ++i)
	{
		sta[tp++] = m[x][i];
		if (i == y)
		{
			sta[tp - 1] = AI;
		}
	}
	sum += score3(tp, sta);
	tp = 0;
	int i = x, j = y;
	while (i > x1&&j > y1) {--i; --j;}
	for (; i <= x2 && j <= y2; ++i, ++j)
	{
		sta[tp++] = m[i][j];
		if (i == x)
		{
			sta[tp - 1] = AI;
		}
	}
	sum += score3(tp, sta);
	tp = 0;
	i = x, j = y;
	while (i > x1&&j < y2) { --i; ++j; }
	for (; i <= x2 && j >= y1; ++i, --j)
	{
		sta[tp++] = m[i][j];
		if (i == x)
		{
			sta[tp - 1] = AI;
		}
	}
	sum += score3(tp, sta);
	state[nw].score[x][y] = sum;
}
int score3(int tp, int t[11])//对传入的一串棋子进行匹配
{
	for (int i = 0; i < tp - 5; ++i)
	{
		int f = 0;
		for (int j = 0; j <= 5; ++j)
		{
			if (t[i + j] != winmods[j])
			{
				f = 1;
				break;
			}
		}
		if (f == 0)
		{
			return sco1;
		}
	}
	int f;
	for (int i = 0; i <= 7; ++i)
	{
		for (int j = 0; j < tp - 4; ++j)
		{
			f = 0;
			for (int k = 0; k <= 4; ++k)
			{
				if (t[j + k] != mods[i][k])
				{
					f = 1;
					break;
				}
			}
			if (f == 0)
				return  sco[i];
		}
	}
	return 0;
}
int evalu(int now)
{
	int mx = 0;
	for (int i = 1; i <= 15; ++i)
	{
		for (int j = 1; j <= 15; ++j)
		{
			if (state[now].b[i][j])
			{
				mx = max(mx, state[now].score[i][j]);
			}
		}
	}
	return mx;
}
void Aichoice()
{
	top = 0;
	score1(mp, ++top);//判现图权值
	int m[17][17];
	for (int i = 1; i <= 15; ++i)
	{
		for (int j = 1; j <= 15; ++j)
		{
			if (mp[i][j] == AI)
			{
				m[i][j] = Gamer;
			}
			else if (mp[i][j] == Gamer)
			{
				m[i][j] = AI;
			}
			else
			{
				m[i][j] = Blank;
			}
		}
	}//建用于判对方走法的反图
	for (int i = 1; i <= 15; ++i)
	{
		for (int j = 1; j <= 15; ++j)
		{
			if (m[i][j] == Blank)
			{
				m[i][j] = Gamer;
				score1(m, ++top);
				m[i][j] = Blank;
			}
		}
	}
	int now = 1, bx, by, bva = -0x7fffffff, f = 0;
	for (int i = 1; i <= 15; ++i)
	{
		for (int j = 1; j <= 15; ++j)
		{
			if (state[1].b[i][j])
			{
				if (state[1].score[i][j] >= winsco)
				{
					bx = i;
					by = j;
					f = 1;
					break;
				}
				++now;
				int bads = evalu(now);
				if (bads >= winsco)
					continue;
				int mx = state[1].score[i][j] - bads;
				if (mx > bva)
				{
					bva = mx;
					bx = i;
					by = j;
				}
			}
		}
		if (f == 1)
			break;
	}
	if (bva == -0x7fffffff && f != 1)
	{
		bx = 0; by = 0;
		while (mp[bx][by] != Blank) { bx = rand() % 16; by = rand() % 16; }
	}
	mp[bx][by] = AI;
	move(2 * by, bx);
	paint(bx, by);
}