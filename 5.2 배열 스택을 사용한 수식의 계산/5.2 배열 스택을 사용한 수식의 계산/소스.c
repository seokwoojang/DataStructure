#include<stdio.h>
#include<string.h>

char s[15] = "(a+b)*(c/d)";
char stack[5];
char item2;
int top = -1;

int prec(char op) {
	switch (op)
	{
	/*case'(':
		return 0;*/
	case'+': case'-':
		return 1;
	case'*': case'/':
		return 2;
	}
	return -1;
}

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

char Stack_push(char item)
{
	if (Stack_full())
		return 0;
	top = top + 1;
	stack[top] = item;
}

char Stack_pop()
{
	if (Stack_empty())
		return 0;
	item2 = stack[top];
	top = top - 1;
	return item2;
}

void infix_to_posfix(char s[])
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		char token = s[i];
		switch (token)
		{
		case'+': case'-': case'*': case'/':
			while (prec(token) <= prec(stack[top]))
				printf("%c", Stack_pop());
			Stack_push(token);
			break; 
		case'(':
			Stack_push(token);
			break;
		case')':
			while (stack[top] != '(')
			{
				printf("%c", Stack_pop());
			}
			break;
		default:
			printf("%c", token);
			break;
		}
	}
	while (1) {
		if (Stack_empty() == 1)
			break;
		else
			if (stack[top] == '(')
				Stack_pop();
			else
				printf("%c", Stack_pop());
	}
}

int main(void)
{
	infix_to_posfix(s);
}