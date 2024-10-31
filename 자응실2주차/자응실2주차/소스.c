#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct info_book
{
	int num;//학번
	char name[20];//도서명
	int rent_day;//대여일
	int return_day;//반납일
}typedef info_book;
info_book book[100] = { {123,"e",123,123},
	{234,"ee",234,234},
	{123,"eee",124,124},
	{234,"eeee",235,235},
	{345,"eere",345,345} };

void Insert_book(info_book book[], int* n)
{
	printf("학번 : ");
	scanf("%d", &book[*n].num);

	printf("도서명 : ");
	scanf("%s", &book[*n].name);

	printf("대여일 : ");
	scanf("%d", &book[*n].rent_day);

	printf("반납일 : ");
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
	case 1://학번
		for (int i = 0; i < n; i++)
			if (book[i].num == value)
				Display(book[i]);
		break;
	case 2://대여일
		for (int i = 0; i < n; i++)
			if (book[i].rent_day == value)
				Display(book[i]);
		break;
	case 3://반납일
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
		printf("선택\n1. 입력\n2. 검색\n입력 :");
		scanf("%d", &select);
		if (select == 1)
		{
			Insert_book(book, &n);
		}
		else if (select == 2)
		{
			int value;

			printf("\n------------------\n");
			printf("검색방법\n1. 학번\n2. 대여일\n3. 반납일\n입력 : ");
			scanf("%d", &select);

			printf("검색값 입력 : ");
			scanf("%d", &value);

			Search(book, n, select, value);
		}
	}

}