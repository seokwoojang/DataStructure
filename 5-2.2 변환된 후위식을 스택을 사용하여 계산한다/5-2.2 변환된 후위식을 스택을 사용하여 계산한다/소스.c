#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[10] = "235*+42/-";
int stack[5];
int item2;
int top = -1;


int Stack_empty()
{
	if (top == -1)
		return 1;
	else {
		return 0;//False
	}
}

int Stack_full()
{
	if (top == 5)
	{
		return 1;
	}
	else
		return 0;
}

void Stack_push(int item)
{
	if (Stack_full())
		return 0;
	top = top + 1;
	stack[top] = item;
}

int Stack_pop()
{
	if (Stack_empty())
		return 0;
	item2 = stack[top];
	top = top - 1;
	return item2;
}

int postfix_eval(char postfix[])
{
	int len = strlen(postfix);
	for (int i = 0; i < len; i++)
	{
		char token = postfix[i];
		switch (token)
		{
		case'+':
		{
			int op2 = Stack_pop();
			int op1 = Stack_pop();
			int result = op1 + op2;
			Stack_push(result);
			break;
		}
		case'-':
		{
			int op2 = Stack_pop();
			int op1 = Stack_pop();
			int result = op1 - op2;
			Stack_push(result);
			break;
		}
		case'*':
		{
			int op2 = Stack_pop();
			int op1 = Stack_pop();
			int result = op1 * op2;
			Stack_push(result);
			break;
		}
		case'/':
		{
			int op2 = Stack_pop();
			int op1 = Stack_pop();
			int result = (int)op1 / op2;
			Stack_push(result);
			break;
		}
		default:
		{
			int n = token - '0';
			Stack_push(n);
			break;
		}
		}
	}
	return Stack_pop();
}

int main(void)
{
	printf("%d", postfix_eval(s));
}