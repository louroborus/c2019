#include"yuan.h"
void menu()
{
	for (int i = 1; i <= 15; ++i)
	{
		for (int j = 1; j <= 15; ++j)
		{
			mp[i][j] = Blank;
		}
	}
	for (int j = 0; j <= 16; ++j)
	{
		mp[0][j] = mp[16][j] = mp[j][0] = mp[j][16] = Wall;
	}
	char s[10];
	for (;;) {
		printf("������\n");
		printf("1��������114514��ʼ��Ҽ��ս!\n");
		printf("2��������kksk��ʼ��AI��ս!\n");
		printf("3������esc�˳�!\n");
		scanf("%s", s);
		if (s[0] == '1'&&s[1] == '1'&&s[2] == '4'&&s[3] == '5'&&s[4] == '1'&&s[5] == '4'&&s[6] == '\0')
		{
			game();
		}
		else if (s[0] == 'k'&&s[1] == 'k'&&s[2] == 's'&&s[3] == 'k'&&s[4] == '\0')
		{
			AIgame();
		}
		else if (s[0] == 'e'&&s[1] == 's'&&s[2] == 'c'&&s[3] == '\0')
		{
			break;
		}
		else
		{
			system("cls");
			printf("������ˣ����򽴲����������!\n");
			printf("��������һ�ΰɣ�\n");
		}
	}
}