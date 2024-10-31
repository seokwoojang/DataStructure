/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable : 4996)
#define MAXSIZE 30

char infix[MAXSIZE];
char postfix[MAXSIZE];
char stack[MAXSIZE];

int top = -1;
int i_top = -1;
int p_top = -1;

int Em()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int Fu()
{
	if (top == MAXSIZE - 1)
		return 1;
	else
		return 0;
}

void push(int item)
{
	if (Fu())
	{
		printf("스택이 가득\n");
		return;
	}
	top = top + 1;
	stack[top] = item;
}

char pop()
{
	if (Em())
	{
		printf("스택이 비었다!!\n");
		return ;
	}
	return stack[top--];
}

int E(char data)//우선순위 토큰
{
	switch (data)
	{
	case '(':
		return 0;
		break;
	case '+': case '-':
		return 1;
		break;
	case '*': case '/':
		return 2;
		break;
	default:
		break;
	}
}

double result()
{
	double A, B;
	char temp;
	int len = strlen(postfix);
	for (int i = 0; i < len; i++)
	{
		temp = postfix[i];
		if (temp >= '0' && temp <= '9')
		{
			push(temp-'0');
		}
		else
		{
			B = pop();
			A = pop();
			switch (temp)
			{
			case'+':
				push(A + B);
				break;
			case'-':
				push(A - B);
				break;
			case'/':
				push(A / B);
				break;
			case'*':
				push(A * B);
				break;
			default:
				break;
			}
		}
	}
	return pop();
}

void main()
{
	printf("중위식을 입력하세요 : ");
	scanf("%s", infix);

	int len = strlen(infix);
	char temp;
	for (int i = 0; i < len; i++)
	{
		char data = infix[i];
		switch (data)
		{
		case'(':
			push(data);
			break;
		case')':
			temp = pop();
			while (temp != ')')
			{
				p_top = p_top + 1;
				postfix[p_top] = temp;
				temp = pop();
			}
			break;
		case'+': case'-': case'*': case'/':
			while (top != -1 && (E(data) <= E(stack[top])))
			{
				p_top = p_top + 1;
				postfix[p_top] = pop();
			}
			push(data);
			break;
		default:
			p_top = p_top + 1;
			postfix[p_top] = data;
			break;
		}
	}
	while (top != -1)
	{
		p_top = p_top + 1;
		postfix[p_top] = pop();
	}

	printf("-------------------------------\n");
	printf("후위식 : %s\n", postfix);


	printf("-------------------------------\n");
	printf("결과값 : %f\n", result());
}*/