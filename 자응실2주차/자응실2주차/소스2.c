#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct book {
	int num;//�й�
	char name[20];//������
	int rent_day;//�뿩��
	int return_day;//�ݳ���
}book;

book bk[100] = {
	{1,"a",1,1},
	{3,"c",3,3},
	{4,"d",4,4},
	{5,"e",5,5},
};

void insert(int* n)
{
	printf("�й� : ");
	scanf("%d", &bk[*n].num);
	printf("������ : ");
	scanf("%s", &bk[*n].name);
	printf("�뿩�� : ");
	scanf("%d", &bk[*n].rent_day);
	printf("�ݳ��� : ");
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
	case 1://�й�
		for (int i = 0; i < n; i++)
		{
			if (bk[i].num == value)
			{
				display(bk[i]);
			}
		}
		break;
	case 2://�뿩��
		for (int i = 0; i < n; i++)
		{
			if (bk[i].rent_day == value)
			{
				display(bk[i]);
			}
		}
		break;
	case 3://�ݳ���
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
		printf("����\n1. �Է�\n2. �˻�\n�Է� :");
		scanf("%d", &select);
		if (select == 1)
		{
			insert(&n);
		}
		else if (select == 2)
		{
			int value;

			printf("\n------------------\n");
			printf("�˻����\n1. �й�\n2. �뿩��\n3. �ݳ���\n�Է� : ");
			scanf("%d", &select);

			printf("�˻��� �Է� : ");
			scanf("%d", &value);

			search(n, select, value);
		}
	}
}