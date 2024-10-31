#include<stdio.h>
#include<string.h>
#define Stack_size 30

int stack[Stack_size];
int top = -1;
char infix[Stack_size] = "2+3*5";
int itop = -1;
char postfix[Stack_size];
int ptop = -1;

int empty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

int full()
{
	if (top == (Stack_size - 1))
		return 1;
	else
		return 0;
}

void push(char item)
{
	if (full())
		return;
	else
	{
		top = top + 1;
		stack[top] = item;
	}
}

char pop()
{
	if (empty())
		return -1;
	else
	{
		char temp = stack[top];
		top = top - 1;
		return temp;
	}
}

int token(char ch)
{
	switch (ch)
	{
	case'(':
		return 0;
		break;
	case '+':case'-':
		return 1;
		break;
	case'*':case'/':
		return 2;
		break;
	default:
		break;
	}
}

void infixto()
{
	int len = strlen(infix);
	for (int i = 0; i < len; i++)
	{
		char temp = infix[i];
		switch (temp)
		{
		case '(':
			push(temp);
			break;
		case ')':
			while (stack[top] != '(')
			{
				ptop = ptop + 1;
				postfix[ptop] = pop();
			}
		case '+': case '-': case '*': case '/':
			while (top != -1 && (token(temp) <= token(stack[top])))
			{
				ptop = ptop + 1;
				postfix[ptop] = pop();
			}
			push(temp);
			break;
		default:
			ptop = ptop + 1;
			postfix[ptop] = temp;
			break;
		}
	}
	while (empty() != 1)
	{
		ptop = ptop + 1;
		postfix[ptop] = pop();
	}
}

double eval()
{
	double a, b;
	int len = strlen(postfix);
	for (int i = 0; i < len; i++)
	{
		char temp = postfix[i];
		if (temp >= '0' && temp <= '9')
		{
			push(temp-'0');
		}
		else
		{
			b = pop();
			a = pop();
			switch (temp)
			{
			case'+':
				push(a + b);
				break;
			case'-':
				push(a - b);
				break;
			case'*':
				push(a * b);
				break;
			case'/':
				push(a / b);
				break;
			default:
				break;
			}
		}
	}
	return pop();
}

int main(void)
{
	infixto();
	printf("%s\n", postfix);
	printf("%.2f", eval());
}