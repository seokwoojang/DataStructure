#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define STACK_SIZE 5

int ary[STACK_SIZE];
int top = -1;

int isempty()
{
	if (top == -1)
	{
		return 1;
	}
	else
		return 0;
}

int isfull()
{
	if (top == STACK_SIZE - 1)
{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int item)
{
	if (isfull() == 1)
	{
		printf("���� �� �ֽ��ϴ�.\n");
		return;
	}
	else
	{
		top = top + 1;
		ary[top] = item;
		return;
	}
}

int pop(int item)
{
	int temp;
	if (isempty() == 1)
	{
		printf("�� ���� �Դϴ�.\n");
		return 0;
	}
	else
	{
		temp = ary[top];
		top = top - 1;
		return temp;
	}
}

peek()//top ����Ű�� ���� Ȯ��
{

}

void display()
{
	for (int i = STACK_SIZE - 1; i >=0 ; i--)
	{
		printf("[%d]  |  %d  |\n", i, ary[i]);
	}
	printf("         -----\n");
}

void main()
{
	srand(time(NULL));
	for (int i = 1; i < 11; i++)
	{
		int ran = rand() % 2 ;
		if (ran == 1)
		{
			printf("\n�Է��� �� : %d\n", i);
			push(i);
		}
		else
		{
			int temp = pop(i);
			if (temp != 0)
			{
				printf("\n����� �� : %d\n", temp);
			}
		}
		display();
		//peek()
	}
}