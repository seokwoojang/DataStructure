#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct info_book
{
	int num;//�й�
	char name[20];//������
	int rent_day;//�뿩��
	int return_day;//�ݳ���
}typedef info_book;
info_book book[100] = { {123,"e",123,123},
	{234,"ee",234,234},
	{123,"eee",124,124},
	{234,"eeee",235,235},
	{345,"eere",345,345} };

void Insert_book(info_book book[], int* n)
{
	printf("�й� : ");
	scanf("%d", &book[*n].num);

	printf("������ : ");
	scanf("%s", &book[*n].name);

	printf("�뿩�� : ");
	scanf("%d", &book[*n].rent_day);

	printf("�ݳ��� : ");
	scanf("%d", &book[*n].return_day);
	(*n)++;
}

void Display(info_book A)
{
	printf("\n--------------------\n");
	printf("%10d%10s%10d%10d\n", A.num, A.name, A.rent_day, A.return_day);
}

void Search(info_book book[], int n, int select, int value)
{
	switch (select)
	{
	case 1://�й�
		for (int i = 0; i < n; i++)
			if (book[i].num == value)
				Display(book[i]);
		break;
	case 2://�뿩��
		for (int i = 0; i < n; i++)
			if (book[i].rent_day == value)
				Display(book[i]);
		break;
	case 3://�ݳ���
		for (int i = 0; i < n; i++)
		{
			if (book[i].return_day == value)
			{
				Display(book[i]);
			}
		}
		break;
	}
}

int main123(void)
{
	int n = 5;
	int select = 0;
	while (1)
	{
		printf("����\n1. �Է�\n2. �˻�\n�Է� :");
		scanf("%d", &select);
		if (select == 1)
		{
			Insert_book(book, &n);
		}
		else if (select == 2)
		{
			int value;

			printf("\n------------------\n");
			printf("�˻����\n1. �й�\n2. �뿩��\n3. �ݳ���\n�Է� : ");
			scanf("%d", &select);

			printf("�˻��� �Է� : ");
			scanf("%d", &value);

			Search(book, n, select, value);
		}
	}

}