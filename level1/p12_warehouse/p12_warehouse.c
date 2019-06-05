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
	printf("数据已保存，退出程序成功!\n");
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
		printf("不能打开文件!\n");
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
		printf("不能打开文件!\n");
		return;
	}
	for (int i = 0; i < num; ++i)
	{
		fprintf(fp, "%s %d %s\n", product[i].name, product[i].count, product[i].danwei);
	}
	printf("\n操作已保存!\n");
	fclose(fp);
}
void input()
{
	char t[15], x[15];
	int n, i;
	printf("请输入存入货物的型号:");
	scanf("%s", t);
	printf("\n");
	for (i = 0; i < num; ++i) 
	{
		if (!strcmp(product[i].name, t)) 
		{
			printf("请输入商品入库量:\n");
			scanf("%d", &n);
			product[i].count = product[i].count + n;
			printf("入库后该商品的总量:%d\n", product[i].count);
			break;
		}
	}
	if (i == num) 
	{
		strcpy(product[num].name, t);
		printf("请输入商品数量:\n");
		scanf("%d", &n);
		printf("请输入商品单位:\n");
		scanf("%s", &x);
		product[num].count = n;
		strcpy(product[num].danwei, x);
		printf("该商品的入库量:%d\n", n);
		printf("入库后该商品的总量:%d\n", n);
		++num;
	}
	save();
	printf("是否继续入库商品?\n");
	printf("按y继续添加，按n不添加:\n");
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
	printf("请输入想要出库商品的型号:");
	scanf("%s", str);
	printf("\n");
	for (i = 0; i < num; ++i) 
	{
		if (strcmp(product[i].name, str) == 0)
		{
			printf("该商品原库存量为:%d\n", product[i].count);
			printf("请输入出库商品的数量:\n");
			scanf("%d", &n);
			if (n <= product[i].count) 
			{
				printf("出库后该商品的剩余库存量为:%d\n", product[i].count - n);
				product[i].count -= n;
				save();
			}
			else 
			{
				printf("库存量不足!\n");
				break;
			}
		}
	}
	if (i == num) 
	{
		printf("没有该商品!\n");
	}
	printf("是否还想继续出库商品?\n");
	printf("按y继续出库，按n不继续出库:\n");
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
		printf("第%d类商品:型号:%s 数量:%d 单位:%s\n", i + 1, product[i].name, product[i].count, product[i].danwei);
	}
	printf("\n");
}
void menu()
{
	printf("*********************************\n"
		   "*		菜单:		*\n"
			"*        1.显示存货列表		*\n"
			"*        2.入库			*\n"
			"*        3.出库			*\n"
			"*        4.清空屏幕		*\n"
			"*        5.退出程序		*\n"
			"*********************************\n"
			"请按数字键进行对应操作:");
}