/*#include<stdio.h>
#define Stack_size 10

int stack[Stack_size];
int top = -1;

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

void push(int item)
{
	if (full())
		return;
	else
	{
		top = top + 1;
		stack[top] = item;
	}
}

int pop()
{
	if (empty())
		return -1;
	else
	{
		int temp = stack[top];
		top = top - 1;
		return temp;
	}
}

int main(void)
{
	push(1);
	push(2);
	push(3);
	push(4);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
}*/