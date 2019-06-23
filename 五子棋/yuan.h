#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define HC 13
#define AI 2233
#define Gamer 114514
#define Wall 0
#define Blank -1			//空白：┼		当前选中位置:☆ 玩家棋子：●		AI棋子：○

int mp[17][17], whowin;
void move(int, int);
void game();
void AIgame();
void paint(int, int);
void choice(int);

void hidden();
void menu();

void score1(int[17][17], int);
void score2(int, int, int[17][17], int);
int score3(int, int[11]);
void Aichoice();
int evalu(int);

int ISEND();
void OVER(int);
void ju(int, int);