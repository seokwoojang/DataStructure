#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct book {
	int num;//학번
	char name[20];//도서명
	int rent_day;//대여일
	int return_day;//반납일
}book;

book bk[100] = {
	{1,"a",1,1},
	{3,"c",3,3},
	{4,"d",4,4},
	{5,"e",5,5},
};

void insert(int* n)
{
	printf("학번 : ");
	scanf("%d", &bk[*n].num);
	printf("도서명 : ");
	scanf("%s", &bk[*n].name);
	printf("대여일 : ");
	scanf("%d", &bk[*n].rent_day);
	printf("반납일 : ");
	scanf("%d", &bk[*n].return_day);
	(*n)++;
}

void display(book bk)
{
	printf("\n\n--------------------------------------------------\n");
	printf("%d  %s  %d  %d\n\n", bk.num, bk.name, bk.rent_day, bk.return_day);
}

void search(int n, int select, int value)
{
	switch (select)
	{
	case 1://학번
		for (int i = 0; i < n; i++)
		{
			if (bk[i].num == value)
			{
				display(bk[i]);
			}
		}
		break;
	case 2://대여일
		for (int i = 0; i < n; i++)
		{
			if (bk[i].rent_day == value)
			{
				display(bk[i]);
			}
		}
		break;
	case 3://반납일
		for (int i = 0; i < n; i++)
		{
			if (bk[i].return_day == value)
			{
				display(bk[i]);
			}
		}
		break;
	default:
		break;
	}
}

int main(void)
{
	int n = 5;
	int select = 0;
	while (1)
	{
		printf("선택\n1. 입력\n2. 검색\n입력 :");
		scanf("%d", &select);
		if (select == 1)
		{
			insert(&n);
		}
		else if (select == 2)
		{
			int value;

			printf("\n------------------\n");
			printf("검색방법\n1. 학번\n2. 대여일\n3. 반납일\n입력 : ");
			scanf("%d", &select);

			printf("검색값 입력 : ");
			scanf("%d", &value);

			search(n, select, value);
		}
	}
}