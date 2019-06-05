#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
struct thing {
	char name[15];
	int count;
	char danwei[15];
}product[1000];
int num;
void read();
void save();
void input();
void output();
void show();
void menu();
void clear();
int main()
{
	int c;
	read();
	for (;;) {
		menu();
		scanf("%d", &c);
		printf("\n");
		if (c == 5)
			break;
		switch (c) {
		case 1:
			show();
			break;
		case 2:
			input();
			break;
		case 3:
			output();
			break;
		case 4:
			clear();
			break;
		default:
			break;
		}
	}
	printf("�����ѱ��棬�˳�����ɹ�!\n");
	return 0;
}
void clear()
{
	system("cls");
}
void read()
{
	FILE* fp = fopen("product.txt", "r");
	if (fp == NULL)
	{
		printf("���ܴ��ļ�!\n");
		return;
	}
	int i;
	for (i = 0; !feof(fp); ++i)
	{
		fscanf(fp, "%s %d %s\n", product[i].name, &product[i].count, &product[i].danwei);
	}
	num = i - 1;
	fclose(fp);
}
void save()
{
	FILE* fp = fopen("product.txt", "w");
	if (fp == NULL) 
	{
		printf("���ܴ��ļ�!\n");
		return;
	}
	for (int i = 0; i < num; ++i)
	{
		fprintf(fp, "%s %d %s\n", product[i].name, product[i].count, product[i].danwei);
	}
	printf("\n�����ѱ���!\n");
	fclose(fp);
}
void input()
{
	char t[15], x[15];
	int n, i;
	printf("��������������ͺ�:");
	scanf("%s", t);
	printf("\n");
	for (i = 0; i < num; ++i) 
	{
		if (!strcmp(product[i].name, t)) 
		{
			printf("��������Ʒ�����:\n");
			scanf("%d", &n);
			product[i].count = product[i].count + n;
			printf("�������Ʒ������:%d\n", product[i].count);
			break;
		}
	}
	if (i == num) 
	{
		strcpy(product[num].name, t);
		printf("��������Ʒ����:\n");
		scanf("%d", &n);
		printf("��������Ʒ��λ:\n");
		scanf("%s", &x);
		product[num].count = n;
		strcpy(product[num].danwei, x);
		printf("����Ʒ�������:%d\n", n);
		printf("�������Ʒ������:%d\n", n);
		++num;
	}
	save();
	printf("�Ƿ���������Ʒ?\n");
	printf("��y������ӣ���n�����:\n");
	char choice[2];
	scanf("%s", choice);
	if (choice[0] == 'y')
	{
		input();
	}
	printf("\n");
}
void output()
{
	char str[10];
	int i, n;
	printf("��������Ҫ������Ʒ���ͺ�:");
	scanf("%s", str);
	printf("\n");
	for (i = 0; i < num; ++i) 
	{
		if (strcmp(product[i].name, str) == 0)
		{
			printf("����Ʒԭ�����Ϊ:%d\n", product[i].count);
			printf("�����������Ʒ������:\n");
			scanf("%d", &n);
			if (n <= product[i].count) 
			{
				printf("��������Ʒ��ʣ������Ϊ:%d\n", product[i].count - n);
				product[i].count -= n;
				save();
			}
			else 
			{
				printf("���������!\n");
				break;
			}
		}
	}
	if (i == num) 
	{
		printf("û�и���Ʒ!\n");
	}
	printf("�Ƿ������������Ʒ?\n");
	printf("��y�������⣬��n����������:\n");
	char choice[2];
	scanf("%s", choice);
	if (choice[0] == 'y')
	{
		output();
	}
	printf("\n");
}
void show()
{
	for (int i = 0; i < num; i++)
	{
		printf("��%d����Ʒ:�ͺ�:%s ����:%d ��λ:%s\n", i + 1, product[i].name, product[i].count, product[i].danwei);
	}
	printf("\n");
}
void menu()
{
	printf("*********************************\n"
		   "*		�˵�:		*\n"
			"*        1.��ʾ����б�		*\n"
			"*        2.���			*\n"
			"*        3.����			*\n"
			"*        4.�����Ļ		*\n"
			"*        5.�˳�����		*\n"
			"*********************************\n"
			"�밴���ּ����ж�Ӧ����:");
}