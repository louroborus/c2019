#pragma warning(disable:4996)
#include <stdio.h>
#include<malloc.h>

typedef struct link
{
	int value;
	struct link *next;
}LinkList;

LinkList *create(int n)
{
	LinkList *head, *node, *end;
	head = (LinkList*)malloc(sizeof(LinkList));
	scanf("%d", &head->value);
	end = head;
	for (int i = 1; i < n; ++i)
	{
		node = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d", &node->value);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

void insert(LinkList *head, int n)//�ڵ�n�������һ��
{
	LinkList *t = head, *in;
	for (int i = 1; i < n && t != NULL; i++)
	{
		t = t->next;
	}
	if (t != NULL && n >= 0)
	{
		in = (LinkList*)malloc(sizeof(LinkList));
		puts("����Ҫ�����ֵ");
		scanf("%d", &in->value);
		in->next = t->next;
		t->next = in;
	}
	else
	{
		puts("�ڵ㲻����");
	}
}

void change(LinkList *head, int n)
{
	LinkList *t = head;
	for (int i = 1; i < n && t != NULL; ++i) 
	{
		t = t->next;
	}
	if (t != NULL && n > 0)
	{
		puts("����Ҫ�޸ĵ�ֵ");
		scanf("%d", &t->value);
	}
	else 
	{
		puts("�ڵ㲻����");
	}
}

void dele(LinkList **head, int n)
{
	LinkList *t = *head, *d = t;;
	if (n <= 0)
	{
		puts("�ڵ㲻����");
	}
	else if (n == 1)
	{
		t = t->next;
		*head = t;
		free(d);
	}
	else
	{
		for (int i = 1; i < n && t != NULL; ++i)
		{
			d = t;
			t = t->next;
		}
		if (t != NULL)
		{
			d->next = t->next;
			free(t);
		}
		else
		{
			puts("�ڵ㲻����");
		}
	}
}

int main()
{
	int n;
	puts("����Ҫ�����ֵ�ĸ���");
	scanf("%d", &n);
	struct link *head = create(n);
	struct link *p = head;
	for (int i = 1; i < n; ++i)
	{
		LinkList *t = head, *in;
		for (int i = 1; i < n; i++)
		{
			t = t->next;
		}
		in = (LinkList*)malloc(sizeof(LinkList));
		in->value=p->value;
		in->next = t->next;
		t->next = in;
		p = p->next;
	}
	for (int i = 1; i < n; ++i)
	{
		dele(&head, 1);
	}
	p = head;
	int flag = 0;
	for (int i = 1; i < n; ++i)
	{
		if (p->value == 5)
		{
			printf("%d ", i);
			++flag;
		}
		p = p->next;
	}
	if (flag == 0)
		printf("-1");
	return 0;
}
